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




//=======

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

