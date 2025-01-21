#include"all.h"

int info_state;
int info_timer;

Sprite* spr1;
Sprite* spr2;

void info_init()
{
	info_state = 0;
	info_timer = 0;
}

void info_deinit()
{
	music::stop(0);

	//safe_delete(spr1,sper2,spr3);
}

void info_update()
{
	switch(info_state)
	{
	case 0:
		info_state++;

	case 1:
		info_state++;
	}
}

void info_render()
{
}
