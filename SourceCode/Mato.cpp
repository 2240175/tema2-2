#include"all.h"

using namespace std;

//�ϐ�
int mato_state;
int mato_timer;

float posX1;
float posY1;//�I�P�̍��W

//�錾



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


	
}

void mato_update()
{
	switch(mato_state)
	{
	case 0:



		mato_state++;
		break;

	case 1:
		

	


		break;

	}
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

