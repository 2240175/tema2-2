#include "all.h"
#include"Mato.h"
#include<sstream>
//
//if (mato_state3 == 0) {  // 1000 から 360 に移動
//	velocityX3 += acceleratorX3;
//	velocityY3 += acceleratorY3;
//	posy3 += velocityY3;
//	posx3 += velocityX3;
//
//	float threshold = 1.0f; // 目標地点の誤差範囲
//	if (abs(posx3 - 378.0f) <= threshold && abs(posy3 - 195.0f) <= threshold) {
//		posx3 = 378.0f; // 目標地点に固定
//		posy3 = 195.0f;
//		velocityX3 = 0.0f; // 停止
//		velocityY3 = 0.0f; // 停止
//		mato_state3++; // 次の状態に進む
//	}
//}
//if (mato_state3 == 1) {  // 初期状態: (-151, 325) から (378, 195) に移動
//	// 加速度を適用して速度を更新
//	velocityX3 += acceleratorX3;
//	velocityY3 += acceleratorY3;
//
//
//
//	// 座標を更新
//	posx3 += velocityX3;
//	posy3 += velocityY3;
//
//	// 到達判定
//	float threshold = 1.0f; // 誤差範囲
//	if ((abs(posx3 - 378.0f) <= threshold && abs(posy3 - 195.0f) <= threshold) ||
//		(velocityX3 == 0.0f && velocityY3 == 0.0f)) {
//		posx3 = 378.0f; // 目標地点に固定
//		posy3 = 195.0f;
//		velocityX3 = 0.0f; // 停止
//		velocityY3 = 0.0f; // 停止
//		mato_state3++;     // 次の状態に進む
//	}
