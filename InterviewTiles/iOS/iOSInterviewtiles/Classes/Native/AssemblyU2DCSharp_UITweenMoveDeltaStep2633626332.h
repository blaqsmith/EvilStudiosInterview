#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>
struct Func_4_t178615958;

#include "AssemblyU2DCSharp_UITweenStep2590330787.h"
#include "UnityEngine_UnityEngine_Vector33525329789.h"

// UITweenMoveDeltaStep
struct  UITweenMoveDeltaStep_t2633626332  : public UITweenStep_t2590330787
{
	// UnityEngine.Vector3 UITweenMoveDeltaStep::startPosition
	Vector3_t3525329789  ___startPosition_3;
	// UnityEngine.Vector3 UITweenMoveDeltaStep::deltaPosition
	Vector3_t3525329789  ___deltaPosition_4;
	// System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3> UITweenMoveDeltaStep::easingFunction
	Func_4_t178615958 * ___easingFunction_5;
};
