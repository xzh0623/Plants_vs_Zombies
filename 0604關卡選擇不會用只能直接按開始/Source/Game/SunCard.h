#ifndef SUNCARD_H
#define SUNCARD_H
#pragma once
namespace game_framework {
	class SunCard {
	public:
		SunCard() {
		
		};
		~SunCard() {}
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnShow();
		CMovingBitmap suncard[1];
	protected:

	private:

	};

}
#endif