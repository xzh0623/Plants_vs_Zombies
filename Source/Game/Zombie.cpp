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
//  鞮ǐ隔
		zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[0].SetTopLeft(1200, 420);
		zombie[0].SetAnimation(100, false);

//  鞮
		zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
		zombie[1].SetAnimation(135, false);

//  鞮ヰ
		zombie[2].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
		zombie[2].SetAnimation(135, false);

//  臟表鞮ヰ
		zombie[3].LoadBitmapByString({ "resources/bucket_zom_relax_0.bmp","resources/bucket_zom_relax_1.bmp","resources/bucket_zom_relax_2.bmp","resources/bucket_zom_relax_3.bmp","resources/bucket_zom_relax_4.bmp","resources/bucket_zom_relax_5.bmp" }, RGB(255, 255, 255));
		zombie[3].SetAnimation(135, false);

//  à繞鞮ヰ
		zombie[4].LoadBitmapByString({ "resources/tri_zom_relax_0.bmp","resources/tri_zom_relax_1.bmp","resources/tri_zom_relax_2.bmp","resources/tri_zom_relax_3.bmp","resources/tri_zom_relax_4.bmp","resources/tri_zom_relax_5.bmp","resources/tri_zom_relax_6.bmp","resources/tri_zom_relax_7.bmp" }, RGB(255, 255, 255));
		zombie[4].SetAnimation(135, false);

//  臟表鞮ǐ隔
		zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[5].SetTopLeft(1000, 320);
		zombie[5].SetAnimation(100, false);

//  臟表鞮狥﹁
		zombie[9].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[9].SetAnimation(135, false);

//  à繞鞮
		zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
		zombie[10].SetTopLeft(1200, 230);
		zombie[10].SetAnimation(135, false);

