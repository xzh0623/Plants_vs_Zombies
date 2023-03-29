#ifndef PLANTSCARD_H
#define PLANTSCARD_H
#pragma once
namespace game_framework {
	class PlantsCard {
	public:
		PlantsCard(){
			for (int i = 0; i < 4; i++) {
				count[i] = 0;
				iscount[i] = false;
			}
			score = 50;
		};
		~PlantsCard(){}
		void OnInit();  							// �C������Ȥιϧγ]�w
		void OnMove(int index, int scorelimit);								// ����
		void OnShow();								// �N�ϧζK��e��
		void OnLButtonDown(int index, int scorelimit);
		CMovingBitmap plantscard[4];
		int count[4];
		bool iscount[4];
		int score;
	protected:

	private:

	};
}
#endif