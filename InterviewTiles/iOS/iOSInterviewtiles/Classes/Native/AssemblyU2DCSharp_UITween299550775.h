#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.Dictionary`2<UnityEngine.GameObject,UITweenSequence>
struct Dictionary_2_t3212959536;
// UITween
struct UITween_t299550775;
// UnityEngine.GameObject
struct GameObject_t4012695102;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t514686775;

#include "UnityEngine_UnityEngine_MonoBehaviour3012272455.h"

// UITween
struct  UITween_t299550775  : public MonoBehaviour_t3012272455
{
	// System.Boolean UITween::isRunning
	bool ___isRunning_5;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> UITween::deletedKeys
	List_1_t514686775 * ___deletedKeys_6;
};
struct UITween_t299550775_StaticFields{
	// System.Collections.Generic.Dictionary`2<UnityEngine.GameObject,UITweenSequence> UITween::tweens
	Dictionary_2_t3212959536 * ___tweens_2;
	// UITween UITween::script
	UITween_t299550775 * ___script_3;
	// UnityEngine.GameObject UITween::go
	GameObject_t4012695102 * ___go_4;
};
