#include "Mato.h"
#include"all.h"

using namespace std;

//変数
int mato_state;
int mato_timer;

float posX;
float posY;

//宣言
OBJ2D enemy[MATO_MAX];



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
	int enemyType;
	VECTOR2 pos;

};

struct ENEMY_SET enemySet[] =
{
	{0,{posX,posY}},//敵０

};

//初期更新
void mato_init()
{
	mato_state = 0;
	mato_timer = 0;
}

//終了更新
void mato_deinit()
{
	//dataNumでfor文を回す
	//dataNum回matoData[i].sprMatoを削除
	int dataNum = ARRAYSIZE(matoData);
	for (int i = 0; i = dataNum; i++)
	{
		safe_delete(matoData[i].sprMato);
	}
}

void mato_update()
{
	switch(mato_state)
	{
	case 0:

		int dataNum;

		dataNum = sizeof(matoData) / sizeof(MATO_DATA);

		//初期設定
		for (int i = 0; i < dataNum; i++)
		{
			matoData[i].sprMato = sprite_load(matoData[i].filePath);
		}
		mato_state++;
		break;

	case 1:
		//パラメータの設定

		//敵データのクリア
		for (int i = 0; i < MATO_MAX; i++)
		{
			enemy[i] = {};
			
		}

		mato_state++;
		break;





	
	}
}

//描画
void mato_render()
{
	/*sprite_render(sprMato, 0, 0);*/
}

