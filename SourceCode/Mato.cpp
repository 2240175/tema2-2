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

//�����X�V
void mato_init()
{
	mato_state = 0;
	mato_timer = 0;
}

//�I���X�V
void mato_deinit()
{
	//dataNum��for������
	//dataNum��matoData[i].sprMato���폜
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

		//�����ݒ�
		for (int i = 0; i < dataNum; i++)
		{
			matoData[i].sprMato = sprite_load(matoData[i].filePath);
		}
		mato_state++;
		break;

	case 1:
		//�p�����[�^�̐ݒ�

		//�G�f�[�^�̃N���A
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

