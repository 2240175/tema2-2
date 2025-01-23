
#include "all.h"

#include<sstream>

/*extern*/ int kunai_state2;
extern int score2 = 0;

int game_state2;
int game_timer2;
int wait_timer2;
int moment_timer1;
int moment_timer2;
int gmato_state ;
int counter2;

//�I�P
float gposx1;//�I1��posx
float gposy1;//�I1��posy
float gvelocity1;//�������x
float gaccelerator1;//���������x
int gmato_state1;//��Ԃ��Ǘ�

//�I�Q
float gposx2;//�I1��posx
float gposy2;//�I1��posy
float gvelocity2;//�������x
float gaccelerator2;//���������x
int gmato_state2;//��Ԃ��Ǘ�

//�I�R
float gposx3;//�I3��posx
float gposy3;//�I3��posy
float gvelocityX3;//�������x
float gacceleratorX3;//���������x
int gmato_state3;//��Ԃ��Ǘ�

//�I4
float gposx4;//�I3��posx
float gposy4;//�I3��posy
float gvelocity4;//�������x
float gaccelerator4;//���������x
int gmato_state4;//��Ԃ��Ǘ�

float w = 0;
float s = 0;
float a = 0;
static float angle = 0;

bool isHit2;//�I�����������̔���

bool mato_active21 = false;//�I�̓���
bool mato_active22 = false;//�I2
bool mato_active23 = false;//  3
bool mato_active24 = false;//  4


Sprite* sprCenter2;
Sprite* sprK2;
Sprite* mmato1;
Sprite* mmato2;
Sprite* mmato3;
Sprite* mmato4;



Sprite* sprMato21;
Sprite* sprMato22;
Sprite* sprMato23;
Sprite* sprMato24;
Sprite* sprMato25;


Sprite* sprBack2;

void game2_init()
{
	game_state2 = 0;
	game_timer2 = 0;
	wait_timer2 = 0;
	moment_timer1 = 0;
	moment_timer2 = 0;
	gmato_state = 0;

	//�I�P
	gposx1 = 1280 / 2;//�I1��posx
	gposy1 = 850;//�I1��posy
	gvelocity1 = 0.0f;//�������x
	gaccelerator1 = -0.3f;//���������x
	gmato_state1 = 0;//��Ԃ��Ǘ�

	//�I�Q
	gposx2 = -100.0f;
	gposy2 = 720.0f / 2.0f;
	gvelocity2 = 1.0f;
	gaccelerator2 = 0.5f;
	gmato_state2 = 0;


	//�I�R
	gposx3 = 1400;//�I3��posx
	gposy3 = 720 / 2;//�I3��posy
	gvelocityX3 = -2.0f;//�������x
	gacceleratorX3 = -1.0f;//���������x
	gmato_state3 = 0;//��Ԃ��Ǘ�

	//�I4
	gposx4 = 1280 / 2;//�I3��posx
	gposy4 = -200;//�I3��posy
	gvelocity4 = 2.5f;//�������x
	gaccelerator4 = 1.0f;//���������x
	gmato_state4 = 0;//��Ԃ��Ǘ�


};

void game2_deinit()
{

	kunai_deinit();
	safe_delete(sprBack2);


}

