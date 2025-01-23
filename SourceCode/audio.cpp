#include "all.h"


void audio_init()
{
    // âπäyÇÃì«Ç›çûÇ›
    music::load(0, L"./Data/Musics/title_bgm.wav");
    music::load(1, L"./Data/Musics/Break.wav");
    music::load(2, L"./Data/Musics/Launch.wav");
    music::load(3, L"./Data/Musics/Wind.wav");
    music::load(4, L"./Data/Musics/ã’.wav");
    music::load(5, L"./Data/Musics/é⁄î™.wav");

    sound::load(XWB_SYSTEM, L"./Data/Sounds/system.xwb");    
    sound::load(XWB_STAGE1, L"./Data/Sounds/stage1.xwb");    

    sound::setVolume(XWB_STAGE1, XWB_STAGE1_JUMP, 0.1f);
}


void audio_deinit()
{
   
    music::clear();
}
