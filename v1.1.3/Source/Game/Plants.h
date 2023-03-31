#ifndef PLANTS_H
#define PLANTS_H
#pragma once
namespace game_framework {
	class Plants {
	public:
		Plants() {
			twiceflag = false;
			isflag = 0;
			x = 0;
			y = 0;
		};
		~Plants(){}
		void OnInit();
		void OnShow(int index);
		//void OnLButtonDown();
		CMovingBitmap plants[4];
		bool twiceflag;
		int isflag;
		int x, y;
	protected:

	private:

	};

}
#endif
