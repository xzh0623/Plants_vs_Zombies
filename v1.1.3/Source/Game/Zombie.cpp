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
#include "Zombie.h"
namespace game_framework {
	

	void Zombie::OnInit()
	{
// 一般殭屍走路
		zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[0].SetTopLeft(1200, 400);
		zombie[0].SetAnimation(100, false);
// 一般殭屍吃
		zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
		zombie[1].SetAnimation(135, false);
// 一般殭屍休息
		zombie[2].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
		zombie[2].SetAnimation(135, false);
// 鐵桶殭屍休息
		zombie[3].LoadBitmapByString({ "resources/bucket_zom_relax_0.bmp","resources/bucket_zom_relax_1.bmp","resources/bucket_zom_relax_2.bmp","resources/bucket_zom_relax_3.bmp","resources/bucket_zom_relax_4.bmp","resources/bucket_zom_relax_5.bmp" }, RGB(255, 255, 255));
		zombie[3].SetAnimation(135, false);
// 三角錐殭屍休息
		zombie[4].LoadBitmapByString({ "resources/tri_zom_relax_0.bmp","resources/tri_zom_relax_1.bmp","resources/tri_zom_relax_2.bmp","resources/tri_zom_relax_3.bmp","resources/tri_zom_relax_4.bmp","resources/tri_zom_relax_5.bmp","resources/tri_zom_relax_6.bmp","resources/tri_zom_relax_7.bmp" }, RGB(255, 255, 255));
		zombie[4].SetAnimation(135, false);
// 鐵桶殭屍走路
		zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[5].SetTopLeft(1000, 300);
		zombie[5].SetAnimation(100, false);
// 掉頭
		zombie[6].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[6].SetTopLeft(230, 305);
		zombie[6].SetAnimation(135, true);
		zombie[6].ToggleAnimation();
//  太陽花
		zombie[7].LoadBitmapByString({ "resources/sunflower_0.bmp", "resources/sunflower_1.bmp", "resources/sunflower_2.bmp", "resources/sunflower_3.bmp", "resources/sunflower_4.bmp", "resources/sunflower_5.bmp", "resources/sunflower_6.bmp", "resources/sunflower_7.bmp", "resources/sunflower_8.bmp", "resources/sunflower_9.bmp", "resources/sunflower_10.bmp", "resources/sunflower_11.bmp", "resources/sunflower_12.bmp", "resources/sunflower_13.bmp", "resources/sunflower_14.bmp", "resources/sunflower_15.bmp", "resources/sunflower_16.bmp", "resources/sunflower_17.bmp" }, RGB(255, 255, 255));
		zombie[7].SetTopLeft(410, 470);
		zombie[7].SetAnimation(135, false);

/*    三角錐殭屍
	character.LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    三角錐殭屍吃東西
	character.LoadBitmapByString({ "resources/tri_zom_eat_0.bmp", "resources/tri_zom_eat_1.bmp", "resources/tri_zom_eat_2.bmp", "resources/tri_zom_eat_3.bmp", "resources/tri_zom_eat_4.bmp", "resources/tri_zom_eat_5.bmp", "resources/tri_zom_eat_6.bmp", "resources/tri_zom_eat_7.bmp", "resources/tri_zom_eat_8.bmp", "resources/tri_zom_eat_9.bmp", "resources/tri_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*     鐵桶殭屍吃東西
	character.LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*     沒頭殭屍
	character.LoadBitmapByString({ "resources/nohead_zom_0.bmp", "resources/nohead_zom_1.bmp", "resources/nohead_zom_2.bmp", "resources/nohead_zom_3.bmp", "resources/nohead_zom_4.bmp", "resources/nohead_zom_5.bmp", "resources/nohead_zom_6.bmp", "resources/nohead_zom_7.bmp", "resources/nohead_zom_8.bmp", "resources/nohead_zom_9.bmp", "resources/nohead_zom_10.bmp", "resources/nohead_zom_11.bmp", "resources/nohead_zom_12.bmp", "resources/nohead_zom_13.bmp", "resources/nohead_zom_14.bmp", "resources/nohead_zom_15.bmp", "resources/nohead_zom_16.bmp", "resources/nohead_zom_17.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*     沒頭殭屍吃東西
	character.LoadBitmapByString({ "resources/nohead_zom_eat_0.bmp", "resources/nohead_zom_eat_1.bmp", "resources/nohead_zom_eat_2.bmp", "resources/nohead_zom_eat_3.bmp", "resources/nohead_zom_eat_4.bmp", "resources/nohead_zom_eat_5.bmp", "resources/nohead_zom_eat_6.bmp", "resources/nohead_zom_eat_7.bmp", "resources/nohead_zom_eat_8.bmp", "resources/nohead_zom_eat_9.bmp", "resources/nohead_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    旗幟殭屍
	character.LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp"}, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    旗幟殭屍吃東西
	character.LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/

	/*    旗幟殭屍沒頭
	character.LoadBitmapByString({ "resources/flag_zom_nohead_0.bmp", "resources/flag_zom_nohead_1.bmp", "resources/flag_zom_nohead_2.bmp", "resources/flag_zom_nohead_3.bmp", "resources/flag_zom_nohead_4.bmp", "resources/flag_zom_nohead_5.bmp", "resources/flag_zom_nohead_6.bmp", "resources/flag_zom_nohead_7.bmp", "resources/flag_zom_nohead_8.bmp", "resources/flag_zom_nohead_9.bmp", "resources/flag_zom_nohead_10.bmp", "resources/flag_zom_nohead_11.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    旗幟殭屍沒頭吃東西
	character.LoadBitmapByString({ "resources/flag_zom_nohead_eat_0.bmp", "resources/flag_zom_nohead_eat_1.bmp", "resources/flag_zom_nohead_eat_2.bmp", "resources/flag_zom_nohead_eat_3.bmp", "resources/flag_zom_nohead_eat_4.bmp", "resources/flag_zom_nohead_eat_5.bmp", "resources/flag_zom_nohead_eat_6.bmp", "resources/flag_zom_nohead_eat_7.bmp", "resources/flag_zom_nohead_eat_8.bmp", "resources/flag_zom_nohead_eat_9.bmp", "resources/flag_zom_nohead_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*     殭屍倒下
	character.LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"}, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/
	}

// 殭屍移動code，定點吃東西
	void Zombie::OnMove()
	{
		if (!_flag)
		{
			zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
			if (CMovingBitmap::IsOverlap(zombie[7], zombie[0])) _flag = true;
		}
		if (_flag)
		{
			zombie[1].SetTopLeft(zombie[7].GetLeft(), zombie[0].GetTop());
		}

	}

	void Zombie::OnShow1() {
		for (int i = 2; i < 5; i++) {
			zombie[i].ShowBitmap();
		}
	}

	void Zombie::OnShow2() {
// 殭屍從走路換吃東西的動畫
		if ((!_flag)) {
			zombie[0].ShowBitmap();
		}
		else {
			zombie[1].ShowBitmap();
		}

// 殭屍被車輾過，殭屍消失並掉頭
		if (!_flag1)
		{
			zombie[5].ShowBitmap();
		}
		else
		{
			if (!(zombie[6].IsAnimationDone())) zombie[6].ShowBitmap();
		}
		
		
	}
}