#include "Mato.h"
#include"all.h"

using namespace std;

//�ϐ�
int mato_state;
int mato_timer;

float posX1;
float posY1;//�I�P�̍��W

//�錾
OBJ2D mato[MATO_MAX];
Sprite* sprMato;



//<<<<<<< HEAD
//�I�f�[�^�\����
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

//�G�̔z�u
struct ENEMY_SET
{
	int area; //�G���A��
	int enemyType;//�G�̃^�C�v
	VECTOR2 pos;

};

struct ENEMY_SET enemySet[] =
{
	{0,0,{posX1,posY1}},//�G�O
	{0,0,{640,-600}},//�G1
	{0,0,{1800,360}},//�G2
	{0,0,{1800,540}},//�G2
	


};
//=======
//>>>>>>> ba04d5c80b0cf390fcabdc94f92c521cee2d1fbf

//�����X�V
void mato_init()
{
	mato_state = 0;
	mato_timer = 0;
}

//�I���X�V
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
		

		//�G�f�[�^�̃N���A
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
//�`��
void mato_render()
{
	//sprite_render(sprMato, 0, 0);

	//	//�����蔻��̐ԉ~
	//primitive::circle(
	//	mato.pos + Kunai.offset,
	//	Kunai.radius, { 0.3,0.3 },
	//	ToRadian(0), { 1,0,0,0.2f }
	//);
}

