#include"all.h"
#include"Kunai.h"

int     kunai_state;

OBJ2D   Kunai;

Sprite* sprKunai;

//�����ݒ�
void kunai_init()
{
    kunai_state = 0;
}

//�I������
void kunai_deinit()
{
    safe_delete(sprKunai);
}

//�X�V����
void kunai_update()
{
	switch (kunai_state)
	{
	case 0:
		//�摜�̓ǂݍ���
		sprKunai = sprite_load(L"./Data/Images/Okunai.png");

		kunai_state++;
		break;
	case 1:
		//kunai�����ݒ�
		Kunai = {};
		Kunai.timer = 0;
		Kunai.pos = { 1280/ 2,760 };//�摜�̈ʒu
		Kunai.scale = { 1.0f,1.0f };//�傫��
		Kunai.texSize = { PLAYER_TEX_W, PLAYER_TEX_H };//�摜�̃T�C�Y
		Kunai.pivot = { PLAYER_PIVOT_X, PLAYER_PIVOT_Y };//���S
		Kunai.radius = 24;
		Kunai.offset = { 0,-32 };


		kunai_state++;
	
	}
}

void kunai_render()
{

	sprite_render(sprKunai,
		Kunai.pos.x, Kunai.pos.y, 
		Kunai.scale.x, Kunai.scale.y,
		0, 0, 
		Kunai.texSize.x, Kunai.texSize.y,
		Kunai.pivot.x, Kunai.pivot.y, 
		ToRadian(0),
		1.0f, 1.0f, 1.0f, 1.0f, true);

	//�����蔻��̐ԉ~
	primitive::circle(
		Kunai.pos+ Kunai.offset,
		Kunai.radius, { 0.3,0.3 },
		ToRadian(0), { 1,0,0,0.2f }
	);

}

//bool kunai_hit()
//{
//	if (TRG(0) & PAD_TRG1  )
//	{
//		sound::play(XWB_STAGE1, XWB_STAGE1_JUMP);
//		
//		Kunai.pos.y = 390;
//	
//		return true;
//	}
//
//	return false;
//}
