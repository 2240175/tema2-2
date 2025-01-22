#ifndef ALL_H
#define ALL_H

//******************************************************************************
//
//
//      all.h
//
//
//******************************************************************************

// システムやライブラリのヘッダーファイルは上の方へ
#include "../GameLib/game_lib.h"

// 共通で使われるようなヘッダー
#include "common.h"

// 個々のヘッダーファイルは下の方へ
#include "audio.h"


#include "obj2d.h"

#include "info.h"
#include "scene_game.h"
#include "scene_game2.h"
#include "scene_title.h"
#include "game_tutorial.h"
#include "game_result.h"
#include"judge.h"

#include "Mato.h"
#include "Kunai.h"



// namespace
using namespace GameLib;
using namespace input;

#endif//ALL_H
