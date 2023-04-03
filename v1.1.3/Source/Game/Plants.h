#ifndef PLANTS_H
#define PLANTS_H
#pragma once
namespace game_framework {
	class Plants {
	public:
		Plants() {
			twiceflag = false;
			flag_sun = true;
			IsShowBitmap = false;
			SetPosDone = false;
			isflag = 0;
			delay1 = 0;
			for (int i = 0; i < 4; i++) turnToplant[i] = false;
		};
		~Plants(){}
		void OnInit();
		void OnShow(int index);
		//void OnLButtonDown();
		CMovingBitmap plants[8];
		bool twiceflag;
		int isflag;
		int delay1;
		bool flag_sun;
		bool IsShowBitmap;
		bool SetPosDone;
		bool turnToplant[4];
	protected:

	private:

	};

}
#endif
