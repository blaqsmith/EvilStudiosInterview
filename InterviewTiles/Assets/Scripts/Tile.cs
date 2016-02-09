using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Tile : MonoBehaviour
{
	[HideInInspector]
	public bool dragAllowed = true;
	[HideInInspector]
	public Animator animator;
	private bool isDragging = false;
	private Vector3 lastMousePos;

	public Text textLetter;
	public Image imageBackground;

	void Start()
	{
		animator = gameObject.GetComponent<Animator>();
	}

	public void Init()
	{
		transform.localPosition = Vector3.zero;
		AllowDrag( true );
        if ( animator != null )
			animator.SetBool( "Visible", true );
	}

	private char _letter;
	public char letter
	{
		get { return _letter; }
		set
		{
			_letter = char.ToUpper( value );    //Sanitize input

			if ( value < 'A' || value > 'Z' )
				return;

			RefreshView();
		}
	}

	private void RefreshView()
	{
		textLetter.text = _letter.ToString();
	}

	public void AllowDrag( bool value )
	{
		if ( dragAllowed != value )
		{
			dragAllowed = value;
			CanvasGroup cg = gameObject.GetComponent<CanvasGroup>();
			cg.interactable = value;
			cg.blocksRaycasts = value;
		}
	}

	public void OnPointerDown()
	{
		lastMousePos = Input.mousePosition;
		isDragging = true;
		transform.SetAsLastSibling();
		StartCoroutine( OnDrag() );
	}

	public IEnumerator OnDrag()
	{
		while ( isDragging )
		{
			transform.position -= ( lastMousePos - Input.mousePosition );
			lastMousePos = Input.mousePosition;
			yield return null;
		}
	}

	public void OnPointerUp()
	{
		if ( isDragging )
		{
			isDragging = false;

			//Detect if dropped on the right slot
			GameLogic.Instance.CheckMatch( this );
		}
	}
}
