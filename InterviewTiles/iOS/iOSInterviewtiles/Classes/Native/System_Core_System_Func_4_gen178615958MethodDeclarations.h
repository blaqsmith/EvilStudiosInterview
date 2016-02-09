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

// System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>
struct Func_4_t178615958;
// System.Object
struct Object_t;
// System.IAsyncResult
struct IAsyncResult_t537683269;
// System.AsyncCallback
struct AsyncCallback_t1363551830;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Object837106420.h"
#include "mscorlib_System_IntPtr676692020.h"
#include "UnityEngine_UnityEngine_Vector33525329789.h"
#include "mscorlib_System_AsyncCallback1363551830.h"

// System.Void System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>::.ctor(System.Object,System.IntPtr)
extern "C"  void Func_4__ctor_m2284912700_gshared (Func_4_t178615958 * __this, Object_t * ___object, IntPtr_t ___method, const MethodInfo* method);
#define Func_4__ctor_m2284912700(__this, ___object, ___method, method) ((  void (*) (Func_4_t178615958 *, Object_t *, IntPtr_t, const MethodInfo*))Func_4__ctor_m2284912700_gshared)(__this, ___object, ___method, method)
// TResult System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>::Invoke(T1,T2,T3)
extern "C"  Vector3_t3525329789  Func_4_Invoke_m2922043889_gshared (Func_4_t178615958 * __this, float ___arg1, Vector3_t3525329789  ___arg2, Vector3_t3525329789  ___arg3, const MethodInfo* method);
#define Func_4_Invoke_m2922043889(__this, ___arg1, ___arg2, ___arg3, method) ((  Vector3_t3525329789  (*) (Func_4_t178615958 *, float, Vector3_t3525329789 , Vector3_t3525329789 , const MethodInfo*))Func_4_Invoke_m2922043889_gshared)(__this, ___arg1, ___arg2, ___arg3, method)
// System.IAsyncResult System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>::BeginInvoke(T1,T2,T3,System.AsyncCallback,System.Object)
extern "C"  Object_t * Func_4_BeginInvoke_m2731587647_gshared (Func_4_t178615958 * __this, float ___arg1, Vector3_t3525329789  ___arg2, Vector3_t3525329789  ___arg3, AsyncCallback_t1363551830 * ___callback, Object_t * ___object, const MethodInfo* method);
#define Func_4_BeginInvoke_m2731587647(__this, ___arg1, ___arg2, ___arg3, ___callback, ___object, method) ((  Object_t * (*) (Func_4_t178615958 *, float, Vector3_t3525329789 , Vector3_t3525329789 , AsyncCallback_t1363551830 *, Object_t *, const MethodInfo*))Func_4_BeginInvoke_m2731587647_gshared)(__this, ___arg1, ___arg2, ___arg3, ___callback, ___object, method)
// TResult System.Func`4<System.Single,UnityEngine.Vector3,UnityEngine.Vector3,UnityEngine.Vector3>::EndInvoke(System.IAsyncResult)
extern "C"  Vector3_t3525329789  Func_4_EndInvoke_m2304484606_gshared (Func_4_t178615958 * __this, Object_t * ___result, const MethodInfo* method);
#define Func_4_EndInvoke_m2304484606(__this, ___result, method) ((  Vector3_t3525329789  (*) (Func_4_t178615958 *, Object_t *, const MethodInfo*))Func_4_EndInvoke_m2304484606_gshared)(__this, ___result, method)
