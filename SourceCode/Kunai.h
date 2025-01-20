#pragma once

// プレイヤーの画像の定数
#define PLAYER_TEX_W            (128.0f)    // プレイヤーの画像1つの幅
#define PLAYER_TEX_H            (128.0f)    // プレイヤーの画像1つの高さ
#define PLAYER_PIVOT_X          (64.0f)     // プレイヤーの横方向の中心
#define PLAYER_PIVOT_Y          (64.0f)    // プレイヤーの縦方向の下端


extern OBJ2D Kunai;

void kunai_init();
void kunai_deinit();
void kunai_update();
void kunai_render();

bool kunai_hit();

