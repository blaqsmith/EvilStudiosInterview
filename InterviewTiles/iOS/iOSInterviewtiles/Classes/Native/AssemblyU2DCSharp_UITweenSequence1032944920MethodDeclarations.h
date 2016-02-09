#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// UITweenSequence
struct UITweenSequence_t1032944920;
// UnityEngine.GameObject
struct GameObject_t4012695102;
// System.Action
struct Action_t437523947;
// System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>
struct Func_4_t178615958;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_GameObject4012695102.h"
#include "System_Core_System_Action437523947.h"
#include "UnityEngine_UnityEngine_Vector33525329789.h"

// System.Void UITweenSequence::.ctor(UnityEngine.GameObject)
extern "C"  void UITweenSequence__ctor_m2244928651 (UITweenSequence_t1032944920 * __this, GameObject_t4012695102 * ___gameObject, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UITweenSequence::Update()
extern "C"  bool UITweenSequence_Update_m1548565478 (UITweenSequence_t1032944920 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UITweenSequence UITweenSequence::Wait(System.Single)
extern "C"  UITweenSequence_t1032944920 * UITweenSequence_Wait_m1694512160 (UITweenSequence_t1032944920 * __this, float ___waitTimeInSecs, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UITweenSequence UITweenSequence::Call(System.Action)
extern "C"  UITweenSequence_t1032944920 * UITweenSequence_Call_m1996980201 (UITweenSequence_t1032944920 * __this, Action_t437523947 * ___action, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UITweenSequence UITweenSequence::MoveToPoint(UnityEngine.Vector3,System.Single,System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>)
extern "C"  UITweenSequence_t1032944920 * UITweenSequence_MoveToPoint_m1392318403 (UITweenSequence_t1032944920 * __this, Vector3_t3525329789  ___targetPos, float ___duration, Func_4_t178615958 * ___easingFunction, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UITweenSequence UITweenSequence::Move(UnityEngine.Vector3,System.Single,System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>)
extern "C"  UITweenSequence_t1032944920 * UITweenSequence_Move_m3126245594 (UITweenSequence_t1032944920 * __this, Vector3_t3525329789  ___deltaVector, float ___duration, Func_4_t178615958 * ___easingFunction, const MethodInfo* method) IL2CPP_METHOD_ATTR;
