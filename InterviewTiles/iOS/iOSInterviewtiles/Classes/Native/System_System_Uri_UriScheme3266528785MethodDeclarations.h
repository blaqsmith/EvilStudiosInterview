﻿#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "System_System_Uri_UriScheme3266528785.h"
#include "mscorlib_System_String968488902.h"

// System.Void System.Uri/UriScheme::.ctor(System.String,System.String,System.Int32)
extern "C"  void UriScheme__ctor_m535258662 (UriScheme_t3266528785 * __this, String_t* ___s, String_t* ___d, int32_t ___p, const MethodInfo* method) IL2CPP_METHOD_ATTR;

// Methods for marshaling
struct UriScheme_t3266528785;
struct UriScheme_t3266528785_marshaled;

extern "C" void UriScheme_t3266528785_marshal(const UriScheme_t3266528785& unmarshaled, UriScheme_t3266528785_marshaled& marshaled);
extern "C" void UriScheme_t3266528785_marshal_back(const UriScheme_t3266528785_marshaled& marshaled, UriScheme_t3266528785& unmarshaled);
extern "C" void UriScheme_t3266528785_marshal_cleanup(UriScheme_t3266528785_marshaled& marshaled);
