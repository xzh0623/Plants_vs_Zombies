#ifndef ZOMBIE_H
#define ZOMBIE_H
#pragma once

namespace game_framework {
	class Zombie {
	public:
		Zombie() {
			for (int i = 0; i < 10; i++)
			{
				flag_zom_touch_plant[i] = false;
				_flag_car_0[i] = false;
				_flag_car_1[i] = false;
				_flag_car_2[i] = false;
				_flag_car_3[i] = false;
				_flag_car_4[i] = false;
			}
			for (int j = 0; j < 10; j++)
			{
				hit_count_normal[j] = 0;
				hit_count_bucket[j] = 0;
				hit_count_tri[j] = 0;
				hit_count_flag[j] = 0;
			}
			wave2 = false;
			wave3 = false;
			wave4 = false;
			win1 = false;
			lose1 = false;
			win2 = false;
			lose2 = false;
			win3 = false;
			lose3 = false;
			win4 = false;
			lose4 = false;
			win5 = false;
			lose5 = false;
			level = 0;
			count_last_wave = 0;
			count_gameover = 0;
			ZombieGotBean1 = false;
		}
		~Zombie() {}
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnMove();								// 移動
		void OnShow1();								// 將圖形貼到畫面
		void OnShow2();

		bool flag_zom_touch_plant[10];
		bool _flag_car_0[10];
		bool _flag_car_1[10];
		bool _flag_car_2[10];
		bool _flag_car_3[10];
		bool _flag_car_4[10];
		bool wave2;
		bool wave3;
		bool wave4;

		bool win1;
		bool lose1;
		bool win2;
		bool lose2;
		bool win3;
		bool lose3;
		bool win4;
		bool lose4;
		bool win5;
		bool lose5;

		int level;
		int count_gameover;
		int hit_count_normal[10];
		int hit_count_bucket[10];
		int hit_count_tri[10];
		int hit_count_flag[10];
		int count_last_wave;
		bool ZombieGotBean1;
		CMovingBitmap zombie[100];
		CMovingBitmap zombiegotbean[2];
	protected:
	private:


	};
}

#endif
