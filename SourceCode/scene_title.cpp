#include "all.h"
//#include <cmath> // sin��cos���g�����߂ɕK�v
//
//// �I�̍\���̂܂��̓N���X
//struct Target {
//    float x, y;            // �I�̈ʒu
//    float centerX, centerY; // �I�̒��S�ʒu�i�����l�j
//    float amplitude;       // �����̐U��
//    float speed;           // ��������
//
//    Target(float startX, float startY, float amp, float spd)
//        : x(startX), y(startY), centerX(startX), centerY(startY), amplitude(amp), speed(spd) {}
//
//    // �I�̈ʒu���X�V
//    void update(float deltaTime) {
//        x = centerX + amplitude * std::sin(speed * deltaTime);
//    }
//};

int title_state;
int title_timer;

Sprite* sprtitle;
Sprite* sprKi;


//--------------------------------------
//  �����ݒ�
//--------------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;
}

//--------------------------------------
//  �I������
//--------------------------------------
void title_deinit()
{
    music::stop(0);

    safe_delete(sprtitle);
}

//--------------------------------------
//  �^�C�g���̍X�V����
//--------------------------------------    
void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// �����ݒ� ////////
        sprKi = sprite_load(L"./Data/Images/push.png");
        sprtitle = sprite_load(L"./Data/Images/title1.jpg");
        

        title_state++;
        /*fallthrough*/





    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::play(0);
        music::setVolume(0, 0.1f);

        title_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        if (TRG(0) & PAD_START)
        {
            sound::play(XWB_SYSTEM, XWB_SYSTEM_START);

            nextScene = SCENE_GAME;
            break;
        }

        break;
    }

    debug::setString("");
    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

    title_timer++;
}

//--------------------------------------
//  �^�C�g���̕`�揈��6
//--------------------------------------
void title_render()
{  
    sprite_render(sprtitle, 0, 0);
    sprite_render(sprKi, 0, 0);

  

    //// �^�C�g���̕���
    //font::textOut(4, "ECC COMP", VECTOR2(100, 80), VECTOR2(2.4f, 2.4f), VECTOR4(1, 0.8f, 0, 1));
    //font::textOut(4, "Game Programming I", VECTOR2(80, 180), VECTOR2(2.0f, 2.0f), VECTOR4(0, 1, 0.6f, 1));

  


}
