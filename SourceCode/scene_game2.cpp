#include "all.h"
#include"Mato.h"
#include<sstream>
//
//if (mato_state3 == 0) {  // 1000 ���� 360 �Ɉړ�
//	velocityX3 += acceleratorX3;
//	velocityY3 += acceleratorY3;
//	posy3 += velocityY3;
//	posx3 += velocityX3;
//
//	float threshold = 1.0f; // �ڕW�n�_�̌덷�͈�
//	if (abs(posx3 - 378.0f) <= threshold && abs(posy3 - 195.0f) <= threshold) {
//		posx3 = 378.0f; // �ڕW�n�_�ɌŒ�
//		posy3 = 195.0f;
//		velocityX3 = 0.0f; // ��~
//		velocityY3 = 0.0f; // ��~
//		mato_state3++; // ���̏�Ԃɐi��
//	}
//}
//if (mato_state3 == 1) {  // �������: (-151, 325) ���� (378, 195) �Ɉړ�
//	// �����x��K�p���đ��x���X�V
//	velocityX3 += acceleratorX3;
//	velocityY3 += acceleratorY3;
//
//
//
//	// ���W���X�V
//	posx3 += velocityX3;
//	posy3 += velocityY3;
//
//	// ���B����
//	float threshold = 1.0f; // �덷�͈�
//	if ((abs(posx3 - 378.0f) <= threshold && abs(posy3 - 195.0f) <= threshold) ||
//		(velocityX3 == 0.0f && velocityY3 == 0.0f)) {
//		posx3 = 378.0f; // �ڕW�n�_�ɌŒ�
//		posy3 = 195.0f;
//		velocityX3 = 0.0f; // ��~
//		velocityY3 = 0.0f; // ��~
//		mato_state3++;     // ���̏�Ԃɐi��
//	}
