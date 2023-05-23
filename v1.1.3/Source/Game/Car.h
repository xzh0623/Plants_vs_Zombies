#ifndef CAR_H
#define CAR_H
#pragma once
namespace game_framework {
	class Car {
	public:
		Car() {
		}
		~Car() {}
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		//void OnMove();								// 移動
		void OnShow();								// 將圖形貼到畫面
		CMovingBitmap car[5];
	

	protected:
	private:

	};
}


#endif