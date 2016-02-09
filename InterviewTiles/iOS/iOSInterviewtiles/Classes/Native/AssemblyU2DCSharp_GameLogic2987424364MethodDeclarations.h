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

// GameLogic
struct GameLogic_t2987424364;
// UnityEngine.GameObject
struct GameObject_t4012695102;
// Tile
struct Tile_t2606798;
// System.Collections.IEnumerator
struct IEnumerator_t287207039;

#include "codegen/il2cpp-codegen.h"
#include "AssemblyU2DCSharp_Tile2606798.h"

// System.Void GameLogic::.ctor()
extern "C"  void GameLogic__ctor_m737121407 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::Start()
extern "C"  void GameLogic_Start_m3979226495 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::Init()
extern "C"  void GameLogic_Init_m2330619381 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject GameLogic::GetSlot(System.Char)
extern "C"  GameObject_t4012695102 * GameLogic_GetSlot_m2254700759 (GameLogic_t2987424364 * __this, uint16_t ___letter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.GameObject GameLogic::GetTile(System.Char)
extern "C"  GameObject_t4012695102 * GameLogic_GetTile_m3905369639 (GameLogic_t2987424364 * __this, uint16_t ___letter, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::CheckMatch(Tile)
extern "C"  void GameLogic_CheckMatch_m802678452 (GameLogic_t2987424364 * __this, Tile_t2606798 * ___tile, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator GameLogic::SpinWheel()
extern "C"  Object_t * GameLogic_SpinWheel_m265414110 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::OnPlayAgainClicked()
extern "C"  void GameLogic_OnPlayAgainClicked_m3740902751 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::TriggerInit()
extern "C"  void GameLogic_TriggerInit_m1645448581 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GameLogic::ShowHint()
extern "C"  void GameLogic_ShowHint_m1828366601 (GameLogic_t2987424364 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
