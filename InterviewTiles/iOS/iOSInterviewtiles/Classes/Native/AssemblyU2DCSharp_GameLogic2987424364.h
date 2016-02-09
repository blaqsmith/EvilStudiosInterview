#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// GameLogic
struct GameLogic_t2987424364;
// System.String
struct String_t;
// UnityEngine.GameObject
struct GameObject_t4012695102;
// UnityEngine.Transform
struct Transform_t284553113;
// System.Collections.Generic.List`1<Tile>
struct List_1_t799565767;
// System.Collections.Generic.List`1<TileSlot>
struct List_1_t3050548965;
// UnityEngine.Animator
struct Animator_t792326996;
// UnityEngine.AudioSource
struct AudioSource_t3628549054;
// UnityEngine.AudioClip
struct AudioClip_t3714538611;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t514686775;

#include "UnityEngine_UnityEngine_MonoBehaviour3012272455.h"
#include "UnityEngine_UnityEngine_Vector33525329789.h"

// GameLogic
struct  GameLogic_t2987424364  : public MonoBehaviour_t3012272455
{
	// System.String GameLogic::validChars
	String_t* ___validChars_3;
	// System.String GameLogic::secretPhrase
	String_t* ___secretPhrase_4;
	// UnityEngine.GameObject GameLogic::slotPrefab
	GameObject_t4012695102 * ___slotPrefab_5;
	// UnityEngine.GameObject GameLogic::tilePrefab
	GameObject_t4012695102 * ___tilePrefab_6;
	// UnityEngine.Transform GameLogic::slotsContainter
	Transform_t284553113 * ___slotsContainter_7;
	// UnityEngine.Transform GameLogic::tilesContainer
	Transform_t284553113 * ___tilesContainer_8;
	// System.Collections.Generic.List`1<Tile> GameLogic::currentTiles
	List_1_t799565767 * ___currentTiles_9;
	// System.Collections.Generic.List`1<TileSlot> GameLogic::currentSlots
	List_1_t3050548965 * ___currentSlots_10;
	// UnityEngine.Animator GameLogic::winAnimator
	Animator_t792326996 * ___winAnimator_11;
	// UnityEngine.Transform GameLogic::winWheel
	Transform_t284553113 * ___winWheel_12;
	// UnityEngine.AudioSource GameLogic::audioSource
	AudioSource_t3628549054 * ___audioSource_13;
	// UnityEngine.AudioClip GameLogic::tileTouched
	AudioClip_t3714538611 * ___tileTouched_14;
	// UnityEngine.AudioClip GameLogic::goodMatch
	AudioClip_t3714538611 * ___goodMatch_15;
	// UnityEngine.AudioClip GameLogic::badMatch
	AudioClip_t3714538611 * ___badMatch_16;
	// System.Int32 GameLogic::numMatches
	int32_t ___numMatches_17;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> GameLogic::tileGOPool
	List_1_t514686775 * ___tileGOPool_18;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> GameLogic::slotGOPool
	List_1_t514686775 * ___slotGOPool_19;
	// UnityEngine.Vector3 GameLogic::rot
	Vector3_t3525329789  ___rot_20;
	// System.Boolean GameLogic::wheelSpinning
	bool ___wheelSpinning_21;
};
struct GameLogic_t2987424364_StaticFields{
	// GameLogic GameLogic::Instance
	GameLogic_t2987424364 * ___Instance_2;
};
