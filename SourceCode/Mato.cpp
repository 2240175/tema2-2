#include "Mato.h"
#include"all.h"

using namespace std;

//変数
int mato_state;
int mato_timer;

float posX1;
float posY1;//的１の座標

//宣言
OBJ2D mato[MATO_MAX];
Sprite* sprMato;




//=======

//初期更新
void mato_init()
{
	mato_state = 0;
	mato_timer = 0;
}

//終了更新
void mato_deinit()
{

		safe_delete(sprMato);
	
}

void mato_update()
{
	switch(mato_state)
	{
	case 0:

	

		mato_state++;
		break;

	case 1:
		

		//敵データのクリア
		for (int i = 0; i < MATO_MAX; i++)
		{
			mato[i] = {};
			
		}



		mato_state++;
		break;

	}
}
void enemy1()
{

}
//描画
void mato_render()
{
	//sprite_render(sprMato, 0, 0);

	//	//当たり判定の赤円
	//primitive::circle(
	//	mato.pos + Kunai.offset,
	//	Kunai.radius, { 0.3,0.3 },
	//	ToRadian(0), { 1,0,0,0.2f }
	//);
}

