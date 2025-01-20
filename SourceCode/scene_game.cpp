//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< �C���N���[�h >-----------------------------------------------------------
#include "all.h"
#include"Mato.h"

#include<sstream>


//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;


int matoX;
int matoY;
float posx1;//�I1��posx
float posy1;//�I1��posy
float poskx1 = 1280/2;
float posky1 = 800;
float Kspeed1 = 0.0f;
int Kstay_timer ;


//------�錾------
bool isHit;//�I�����������̔���

//-----�摜-------
Sprite* sprBack;
Sprite* sprPush;
Sprite* sprCenter;
Sprite* sprK;

//--------------------------------------
//  �Q�[���̏����ݒ�
//--------------------------------------
void game_init()
{
    game_state      = 0;
    game_timer      = 0;
    Kstay_timer = 0;
}

//--------------------------------------
//  �Q�[���̏I������
//--------------------------------------
void game_deinit()
{
#if 11
//******************************************************************************
// TODO:11 �v���C���[�̏I�������֐����Ăяo��
//------------------------------------------------------------------------------
/*
�ۑ�j
    ���L��player_deinit�֐����Ăт܂��傤�B
*/
//******************************************************************************
#endif
    //TODO_11

    kunai_deinit();

    safe_delete(sprBack);
}

//--------------------------------------
//  �Q�[���̍X�V����
//--------------------------------------
void game_update()            
{
    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////

        sprBack = sprite_load(L"./Data/Images/back.png");
        sprCenter = sprite_load(L"./Data/Images/senter.png");
        sprK = sprite_load(L"./Data/Images/Okunai.png");

        //TODO_10  
        // //���Ȃ��̏����ݒ�
        kunai_init();
      

        game_state++;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

      

        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        debug::setString("");
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("Kstay_timer:%d", Kstay_timer);
        debug::setString("hantei: % d", isHit);
                         
        POINT point;                                            // �ʒu�p�̕ϐ���錾����
        GetCursorPos(&point);                                   // �X�N���[�����W���擾����
        ScreenToClient(window::getHwnd(), &point);              // �N���C�A���g���W�ɕϊ�����

        debug::setString("x = %d, y = %d", point.x, point.y);
  

        //���Ȃ��̍X�V


        kunai_update();
        if (TRG(0) & PAD_TRG1)
        {
            sound::play(XWB_STAGE1, XWB_STAGE1_JUMP);

            Kunai.pos.y = 390;

            
        }

       


        //1�̓I���q�b�g��  ���玟�̓I��
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;

    case 3:

        //�Q�̓I���q�b�g�����玟�̓I��
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;
    case 4:

        //�R�̓I���q�b�g�����玟�̓I��
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }

        break;
    case 5:

        //�S�̓I���q�b�g�����玟�̓I��
        if (isHit == true)
        {
            isHit = false;
            game_state++;
        }
        break;

    case 6:

        //�T�̓I���q�b�g�����玟�̓I��
        if (isHit == true)
        {
            isHit = false;
            nextScene = SCENE_TITLE;
            break;
        }





        break;
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
    sprite_render(sprCenter,1280/2, 720/2,1.0f,1.0f,0,0,128,128,128/2,128/2,0.0f,0.8f,0.8f,0.8f,0.8f,true);

    sprite_render(sprK, poskx1, posky1, 1.0f, 1.0f, 0, 0, 128, 128, 128 / 2, 128 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);

    //���Ȃ��`��
    kunai_render();

}
