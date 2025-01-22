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



//<<<<<<< HEAD
//的データ構造体
struct MATO_DATA
{
	Sprite* sprMato;

	const wchar_t* filePath;

	VECTOR2 texPos;

	VECTOR2 texSize;

	VECTOR2 pivot;

	float radius;

};

struct MATO_DATA matoData[] =
{
	{NULL, L"Data/Images/mato.png", {0, 0}, {256, 256}, {256, 256}, 30},

};

//敵の配置
struct ENEMY_SET
{
	int area; //エリア数
	int enemyType;//敵のタイプ
	VECTOR2 pos;

};

struct ENEMY_SET enemySet[] =
{
	{0,0,{posX1,posY1}},//敵０
	{0,0,{640,-600}},//敵1
	{0,0,{1800,360}},//敵2
	{0,0,{1800,540}},//敵2
	


};
//=======
//>>>>>>> ba04d5c80b0cf390fcabdc94f92c521cee2d1fbf

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
//<<<<<<< HEAD
//=======
// 
//	
//>>>>>>> ba04d5c80b0cf390fcabdc94f92c521cee2d1fbf
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

