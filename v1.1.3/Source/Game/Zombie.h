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
			Zombie(bool flag,bool flag1);
			~Zombie() {}
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnMove();								// ����
			void OnShow();								// �N�ϧζK��e��
			bool _flag1;
			bool _flag;
		protected:
		private:
			CMovingBitmap one[8];
	};
}

#endif
