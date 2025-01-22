
//----< インクルード >-----------------------------------------------------------
#include "all.h"
//#include"Mato.h"
#include<sstream>
extern int kunai_state;
extern int mato_state;
extern int score =0;


//------< 変数 >----------------------------------------------------------------
int game_state;
int game_timer;
int counter;
float posx1 = 1280 / 2;//的1のposx
float posy1 = 850;//的1のposy
float velocity1 = 0.0f;//初期速度
float accelerator1 = -0.3f;//初期加速度
int mato_state1 = 0;//状態を管理

float posx2 = 1400;//的1のposx
float posy2 = 720/2;//的1のposy
float velocity2 = 0.0f;//初期速度
float accelerator2 = -0.3f;//初期加速度
int mato_state2 = 0;//状態を管理

//------フラグ------
bool isHit;//的があった時の判定

bool mato_active1 = false;//的の動き
bool mato_active2 = false;//的2
bool mato_active3 = false;//  3
bool mato_active4 = false;//  4
bool mato_active5 = false;//  5

//-----画像-------
Sprite* sprBack;
Sprite* sprPush;
Sprite* sprCenter;
Sprite* sprK;

Sprite* sprMato1;



Sprite* sprMato2;
Sprite* sprMato3;
Sprite* sprMato4;
Sprite* sprMato5;

//--------------------------------------
//  ゲームの初期設定
//--------------------------------------

void game_init()
{
	game_state = 0;
	game_timer = 0;

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
		music::play(3);
		sprBack = sprite_load(L"./Data/Images/back.png");
		sprCenter = sprite_load(L"./Data/Images/senter.png");
		sprK = sprite_load(L"./Data/Images/Okunai.png");

		sprMato1 = sprite_load(L"./Data/Images/mato.png");
		sprMato2 = sprite_load(L"./Data/Images/mato.png");
		sprMato3 = sprite_load(L"./Data/Images/mato.png");
		sprMato4 = sprite_load(L"./Data/Images/mato.png");
		sprMato5 = sprite_load(L"./Data/Images/mato.png");

		//くないの初期設定
		kunai_init();
	
		//的の初期設定
		mato_init();


		game_state++;
	case 1:
		//////// パラメータの設定 ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);

		

		game_state++;
		/*fallthrough*/
	
	case 2:

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
		if (TRG(0) & PAD_TRG1)
		{
			kunai_render();
			Kunai.pos.y = 390;
			counter++;
			if (counter == 1)
				music::play(1);
			music::play(2);
		}
		//くないの動き
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit1();
			mato_state++;
			
		}
		//１の的がヒットしたら次の的へ
		if (isHit == true)
		{
			mato_active1 = false;

			safe_delete(sprMato1);

			Kunai.pos.y = 760;

			isHit = false;
			game_state++;
		}
		break;

	case 3:
		mato_active2 = true;
	
		if (mato_active2)
		{
			if (mato_state2 == 0) {  // 1000 から 360 に移動
				velocity2 += accelerator2;
				posx2 += velocity2;
				if (posx2 <= 0.0f) {  // 到達
					posx2 = 0.0f;
					velocity2 = 2.0f;    // リセット
					accelerator2 = 2.0f; // 次の移動用加速度
				}
			}
		}


		//くないの更新
		kunai_update();
		if (TRG(0) & PAD_TRG1)
		{
			kunai_render();
			Kunai.pos.y = 390;
			counter = 0;
			counter++;
			if (counter == 1)
			music::play(1);
			music::play(2);
		}
		//くないの動き
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit2();
			mato_state++;

		}

		//2の的がヒットしたら次の的へ
		if (isHit == true)
		{
			mato_active2 = false;

			safe_delete(sprMato2);
			isHit = false;
			game_state++;
		}
		break;
	


	
		
	//case 4:
	//	//３の的がヒットしたら次の的へ
	//	if (isHit == true)
	//	{
	//		isHit = false;
	//		game_state++;
	//	}
	//	break;
	//case 5:
	//	//４の的がヒットしたら次の的へ
	//	if (isHit == true)
	//	{
	//		isHit = false;
	//		game_state++;
	//	}
	//	break;
	//case 6:
	//	//５の的がヒットしたら次の的へ
	//	if (isHit == true)
	//	{
	//		isHit = false;
	//		nextScene = SCENE_TITLE;
	//		break;
	//	}
	//	break;
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
	sprite_render(sprCenter, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato2, posx2, posy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	//くない描画
	kunai_render();


	debug::setString("game_state:%d", game_state);
	debug::setString("game_timer:%d", game_timer);
	debug::setString("score: % d", score);
	POINT point;                                            // 位置用の変数を宣言する
	GetCursorPos(&point);                                   // スクリーン座標を取得する
	ScreenToClient(window::getHwnd(), &point);              // クライアント座標に変換する
	debug::setString("x = %d, y = %d", point.x, point.y);

}


void game_reset()//ゲームのリセット
{
	game_state = 0;
	kunai_state = 1;
	mato_state = 1;
}

void game_result() {
	music::stop(3);
	nextScene = SCENE_TITLE;
}



void game_hit1()//当たり判定
{
	//当たり判定//
	float dx1 = Kunai.pos.x - posx1;
	float dy1 = Kunai.pos.y - posy1;
	float distance1 = sqrtf(dx1 * dx1 + dy1 * dy1);

	if (distance1 < 120)
	{
		isHit = true;
		score = ((120.0f - distance1) / 120.0f); // 1.0 - 0.0
		score *= 100;

	}
	else
	{
		music::stop(3);
		nextScene = SCENE_RESULT;
	}

}

void game_hit2()//当たり判定
{
	//当たり判定
	float dx2 = Kunai.pos.x - posx2;
	float dy2 = Kunai.pos.y - posy2;
	float distance2 = sqrtf(dx2 * dx2 + dy2 * dy2);

	if (distance2 < 120)
	{
		isHit = true;
		score = ((120.0f - distance2) / 120.0f); // 1.0 - 0.0
		score *= 100;

	}
	else
	{
		music::stop(3);
		nextScene = SCENE_RESULT;
	}

}










