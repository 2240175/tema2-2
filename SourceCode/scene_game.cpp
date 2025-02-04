
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
int wait_timer;
int wait2_timer;
int wait3_timer;
int counter;

//的１
float posx1 ;//的1のposx
float posy1 ;//的1のposy
float velocity1 ;//初期速度
float accelerator1 ;//初期加速度
int mato_state1;//状態を管理

//的２
float posx2;//的1のposx
float posy2;//的1のposy
float velocity2;//初期速度
float accelerator2;//初期加速度
int mato_state2;//状態を管理

//的３
float posx3;//的3のposx
float posy3;//的3のposy
float velocityX3;//初期速度
float acceleratorX3;//初期加速度
int mato_state3;//状態を管理

//的4
float posx4;//的3のposx
float posy4;//的3のposy
float velocity4;//初期速度
float accelerator4;//初期加速度
int mato_state4;//状態を管理



//------フラグ------
bool isHit;//的があった時の判定

bool mato_active1 = false;//的の動き
bool mato_active2 = false;//的2
bool mato_active3 = false;//  3
bool mato_active4 = false;//  4


//-----画像-------
Sprite* sprBack;
Sprite* sprPush;
Sprite* sprCenter;
Sprite* sprK;
Sprite* sprmati;
Sprite* sprmati2;
Sprite* sprmati3;
Sprite* sprmati4;



Sprite* sprMato1;
Sprite* sprMato2;
Sprite* sprMato3;
Sprite* sprMato4;
Sprite* sprMato5;



void game_init()
{
	game_state = 0;
	game_timer = 0;
	wait_timer = 0;
	wait2_timer = 0;
	wait3_timer = 0;
	mato_state = 0;

	//的１
	posx1 = 1280 / 2;//的1のposx
	posy1 = 850;//的1のposy
	velocity1 = 0.0f;//初期速度
	accelerator1 = -0.3f;//初期加速度
	mato_state1 = 0;//状態を管理

	//的２
	posx2 = -100.0f;
	posy2 = 720.0f / 2.0f;
	velocity2 = 1.0f;
	accelerator2 = 0.5f;
	mato_state2 = 0;


	//的３
	posx3 = 1400;//的3のposx
	posy3 = 720 / 2;//的3のposy
	velocityX3 = -2.0f;//初期速度
	acceleratorX3 =-1.0f;//初期加速度
	mato_state3 = 0;//状態を管理

	//的4
	posx4 = 1280 / 2;//的3のposx
	posy4 = -200;//的3のposy
	velocity4 = 2.5f;//初期速度
	accelerator4 = 1.0f;//初期加速度
	mato_state4 = 0;//状態を管理


}



void game_deinit()
{
	
	kunai_deinit();
	safe_delete(sprBack);

	
}

