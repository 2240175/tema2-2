//******************************************************************************
//
//
//      scene_result
//
//
//******************************************************************************

//----< インクルード >-----------------------------------------------------------
#include "all.h"
#include "common.h"

extern int score;


Sprite* sprCar = nullptr;


int result_state;
int result_timer;


void result_init()
{
    result_state = 0;
    result_timer = 0;
}

void result_deinit()
{
    safe_delete(sprCar);
}

void result_update()
{
    switch (result_state) // ここを修正しました
    {
    case 0:
        //////// 初期設定 ////////

        sprCar = sprite_load(L"./Data/Images/result.png");
        result_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::stop(1);
        music::play(2);
        music::setVolume(0, 0.1f);

        result_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            music::stop(1);
            music::stop(2);

            score = 0;

            sound::play(XWB_SYSTEM, 2);


            nextScene = SCENE_TITLE;
            break;
        }
        result_timer++;
        if (result_timer / 32 % 2)
        {
            sound::play(XWB_SYSTEM, 3);
        }

        break;

    }

}