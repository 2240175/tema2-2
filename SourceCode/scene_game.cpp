
//----< �C���N���[�h >-----------------------------------------------------------
#include "all.h"
//#include"Mato.h"
#include<sstream>
extern int kunai_state;
extern int mato_state;
extern int score =0;


//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;
int counter;
float posx1 = 1280 / 2;//�I1��posx
float posy1 = 850;//�I1��posy
float velocity1 = 0.0f;//�������x
float accelerator1 = -0.3f;//���������x
int mato_state1 = 0;//��Ԃ��Ǘ�

float posx2 = 1400;//�I1��posx
float posy2 = 720/2;//�I1��posy
float velocity2 = 0.0f;//�������x
float accelerator2 = -0.3f;//���������x
int mato_state2 = 0;//��Ԃ��Ǘ�

//------�t���O------
bool isHit;//�I�����������̔���

bool mato_active1 = false;//�I�̓���
bool mato_active2 = false;//�I2
bool mato_active3 = false;//  3
bool mato_active4 = false;//  4
bool mato_active5 = false;//  5

//-----�摜-------
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
//  �Q�[���̏����ݒ�
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
		//////// �����ݒ� ////////
		music::play(3);
		sprBack = sprite_load(L"./Data/Images/back.png");
		sprCenter = sprite_load(L"./Data/Images/senter.png");
		sprK = sprite_load(L"./Data/Images/Okunai.png");

		sprMato1 = sprite_load(L"./Data/Images/mato.png");
		sprMato2 = sprite_load(L"./Data/Images/mato.png");
		sprMato3 = sprite_load(L"./Data/Images/mato.png");
		sprMato4 = sprite_load(L"./Data/Images/mato.png");
		sprMato5 = sprite_load(L"./Data/Images/mato.png");

		//���Ȃ��̏����ݒ�
		kunai_init();
	
		//�I�̏����ݒ�
		mato_init();


		game_state++;
	case 1:
		//////// �p�����[�^�̐ݒ� ////////
		GameLib::setBlendMode(Blender::BS_ALPHA);

		

		game_state++;
		/*fallthrough*/
	
	case 2:

		mato_active1 = true;
		if (mato_active1)
		{
			if (mato_state1 == 0) {  // 1000 ���� 360 �Ɉړ�
				velocity1 += accelerator1;
				posy1 += velocity1;
				if (posy1 <= 0.0f) {  // ���B
					posy1 = 0.0f;
					velocity1 = 2.0f;    // ���Z�b�g
					accelerator1 = 2.0f; // ���̈ړ��p�����x
				}
			}
		}

		//���Ȃ��̍X�V
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
		//���Ȃ��̓���
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit1();
			mato_state++;
			
		}
		//�P�̓I���q�b�g�����玟�̓I��
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
			if (mato_state2 == 0) {  // 1000 ���� 360 �Ɉړ�
				velocity2 += accelerator2;
				posx2 += velocity2;
				if (posx2 <= 0.0f) {  // ���B
					posx2 = 0.0f;
					velocity2 = 2.0f;    // ���Z�b�g
					accelerator2 = 2.0f; // ���̈ړ��p�����x
				}
			}
		}


		//���Ȃ��̍X�V
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
		//���Ȃ��̓���
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit2();
			mato_state++;

		}

		//2�̓I���q�b�g�����玟�̓I��
		if (isHit == true)
		{
			mato_active2 = false;

			safe_delete(sprMato2);
			isHit = false;
			game_state++;
		}
		break;
	


	
		
	//case 4:
	//	//�R�̓I���q�b�g�����玟�̓I��
	//	if (isHit == true)
	//	{
	//		isHit = false;
	//		game_state++;
	//	}
	//	break;
	//case 5:
	//	//�S�̓I���q�b�g�����玟�̓I��
	//	if (isHit == true)
	//	{
	//		isHit = false;
	//		game_state++;
	//	}
	//	break;
	//case 6:
	//	//�T�̓I���q�b�g�����玟�̓I��
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
//  �Q�[���̕`�揈��
//--------------------------------------
void game_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	sprite_render(sprBack, 0, 0);
	sprite_render(sprCenter, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato2, posx2, posy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	//���Ȃ��`��
	kunai_render();


	debug::setString("game_state:%d", game_state);
	debug::setString("game_timer:%d", game_timer);
	debug::setString("score: % d", score);
	POINT point;                                            // �ʒu�p�̕ϐ���錾����
	GetCursorPos(&point);                                   // �X�N���[�����W���擾����
	ScreenToClient(window::getHwnd(), &point);              // �N���C�A���g���W�ɕϊ�����
	debug::setString("x = %d, y = %d", point.x, point.y);

}


void game_reset()//�Q�[���̃��Z�b�g
{
	game_state = 0;
	kunai_state = 1;
	mato_state = 1;
}

void game_result() {
	music::stop(3);
	nextScene = SCENE_TITLE;
}



void game_hit1()//�����蔻��
{
	//�����蔻��//
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

void game_hit2()//�����蔻��
{
	//�����蔻��
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










