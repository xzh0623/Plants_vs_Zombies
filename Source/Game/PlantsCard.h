#ifndef PLANTSCARD_H
#define PLANTSCARD_H
#pragma once
namespace game_framework {
	class PlantsCard{
	public:
		PlantsCard(){
			for (int i = 0; i < 4; i++) {
				count[i] = 0;
				iscount[i] = false;
				scorecost[i] = false;
			}
			score = 50;
		};
		~PlantsCard(){}
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  							// 遊戲的初值及圖形設定
		void OnMove(int index, int scorelimit);								// 移動
		void OnShow();								// 將圖形貼到畫面
		void OnLButtonDown(int index, int scorelimit);
		CMovingBitmap plantscard[4];
		int count[4];
		bool iscount[4];
		int score;
		bool scorecost[4];
	protected:

	private:

	};
}
#endif