void game2_update()
{
	switch (game_state2)
	{
	case 0:

		music::play(3);
		game_timer2++;
		sprBack2 = sprite_load(L"./Data/Images/back.png");
		sprCenter2 = sprite_load(L"./Data/Images/senter.png");
		sprK2 = sprite_load(L"./Data/Images/Okunai.png");
		mmato1 = sprite_load(L"./Data/Images/UI1.png");
		mmato2 = sprite_load(L"./Data/Images/UI2.png");
		mmato3 = sprite_load(L"./Data/Images/UI3.png");
		mmato4 = sprite_load(L"./Data/Images/UI4.png");

		sprMato21 = sprite_load(L"./Data/Images/mato.png");
		sprMato22 = sprite_load(L"./Data/Images/mato.png");
		sprMato23 = sprite_load(L"./Data/Images/mato.png");
		sprMato24 = sprite_load(L"./Data/Images/mato.png");

		//���Ȃ��̏����ݒ�
		kunai_init();

		game_state2++;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);



		game_state2++;


	case 2:
		sprite_render(mmato1, 0, 0);
		music::play(5);
		if (game_timer2 > 110)
		{
			music::stop(5);
			safe_delete(mmato1);
		}
		if (game_timer2 > 180)
		{
			angle = 0;

			w = 0.2; // �p���x
			a = 200; // �U��
			s = 8; // �������̑���

			angle += w;

			gposx3 += s; // �ڕW�n�_�ɌŒ�
			gposy3 = 325 + a * sinf(angle);

		}
		//���Ȃ��̍X�V
		kunai_update(); {

			if (counter2 == 0) {
				if (game_timer2 > 280)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//���Ȃ��̓���
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit1();
			gmato_state++;

		}


		//�P�̓I���q�b�g�����玟�̓I��
		if (isHit2 == true)
		{
			mato_active21 = false;

			safe_delete(sprMato21);

			Kunai.pos.y = 760;//���Ȃ�������

			isHit2 = false;
			game_state2++;
		}

		break;

	case 3:
		wait_timer2++;
		sprite_render(mmato2, 0, 0);
		music::play(5);
		if (wait_timer2 > 110)
		{
			music::stop(5);
			safe_delete(mmato2);
		}
		if (wait_timer2 > 180)
		{
			angle = 0;

			w = 0.5; // �p���x
			a = 300; // �U��
			s = -8; // �������̑���

			angle += w;

			gposx3 += s; // �ڕW�n�_�ɌŒ�
			gposy3 = 325 + a * sinf(angle);

		}


		//���Ȃ��̍X�V
		kunai_update(); {

			if (counter2 == 0) {
				if (game_timer2 > 120)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}


		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit2();
			gmato_state++;

		}

		//2�̓I���q�b�g�����玟�̓I��
		if (isHit2 == true)
		{
			mato_active22 = false;

			Kunai.pos.y = 760;//���Ȃ�������

			safe_delete(sprMato22);
			isHit2 = false;
			game_state2++;
		}
		break;


	case 4:
		moment_timer1++;
		sprite_render(mmato3, 0, 0);
		music::play(5);
		if (moment_timer1 > 110)
		{
			music::stop(5);
			safe_delete(mmato3);
		}

		if (moment_timer1 > 180)
		{
			mato_active23 = true;


			w = 0;
			a = 0;
			s = 0;

			angle = 0;

			w = 0.2; // �p���x
			a = 200; // �U��
			s = 8; // �������̑���

			angle += w;

			gposx3 += s; // �ڕW�n�_�ɌŒ�
			gposy3 = 325 + a * sinf(angle);

		}
		//���Ȃ��̍X�V
		kunai_update(); {
			if (counter2 == 0) {
				if (game_timer2 > 280)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//���Ȃ��̓���
		kunai_move();

		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit3();
			gmato_state++;

		}

		//2�̓I���q�b�g�����玟�̓I��
		if (isHit2 == true)
		{
			mato_active23 = false;

			safe_delete(sprMato23);
			isHit2 = false;
			game_state2++;
		}
		break;





	case 5:
		moment_timer2++;
		sprite_render(mmato4, 0, 0);
		music::play(5);
		if (moment_timer1 > 110)
		{
			music::stop(5);
			safe_delete(mmato4);
		}

		if (moment_timer2 > 180)
		{
			w = 0;
			a = 0;
			s = 0;

			angle = 0;

			w = 0.2; // �p���x
			a = 200; // �U��
			s = 8; // �������̑���

			angle += w;

			gposx3 += s; // �ڕW�n�_�ɌŒ�
			gposy3 = 325 + a * sinf(angle);

		}

		//���Ȃ��̍X�V
		kunai_update(); {
			if (counter2 == 0) {
				if (game_timer2 > 120)
				{
					nextScene = SCENE_RESULT;
				}
			}
			if (TRG(0) & PAD_TRG1)
			{
				kunai_render();
				Kunai.pos.y = 390;
				counter2++;
				if (counter2 == 1)
					music::play(1);
				music::play(2);
				game_timer2 = 0;
				counter2 = 0;
			}
		}
		//���Ȃ��̓���
		kunai_move();


		// SPACE PUSHED
		if (TRG(0) & PAD_TRG1)
		{
			game_hit4();
			gmato_state++;

		}


		//�S�̓I���q�b�g�����玟�̓I��
		if (isHit2 == true)
		{
			mato_active24 = false;

			safe_delete(sprMato24);

			isHit2 = false;
			game_state2++;
		}
		break;
	case 6:
		nextScene = SCENE_RESULT;

		break;
	}
	game_timer2++;
}



void game2_render()
{
	GameLib::clear(0.2f, 0.2f, 0.4f);
	sprite_render(sprBack2, 0, 0);
	sprite_render(sprCenter2, 1280 / 2, 720 / 2, 1.5f, 1.5f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, true);
	sprite_render(sprMato21, gposx1, gposy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato22, gposx2, gposy2, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato23, gposx3, gposy3, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(sprMato24, gposx4, gposy4, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I
	sprite_render(mmato1, 0, 0);
	if (wait_timer2 > 30)
	{
		music::play(5);
		sprite_render(mmato2, 0, 0);
	}
	if (moment_timer1 > 30)
	{
		music::play(5);
		sprite_render(mmato3, 0, 0);
	}
	if (moment_timer2 > 30)
	{
		music::play(5);
		sprite_render(mmato4, 0, 0);
	}

	//���Ȃ��`��
	kunai_render();



	debug::setString("score: % d", score2);
	POINT point;                                            // �ʒu�p�̕ϐ���錾����
	GetCursorPos(&point);                                   // �X�N���[�����W���擾����
	ScreenToClient(window::getHwnd(), &point);              // �N���C�A���g���W�ɕϊ�����
	//debug::setString("x = %d, y = %d", point.x, point.y);

}


void game2_reset()//�Q�[���̃��Z�b�g
{
	game_state2 = 0;
	kunai_state2 = 1;
	gmato_state = 1;
}

void game2_result() {
	music::stop(3);
	nextScene = SCENE_TITLE;
}
