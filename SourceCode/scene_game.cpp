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

extern int kunai_state;
extern int mato_state;


//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;



float posx1 =1280/2;//�I1��posx
float posy1 = 850;//�I1��posy
float poskx1 = 1280/2;
float posky1 = 800;
float Kspeed1 = 0.0f;
int Kstay_timer ;


float velocity1 = 0.0f;//�������x
float accelerator1 = -0.3f;//���������x
int mato_state1 = 0;//��Ԃ��Ǘ�




//------�t���O------
bool isHit;//�I�����������̔���
bool mato_active1=false;//�I�̓���

//-----�摜-------
Sprite* sprBack;
Sprite* sprPush;
Sprite* sprCenter;
Sprite* sprK;
Sprite* sprMato1;

//--------------------------------------
//  �Q�[���̏����ݒ�
//--------------------------------------
void game_init()
{
    game_state      = 0;
    game_timer      = 0;
    Kstay_timer = 0;
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

        sprBack = sprite_load(L"./Data/Images/back.png");
        sprCenter = sprite_load(L"./Data/Images/senter.png");
        sprK = sprite_load(L"./Data/Images/Okunai.png");
        sprMato1 = sprite_load(L"./Data/Images/mato.png");

     
        //���Ȃ��̏����ݒ�
        kunai_init();
        
        //�I�̏����ݒ�
        mato_init();

        game_state++;
       

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        debug::setString("");
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("Kstay_timer:%d", Kstay_timer);
        debug::setString("hantei: % d", isHit);
                         
        POINT point;                                            // �ʒu�p�̕ϐ���錾����
        GetCursorPos(&point);                                   // �X�N���[�����W���擾����
        ScreenToClient(window::getHwnd(), &point);              // �N���C�A���g���W�ɕϊ�����

        debug::setString("x = %d, y = %d", point.x, point.y);

        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

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

        //����̓���
        kunai_move();




        //�P�̓I���q�b�g�����玟�̓I��
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
    
    sprite_render(sprCenter,1280/2, 720/2,1.5f,1.5f,0,0,128,128,128/2,128/2,0.0f,0.8f,0.8f,0.8f,0.8f,true);
    sprite_render(sprMato1, posx1, posy1, 1.5f, 1.5f, 0, 0, 256, 256, 256 / 2, 256 / 2, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, true);//�I

    
   
    //���Ȃ��`��
    kunai_render();

}

void game_reset()
{

    game_state = 1;
    kunai_state = 1;
    mato_state = 1;
}
void game_result() {
    nextScene = SCENE_TITLE;
}
