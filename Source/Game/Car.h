#ifndef CAR_H
#define CAR_H
#pragma once
namespace game_framework {
	class Car {
	public:
		Car() {
		}
		~Car() {}
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		//void OnMove();								// ����
		void OnShow();								// �N�ϧζK��e��
		CMovingBitmap car[5];
	

	protected:
	private:

	};
}


#endif