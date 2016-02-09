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

// UITween
struct UITween_t299550775;
// UnityEngine.GameObject
struct GameObject_t4012695102;
// UITweenSequence
struct UITweenSequence_t1032944920;
// System.Collections.IEnumerator
struct IEnumerator_t287207039;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_GameObject4012695102.h"

// System.Void UITween::.ctor()
extern "C"  void UITween__ctor_m4055282964 (UITween_t299550775 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UITween::.cctor()
extern "C"  void UITween__cctor_m677624089 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject UITween::get_instance()
extern "C"  GameObject_t4012695102 * UITween_get_instance_m3334798361 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UITweenSequence UITween::On(UnityEngine.GameObject)
extern "C"  UITweenSequence_t1032944920 * UITween_On_m995175404 (Object_t * __this /* static, unused */, GameObject_t4012695102 * ___targetGO, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UITween::StartTweening()
extern "C"  void UITween_StartTweening_m586519307 (UITween_t299550775 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator UITween::UpdateTweens()
extern "C"  Object_t * UITween_UpdateTweens_m1337714873 (UITween_t299550775 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
