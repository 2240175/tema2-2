#include "all.h"


int title_state;
int title_timer;

Sprite* sprtitle;
Sprite* sprKi;


//--------------------------------------
//  初期設定
//--------------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;
}

//--------------------------------------
//  終了処理
//--------------------------------------
void title_deinit()
{
    music::stop(0);

    safe_delete(sprtitle);
}

//--------------------------------------
//  タイトルの更新処理
//--------------------------------------    
void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////
        sprKi = sprite_load(L"./Data/Images/push.png");
        sprtitle = sprite_load(L"./Data/Images/title1.jpg");
        

        title_state++;
        /*fallthrough*/





    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::play(0);
        music::setVolume(0, 0.1f);

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            music::play(4);

            nextScene = SCENE_GAME;
            break;
        }
        if (TRG(0) & PAD_TRG1)
        {
            nextScene = SCENE_TUTORIAL1;
            break;
        }
        break;
    }

    debug::setString("");
    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

    title_timer++;
}

//--------------------------------------
//  タイトルの描画処理6
//--------------------------------------
void title_render()
{  
    sprite_render(sprtitle, 0, 0);
    sprite_render(sprKi, 0, 0);

  

    //// タイトルの文字
    //font::textOut(4, "ECC COMP", VECTOR2(100, 80), VECTOR2(2.4f, 2.4f), VECTOR4(1, 0.8f, 0, 1));
    //font::textOut(4, "Game Programming I", VECTOR2(80, 180), VECTOR2(2.0f, 2.0f), VECTOR4(0, 1, 0.6f, 1));

  


}
