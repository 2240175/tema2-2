#include "all.h"

//extern OBJ2D Kunai;
//extern OBJ2D Mato[MATO_MAX];

#if 25
//******************************************************************************
// TODO:25 �~�Ɖ~�̂����蔻��
//------------------------------------------------------------------------------
/*
�ۑ�j
    �ȉ��̎d�l�̊֐����쐬���Ȃ����B

    �߂�l�Fbool�^�itrue �������Ă���, false �������Ă��Ȃ��j
    �֐����FhitCheckCircle
    �����@�FVECTOR2 pos1, float r1, VECTOR2 pos2, float r2

�q���g�j
    ���肬��G��Ă���ꍇ�́A�������Ă���ŗǂ��B
    �Ȃ��Asqrtf�֐��͎g�p���Ȃ����ƁB
*/
//******************************************************************************
#endif
//TODO_25
bool hitCheckCircle(VECTOR2 pos1, float r1, VECTOR2 pos2, float r2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r = r1 + r2;

    if (dx * dx + dy * dy <= r * r)
        return true;

    return false;


}

#if 26
//******************************************************************************
// TODO:26 OBJ2D���m�̂����蔻��
//------------------------------------------------------------------------------
/*
�ۑ�j
    �ȉ��̎d�l�̊֐����쐬���Ȃ����B

    �߂�l�Fbool�^�itrue �������Ă���, false �������Ă��Ȃ��j
    �֐����FhitCheck
    �����@�FOBJ2D* obj1, OBJ2D* obj2

�q���g�j
    ��L��hitCheckCircle�֐������܂��g���Ηǂ��B
*/
//******************************************************************************
#endif
//TODO_26 
bool hitCheck(OBJ2D* obj1, OBJ2D* obj2)
{
    return hitCheckCircle(
        obj1->pos + obj1->offset, obj1->radius,
        obj2->pos + obj2->offset, obj2->radius
    );

}

void judge()
{
#if 28
    //******************************************************************************
    // TODO:28 �v���C���[vs�G�̂����蔻��
    //------------------------------------------------------------------------------
    /*
    �ۑ�j
        �v���C���[�ƑS�Ă̓G�𑍓�����ł����蔻����s�����ƁB

        �v���C���[�ƓG���������Ă�����Agame_reset�֐����Ăуv���C���[�����X�|�[��
        �����邱�ƁB�i�G�������ʒu�Ƀ��Z�b�g����j

    �q���g�j
        �ʃG���A�̓G�Ƃ����蔻������K�v�͂���܂���B
    */
    //******************************************************************************
#endif
    //TODO_28
    //for (int i = 0; i < MATO_MAX; ++i)
    //{
    //    if (Mato[i].moveAlg == -1) continue;
    //    if (Mato[i].area != Kunai.area) continue;

    //    if (hitCheck(&Kunai, &Mato[i]))
    //    {
    //        game_reset();
    //    }
    //}
}



