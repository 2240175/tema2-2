#ifndef AUDIO_H
#define AUDIO_H



// XWBの種類
#define XWB_SYSTEM          0
#define XWB_STAGE1          1

// SYSTEMの効果音
#define XWB_SYSTEM_KATI     0
#define XWB_SYSTEM_START    1

// STAGE1の効果音
#define XWB_STAGE1_COIN     0
#define XWB_STAGE1_JUMP     1
#define XWB_STAGE1_SHOT     2
#define XWB_STAGE1_MISSILE  3
#define XWB_STAGE1_LASER    4
#define XWB_STAGE1_BOMB     5


void audio_init();
void audio_deinit();

#endif
