#include "all.h"

extern OBJ2D Kunai;
extern OBJ2D Mato[MATO_MAX];

#if 25
//******************************************************************************
// TODO:25 円と円のあたり判定
//------------------------------------------------------------------------------
/*
課題）
    以下の仕様の関数を作成しなさい。

    戻り値：bool型（true あたっている, false あたっていない）
    関数名：hitCheckCircle
    引数　：VECTOR2 pos1, float r1, VECTOR2 pos2, float r2

ヒント）
    ぎりぎり触れている場合は、あたっているで良い。
    なお、sqrtf関数は使用しないこと。
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
// TODO:26 OBJ2D同士のあたり判定
//------------------------------------------------------------------------------
/*
課題）
    以下の仕様の関数を作成しなさい。

    戻り値：bool型（true あたっている, false あたっていない）
    関数名：hitCheck
    引数　：OBJ2D* obj1, OBJ2D* obj2

ヒント）
    上記のhitCheckCircle関数をうまく使えば良い。
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
    // TODO:28 プレイヤーvs敵のあたり判定
    //------------------------------------------------------------------------------
    /*
    課題）
        プレイヤーと全ての敵を総当たりであたり判定を行うこと。

        プレイヤーと敵があたっていたら、game_reset関数を呼びプレイヤーをリスポーン
        させること。（敵も初期位置にリセットする）

    ヒント）
        別エリアの敵とあたり判定を取る必要はありません。
    */
    //******************************************************************************
#endif
    //TODO_28
    //for (int i = 0; i < MATO_MAX; ++i)
    //{
    //    if (Mato[i].moveAlg == -1) continue;
    //    if (enemy[i].area != Mato.area) continue;

    //    if (hitCheck(&player, &enemy[i]))
    //    {
    //        game_reset();
    //    }
    //}
}