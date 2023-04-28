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
				_flag3 = false;
				_flag_car_0 = false;
				_flag_car_1 = false;
				_flag_car_2 = false;
				_flag_car_3 = false;
				_flag_car_4 = false;
				ZombieGotBean1 = false;
				hit_count_normal = 0;
				hit_count_normal_1 = 0;
				hit_count_bucket = 0;
				hit_count_tri = 0;
			}
			~Zombie() {}
			void OnInit();  								// 遊戲的初值及圖形設定
			void OnMove();								// 移動
			void OnShow1();								// 將圖形貼到畫面
			void OnShow2();
			
			bool _flag;
			bool _flag1;
			bool _flag2;
			bool _flag3;
			bool _flag_car_0;
			bool _flag_car_1;
			bool _flag_car_2;
			bool _flag_car_3;
			bool _flag_car_4;
			int hit_count_normal;
			int hit_count_normal_1;
			int hit_count_bucket;
			int hit_count_tri;

			bool ZombieGotBean1;
			CMovingBitmap zombie[50];
			CMovingBitmap zombiegotbean[2];
		protected:
		private:
			

	};
}

#endif
