#ifndef ZOMBIE_H
#define ZOMBIE_H
#pragma once

namespace game_framework {
	class Zombie {
		public:
			Zombie() {
				_flag1 = false;
				_flag = false;
			}
			~Zombie() {}
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnMove();								// ����
			void OnShow1();								// �N�ϧζK��e��
			void OnShow2();
			bool _flag1;
			bool _flag;
			CMovingBitmap zombie[8];
		protected:
		private:


	};
}

#endif
