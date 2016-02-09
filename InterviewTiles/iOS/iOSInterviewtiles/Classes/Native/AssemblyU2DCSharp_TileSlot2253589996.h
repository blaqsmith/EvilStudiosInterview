#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.UI.Text
struct Text_t3286458198;
// UnityEngine.Animator
struct Animator_t792326996;

#include "UnityEngine_UnityEngine_MonoBehaviour3012272455.h"

// TileSlot
struct  TileSlot_t2253589996  : public MonoBehaviour_t3012272455
{
	// UnityEngine.UI.Text TileSlot::textLetter
	Text_t3286458198 * ___textLetter_2;
	// System.Char TileSlot::letter
	uint16_t ___letter_3;
	// System.Boolean TileSlot::claimed
	bool ___claimed_4;
	// UnityEngine.Animator TileSlot::animator
	Animator_t792326996 * ___animator_5;
};
