#ifndef ZOMBIE_H
#define ZOMBIE_H
#pragma once

namespace game_framework {
	class Zombie {
		public:
			Zombie() {
				_flag = false;
				_flag1 = false;
				_flag2 = false;
				_flag_car_2 = false;
				_flag_car_3 = false;
				_flag_car_4 = false;
				ZombieGotBean1 = false;
			}
			~Zombie() {}
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnMove();								// ����
			void OnShow1();								// �N�ϧζK��e��
			void OnShow2();
			
			bool _flag;
			bool _flag1;
			bool _flag2;
			bool _flag_car_2;
			bool _flag_car_3;
			bool _flag_car_4;

			bool ZombieGotBean1;
			CMovingBitmap zombie[20];
			CMovingBitmap zombiegotbean[2];
		protected:
		private:
			

	};
}

#endif
