#ifndef SUN_H
#define SUN_H
#pragma once
namespace game_framework {
	class Sun {
	public:
		Sun() {
			flag2 = false;
			flag_sun = false;
			delay = 0;
		};
		~Sun(){}
		void OnInit();  							// �C������Ȥιϧγ]�w
		void OnMove();								// ����
		void Onshow1();
		void OnShow2();								// �N�ϧζK��e��
		void OnShow3();
		int random(int low, int high);
		CMovingBitmap sun[3];
		bool flag2;
		bool flag_sun;
	protected:

	private:
		int delay;
	};
}

#endif