//  à繞鞮狥﹁
		zombie[11].LoadBitmapByString({ "resources/tri_zom_eat_0.bmp", "resources/tri_zom_eat_1.bmp", "resources/tri_zom_eat_2.bmp", "resources/tri_zom_eat_3.bmp", "resources/tri_zom_eat_4.bmp", "resources/tri_zom_eat_5.bmp", "resources/tri_zom_eat_6.bmp", "resources/tri_zom_eat_7.bmp", "resources/tri_zom_eat_8.bmp", "resources/tri_zom_eat_9.bmp", "resources/tri_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[11].SetAnimation(135, false);

//  奔繷()
		zombie[6].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp"}, RGB(255, 255, 255));
		zombie[6].SetAnimation(80, true);
		zombie[6].ToggleAnimation();

//  奔繷(臟表)
		zombie[7].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp"}, RGB(255, 255, 255));
		zombie[7].SetAnimation(80, true);
		zombie[7].ToggleAnimation();

//  奔繷(à繞)
		zombie[8].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" , "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[8].SetAnimation(80, true);
		zombie[8].ToggleAnimation();

//  鞮()
		zombie[13].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[13].SetAnimation(90, true);
		zombie[13].ToggleAnimation();

//  鞮(臟表)
		zombie[14].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[14].SetAnimation(90, true);
		zombie[14].ToggleAnimation();

    /* ⊿繷鞮()
	zombie[12].LoadBitmapByString({ "resources/nohead_zom_0.bmp", "resources/nohead_zom_1.bmp", "resources/nohead_zom_2.bmp", "resources/nohead_zom_3.bmp", "resources/nohead_zom_4.bmp", "resources/nohead_zom_5.bmp", "resources/nohead_zom_6.bmp", "resources/nohead_zom_7.bmp", "resources/nohead_zom_8.bmp", "resources/nohead_zom_9.bmp", "resources/nohead_zom_10.bmp", "resources/nohead_zom_11.bmp", "resources/nohead_zom_12.bmp", "resources/nohead_zom_13.bmp", "resources/nohead_zom_14.bmp", "resources/nohead_zom_15.bmp", "resources/nohead_zom_16.bmp", "resources/nohead_zom_17.bmp" }, RGB(255, 255, 255));
	zombie[12].SetAnimation(135, false);
    */


	/*     ⊿繷鞮狥﹁
	character.LoadBitmapByString({ "resources/nohead_zom_eat_0.bmp", "resources/nohead_zom_eat_1.bmp", "resources/nohead_zom_eat_2.bmp", "resources/nohead_zom_eat_3.bmp", "resources/nohead_zom_eat_4.bmp", "resources/nohead_zom_eat_5.bmp", "resources/nohead_zom_eat_6.bmp", "resources/nohead_zom_eat_7.bmp", "resources/nohead_zom_eat_8.bmp", "resources/nohead_zom_eat_9.bmp", "resources/nohead_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    篨糾鞮
	character.LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp"}, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    篨糾鞮狥﹁
	character.LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/

	/*    篨糾鞮⊿繷
	character.LoadBitmapByString({ "resources/flag_zom_nohead_0.bmp", "resources/flag_zom_nohead_1.bmp", "resources/flag_zom_nohead_2.bmp", "resources/flag_zom_nohead_3.bmp", "resources/flag_zom_nohead_4.bmp", "resources/flag_zom_nohead_5.bmp", "resources/flag_zom_nohead_6.bmp", "resources/flag_zom_nohead_7.bmp", "resources/flag_zom_nohead_8.bmp", "resources/flag_zom_nohead_9.bmp", "resources/flag_zom_nohead_10.bmp", "resources/flag_zom_nohead_11.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    篨糾鞮⊿繷狥﹁
	character.LoadBitmapByString({ "resources/flag_zom_nohead_eat_0.bmp", "resources/flag_zom_nohead_eat_1.bmp", "resources/flag_zom_nohead_eat_2.bmp", "resources/flag_zom_nohead_eat_3.bmp", "resources/flag_zom_nohead_eat_4.bmp", "resources/flag_zom_nohead_eat_5.bmp", "resources/flag_zom_nohead_eat_6.bmp", "resources/flag_zom_nohead_eat_7.bmp", "resources/flag_zom_nohead_eat_8.bmp", "resources/flag_zom_nohead_eat_9.bmp", "resources/flag_zom_nohead_eat_10.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	
	

//い紆
		zombiegotbean[0].LoadBitmapByString({ "resources/fly_beans_1.bmp" }, RGB(255, 255, 255));

	}


	void Zombie::OnMove()
	{
		
		for (int i = 0; i < 5000; i++)
		{
			for (int j = 0; j < 5000; j++) {}
		}
// 鞮传篈
		if ((!_flag) && (!_flag_car_4) && hit_count_normal < 42)
		{
			zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
		}
		else if (_flag && hit_count_normal < 42)
		{
			zombie[1].SetTopLeft(zombie[0].GetLeft()-80, zombie[0].GetTop());
		}
		else if (_flag_car_4 || hit_count_normal >= 42)
		{
			if ((!_flag_car_4) && hit_count_normal >= 42)
			{
				zombie[13].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());	
			}
			zombie[6].SetTopLeft(zombie[0].GetLeft() +20 , zombie[0].GetTop() - 25);

			if(zombie[6].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
		}
		
//臟表鞮传篈
		if ((!_flag1) && (!_flag_car_3) && hit_count_bucket < 42)
		{
			zombie[5].SetTopLeft(zombie[5].GetLeft() - 1, zombie[5].GetTop());
		}
		else if (_flag1 && hit_count_bucket < 42)
		{
			zombie[9].SetTopLeft(zombie[5].GetLeft() - 80, zombie[5].GetTop());
		}
		else if (_flag_car_3 || hit_count_bucket >= 42)
		{
			if ((!_flag_car_4) && hit_count_bucket >= 42)
			{
				zombie[14].SetTopLeft(zombie[5].GetLeft() - 25, zombie[5].GetTop());
			}
			zombie[7].SetTopLeft(zombie[5].GetLeft()+20, zombie[5].GetTop()-25);

			if (zombie[7].IsAnimationDone())zombie[5].SetTopLeft(1500, 1500);
		}


//à繞鞮传篈
		if ((!_flag2) && (!_flag_car_2))
		{
			zombie[10].SetTopLeft(zombie[10].GetLeft() - 1, zombie[10].GetTop());
		}
		else if (_flag2)
		{
			zombie[11].SetTopLeft(zombie[10].GetLeft() - 80, zombie[10].GetTop());
		}
		else if (_flag_car_2)
		{
			zombie[8].SetTopLeft(zombie[10].GetLeft(), zombie[10].GetTop());
			if (zombie[8].IsAnimationDone())zombie[10].SetTopLeft(1500, 1500);
		}


	}

	void Zombie::OnShow1() {
		for (int i = 2; i < 5; i++) {
			zombie[i].ShowBitmap();
		}
	}

	void Zombie::OnShow2() {

// 鞮ǐ隔传狥﹁笆礶窱ó奔繷
		if ((!_flag) && (!_flag_car_4) && hit_count_normal < 42) {
			zombie[0].ShowBitmap();
		}
		else if (_flag && hit_count_normal < 42)
		{
			zombie[1].ShowBitmap();
		}
		else if ((_flag_car_4 || hit_count_normal >= 42))
		{
			if ((!_flag_car_4) && hit_count_normal >= 42)
			{
				zombie[13].ShowBitmap();
			}
			zombie[6].ShowBitmap();
		}
	 


// 臟表鞮ǐ隔传狥﹁笆礶窱ó奔繷
		if ((!_flag1) && (!_flag_car_3) && hit_count_bucket < 42) {
			zombie[5].ShowBitmap();
		}
		else if (_flag1 && hit_count_bucket < 42)
		{
			zombie[9].ShowBitmap();
		}
		else if (_flag_car_3 || hit_count_bucket >= 42)
		{
			if ((!_flag_car_3) && hit_count_bucket >= 42)
			{
				zombie[14].ShowBitmap();
			}
			zombie[7].ShowBitmap();
		}


// à繞鞮ǐ隔传狥﹁笆礶窱ó奔繷
		if ((!_flag2) && (!_flag_car_2)) {
			zombie[10].ShowBitmap();
		}
		else if (_flag2)
		{
			zombie[11].ShowBitmap();
		}
		else if (_flag_car_2 && zombie[8].GetFrameIndexOfBitmap() < 12)
		{
			zombie[8].ShowBitmap();
		}

		

		
	}
}