using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/* Some example useage:
	
	UITween.On( gameobject )
		.MoveToPoint( vectorPoint, 2f, TweenEase.BOUNCE )
		.Call( () => { Debug.Log("Anonymous funcition"); } )
		.Move( deltaVector, 2f, TweenEase.QUAD )
		.Wait( 2f )
		.Call( function );

*/

public class UITween : MonoBehaviour
{
	private static Dictionary<GameObject, UITweenSequence> tweens = new Dictionary<GameObject, UITweenSequence>();
	private static UITween script;
	private static GameObject go;
	private static GameObject instance
	{
		get
		{
			if ( go == null )
			{
				go = new GameObject( "UITweenManager" );
				script = go.AddComponent<UITween>();
			}
			return go;
		}
	}

	public static UITweenSequence On( GameObject targetGO )
	{
		if ( instance == null )
		{
			Debug.LogError( "Unable to access or create an instance of UITween." );
			return null;
		}

		UITweenSequence seq;
		tweens.TryGetValue( targetGO, out seq );
		if ( seq == null )
		{
			seq = new UITweenSequence( targetGO );
			tweens[ targetGO ] = seq;
		}

		script.StartTweening();
		return seq;
	}

	private bool isRunning = false;
	private void StartTweening()
	{
		if ( !isRunning )
			StartCoroutine( UpdateTweens() );
	}

	private List<GameObject> deletedKeys = new List<GameObject>();
	private IEnumerator UpdateTweens()
	{
		isRunning = true;
		yield return new WaitForEndOfFrame();

		while ( tweens.Count > 0 )
		{
			//Debug.Log( "time: " + Time.time );
			foreach ( KeyValuePair<GameObject, UITweenSequence> tween in tweens )
			{
				if ( tween.Value.Update() ) //Returns true when the animation sequence is completed
				{
					deletedKeys.Add( tween.Key );
				}
			}

			if ( deletedKeys.Count > 0 )
			{
				foreach ( GameObject go in deletedKeys )
				{
					tweens.Remove( go );
				}
				deletedKeys.Clear();
			}

			yield return null;
		}

		isRunning = false;
	}
}


public class UITweenSequence
{
	private List<UITweenStep> steps = new List<UITweenStep>();
	private RectTransform targetTransform;
	private UITweenStep currentStep = null;

	internal UITweenSequence( GameObject gameObject )
	{
		this.targetTransform = gameObject.transform as RectTransform;
	}

	internal bool Update() //Returns true when all steps complete
	{
		if ( currentStep == null && steps.Count > 0 )
		{
			currentStep = steps[ 0 ];
			currentStep.Init( targetTransform );
			steps.RemoveAt( 0 );
		}

		if ( currentStep != null  )
		{
			if ( currentStep.ApplyProgress( targetTransform ) )
			{
				currentStep = null;
			}
			return false; //Single step complete, will check for more next frame
		}

		return true; //All Steps complete
	}

	public UITweenSequence Wait( float waitTimeInSecs )
	{
		UITweenWaitStep step = new UITweenWaitStep();
		step.duration = waitTimeInSecs;
		steps.Add( step );
		return this;
	}

	public UITweenSequence Call( System.Action action )
	{
		UITweenCallStep step = new UITweenCallStep();
		step.func = action;
		steps.Add( step );
		return this;
	}

	public UITweenSequence MoveToPoint( Vector3 targetPos, float duration, System.Func<float, Vector3, Vector3, Vector3> easingFunction )
	{
		UITweenMoveToPositionStep step = new UITweenMoveToPositionStep();
		step.deltaPosition = targetPos; //deltaPosition calculated on step.Init, stuffing targetPosition in there until then
		step.duration = duration;
		step.easingFunction = easingFunction;
		steps.Add( step );
		return this;
	}

	public UITweenSequence Move( Vector3 deltaVector, float duration, System.Func<float, Vector3, Vector3, Vector3> easingFunction )
	{
		UITweenMoveDeltaStep step = new UITweenMoveDeltaStep();
		step.deltaPosition = deltaVector;
		step.duration = duration;
		step.easingFunction = easingFunction;
		steps.Add( step );
		return this;
	}
}


#region Step classes

internal abstract class UITweenStep
{
	internal float delay = 0f;
	internal float startTime = 0f;
	internal float duration = 0f;

