#include "all.h"

//--------------------------------------
//  �I�[�f�B�I�̏����ݒ�
//--------------------------------------
void audio_init()
{
    // ���y�̓ǂݍ���
    music::load(0, L"./Data/Musics/title_bgm.wav");
    music::load(1, L"./Data/Musics/��.wav");
    music::load(2, L"./Data/Musics/Wind.wav");
    music::load(3, L"./Data/Musics/Launch.wav");
    music::load(4, L"./Data/Musics/Break.wav");
    music::load(5, L"./Data/Musics/�ڔ�.wav");

    sound::load(XWB_SYSTEM, L"./Data/Sounds/system.xwb");    // ���j���[�Ȃǂ�SE
    sound::load(XWB_STAGE1, L"./Data/Sounds/stage1.xwb");    // �X�e�[�W�p��SE

    sound::setVolume(XWB_STAGE1, XWB_STAGE1_JUMP, 0.1f);
}

//--------------------------------------
//  �I�[�f�B�I�̏I������
//--------------------------------------
void audio_deinit()
{
    // ���y��S�ĉ��
    music::clear();
}
