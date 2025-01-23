#include "all.h"

int select_state;
int select_timer;


Sprite* sprselect;


void select_init()
{
	select_state = 0;
	select_timer = 0;
}
void select_deinit()
{
	safe_delete(sprselect);
}
void select_update()
{
	switch (select_state)
	{
	case 0:


		sprselect = sprite_load(L"./Data/Images/�Z���N�g���1.png");
		sprite_render(sprselect, 0, 0);

		select_state++;
		break;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);

		//music::play(0);
		//music::setVolume(0, 0.1f);

		select_state++;


	}

	select_timer++;

}
void select_render()
{
	// ��ʂ�œh��Ԃ�
	//GameLib::clear(0.3f, 0.5f, 1.0f);

}

