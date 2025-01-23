#include "all.h"

int tutorial_state;
int tutorial_timer;
int tutorialcounter = 0;//チュートリアル枚数確認用
int tutorialrender = 0;//チュートリアル座標変化用

Sprite* sprhaikei;
Sprite* sprhaikei3;
Sprite* sprhaikei4;

void tutorial_init()
{
	tutorial_state = 0;
	tutorial_timer = 0;
}
void tutorial_deinit()
{
	safe_delete(sprhaikei);
}
void tutorial_update()
{
	switch (tutorial_state)
	{
	case 0:


		sprhaikei = sprite_load(L"./Data/Images/チュートリアル画面1.png");
		sprite_render(sprhaikei, 0, 0);

		tutorial_state++;
		break;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);

		//music::play(0);
		//music::setVolume(0, 0.1f);

		tutorial_state++;


	case 2:
		// チュートリアルの進行条件
		if (TRG(0) & PAD_TRG1)
		{
			sprhaikei = sprite_load(L"./Data/Images/チュートリアル画面2.png");
			sprite_render(sprhaikei, 0, 0);
			tutorial_state++;
		}
		break;
	case 3:

		GameLib::setBlendMode(Blender::BS_ALPHA);

	
		tutorial_state++;


	case 4:
		if (TRG(0) & PAD_TRG1)
		{
			sprhaikei = sprite_load(L"./Data/Images/チュートリアル画面3.png");
			sprite_render(sprhaikei, 0, 0);
			tutorial_state++;
		}
		break;
	case 5:

		GameLib::setBlendMode(Blender::BS_ALPHA);


		tutorial_state++;
	case 6:
		if (TRG(0) & PAD_TRG1)
		{
			sprhaikei = sprite_load(L"./Data/Images/チュートリアル画面4.png");
			sprite_render(sprhaikei, 0, 0);
			tutorial_state++;
		}
		break;

	case 7:

		GameLib::setBlendMode(Blender::BS_ALPHA);


		tutorial_state++;

	case 8:
		if (TRG(0) & PAD_TRG1)
		{
			sprhaikei = sprite_load(L"./Data/Images/チュートリアル画面5.png");
			sprite_render(sprhaikei, 0, 0);
			tutorial_state++;
		}
		break;

	case 9:

		GameLib::setBlendMode(Blender::BS_ALPHA);

	
		tutorial_state++;

	case 10:
		if (TRG(0) & PAD_TRG1)
		{
			nextScene = SCENE_TITLE;
			tutorial_state = 0;
		}
		break;

	}

	tutorial_timer++;

}
void tutorial_render()
{


}

