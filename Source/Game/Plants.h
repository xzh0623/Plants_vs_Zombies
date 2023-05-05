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
			vanish = false;
			bean_got = 0;
			clean = false;
			bean1_show = false;
			bean1_isoverlap = false;
			
			bean2_delay = 0;
			bean2_show=false;
			bean2_isoverlap = false;

			isflag = 0;
			delay1 = 0;
			bean1_delay = 0;
			for (int i = 0; i < 4; i++) turnToplant[i] = false;
		};
		~Plants(){}
		void OnInit();
		void OnShow(int index);
		//void OnLButtonDown();
		CMovingBitmap plants[10];
		bool twiceflag;
		int isflag;
		int delay1;
		bool flag_sun;
		bool IsShowBitmap;
		bool SetPosDone;
		bool turnToplant[4];
		bool vanish;
		int bean_got;//紆琌ゴ鞮
		int clean;
		//紆1把计
		int bean1_delay;
		bool bean1_show;
		bool bean1_isoverlap;
		//紆2把计
		int bean2_delay;
		bool bean2_show;
		bool bean2_isoverlap;

	protected:

	private:

	};

}
#endif
