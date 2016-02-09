#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Animator
struct Animator_t792326996;
// UnityEngine.UI.Text
struct Text_t3286458198;
// UnityEngine.UI.Image
struct Image_t3354615620;

#include "UnityEngine_UnityEngine_MonoBehaviour3012272455.h"
#include "UnityEngine_UnityEngine_Vector33525329789.h"

// Tile
struct  Tile_t2606798  : public MonoBehaviour_t3012272455
{
	// System.Boolean Tile::dragAllowed
	bool ___dragAllowed_2;
	// UnityEngine.Animator Tile::animator
	Animator_t792326996 * ___animator_3;
	// System.Boolean Tile::isDragging
	bool ___isDragging_4;
	// UnityEngine.Vector3 Tile::lastMousePos
	Vector3_t3525329789  ___lastMousePos_5;
	// UnityEngine.UI.Text Tile::textLetter
	Text_t3286458198 * ___textLetter_6;
	// UnityEngine.UI.Image Tile::imageBackground
	Image_t3354615620 * ___imageBackground_7;
	// System.Char Tile::_letter
	uint16_t ____letter_8;
};
