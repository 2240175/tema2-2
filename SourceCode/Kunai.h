#pragma once

// �v���C���[�̉摜�̒萔
#define PLAYER_TEX_W            (128.0f)    // �v���C���[�̉摜1�̕�
#define PLAYER_TEX_H            (128.0f)    // �v���C���[�̉摜1�̍���
#define PLAYER_PIVOT_X          (64.0f)     // �v���C���[�̉������̒��S
#define PLAYER_PIVOT_Y          (64.0f)    // �v���C���[�̏c�����̉��[


extern OBJ2D Kunai;

void kunai_init();
void kunai_deinit();
void kunai_update();
void kunai_render();

bool kunai_hit();

