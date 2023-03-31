#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include <string>
#include <random>
#include <iostream>
#include <ctime> 
#include <Windows.h>
#include "Sun.h"
std::random_device rd;
std::mt19937 gen(rd());
namespace game_framework {
	void Sun::OnInit() {
		//   太陽
		sun[0].LoadBitmapByString({ "resources/sun_0.bmp", "resources/sun_1.bmp", "resources/sun_2.bmp", "resources/sun_3.bmp", "resources/sun_4.bmp", "resources/sun_5.bmp", "resources/sun_6.bmp", "resources/sun_7.bmp", "resources/sun_8.bmp", "resources/sun_9.bmp", "resources/sun_10.bmp", "resources/sun_11.bmp", "resources/sun_12.bmp", "resources/sun_13.bmp", "resources/sun_14.bmp", "resources/sun_15.bmp", "resources/sun_16.bmp", "resources/sun_17.bmp", "resources/sun_18.bmp" , "resources/sun_19.bmp", "resources/sun_20.bmp" , "resources/sun_21.bmp" }, RGB(255, 255, 255));
		sun[0].SetTopLeft(random(250, 900), 0);
		sun[0].SetAnimation(100, false);
		//    太陽花(要產太陽前)
		sun[1].LoadBitmapByString({ "resources/sunflower_getsun_0.bmp", "resources/sunflower_getsun_1.bmp", "resources/sunflower_getsun_2.bmp", "resources/sunflower_getsun_3.bmp", "resources/sunflower_getsun_4.bmp", "resources/sunflower_getsun_5.bmp", "resources/sunflower_getsun_6.bmp", "resources/sunflower_getsun_7.bmp", "resources/sunflower_getsun_8.bmp", "resources/sunflower_getsun_9.bmp", "resources/sunflower_getsun_10.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_12.bmp", "resources/sunflower_getsun_13.bmp", "resources/sunflower_getsun_14.bmp", "resources/sunflower_getsun_15.bmp", "resources/sunflower_getsun_16.bmp", "resources/sunflower_getsun_17.bmp" }, RGB(255, 255, 255));
		sun[1].SetTopLeft(410, 470);
		sun[1].SetAnimation(135, false);

		//   花的太陽
		sun[2].LoadBitmapByString({ "resources/sun_0.bmp", "resources/sun_1.bmp", "resources/sun_2.bmp", "resources/sun_3.bmp", "resources/sun_4.bmp", "resources/sun_5.bmp", "resources/sun_6.bmp", "resources/sun_7.bmp", "resources/sun_8.bmp", "resources/sun_9.bmp", "resources/sun_10.bmp", "resources/sun_11.bmp", "resources/sun_12.bmp", "resources/sun_13.bmp", "resources/sun_14.bmp", "resources/sun_15.bmp", "resources/sun_16.bmp", "resources/sun_17.bmp", "resources/sun_18.bmp" , "resources/sun_19.bmp", "resources/sun_20.bmp" , "resources/sun_21.bmp" }, RGB(255, 255, 255));
		sun[2].SetAnimation(100, false);
	}

	void Sun::Onshow1() {
		sun[1].ShowBitmap();
		sun[2].SetTopLeft(sun[1].GetLeft() + 5, sun[1].GetTop() + 7);
	}

	void Sun::OnShow2() {
//寫滑鼠點擊消失的flag，我相信庠姊你可以的!!!
		if (!flag2) {
			sun[0].ShowBitmap();
		}
	}

	void Sun::OnShow3() {
//庠姊幫我寫程式，使滑鼠點擊讓flag_sun變false		
		if (flag_sun) sun[2].ShowBitmap();

	}

	void Sun::OnMove() {
// 天空的太陽掉落
		if ((sun[0].GetTop() < 500)) {
			sun[0].SetTopLeft(sun[0].GetLeft(), sun[0].GetTop() + 1);
		}
		if (flag2) {
			delay += 1;
			if (delay > 300) {
				flag2 = false;
				delay = 0;
				sun[0].SetTopLeft(random(250, 900), 0);
			}
		}
	}

//  隨機生成數字
	int Sun::random(int low, int high){
		std::uniform_int_distribution<> dist(low, high);
		return dist(gen);
	}
}