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
			void OnInit();  								// 遊戲的初值及圖形設定
			void OnMove();								// 移動
			void OnShow1();								// 將圖形貼到畫面
			void OnShow2();
			bool _flag1;
			bool _flag;
			CMovingBitmap zombie[8];
		protected:
		private:


	};
}

#endif
