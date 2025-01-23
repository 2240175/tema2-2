
#include "all.h"

#include<sstream>

/*extern*/ int kunai_state2;
extern int score2 = 0;

int game_state2;
int game_timer2;
int gmato_state ;
int counter2;

//的１
float gposx1;//的1のposx
float gposy1;//的1のposy
float gvelocity1;//初期速度
float gaccelerator1;//初期加速度
int gmato_state1;//状態を管理

//的２
float gposx2;//的1のposx
float gposy2;//的1のposy
float gvelocity2;//初期速度
float gaccelerator2;//初期加速度
int gmato_state2;//状態を管理

//的３
float gposx3;//的3のposx
float gposy3;//的3のposy
float gvelocityX3;//初期速度
float gacceleratorX3;//初期加速度
int gmato_state3;//状態を管理

//的4
float gposx4;//的3のposx
float gposy4;//的3のposy
float gvelocity4;//初期速度
float gaccelerator4;//初期加速度
int gmato_state4;//状態を管理

float w = 0;
float s = 0;
float a = 0;
static float angle = 0;

bool isHit2;//的があった時の判定

bool mato_active21 = false;//的の動き
bool mato_active22 = false;//的2
bool mato_active23 = false;//  3
bool mato_active24 = false;//  4


Sprite* sprCenter2;
Sprite* sprK2;
Sprite* sprMato21;
Sprite* sprMato22;
Sprite* sprMato23;
Sprite* sprMato24;
Sprite* sprMato25;


Sprite* sprBack2;

void game2_init()
{
	game_state2 = 0;
	game_timer2 = 0;
	gmato_state = 0;

	//的１
	gposx1 = 1280 / 2;//的1のposx
	gposy1 = 850;//的1のposy
	gvelocity1 = 0.0f;//初期速度
	gaccelerator1 = -0.3f;//初期加速度
	gmato_state1 = 0;//状態を管理

	//的２
	gposx2 = -100.0f;
	gposy2 = 720.0f / 2.0f;
	gvelocity2 = 1.0f;
	gaccelerator2 = 0.5f;
	gmato_state2 = 0;


	//的３
	gposx3 = 1400;//的3のposx
	gposy3 = 720 / 2;//的3のposy
	gvelocityX3 = -2.0f;//初期速度
	gacceleratorX3 = -1.0f;//初期加速度
	gmato_state3 = 0;//状態を管理

	//的4
	gposx4 = 1280 / 2;//的3のposx
	gposy4 = -200;//的3のposy
	gvelocity4 = 2.5f;//初期速度
	gaccelerator4 = 1.0f;//初期加速度
	gmato_state4 = 0;//状態を管理


};

void game2_deinit()
{

	kunai_deinit();
	safe_delete(sprBack2);


}

void game2_update()
{
	switch (game_state2)
	{
	case 0:

		music::play(3);
		game_timer2++;
		sprBack2 = sprite_load(L"./Data/Images/back.png");
		sprCenter2 = sprite_load(L"./Data/Images/senter.png");
		sprK2 = sprite_load(L"./Data/Images/Okunai.png");

		sprMato21 = sprite_load(L"./Data/Images/mato.png");
		sprMato22 = sprite_load(L"./Data/Images/mato.png");
		sprMato23 = sprite_load(L"./Data/Images/mato.png");
		sprMato24 = sprite_load(L"./Data/Images/mato.png");

		//くないの初期設定
		kunai_init();

		game_state2++;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);



		game_state2++;


	case 2:

			angle = 0;

			w = 0.2; // 角速度
			a = 200; // 振幅
			s = 8; // 横向きの速さ

			angle += w;

			gposx3 += s; // 目標地点に固定
			gposy3 = 325 + a * sinf(angle);
			

		//くないの更新
		kunai_update(); {

			if (counter2 == 0) {
				if (game_timer2 > 120)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//くないの動き
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit1();
			gmato_state++;

		}


		//１の的がヒットしたら次の的へ
		if (isHit2 == true)
		{
			mato_active21 = false;

			safe_delete(sprMato21);

			Kunai.pos.y = 760;//くない初期化

			isHit2 = false;
			game_state2++;
		}

		break;

	case 3:
		
		angle = 0;

		w = 0.5; // 角速度
		a = 300; // 振幅
		s = -8; // 横向きの速さ

		angle += w;

		gposx3 += s; // 目標地点に固定
		gposy3 = 325 + a * sinf(angle);
		



		//くないの更新
		kunai_update(); {

			if (counter2 == 0) {
				if (game_timer2 > 120)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}


		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit2();
			gmato_state++;

		}

		//2の的がヒットしたら次の的へ
		if (isHit2 == true)
		{
			mato_active22 = false;

			Kunai.pos.y = 760;//くない初期化

			safe_delete(sprMato22);
			isHit2 = false;
			game_state2++;
		}
		break;


	case 4:
		mato_active23 = true;


		w = 0;
		a = 0;
		s = 0;
		
				angle = 0;

				w = 0.2; // 角速度
				a = 200; // 振幅
				s = 8; // 横向きの速さ

				angle += w;

				gposx3 += s; // 目標地点に固定
				gposy3 = 325 + a * sinf(angle);


		//くないの更新
		kunai_update(); {
			if (counter2 == 0) {
				if (game_timer2 > 280)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//くないの動き
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit3();
			gmato_state++;

		}

		//2の的がヒットしたら次の的へ
		if (isHit2 == true)
		{
			mato_active23 = false;

			safe_delete(sprMato23);
			isHit2 = false;
			game_state2++;
		}
		break;





	case 5:

		w = 0;
		a = 0;
		s = 0;

		angle = 0;

		w = 0.2; // 角速度
		a = 200; // 振幅
		s = 8; // 横向きの速さ

		angle += w;

		gposx3 += s; // 目標地点に固定
		gposy3 = 325 + a * sinf(angle);



		//くないの更新
		kunai_update(); {
			if (counter2 == 0) {
				if (game_timer2 > 120)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//くないの動き
		kunai_move();


		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit4();
			gmato_state++;

		}


		//４の的がヒットしたら次の的へ
		if (isHit2 == true)
		{
			mato_active24 = false;

			safe_delete(sprMato24);

			isHit2 = false;
			game_state2++;
		}
		break;
	case 6:
		nextScene = SCENE_RESULT;

		break;
	}
	game_timer2++;
}

//static float angle = 0;
//
//float w = 0.2; // 角速度
//float a = 200; // 振幅
//float s = 8; // 横向きの速さ
//
//angle += w;
//
//posx3 += s; // 目標地点に固定
//posy3 = 325 + a * sinf(angle);
//velocityX3 = 0.0f; // 停止
//velocityY3 = 0.0f; // 停止

void game2_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	sprite_render(sprBack2, 0, 0);
	sprite_render(sprCenter2, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato21, gposx1, gposy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato22, gposx2, gposy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato23, gposx3, gposy3, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato24, gposx4, gposy4, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的


	//くない描画
	kunai_render();


	debug::setString("game_state:%d", game_state2);
	debug::setString("game_timer:%d", game_timer2);
	debug::setString("score: % d", score2);
	POINT point;                                            // 位置用の変数を宣言する
	GetCursorPos(&point);                                   // スクリーン座標を取得する
	ScreenToClient(window::getHwnd(), &point);              // クライアント座標に変換する
	debug::setString("x = %d, y = %d", point.x, point.y);

}


void game2_reset()//ゲームのリセット
{
	game_state2 = 0;
	kunai_state2 = 1;
	gmato_state = 1;
}

void game2_result() {
	music::stop(3);
	nextScene = SCENE_TITLE;
}
