
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

//�I�P
float posx1 = 1280 / 2;//�I1��posx
float posy1 = 850;//�I1��posy
float velocity1 = 0.0f;//�������x
float accelerator1 = -0.3f;//���������x
int mato_state1 = 0;//��Ԃ��Ǘ�

//�I�Q
float posx2 = -100;//�I1��posx
float posy2 = 720/2;//�I1��posy
float velocity2 = 0.3f;//�������x
float accelerator2 = 0.4f;//���������x
int mato_state2 = 0;//��Ԃ��Ǘ�

//�I�R
float posx3 = -34;//�I3��posx
float posy3 = 834;//�I3��posy
float velocity3 = 0.0f;//�������x
float accelerator3 = -0.3f;//���������x
int mato_state3 = 0;//��Ԃ��Ǘ�

//�I4
float posx4 = -80;//�I3��posx
float posy4 = 800;//�I3��posy
float velocity4 = 0.0f;//�������x
float accelerator4 = -0.3f;//���������x
int mato_state4 = 0;//��Ԃ��Ǘ�

//�I5
float posx5 = -80;//�I3��posx
float posy5 = 800;//�I3��posy
float velocity5 = 0.0f;//�������x
float accelerator5 = -0.3f;//���������x
int mato_state5 = 0;//��Ԃ��Ǘ�


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



void game_init()
{
	game_state = 0;
	game_timer = 0;

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

		GameLib::setBlendMode(Blender::BS_ALPHA);

		

		game_state++;
		
	
	case 2:

		mato_active1 = true;
		if (mato_active1)
		{
			if (mato_state1 == 0) {  // 1000 ���� 360 �Ɉړ�
				velocity1 += accelerator1;
				posy1 += velocity1;
				if (posy1 <= 0.0f) {  // ���B
					posy1 = 0.0f;
					velocity1 = 0.0f;    // ���Z�b�g
					accelerator1 = -0.3f; // ���̈ړ��p�����x
				}
			}
		}

		//���Ȃ��̍X�V
		kunai_update(); {
			
			if (counter == 0) {
				if (game_timer > 120)
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
				if (posx2 >= 1280.0f) {  // ���B
					posx2 = 0.0f;
					velocity2 = 0.3f;    // ���Z�b�g
					accelerator2 = 0.4f; // ���̈ړ��p�����x
					
				}
				
			}
		}
		


		//���Ȃ��̍X�V
		kunai_update(); {
			
			if (counter == 0) {
				if (game_timer > 120)
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
	
		
	case 4:
		mato_active3 = true;

		if (mato_active3)
		{
			if (mato_state3 == 0) {  // 1000 ���� 360 �Ɉړ�
				velocity3 += accelerator3;
				posy3 += velocity3;
				posx3 += velocity3;
				if (posy3 >= 0.0f && posx3 <= 338.0f ) {  // ���B
					posy3 = 0.0f;
					posx3 = 338.0f;
					velocity3 = 2.0f;    // ���Z�b�g
					accelerator3 = 2.0f; // ���̈ړ��p�����x
					mato_state3++;
				}
			}
			else if (mato_state3 == 1)
			{
				if (posx3 >= 500.0f ) {
					posx3 = 500.0f;
					velocity3 = 0.0f;
					accelerator3 = 0.0f;  // ��~

				}
			}
		}
		

		//���Ȃ��̍X�V
		kunai_update(); {
			if (counter == 0) {
				if (game_timer > 120)
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
		//���Ȃ��̓���
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit3();
			mato_state++;

		}

		//2�̓I���q�b�g�����玟�̓I��
		if (isHit == true)
		{
			mato_active3 = false;

			safe_delete(sprMato3);
			isHit = false;
			game_state++;
		}
		break;



		//�R�̓I���q�b�g�����玟�̓I��
		if (isHit == true)
		{
			isHit = false;
			game_state++;
		}
		break;
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

void game_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	sprite_render(sprBack, 0, 0);
	sprite_render(sprCenter, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato2, posx2, posy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato3, posx3, posy3, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato4, posx4, posy4, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato5, posx5, posy5, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I

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



	 if (distance1 <= 10.0f)
		{
			score += 20;
		}
		if (distance1 <= 30.0f)
		{
			score += 20;
		}
		if (distance1 <= 50.0f)
		{
			score += 20;
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

void game_hit2()//�����蔻��
{
	//�����蔻��
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
			score += 20;
		}
		if (distance2 <= 50.0f)
		{
			score += 20;
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
void game_hit3()//�����蔻��
{
	//�����蔻��
	float dx3 = Kunai.pos.x - posx3;
	float dy3 = Kunai.pos.y - posy3;
	float distance3 = sqrtf(dx3 * dx3 + dy3 * dy3);


	if (distance3 <= 120.0f)
	{
		isHit = true;
		if (distance3 <= 10.0f)
		{

			score += 20;
		}
		if (distance3 <= 30.0f)
		{
			score += 20;
		}
		if (distance3 <= 50.0f)
		{
			score += 20;
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
void game_hit4()//�����蔻��
{
	//�����蔻��
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
			score += 20;;
		}
		if (distance4 <= 50.0f)
		{
			score += 20;
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
void game_hit5()//�����蔻��
{
	//�����蔻��
	float dx5 = Kunai.pos.x - posx5;
	float dy5 = Kunai.pos.y - posy5;
	float distance5 = sqrtf(dx5 * dx5 + dy5 * dy5);


	if (distance5 <= 120.0f)
	{
		isHit = true;
		if (distance5 <= 15.0f)
		{

			score += 20;
		}
		if (distance5 <= 30.0f)
		{
			score += 20;
		}
		if (distance5 <= 50.0f)
		{
			score += 20;
		}
		if (distance5 <= 70.0f)
		{
			score += 10;
		}
		if (distance5 <= 90.0f)
		{
			score += 10;
		}
		if (distance5 <= 120.0f)
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











