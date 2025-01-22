//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< インクルード >-----------------------------------------------------------
#include "all.h"
#include"Mato.h"

#include<sstream>

extern int kunai_state;
extern int mato_state;


//------< 変数 >----------------------------------------------------------------
int game_state;
int game_timer;



float posx1 =1280/2;//的1のposx
float posy1 = 850;//的1のposy
float poskx1 = 1280/2;
float posky1 = 800;
float Kspeed1 = 0.0f;
int Kstay_timer ;


float velocity1 = 0.0f;//初期速度
float accelerator1 = -0.3f;//初期加速度
int mato_state1 = 0;//状態を管理




//------フラグ------
bool isHit;//的があった時の判定
bool mato_active1=false;//的の動き

//-----画像-------
Sprite* sprBack;
Sprite* sprPush;
Sprite* sprCenter;
Sprite* sprK;
Sprite* sprMato1;

//--------------------------------------
//  ゲームの初期設定
//--------------------------------------
void game_init()
{
    game_state      = 0;
    game_timer      = 0;
    Kstay_timer = 0;
}


void game_deinit()
{

    //TODO_11

    kunai_deinit();

    safe_delete(sprBack);
}


void game_update()            
{
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        sprBack = sprite_load(L"./Data/Images/back.png");
        sprCenter = sprite_load(L"./Data/Images/senter.png");
        sprK = sprite_load(L"./Data/Images/Okunai.png");
        sprMato1 = sprite_load(L"./Data/Images/mato.png");

     
        //くないの初期設定
        kunai_init();
        
        //的の初期設定
        mato_init();

        game_state++;
       

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        debug::setString("");
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("Kstay_timer:%d", Kstay_timer);
        debug::setString("hantei: % d", isHit);
                         
        POINT point;                                            // 位置用の変数を宣言する
        GetCursorPos(&point);                                   // スクリーン座標を取得する
        ScreenToClient(window::getHwnd(), &point);              // クライアント座標に変換する

        debug::setString("x = %d, y = %d", point.x, point.y);

        game_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        mato_active1 = true;

        if (mato_active1)
        {
            if (mato_state1 == 0) {  // 1000 から 360 に移動

                velocity1 += accelerator1;
                posy1 += velocity1;

                if (posy1 <= 0.0f) {  // 到達 

                    posy1 = 0.0f;
                    velocity1 = 2.0f;    // リセット
                    accelerator1 = 2.0f; // 次の移動用加速度



                }
            }
        
        }
  

        //くないの更新
        kunai_update();

        //区内の動き
        kunai_move();




        //１の的がヒットしたら次の的へ
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;
   

    case 3:

        //２の的がヒットしたら次の的へ
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;
    case 4:

        //３の的がヒットしたら次の的へ
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;
    case 5:

        //４の的がヒットしたら次の的へ
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }
        break;

    case 6:

        //５の的がヒットしたら次の的へ
        if (isHit == true)
        {
            isHit = false;
            nextScene = SCENE_TITLE;
            break;
        }





        break;
    }

    game_timer++;
}

//--------------------------------------
//  ゲームの描画処理
//--------------------------------------
void game_render()
{
    GameLib::clear(0.2f, 0.2f, 0.4f);
sprite_render(sprBack, 0, 0);
    
    sprite_render(sprCenter,1280/2, 720/2,1.5f,1.5f,0,0,128,128,128/2,128/2,0.0f,0.8f,0.8f,0.8f,0.8f,true);
    sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的

    
   
    //くない描画
    kunai_render();

}

void game_reset()
{

    game_state = 1;
    kunai_state = 1;
    mato_state = 1;
}
void game_result() {
    nextScene = SCENE_TITLE;
}
