#ifndef ZOMBIE_H
#define ZOMBIE_H
#pragma once

namespace game_framework {
	class Zombie {

		public:

			Zombie() {
				_flag_car_1 = false;
				_flag_car_2 = false;
				_flag_car_3 = false;
				_flag_car_4 = false;
				_flag_car_5 = false;
				_flag = false;
				_flag1 = false;
				_flag2 = false;
			}
			~Zombie() {}
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnMove();								// ����
			void OnShow1();								// �N�ϧζK��e��
			void OnShow2();
			bool _flag_car_1;
			bool _flag_car_2;
			bool _flag_car_3;
			bool _flag_car_4;
			bool _flag_car_5;

			bool _flag;
			bool _flag1;
			bool _flag2;
			CMovingBitmap zombie[20];
		protected:
		private:


	};
}

#endif
