#include "all.h"


int result_state;
int result_timer;
float resulttime;
extern int score;
Sprite* sprhaikei2;

void result_init()
{
	result_state = 0;
	result_timer = 0;
}
void result_deinit()
{
	safe_delete(sprhaikei2);
}
void result_update()
{
	switch (result_state)
	{
	case 0:
		sprhaikei2 = sprite_load(L"./Data/Images/リザルト2.png");

		result_state++;
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		//music::play(0);
		//music::setVolume(0, 0.1f);

		result_state++;

	case 2:
		// チュートリアルの進行条件
		if (!(STATE(0) & PAD_TRG1) || STATE(0) & PAD_TRG1)
		{
			resulttime += 1;
			if (resulttime > 400)
			{
				game_result();
			}
		}
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
		}

		break;

	}

	result_timer++;

}
void result_render()
{
	// 画面を青で塗りつぶす
	GameLib::clear(0.3f, 0.5f, 1.0f);
	
	sprite_render(sprhaikei2, 0, 0);
	std::string scoreText = std::to_string(score);
	text_out(6, scoreText, 250, 400, 2.5f, 2.5f,1.0,0,0);
}