void game_update()
{
	switch (game_state)
	{
	case 0:
	
		music::play(3);
		game_timer++;
	
		sprBack = sprite_load(L"./Data/Images/back.png");
		sprCenter = sprite_load(L"./Data/Images/senter.png");
		sprK = sprite_load(L"./Data/Images/Okunai.png");
		sprmati  = sprite_load(L"./Data/Images/的UI1.png");
		sprmati2 = sprite_load(L"./Data/Images/的UI2.png");
		sprmati3 = sprite_load(L"./Data/Images/的UI3.png");
		sprmati4 = sprite_load(L"./Data/Images/的UI4.png");

		sprMato1 = sprite_load(L"./Data/Images/mato.png");
		sprMato2 = sprite_load(L"./Data/Images/mato.png");
		sprMato3 = sprite_load(L"./Data/Images/mato.png");
		sprMato4 = sprite_load(L"./Data/Images/mato.png");
		sprMato5 = sprite_load(L"./Data/Images/mato.png");

		//くないの初期設定
		kunai_init();
	
		game_state++;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);

		

		game_state++;
		
	
	case 2:

		sprite_render(sprmati, 0, 0);

		if (game_timer > 110)
		{
			safe_delete(sprmati);
		}

		if (game_timer > 180)
		{
			
			mato_active1 = true;
			if (mato_active1)
			{
				if (mato_state1 == 0) {  // 1000 から 360 に移動
					velocity1 += accelerator1;
					posy1 += velocity1;
					if (posy1 <= 0.0f) {  // 到達
						posy1 = 0.0f;
						velocity1 = 0.0f;    // リセット
						accelerator1 = -0.3f; // 次の移動用加速度
					}
				}
			}
		}
		//くないの更新
		kunai_update(); {
			
			if (counter == 0) {
				if (game_timer > 300)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter++;
				if (counter == 1)
				music::play(1);
				music::play(2);
				game_timer = 0;
				counter = 0;
			}
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

			Kunai.pos.y = 760;//くない初期化

			isHit = false;
			game_state++;
		}

		break;

	case 3:
		wait_timer++;
		
		

		if (wait_timer > 110)
		{
			safe_delete(sprmati2);
		}
	
		if (wait_timer > 180)
		{
			mato_active2 = true;

			if (mato_active2)
			{
				if (mato_state2 == 0) {  // 1000 から 360 に移動
					velocity2 += accelerator2;
					posx2 += velocity2;
					if (posx2 >= 1280.0f) {  // 到達
						posx2 = 0.0f;
						velocity2 = 0.3f;    // リセット
						accelerator2 = 0.4f; // 次の移動用加速度

					}

				}
			}

		}

		//くないの更新
		kunai_update();{
			
			if (counter == 0) {
				if (game_timer > 300)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter++;
				if (counter == 1)
				music::play(1);
				music::play(2);
				game_timer = 0;
				counter = 0;
			}
		}
		

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

			Kunai.pos.y = 760;//くない初期化

			safe_delete(sprMato2);
			isHit = false;
			game_state++;
		}
		break;
	
		
	case 4:
		wait2_timer++;


		if (wait2_timer > 110)
		{
			safe_delete(sprmati3);
		}
		mato_active3 = true;

		

		if (wait2_timer > 180)
		{
			if (mato_active3)
			{
				if (mato_state3 == 0) {  // 1000 から 360 に移動

					velocityX3 += acceleratorX3;

					// 座標を更新
					posx3 += velocityX3;

					// 到達判定 (-100.0f まで)
					if (posx3 <= -100.0f) {
						posx3 = -100.0f;  // 到達時に固定
						velocityX3 = 0.0f; // 停止
						mato_state3++;    // 次の状態に進む
					}

					//
					//static float angle = 0;

					//float w = 0.2; // 角速度
					//float a = 200; // 振幅
					//float s = 8; // 横向きの速さ

					//angle += w;

					//posx3 += s; // 目標地点に固定
					//posy3 = 325 + a * sinf(angle);
					//velocityX3 = 0.0f; // 停止





				}
			}
		}
		

		//くないの更新
		kunai_update(); {
			if (counter == 0) {
				if (game_timer > 300)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter++;
				if (counter == 1)
					music::play(1);
				music::play(2);
				game_timer = 0;
				counter = 0;
			}
		}
		//くないの動き
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit3();
			mato_state++;

		}

		//2の的がヒットしたら次の的へ
		if (isHit == true)
		{
			mato_active3 = false;
			Kunai.pos.y = 760;
			safe_delete(sprMato3);
			isHit = false;
			game_state++;
		}
		break;



	

	case 5:

		wait3_timer++;

		if (wait3_timer > 110)
		{
			safe_delete(sprmati4);
		}

		if (wait3_timer > 180) {
			mato_active4 = true;

			if (mato_active4) {  // 的4がアクティブな場合
				if (mato_state4 == 0) {  // 初期状態: 上から下に移動
					// 加速度を適用して速度を更新
					velocity4 += accelerator4;

					// 座標を更新
					posy4 += velocity4;  // Y方向の座標を増加

					// 到達判定 (850.0f に到達したら停止)
					if (posy4 >= 850.0f) {
						posy4 = 850.0f;   // 到達時に位置を固定
						velocity4 = 0.0f; // 停止
						mato_state4++;    // 次の状態に進む
					}
				}
			}

		}
		//くないの更新
		kunai_update(); {
			if (counter == 0) {
				if (game_timer > 300)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter++;
				if (counter == 1)
					music::play(1);
				music::play(2);
				game_timer = 0;
				counter = 0;

			}
		}
		//くないの動き
		kunai_move();


		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit4();
			mato_state++;

		}


		//４の的がヒットしたら次の的へ
		if (isHit == true)
		{
			mato_active4 = false;
			Kunai.pos.y = 760;
			safe_delete(sprMato4);

			isHit = false;
			game_state++;
		}
		break;
	case 6:
		nextScene = SCENE_RESULT;

		break;
	}
	game_timer++;
}

