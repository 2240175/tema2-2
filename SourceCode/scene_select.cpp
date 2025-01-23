#include "all.h"

int select_state;
int select_timer;

bool choise = true;

Sprite* sprselect;
Sprite* Startup;
Sprite* Startdown;

void select_init()
{
	select_state = 0;
	select_timer = 0;
}
void select_deinit()
{
	safe_delete(sprselect);
	safe_delete(Startup);
	safe_delete(Startdown);
}
void select_update()
{
	switch (select_state)
	{
	case 0:

		
		sprselect = sprite_load(L"./Data/Images/ƒZƒŒƒNƒg‰æ–Ê.png");
		Startup = sprite_load(L"./Data/Images/ber1.png");
		Startdown = sprite_load(L"./Data/Images/ber2.png");

		sprite_render(sprselect, 0, 0);

		select_state++;
		break;

	case 1:

		GameLib::setBlendMode(Blender::BS_ALPHA);



		select_state++;

	case 2:
		if (choise == true)
		{
			if (TRG(0) & PAD_START)
			{
				nextScene = SCENE_GAME;
				break;
			}

			if (TRG(0) & PAD_DOWN)
			{
				choise = false;
			}


		}
		if (choise == false)
		{
			if (TRG(0) & PAD_UP)
			{
				choise = true;
			}

			if (TRG(0) & PAD_START)
			{
				nextScene = SCENE_GAME2;
				
			}
		}
		break;
		
	}
	select_timer++;
	

}

void select_render()
{
	sprite_render(sprselect, 0, 0);


	if (choise == true)
	{
		if (select_timer / 32 % 2)
		{
			sprite_render(Startup, 0, 0);
		}
		sprite_render(Startdown, 0, 0);
	}
	if (choise == false)
	{
		if (select_timer / 32 % 2)
		{
			sprite_render(Startdown, 0, 0);
		}
		sprite_render(Startup, 0, 0);
	}




}

