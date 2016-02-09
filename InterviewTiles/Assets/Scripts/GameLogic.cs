using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GameLogic : MonoBehaviour
{
	public static GameLogic Instance;

	public string validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	[Tooltip("10 characters per word max, restricted to A-Z")]
	public string secretPhrase = "Evil Empire";

	public GameObject slotPrefab;
	public GameObject tilePrefab;

	public Transform slotsContainter;
	public Transform tilesContainer;

	[HideInInspector]
	public List<Tile> currentTiles;
	[HideInInspector]
	public List<TileSlot> currentSlots;

	public Animator winAnimator;
	public Transform winWheel;
	public AudioSource audioSource;

	[Header( "Audio Clips" )]
	public AudioClip tileTouched;
	public AudioClip goodMatch;
	public AudioClip badMatch;

	private int numMatches = 0;
	private List<GameObject> tileGOPool = new List<GameObject>();
	private List<GameObject> slotGOPool = new List<GameObject>();

	void Start()
	{
		Instance = this;
		Init();
	}

	private void Init()
	{
		secretPhrase = secretPhrase.ToUpper();
		string[] phraseLines = secretPhrase.Split( ' ' );

		float padding = 10f;
		float tileDiameter = 64f;
		float currentY = ( ( phraseLines.Length - 1 ) * tileDiameter + ( phraseLines.Length - 1 ) * padding ) / 2;
		string phrase;
		float startX;
		GameObject slot;
		GameObject tile;
		for ( var lineIndex = 0; lineIndex < phraseLines.Length; ++lineIndex )
		{
			phrase = phraseLines[lineIndex];
			startX = -( ( phrase.Length - 1 ) * tileDiameter + ( phrase.Length - 1 ) * padding ) / 2;
			for ( var charIndex = 0; charIndex < phrase.Length; ++charIndex )
			{
				//Grab a slot for our phrase char for the player to drop a tile on
				slot = GetSlot( phrase[ charIndex ] );
				slot.transform.localPosition = new Vector3( startX + charIndex * ( tileDiameter + padding ), currentY, 0f );
				
				//Grab a tile that goes in the slot
				tile = GetTile( phrase[charIndex] );
				while ( Mathf.Abs( tile.transform.localPosition.y ) < 130f )
					tile.transform.localPosition = new Vector3( Random.Range( -300f, 300f ), Random.Range( -600f, 600f ), 0f );

				//Grab another random tile for extra confusion!
				tile = GetTile( validChars[ Random.Range( 0, 26 ) ] );
				while ( Mathf.Abs( tile.transform.localPosition.y ) < 130f )
					tile.transform.localPosition = new Vector3( Random.Range( -300f, 300f ), Random.Range( -600f, 600f ), 0f );
			}
			currentY -= tileDiameter + padding;
		}

		Invoke( "ShowHint", 10f );
	}

	//Gets slot from pool, or creates one if needed
	private GameObject GetSlot( char letter )
	{
		GameObject slotGo;
		if ( slotGOPool.Count > 0 )
		{
			slotGo = slotGOPool[ slotGOPool.Count - 1 ];
			slotGOPool.RemoveAt( slotGOPool.Count - 1 );
		}
		else
		{
			slotGo = Instantiate( slotPrefab );
			slotGo.transform.SetParent( slotsContainter, false );
		}

		TileSlot tileSlot = slotGo.GetComponent<TileSlot>();
		tileSlot.Init();
		tileSlot.letter = letter;
		currentSlots.Add( tileSlot );

		return slotGo;
	}

	//Gets tile from pool, or creates one if needed
	GameObject GetTile( char letter )
	{
		GameObject tileGO;
		if ( tileGOPool.Count > 0 )
		{
			tileGO = tileGOPool[ tileGOPool.Count - 1 ];
			tileGOPool.RemoveAt( tileGOPool.Count - 1 );
		}
		else
		{
			tileGO = Instantiate( tilePrefab );
			tileGO.transform.SetParent( tilesContainer, false );
		}

		Tile tile = tileGO.GetComponent<Tile>();
		tile.Init();
		tile.letter = letter;
		currentTiles.Add( tile );

		return tileGO;
	}

	public void CheckMatch( Tile tile )
	{
		foreach ( TileSlot slot in currentSlots )
		{
			if ( slot.IsTileOver( tile ) )
			{
				if ( slot.Matches( tile ) )
				{
					//Good match - lock tile
					audioSource.PlayOneShot( goodMatch );
					++numMatches;
					slot.claimed = true;
					tile.AllowDrag( false );
					UITween.On( tile.gameObject )
						.MoveToPoint( slot.transform.localPosition, .15f, Easing.QuadEaseInOut );

					//Reset hint time
					CancelInvoke( "ShowHint" );
					Invoke( "ShowHint", 25f );
				}
				else
				{
					//Bad match - eject tile from slot
					audioSource.PlayOneShot( badMatch );
					UITween.On( tile.gameObject )
						.Move( new Vector3( Random.Range( -20f, 20f), Random.Range( 125f, 145f ) * ( tile.transform.localPosition.y < 0f ? -1f : 1f ), 0f), .15f, Easing.SineEaseOut );
				}
				
                break;
			}
		}

		if ( numMatches == currentSlots.Count )
		{
			Debug.Log( "You won!" );
			winAnimator.SetTrigger( "Win" );
			wheelSpinning = true;
			StartCoroutine( SpinWheel() );

			Vector3 outward;
			foreach ( Tile otherTile in currentTiles )
			{
				if ( otherTile.dragAllowed )
				{
					outward = otherTile.transform.localPosition.normalized;
					outward *= 1000f;
					UITween.On( otherTile.gameObject ).MoveToPoint( outward, 0.5f, Easing.QuadEaseIn );
				}
			}
		}

	}

	//Continuous rotations can be unreliable on some platforms, so we're using Coroutine for this instead of an Animator
	private Vector3 rot = new Vector3( 0f, 0f, 0.5f );
	private bool wheelSpinning = false;
	public IEnumerator SpinWheel()
	{
		while ( wheelSpinning )
		{
			winWheel.Rotate( rot );
			yield return null;
		}
	}

	//Restart the game - triggered by "Play Again?" button
	public void OnPlayAgainClicked()
	{
		CancelInvoke( "ShowHint" );
		numMatches = 0;

		winAnimator.SetTrigger( "Hide" );

		foreach ( Tile tile in currentTiles )
		{
			tile.animator.SetBool( "Visible", false );
			tileGOPool.Add( tile.gameObject );
		}
		currentTiles.Clear();

		foreach ( TileSlot slot in currentSlots )
		{
			slot.animator.SetBool( "Visible", false );
			slotGOPool.Add( slot.gameObject );
		}
		currentSlots.Clear();

		//Give the various animations time to hide before starting a new game
		Invoke( "TriggerInit", 1f );
    }

	private void TriggerInit()
	{
		wheelSpinning = false;
		Init();
	}

	private void ShowHint()
	{
		foreach ( TileSlot slot in currentSlots )
		{
			if ( !slot.claimed )
			{
				slot.ShowHint();
				break;
			}
		}

		Invoke( "ShowHint", 25f );
	}
}