void game_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	sprite_render(sprBack, 0, 0);
	sprite_render(sprCenter, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato2, posx2, posy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato3, posx3, posy3, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的
	sprite_render(sprMato4, posx4, posy4, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//的

	
	sprite_render(sprmati, 0, 0);
	if (wait_timer > 30)
	{
		sprite_render(sprmati2, 0, 0);
	}
	if (wait2_timer > 30)
	{
		sprite_render(sprmati3, 0, 0);
	}
	if (wait3_timer > 30)
	{
		sprite_render(sprmati4, 0, 0);
	}

	


	//くない描画
	kunai_render();


	//debug::setString("game_state:%d", game_state);
	//debug::setString("game_timer:%d", game_timer);
	//debug::setString("score: % d", score);
	POINT point;                                            // 位置用の変数を宣言する
	GetCursorPos(&point);                                   // スクリーン座標を取得する
	ScreenToClient(window::getHwnd(), &point);              // クライアント座標に変換する
	//debug::setString("x = %d, y = %d", point.x, point.y);

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



	 if (distance1 <= 10.0f)
		{
			score += 20;
		}
		if (distance1 <= 30.0f)
		{
			score += 25;
		}
		if (distance1 <= 50.0f)
		{
			score += 25;
		}
		if (distance1 <= 70.0f)
		{
			score += 10;
		}
		if (distance1 <= 90.0f)
		{
			score += 10;
		}
		if (distance1 <= 120.0f)
		{
			score += 10;
		}
		//score = ((120.0f - distance1) / 120.0f); // 1.0 - 0.0


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


	if (distance2 <= 120.0f)
	{
		isHit = true;
		if (distance2 <= 10.0f)
		{

			score += 20;
		}
		if (distance2 <= 30.0f)
		{
			score += 25;
		}
		if (distance2 <= 50.0f)
		{
			score += 25;
		}
		if (distance2 <= 70.0f)
		{
			score += 10;
		}
		if (distance2 <= 90.0f)
		{
			score += 10;
		}
		if (distance2 <= 120.0f)
		{
			score += 10;
		}
		//float new_score = ((120.0f - distance2) / 120.0f); // 1.0 - 0.0

	}

	else
	{
		music::stop(3);
		nextScene = SCENE_RESULT;
	}


}
void game_hit3()//当たり判定
{
	//当たり判定
	float dx3 = Kunai.pos.x - posx3;
	float dy3 = Kunai.pos.y - posy3;
	float distance3 = sqrtf(dx3 * dx3 + dy3 * dy3);


	if (distance3 <= 300.0f)
	{
		isHit = true;
		if (distance3 <= 10.0f)
		{

			score += 20;
		}
		if (distance3 <= 30.0f)
		{
			score += 25;
		}
		if (distance3 <= 50.0f)
		{
			score += 25;
		}
		if (distance3 <= 70.0f)
		{
			score += 10;
		}
		if (distance3 <= 90.0f)
		{
			score += 10;
		}
		if (distance3 <= 120.0f)
		{
			score += 10;
		}
		//float new_score = ((120.0f - distance2) / 120.0f); // 1.0 - 0.0

	}

	else
	{
		music::stop(3);
		nextScene = SCENE_RESULT;
	}
}
void game_hit4()//当たり判定
{
	//当たり判定
	float dx4 = Kunai.pos.x - posx4;
	float dy4 = Kunai.pos.y - posy4;
	float distance4 = sqrtf(dx4 * dx4 + dy4 * dy4);


	if (distance4 <= 120.0f)
	{
		isHit = true;
		if (distance4 <= 10.0f)
		{

			score += 20;
		}
		if (distance4 <= 30.0f)
		{
			score += 25;;
		}
		if (distance4 <= 50.0f)
		{
			score += 25;
		}
		if (distance4 <= 70.0f)
		{
			score += 10;
		}
		if (distance4 <= 90.0f)
		{
			score += 10;
		}
		if (distance4 <= 120.0f)
		{
			score += 10;
		}
		//float new_score = ((120.0f - distance2) / 120.0f); // 1.0 - 0.0

	}

	else
	{
		music::stop(3);
		nextScene = SCENE_RESULT;
	}


}















