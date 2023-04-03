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
#include "Plants.h"

namespace game_framework {
	void Plants::OnInit() {


//拖曳的太陽花
		plants[0].LoadBitmapByString({ "resources/sunflower_0.bmp", "resources/sunflower_1.bmp", "resources/sunflower_2.bmp", "resources/sunflower_3.bmp", "resources/sunflower_4.bmp", "resources/sunflower_5.bmp", "resources/sunflower_6.bmp", "resources/sunflower_7.bmp", "resources/sunflower_8.bmp", "resources/sunflower_9.bmp", "resources/sunflower_10.bmp", "resources/sunflower_11.bmp", "resources/sunflower_12.bmp", "resources/sunflower_13.bmp", "resources/sunflower_14.bmp", "resources/sunflower_15.bmp", "resources/sunflower_16.bmp", "resources/sunflower_17.bmp" }, RGB(255, 255, 255));
		plants[0].SetAnimation(135, false);


//種植的太陽花
		plants[4].LoadBitmapByString({ "resources/sunflower_0.bmp", "resources/sunflower_1.bmp", "resources/sunflower_2.bmp", "resources/sunflower_3.bmp", "resources/sunflower_4.bmp", "resources/sunflower_5.bmp", "resources/sunflower_6.bmp", "resources/sunflower_7.bmp", "resources/sunflower_8.bmp", "resources/sunflower_9.bmp", "resources/sunflower_10.bmp", "resources/sunflower_11.bmp", "resources/sunflower_12.bmp", "resources/sunflower_13.bmp", "resources/sunflower_14.bmp", "resources/sunflower_15.bmp", "resources/sunflower_16.bmp", "resources/sunflower_17.bmp" }, RGB(255, 255, 255));
		plants[4].SetAnimation(135, false);

//太陽花(要產太陽前)
		plants[5].LoadBitmapByString({ "resources/sunflower_getsun_0.bmp", "resources/sunflower_getsun_1.bmp", "resources/sunflower_getsun_2.bmp", "resources/sunflower_getsun_3.bmp", "resources/sunflower_getsun_4.bmp", "resources/sunflower_getsun_5.bmp", "resources/sunflower_getsun_6.bmp", "resources/sunflower_getsun_7.bmp", "resources/sunflower_getsun_8.bmp", "resources/sunflower_getsun_9.bmp", "resources/sunflower_getsun_10.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_12.bmp", "resources/sunflower_getsun_13.bmp", "resources/sunflower_getsun_14.bmp", "resources/sunflower_getsun_15.bmp", "resources/sunflower_getsun_16.bmp", "resources/sunflower_getsun_17.bmp" }, RGB(255, 255, 255));
		plants[5].SetAnimation(135, false);

//太陽花的太陽
		plants[6].LoadBitmapByString({ "resources/sun_0.bmp", "resources/sun_1.bmp", "resources/sun_2.bmp", "resources/sun_3.bmp", "resources/sun_4.bmp", "resources/sun_5.bmp", "resources/sun_6.bmp", "resources/sun_7.bmp", "resources/sun_8.bmp", "resources/sun_9.bmp", "resources/sun_10.bmp", "resources/sun_11.bmp", "resources/sun_12.bmp", "resources/sun_13.bmp", "resources/sun_14.bmp", "resources/sun_15.bmp", "resources/sun_16.bmp", "resources/sun_17.bmp", "resources/sun_18.bmp" , "resources/sun_19.bmp", "resources/sun_20.bmp" , "resources/sun_21.bmp" }, RGB(255, 255, 255));
		plants[6].SetAnimation(100, false);
//豌豆
		plants[1].LoadBitmapByString({ "resources/bean_0.bmp", "resources/bean_1.bmp", "resources/bean_2.bmp", "resources/bean_3.bmp", "resources/bean_4.bmp", "resources/bean_5.bmp", "resources/bean_6.bmp", "resources/bean_7.bmp", "resources/bean_8.bmp", "resources/bean_9.bmp", "resources/bean_10.bmp", "resources/bean_11.bmp", "resources/bean_12.bmp" },RGB(255, 255, 255));
		plants[1].SetAnimation(125, false);

//二連發豌豆
		plants[3].LoadBitmapByString({ "resources/double_bean_0.bmp", "resources/double_bean_1.bmp", "resources/double_bean_2.bmp", "resources/double_bean_3.bmp", "resources/double_bean_4.bmp", "resources/double_bean_5.bmp", "resources/double_bean_6.bmp", "resources/double_bean_7.bmp", "resources/double_bean_8.bmp", "resources/double_bean_9.bmp", "resources/double_bean_10.bmp" ,"resources/double_bean_11.bmp","resources/double_bean_12.bmp","resources/double_bean_13.bmp","resources/double_bean_14.bmp" }, RGB(255, 255, 255));
		plants[3].SetAnimation(135, false);

//堅果牆(未傷)
		plants[2].LoadBitmapByString({ "resources/nut_one_0.bmp", "resources/nut_one_1.bmp", "resources/nut_one_2.bmp", "resources/nut_one_3.bmp", "resources/nut_one_4.bmp", "resources/nut_one_5.bmp", "resources/nut_one_6.bmp", "resources/nut_one_7.bmp", "resources/nut_one_8.bmp", "resources/nut_one_9.bmp", "resources/nut_one_10.bmp", "resources/nut_one_11.bmp", "resources/nut_one_12.bmp", "resources/nut_one_13.bmp", "resources/nut_one_14.bmp", "resources/nut_one_15.bmp" }, RGB(0, 0, 0));
		plants[2].SetAnimation(135, false);



		/*     堅果牆(小傷)
		character.LoadBitmapByString({ "resources/nut_two_0.bmp", "resources/nut_two_1.bmp", "resources/nut_two_2.bmp", "resources/nut_two_3.bmp", "resources/nut_two_4.bmp", "resources/nut_two_5.bmp", "resources/nut_two_6.bmp", "resources/nut_two_7.bmp", "resources/nut_two_8.bmp", "resources/nut_two_9.bmp", "resources/nut_two_10.bmp"}, RGB(255, 255, 255));
		character.SetTopLeft(150, 265);
		character.SetAnimation(135, false);
		*/


		/*     堅果牆(大傷)
		character.LoadBitmapByString({ "resources/nut_three_0.bmp", "resources/nut_three_1.bmp", "resources/nut_three_2.bmp", "resources/nut_three_3.bmp", "resources/nut_three_4.bmp", "resources/nut_three_5.bmp", "resources/nut_three_6.bmp", "resources/nut_three_7.bmp", "resources/nut_three_8.bmp", "resources/nut_three_9.bmp", "resources/nut_three_10.bmp", "resources/nut_three_11.bmp", "resources/nut_three_12.bmp", "resources/nut_three_13.bmp", "resources/nut_three_14.bmp" }, RGB(255, 255, 255));
		character.SetTopLeft(150, 265);
		character.SetAnimation(135, false);
		*/
	}
	void Plants::OnShow(int index) {

		plants[index].ShowBitmap();
	}
	
}