#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.List`1<UITweenStep>
struct List_1_t3387289756;
// UnityEngine.RectTransform
struct RectTransform_t3317474837;
// UITweenStep
struct UITweenStep_t2590330787;

#include "mscorlib_System_Object837106420.h"

// UITweenSequence
struct  UITweenSequence_t1032944920  : public Object_t
{
	// System.Collections.Generic.List`1<UITweenStep> UITweenSequence::steps
	List_1_t3387289756 * ___steps_0;
	// UnityEngine.RectTransform UITweenSequence::targetTransform
	RectTransform_t3317474837 * ___targetTransform_1;
	// UITweenStep UITweenSequence::currentStep
	UITweenStep_t2590330787 * ___currentStep_2;
};
