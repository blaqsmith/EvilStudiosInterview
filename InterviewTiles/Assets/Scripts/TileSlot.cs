using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class TileSlot : MonoBehaviour
{
	public Text textLetter;

	[HideInInspector]
	public char letter = ' ';
	[HideInInspector]
	public bool claimed = false;
	[HideInInspector]
	public Animator animator;

	void Start()
	{
		animator = gameObject.GetComponent<Animator>();
	}

	public void Init()
	{
		claimed = false;
		if ( animator != null )
			animator.SetBool( "Visible", true );
	}

	public bool IsTileOver( Tile tile )
	{
		return ( Vector3.Distance( tile.transform.position, transform.position ) < 64f );
	}

	public bool Matches( Tile tile )
	{
		return ( !claimed && tile.letter == letter );
	}

	public void ShowHint()
	{
		textLetter.text = letter.ToString();
		if ( animator != null )
			animator.SetTrigger( "ShowHint" );
	}
}