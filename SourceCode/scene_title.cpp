#include "all.h"


int title_state;
int title_timer;

Sprite* sprtitle;
Sprite* sprSpace;
Sprite* sprEnter;



void title_init()
{
    title_state = 0;
    title_timer = 0;
}


void title_deinit()
{
    music::stop(0);

    safe_delete(sprtitle);
}

    
void title_update()
{
    switch (title_state)
    {
    case 0:

        //////// èâä˙ê›íË ////////
        

       


        sprtitle = sprite_load(L"./Data/Images/title.png");
        sprSpace = sprite_load(L"./Data/Images/space.png");
        sprEnter = sprite_load(L"./Data/Images/enter.png");

        title_state++;
      





    case 1:
      

        GameLib::setBlendMode(Blender::BS_ALPHA);

        music::play(0);
        music::setVolume(0, 0.1f);

        title_state++;
       

    case 2:
       

        if (TRG(0) & PAD_START)
        {
            music::play(4);

            nextScene = SCENE_SELECT;
            break;
        }
        if (TRG(0) & PAD_TRG1)
        {
            nextScene = SCENE_TUTORIAL1;
            break;
        }
        break;
    }

    debug::setString("");
    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

    title_timer++;
}


void title_render()
{  
    sprite_render(sprtitle, 0, 0);
    sprite_render(sprEnter, 0, 0);
    sprite_render(sprSpace, 0, 0);

  



  


}
