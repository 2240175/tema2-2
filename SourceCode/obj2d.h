#ifndef OBJ2D_H
#define OBJ2D_H

#include "../GameLib/game_lib.h"
#include "../GameLib/obj2d_data.h"

struct OBJ2D
{

    
    int timer;
    VECTOR2 pos;
    VECTOR2 scale;
    VECTOR2 texPos;
    VECTOR2 texSize;
    VECTOR2 pivot;
    VECTOR4 color;



    int area;

    int moveAlg;

    VECTOR2 speed;

//=======


    //â~ÇÃìñÇΩÇËîªíËópïœêî

    float radius;
    VECTOR2 offset;
};

#endif//OBJ2D_H