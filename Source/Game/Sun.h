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
		void OnInit();  							// 遊戲的初值及圖形設定
		void OnMove();								// 移動
		void Onshow1();
		void OnShow2();								// 將圖形貼到畫面
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