	virtual internal void Init( RectTransform trans ) { }
	virtual internal bool ApplyProgress( RectTransform trans ) { return true; }
}

internal class UITweenWaitStep : UITweenStep
{
	override internal void Init( RectTransform trans )
	{
		startTime = Time.time;
	}

	override internal bool ApplyProgress( RectTransform trans )
	{
		float percentComplete = ( duration <= 0f ? 1f : Mathf.Clamp01( ( Time.time - startTime ) / duration ) );
		return percentComplete == 1f;
	}
}

internal class UITweenCallStep : UITweenStep
{
	internal System.Action func;
	override internal bool ApplyProgress( RectTransform trans )
	{
		func.Invoke();
		return true;
	}
}

internal class UITweenMoveDeltaStep : UITweenStep
{
	internal Vector3 startPosition;
	internal Vector3 deltaPosition;
	internal System.Func<float, Vector3, Vector3, Vector3> easingFunction;

	override internal void Init( RectTransform trans )
	{
		startPosition = trans.localPosition;
		startTime = Time.time;
	}

	override internal bool ApplyProgress( RectTransform trans )
	{
		float percentComplete = ( duration <= 0f ? 1f : Mathf.Clamp01( ( Time.time - startTime ) / duration ) );
		trans.localPosition = easingFunction( percentComplete, startPosition, deltaPosition );
		return percentComplete == 1f;
	}
}

internal class UITweenMoveToPositionStep : UITweenMoveDeltaStep
{
	override internal void Init( RectTransform trans )
	{
		startPosition = trans.localPosition;
		deltaPosition = deltaPosition - startPosition;
		startTime = Time.time;
	}
}

#endregion


public class Easing
{
	private const float PI_HALF = Mathf.PI / 2;

	public static float Linear( float pctDone, float start, float delta )
	{
		return delta * pctDone + start;
	}

	public static Vector3 Linear( float pctDone, Vector3 start, Vector3 delta )
	{
		return delta * pctDone + start;
	}

	public static float SineEaseIn( float pctDone, float start, float delta )
	{
		return -delta * Mathf.Cos( pctDone * PI_HALF ) + delta + start;
	}

	public static Vector3 SineEaseIn( float pctDone, Vector3 start, Vector3 delta )
	{
		return -delta * Mathf.Cos( pctDone * PI_HALF ) + delta + start;
	}

	public static float SineEaseOut( float pctDone, float start, float delta )
	{
		return delta * Mathf.Sin( pctDone * PI_HALF ) + start;
	}

	public static Vector3 SineEaseOut( float pctDone, Vector3 start, Vector3 delta )
	{
		return delta * Mathf.Sin( pctDone * PI_HALF ) + start;
	}

	public static float SineEaseInOut( float pctDone, float start, float delta )
	{
		return -delta / 2 * ( Mathf.Cos( Mathf.PI * pctDone ) - 1 ) + start;
	}

	public static Vector3 SineEaseInOut( float pctDone, Vector3 start, Vector3 delta )
	{
		return -delta / 2 * ( Mathf.Cos( Mathf.PI * pctDone ) - 1 ) + start;
	}

	public static float QuadEaseIn( float pctDone, float start, float delta )
	{
		return delta * pctDone * pctDone + start;
	}

	public static Vector3 QuadEaseIn( float pctDone, Vector3 start, Vector3 delta )
	{
		return delta * pctDone * pctDone + start;
	}

	public static float QuadEaseOut( float pctDone, float start, float delta )
	{
		return -delta * pctDone * ( pctDone - 2 ) + start;
	}

	public static Vector3 QuadEaseOut( float pctDone, Vector3 start, Vector3 delta )
	{
		return -delta * pctDone * ( pctDone - 2 ) + start;
	}

	public static float QuadEaseInOut( float pctDone, float start, float delta )
	{
		pctDone *= 2;
		if ( pctDone < 1 ) return delta / 2 * pctDone * pctDone + start;
		pctDone--;
		return -delta / 2 * ( pctDone * ( pctDone - 2 ) - 1 ) + start;
	}

	public static Vector3 QuadEaseInOut( float pctDone, Vector3 start, Vector3 delta )
	{
		pctDone *= 2;
		if ( pctDone < 1 ) return delta / 2 * pctDone * pctDone + start;
		pctDone--;
		return -delta / 2 * ( pctDone * ( pctDone - 2 ) - 1 ) + start;
	}
}
