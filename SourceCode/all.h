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

#if 1
//******************************************************************************
// TODO:01 obj2d.hとplayer.hをインクルード
//------------------------------------------------------------------------------
/*
課題）
    下記でobj2d.hとplayer.hをインクルードしましょう。

解説）
    ヘッダーファイルをインクルードする順番は大切です。例えば、obj2d.hでOBJ2Dと
    いう構造体を定義しており、player.cppでOBJ2D型の変数を宣言するため、obj2d.hの
    方が上に来る事になります。

    ※そうしておけば、例えばplayer.h内で extern OBJ2D player; などと書けるように
    　なるのです。
*/
//******************************************************************************
#endif
//TODO_01
#include "obj2d.h"

#include "info.h"
#include "scene_game.h"
#include "scene_title.h"

#include"judge.h"

#include "Mato.h"
#include "Kunai.h"



// namespace
using namespace GameLib;
using namespace input;

#endif//ALL_H
