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

	void Zombie::OnBeginState() {
		for (int i = 0; i < 10; i++)
		{
			flag_zom_touch_plant[i] = false;
			_flag_car_0[i] = false;
			_flag_car_1[i] = false;
			_flag_car_2[i] = false;
			_flag_car_3[i] = false;
			_flag_car_4[i] = false;
		}
		for (int j = 0; j < 10; j++)
		{
			hit_count_normal[j] = 0;
			hit_count_bucket[j] = 0;
			hit_count_tri[j] = 0;
			hit_count_flag[j] = 0;
		}
		wave2 = false;
		wave3 = false;
		wave4 = false;
		win1 = false;
		lose1 = false;
		win3 = false;
		lose3 = false;
		win4 = false;
		lose4 = false;
		win2 = false;
		lose2 = false;
		win5 = false;
		lose5 = false;
		count_last_wave = 0;
		count_gameover = 0;
		ZombieGotBean1 = false;
		

	}
	void Zombie::OnInit()
	{
		//中彈
		zombiegotbean[0].LoadBitmapByString({ "resources/fly_beans_1.bmp" }, RGB(255, 255, 255));

		//  一般殭屍休息
		zombie[2].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
		zombie[2].SetAnimation(135, false);

		//  一般殭屍2休息
		zombie[18].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
		zombie[18].SetAnimation(135, false);

		//  一般殭屍3休息
		zombie[32].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
		zombie[32].SetAnimation(135, false);

		//  鐵桶殭屍休息
		zombie[3].LoadBitmapByString({ "resources/bucket_zom_relax_0.bmp","resources/bucket_zom_relax_1.bmp","resources/bucket_zom_relax_2.bmp","resources/bucket_zom_relax_3.bmp","resources/bucket_zom_relax_4.bmp","resources/bucket_zom_relax_5.bmp" }, RGB(255, 255, 255));
		zombie[3].SetAnimation(135, false);

		//  鐵桶殭屍2休息
		zombie[26].LoadBitmapByString({ "resources/bucket_zom_relax_0.bmp","resources/bucket_zom_relax_1.bmp","resources/bucket_zom_relax_2.bmp","resources/bucket_zom_relax_3.bmp","resources/bucket_zom_relax_4.bmp","resources/bucket_zom_relax_5.bmp" }, RGB(255, 255, 255));
		zombie[26].SetAnimation(135, false);

		//  三角錐殭屍休息
		zombie[4].LoadBitmapByString({ "resources/tri_zom_relax_0.bmp","resources/tri_zom_relax_1.bmp","resources/tri_zom_relax_2.bmp","resources/tri_zom_relax_3.bmp","resources/tri_zom_relax_4.bmp","resources/tri_zom_relax_5.bmp","resources/tri_zom_relax_6.bmp","resources/tri_zom_relax_7.bmp" }, RGB(255, 255, 255));
		zombie[4].SetAnimation(135, false);

		//  三角錐殭屍2休息
		zombie[27].LoadBitmapByString({ "resources/tri_zom_relax_0.bmp","resources/tri_zom_relax_1.bmp","resources/tri_zom_relax_2.bmp","resources/tri_zom_relax_3.bmp","resources/tri_zom_relax_4.bmp","resources/tri_zom_relax_5.bmp","resources/tri_zom_relax_6.bmp","resources/tri_zom_relax_7.bmp" }, RGB(255, 255, 255));
		zombie[27].SetAnimation(135, false);

		//殭屍吃掉你的腦子了
		zombie[56].LoadBitmapByString({ "resources/gameover.bmp" }, RGB(255, 255, 255));
		zombie[56].SetTopLeft(200, 10);

		//最後一波
		zombie[57].LoadBitmapByString({ "resources/last_wave.bmp" }, RGB(0, 0, 0));
		zombie[57].SetTopLeft(425, 280);

		//殭屍進度條
		zombie[59].LoadBitmapByString({ "resources/game_bar_0.bmp","resources/game_bar_1.bmp","resources/game_bar_2.bmp","resources/game_bar_3.bmp" }, RGB(128, 128, 128));
		zombie[59].SetTopLeft(400, 10);

		
		
		if (level == 0)
		{
			//  一般殭屍走路
			zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[0].SetTopLeft(1600, 230);
			zombie[0].SetAnimation(100, false);
			//2200

			//  一般殭屍吃
			zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
			zombie[1].SetAnimation(135, false);

			//  掉頭(一般)
			zombie[41].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[41].SetAnimation(80, true);
			zombie[41].ToggleAnimation();

			//  殭屍倒下(一般)
			zombie[42].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[42].SetAnimation(90, true);
			zombie[42].ToggleAnimation();


			//    旗幟殭屍
			zombie[35].LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp" }, RGB(255, 255, 255));
			zombie[35].SetTopLeft(1200, 230);
			zombie[35].SetAnimation(135, false);

			//   旗幟殭屍吃東西
			zombie[37].LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[37].SetAnimation(135, false);

			//  掉頭(旗幟殭屍)
			zombie[43].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[43].SetAnimation(80, true);
			zombie[43].ToggleAnimation();

			//  殭屍倒下(旗幟殭屍)
			zombie[44].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[44].SetAnimation(90, true);
			zombie[44].ToggleAnimation();

			//以下沒出現
			//以下沒出現
			//以下沒出現

			//  一般殭屍2走路
			zombie[15].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[15].SetTopLeft(1200, 1111);
			zombie[15].SetAnimation(100, false);

			//  一般殭屍3走路
			zombie[20].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[20].SetTopLeft(1800, 1111);
			zombie[20].SetAnimation(100, false);
			//2300

			//  鐵桶殭屍走路
			zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[5].SetTopLeft(1100, 1111);
			zombie[5].SetAnimation(100, false);
			//2000

			//  鐵桶殭屍2走路
			zombie[30].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[30].SetTopLeft(1100, 1111);
			zombie[30].SetAnimation(100, false);

			//  三角錐殭屍走路
			zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[10].SetTopLeft(1300, 1111);
			zombie[10].SetAnimation(135, false);

			//  三角錐殭屍2走路
			zombie[25].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[25].SetTopLeft(1300, 1111);
			zombie[25].SetAnimation(135, false);
			//2400

		}
		else if (level == 1)
		{
			//  一般殭屍走路
			zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[0].SetTopLeft(2100, 230);
			zombie[0].SetAnimation(100, false);
			//2200

			//  一般殭屍吃
			zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
			zombie[1].SetAnimation(135, false);

			//  掉頭(一般)
			zombie[46].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[46].SetAnimation(80, true);
			zombie[46].ToggleAnimation();

			//  殭屍倒下(一般)
			zombie[47].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[47].SetAnimation(90, true);
			zombie[47].ToggleAnimation();

			//  鐵桶殭屍走路
			zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[5].SetTopLeft(1700, 320);
			zombie[5].SetAnimation(100, false);

			//  鐵桶殭屍吃東西
			zombie[9].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[9].SetAnimation(135, false);

			//  掉頭(鐵桶)
			zombie[51].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[51].SetAnimation(80, true);
			zombie[51].ToggleAnimation();

			//  殭屍倒下(鐵桶)
			zombie[52].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[52].SetAnimation(90, true);
			zombie[52].ToggleAnimation();

			//    旗幟殭屍
			zombie[35].LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp" }, RGB(255, 255, 255));
			zombie[35].SetTopLeft(1200, 230);
			zombie[35].SetAnimation(135, false);

			//   旗幟殭屍吃東西
			zombie[37].LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[37].SetAnimation(135, false);

			//  掉頭(旗幟殭屍)
			zombie[48].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[48].SetAnimation(80, true);
			zombie[48].ToggleAnimation();

			//  殭屍倒下(旗幟殭屍)
			zombie[49].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[49].SetAnimation(90, true);
			zombie[49].ToggleAnimation();

			//以下沒出現
			//以下沒出現
			//以下沒出現

			//  一般殭屍2走路
			zombie[15].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[15].SetTopLeft(1200, 1111);
			zombie[15].SetAnimation(100, false);

			//  一般殭屍3走路
			zombie[20].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[20].SetTopLeft(1800, 1111);
			zombie[20].SetAnimation(100, false);
			//2300

			//  鐵桶殭屍2走路
			zombie[30].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[30].SetTopLeft(1100, 1111);
			zombie[30].SetAnimation(100, false);

			//  三角錐殭屍走路
			zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[10].SetTopLeft(1300, 1111);
			zombie[10].SetAnimation(135, false);

			//  三角錐殭屍2走路
			zombie[25].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[25].SetTopLeft(1300, 1111);
			zombie[25].SetAnimation(135, false);
			//2400

		}
		else if (level == 2)
		{
		//  一般殭屍走路
		zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[0].SetTopLeft(2200, 120);
		zombie[0].SetAnimation(100, false);
		//2200

		//  一般殭屍吃
		zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
		zombie[1].SetAnimation(135, false);

		//  掉頭(一般)
		zombie[61].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[61].SetAnimation(80, true);
		zombie[61].ToggleAnimation();

		//  殭屍倒下(一般)
		zombie[62].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[62].SetAnimation(90, true);
		zombie[62].ToggleAnimation();

		//  鐵桶殭屍走路
		zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[5].SetTopLeft(1800, 230);
		zombie[5].SetAnimation(100, false);

		//  鐵桶殭屍吃東西
		zombie[9].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[9].SetAnimation(135, false);

		//  掉頭(鐵桶)
		zombie[63].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[63].SetAnimation(80, true);
		zombie[63].ToggleAnimation();

		//  殭屍倒下(鐵桶)
		zombie[64].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[64].SetAnimation(90, true);
		zombie[64].ToggleAnimation();

		//    旗幟殭屍
		zombie[35].LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp" }, RGB(255, 255, 255));
		zombie[35].SetTopLeft(1200, 320);
		zombie[35].SetAnimation(135, false);

		//   旗幟殭屍吃東西
		zombie[37].LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[37].SetAnimation(135, false);

		//  掉頭(旗幟殭屍)
		zombie[66].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[66].SetAnimation(80, true);
		zombie[66].ToggleAnimation();

		//  殭屍倒下(旗幟殭屍)
		zombie[67].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[67].SetAnimation(90, true);
		zombie[67].ToggleAnimation();

		//以下沒出現
		//以下沒出現
		//以下沒出現

		//  一般殭屍2走路
		zombie[15].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[15].SetTopLeft(1200, 1111);
		zombie[15].SetAnimation(100, false);

		//  一般殭屍3走路
		zombie[20].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[20].SetTopLeft(1800, 1111);
		zombie[20].SetAnimation(100, false);
		//2300

		//  鐵桶殭屍2走路
		zombie[30].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[30].SetTopLeft(1100, 1111);
		zombie[30].SetAnimation(100, false);

		//  三角錐殭屍走路
		zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
		zombie[10].SetTopLeft(1300, 1111);
		zombie[10].SetAnimation(135, false);

		//  三角錐殭屍2走路
		zombie[25].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
		zombie[25].SetTopLeft(1300, 1111);
		zombie[25].SetAnimation(135, false);
		//2400
		}
		else if (level == 3)
		{
		//  一般殭屍走路
		zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[0].SetTopLeft(2200, 320);
		zombie[0].SetAnimation(100, false);
		//2200

		//  一般殭屍吃
		zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
		zombie[1].SetAnimation(135, false);

		//  掉頭(一般)
		zombie[71].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[71].SetAnimation(80, true);
		zombie[71].ToggleAnimation();

		//  殭屍倒下(一般)
		zombie[72].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[72].SetAnimation(90, true);
		zombie[72].ToggleAnimation();

		//  鐵桶殭屍走路
		zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[5].SetTopLeft(1700, 230);
		zombie[5].SetAnimation(100, false);

		//  鐵桶殭屍吃東西
		zombie[9].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[9].SetAnimation(135, false);

		//  掉頭(鐵桶)
		zombie[73].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[73].SetAnimation(80, true);
		zombie[73].ToggleAnimation();

		//  殭屍倒下(鐵桶)
		zombie[74].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[74].SetAnimation(90, true);
		zombie[74].ToggleAnimation();

		//    旗幟殭屍
		zombie[35].LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp" }, RGB(255, 255, 255));
		zombie[35].SetTopLeft(1200, 120);
		zombie[35].SetAnimation(135, false);

		//   旗幟殭屍吃東西
		zombie[37].LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
		zombie[37].SetAnimation(135, false);

		//  掉頭(旗幟殭屍)
		zombie[76].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
		zombie[76].SetAnimation(80, true);
		zombie[76].ToggleAnimation();

		//  殭屍倒下(旗幟殭屍)
		zombie[77].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
		zombie[77].SetAnimation(90, true);
		zombie[77].ToggleAnimation();

		//以下沒出現
		//以下沒出現
		//以下沒出現

		//  一般殭屍2走路
		zombie[15].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[15].SetTopLeft(1200, 1111);
		zombie[15].SetAnimation(100, false);

		//  一般殭屍3走路
		zombie[20].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
		zombie[20].SetTopLeft(1800, 1111);
		zombie[20].SetAnimation(100, false);
		//2300

		//  鐵桶殭屍2走路
		zombie[30].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
		zombie[30].SetTopLeft(1100, 1111);
		zombie[30].SetAnimation(100, false);

		//  三角錐殭屍走路
		zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
		zombie[10].SetTopLeft(1300, 1111);
		zombie[10].SetAnimation(135, false);

		//  三角錐殭屍2走路
		zombie[25].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
		zombie[25].SetTopLeft(1300, 1111);
		zombie[25].SetAnimation(135, false);
		//2400
		}
		else if (level == 4)
		{
			//  一般殭屍走路
			zombie[0].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[0].SetTopLeft(2200, 420);
			zombie[0].SetAnimation(100, false);
			//2200

			//  一般殭屍2走路
			zombie[15].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[15].SetTopLeft(1200, 30);
			zombie[15].SetAnimation(100, false);

			//  一般殭屍3走路
			zombie[20].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
			zombie[20].SetTopLeft(2300, 120);
			zombie[20].SetAnimation(100, false);
			//2300

			//  一般殭屍吃
			zombie[1].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
			zombie[1].SetAnimation(135, false);

			//  一般殭屍2吃
			zombie[17].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
			zombie[17].SetAnimation(135, false);

			//  一般殭屍3吃
			zombie[22].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));
			zombie[22].SetAnimation(135, false);

			//  鐵桶殭屍走路
			zombie[5].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[5].SetTopLeft(1500, 320);
			zombie[5].SetAnimation(100, false);
			//2000

			//  鐵桶殭屍2走路
			zombie[30].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
			zombie[30].SetTopLeft(1100, 420);
			zombie[30].SetAnimation(100, false);

			//  鐵桶殭屍吃東西
			zombie[9].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[9].SetAnimation(135, false);

			//  鐵桶殭屍2吃東西
			zombie[33].LoadBitmapByString({ "resources/bucket_zom_eat_0.bmp", "resources/bucket_zom_eat_1.bmp", "resources/bucket_zom_eat_2.bmp", "resources/bucket_zom_eat_3.bmp", "resources/bucket_zom_eat_4.bmp", "resources/bucket_zom_eat_5.bmp", "resources/bucket_zom_eat_6.bmp", "resources/bucket_zom_eat_7.bmp", "resources/bucket_zom_eat_8.bmp", "resources/bucket_zom_eat_9.bmp", "resources/bucket_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[33].SetAnimation(135, false);

			//  三角錐殭屍走路
			zombie[10].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[10].SetTopLeft(1300, 230);
			zombie[10].SetAnimation(135, false);

			//  三角錐殭屍2走路
			zombie[25].LoadBitmapByString({ "resources/tri_zom_0.bmp", "resources/tri_zom_1.bmp", "resources/tri_zom_2.bmp", "resources/tri_zom_3.bmp", "resources/tri_zom_4.bmp", "resources/tri_zom_5.bmp", "resources/tri_zom_6.bmp", "resources/tri_zom_7.bmp", "resources/tri_zom_8.bmp", "resources/tri_zom_9.bmp", "resources/tri_zom_10.bmp", "resources/tri_zom_11.bmp", "resources/tri_zom_12.bmp", "resources/tri_zom_13.bmp", "resources/tri_zom_14.bmp", "resources/tri_zom_15.bmp", "resources/tri_zom_16.bmp", "resources/tri_zom_17.bmp", "resources/tri_zom_18.bmp", "resources/tri_zom_19.bmp", "resources/tri_zom_20.bmp" }, RGB(255, 255, 255));
			zombie[25].SetTopLeft(1800, 320);
			zombie[25].SetAnimation(135, false);
			//2400

			//  三角錐殭屍吃東西
			zombie[11].LoadBitmapByString({ "resources/tri_zom_eat_0.bmp", "resources/tri_zom_eat_1.bmp", "resources/tri_zom_eat_2.bmp", "resources/tri_zom_eat_3.bmp", "resources/tri_zom_eat_4.bmp", "resources/tri_zom_eat_5.bmp", "resources/tri_zom_eat_6.bmp", "resources/tri_zom_eat_7.bmp", "resources/tri_zom_eat_8.bmp", "resources/tri_zom_eat_9.bmp", "resources/tri_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[11].SetAnimation(135, false);

			//  三角錐殭屍2吃東西
			zombie[28].LoadBitmapByString({ "resources/tri_zom_eat_0.bmp", "resources/tri_zom_eat_1.bmp", "resources/tri_zom_eat_2.bmp", "resources/tri_zom_eat_3.bmp", "resources/tri_zom_eat_4.bmp", "resources/tri_zom_eat_5.bmp", "resources/tri_zom_eat_6.bmp", "resources/tri_zom_eat_7.bmp", "resources/tri_zom_eat_8.bmp", "resources/tri_zom_eat_9.bmp", "resources/tri_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[28].SetAnimation(135, false);

			//  掉頭(一般)
			zombie[6].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[6].SetAnimation(80, true);
			zombie[6].ToggleAnimation();

			//  掉頭(一般2)
			zombie[21].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[21].SetAnimation(80, true);
			zombie[21].ToggleAnimation();

			//  掉頭(一般3)
			zombie[23].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[23].SetAnimation(80, true);
			zombie[23].ToggleAnimation();

			//  掉頭(鐵桶)
			zombie[7].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[7].SetAnimation(80, true);
			zombie[7].ToggleAnimation();

			//  掉頭(鐵桶2)
			zombie[34].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[34].SetAnimation(80, true);
			zombie[34].ToggleAnimation();

			//  掉頭(三角錐)
			zombie[8].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[8].SetAnimation(80, true);
			zombie[8].ToggleAnimation();

			//  掉頭(三角錐2)
			zombie[29].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[29].SetAnimation(80, true);
			zombie[29].ToggleAnimation();

			//  殭屍倒下(一般)
			zombie[13].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[13].SetAnimation(90, true);
			zombie[13].ToggleAnimation();

			//  殭屍倒下(一般2)
			zombie[19].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[19].SetAnimation(90, true);
			zombie[19].ToggleAnimation();

			//  殭屍倒下(一般3)
			zombie[24].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[24].SetAnimation(90, true);
			zombie[24].ToggleAnimation();

			//  殭屍倒下(鐵桶)
			zombie[14].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[14].SetAnimation(90, true);
			zombie[14].ToggleAnimation();

			//  殭屍倒下(鐵桶)
			zombie[36].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[36].SetAnimation(90, true);
			zombie[36].ToggleAnimation();

			//  殭屍倒下(三角)
			zombie[16].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[16].SetAnimation(90, true);
			zombie[16].ToggleAnimation();

			//  殭屍倒下(三角2)
			zombie[31].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[31].SetAnimation(90, true);
			zombie[31].ToggleAnimation();


			//    旗幟殭屍
			zombie[35].LoadBitmapByString({ "resources/flag_zom_0.bmp", "resources/flag_zom_1.bmp", "resources/flag_zom_2.bmp", "resources/flag_zom_3.bmp", "resources/flag_zom_4.bmp", "resources/flag_zom_5.bmp", "resources/flag_zom_6.bmp", "resources/flag_zom_7.bmp", "resources/flag_zom_8.bmp", "resources/flag_zom_9.bmp", "resources/flag_zom_10.bmp" ,"resources/flag_zom_11.bmp" }, RGB(255, 255, 255));
			zombie[35].SetTopLeft(1200, 120);
			zombie[35].SetAnimation(135, false);

			//   旗幟殭屍吃東西
			zombie[37].LoadBitmapByString({ "resources/flag_zom_eat_0.bmp", "resources/flag_zom_eat_1.bmp", "resources/flag_zom_eat_2.bmp", "resources/flag_zom_eat_3.bmp", "resources/flag_zom_eat_4.bmp", "resources/flag_zom_eat_5.bmp", "resources/flag_zom_eat_6.bmp", "resources/flag_zom_eat_7.bmp", "resources/flag_zom_eat_8.bmp", "resources/flag_zom_eat_9.bmp", "resources/flag_zom_eat_10.bmp" }, RGB(255, 255, 255));
			zombie[37].SetAnimation(135, false);

			//  掉頭(旗幟殭屍)
			zombie[38].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
			zombie[38].SetAnimation(80, true);
			zombie[38].ToggleAnimation();

			//  殭屍倒下(旗幟殭屍)
			zombie[39].LoadBitmapByString({ "resources/falldown_0.bmp", "resources/falldown_1.bmp", "resources/falldown_2.bmp", "resources/falldown_3.bmp", "resources/falldown_4.bmp", "resources/falldown_5.bmp", "resources/falldown_6.bmp", "resources/falldown_7.bmp", "resources/falldown_8.bmp", "resources/falldown_9.bmp"/*, "resources/falldown_9.bmp"*/ }, RGB(255, 255, 255));
			zombie[39].SetAnimation(90, true);
			zombie[39].ToggleAnimation();
		}
		

		

		
	}


	void Zombie::OnMove()
	{

		for (int i = 0; i < 5000; i++)
		{
			for (int j = 0; j < 5000; j++) {}
		}

		if (!win1 && level == 1)
		{
			// 一般殭屍換狀態
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_2[0]) && hit_count_normal[0] < 3)
			{
				zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
			{
				zombie[1].SetTopLeft(zombie[0].GetLeft() - 75, zombie[0].GetTop());
			}
			else if (_flag_car_2[0] || hit_count_normal[0] >= 3)
			{
				if ((!_flag_car_2[0]) && hit_count_normal[0] >= 3)
				{
					zombie[42].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());
				}
				zombie[41].SetTopLeft(zombie[0].GetLeft() + 20, zombie[0].GetTop() - 25);

				if (zombie[41].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
			}

			//旗幟殭屍換狀態
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_2[1]) && hit_count_flag[0] < 4)
				{
					if (zombie[35].GetLeft() > 100) zombie[35].SetTopLeft(zombie[35].GetLeft() - 1, zombie[35].GetTop());
					if (zombie[35].GetLeft() == 100 && zombie[35].GetTop() != 250) zombie[35].SetTopLeft(zombie[35].GetLeft(), zombie[35].GetTop() + 5);
					if (zombie[35].GetLeft() != 80 && zombie[35].GetTop() == 250) zombie[35].SetTopLeft(zombie[35].GetLeft() - 5, zombie[35].GetTop());
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_2[1])
				{
					zombie[37].SetTopLeft(zombie[35].GetLeft() - 80, zombie[35].GetTop());
				}
				else if (_flag_car_2[1] || hit_count_flag[0] >= 4)
				{
					if ((!_flag_car_2[1]) && hit_count_flag[0] >= 4)
					{
						zombie[44].SetTopLeft(zombie[35].GetLeft() - 35, zombie[35].GetTop());
					}
					zombie[43].SetTopLeft(zombie[35].GetLeft() + 20, zombie[35].GetTop() - 35);

					if (zombie[43].IsAnimationDone())zombie[35].SetTopLeft(1500, 1500);
				}
			}
		}
		else if (!win2 && level == 2)
		{
			// 一般殭屍換狀態
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_2[0]) && hit_count_normal[0] < 3)
			{
				zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
			{
				zombie[1].SetTopLeft(zombie[0].GetLeft() - 75, zombie[0].GetTop());
			}
			else if (_flag_car_2[0] || hit_count_normal[0] >= 3)
			{
				if ((!_flag_car_2[0]) && hit_count_normal[0] >= 3)
				{
					zombie[47].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());
				}
				zombie[46].SetTopLeft(zombie[0].GetLeft() + 20, zombie[0].GetTop() - 25);

				if (zombie[46].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
			}

			//鐵桶殭屍換狀態
			if ((!flag_zom_touch_plant[1]) && (!_flag_car_3[0]) && hit_count_bucket[0] < 6)
			{
				zombie[5].SetTopLeft(zombie[5].GetLeft() - 1, zombie[5].GetTop());
			}
			else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
			{
				zombie[9].SetTopLeft(zombie[5].GetLeft() - 75, zombie[5].GetTop());
			}
			else if (_flag_car_3[0] || hit_count_bucket[0] >= 6)
			{
				if ((!_flag_car_3[0]) && hit_count_bucket[0] >= 6)
				{
					zombie[52].SetTopLeft(zombie[5].GetLeft() - 25, zombie[5].GetTop());
				}
				zombie[51].SetTopLeft(zombie[5].GetLeft() + 20, zombie[5].GetTop() - 25);

				if (zombie[51].IsAnimationDone())zombie[5].SetTopLeft(1500, 1500);
			}
			

			//旗幟殭屍換狀態
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_2[1]) && hit_count_flag[0] < 4)
				{
					if (zombie[35].GetLeft() > 100) zombie[35].SetTopLeft(zombie[35].GetLeft() - 1, zombie[35].GetTop());
					if (zombie[35].GetLeft() == 100 && zombie[35].GetTop() != 250) zombie[35].SetTopLeft(zombie[35].GetLeft(), zombie[35].GetTop() + 5);
					if (zombie[35].GetLeft() != 80 && zombie[35].GetTop() == 250) zombie[35].SetTopLeft(zombie[35].GetLeft() - 5, zombie[35].GetTop());
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_2[1])
				{
					zombie[37].SetTopLeft(zombie[35].GetLeft() - 80, zombie[35].GetTop());
				}
				else if (_flag_car_2[1] || hit_count_flag[0] >= 4)
				{
					if ((!_flag_car_2[1]) && hit_count_flag[0] >= 4)
					{
						zombie[49].SetTopLeft(zombie[35].GetLeft() - 35, zombie[35].GetTop());
					}
					zombie[48].SetTopLeft(zombie[35].GetLeft() + 20, zombie[35].GetTop() - 35);

					if (zombie[48].IsAnimationDone())zombie[35].SetTopLeft(1500, 1500);
				}
			}
		}

		else if (!win3 && level == 3)
		{
		// 一般殭屍換狀態
		if ((!flag_zom_touch_plant[0]) && (!_flag_car_1[0]) && hit_count_normal[0] < 3)
		{
			zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
		}
		else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
		{
			zombie[1].SetTopLeft(zombie[0].GetLeft() - 75, zombie[0].GetTop());
		}
		else if (_flag_car_1[0] || hit_count_normal[0] >= 3)
		{
			if ((!_flag_car_1[0]) && hit_count_normal[0] >= 3)
			{
				zombie[62].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());
			}
			zombie[61].SetTopLeft(zombie[0].GetLeft() + 20, zombie[0].GetTop() - 25);

			if (zombie[61].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
		}

		//鐵桶殭屍換狀態
		if ((!flag_zom_touch_plant[1]) && (!_flag_car_2[0]) && hit_count_bucket[0] < 6)
		{
			zombie[5].SetTopLeft(zombie[5].GetLeft() - 1, zombie[5].GetTop());
		}
		else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
		{
			zombie[9].SetTopLeft(zombie[5].GetLeft() - 75, zombie[5].GetTop());
		}
		else if (_flag_car_2[0] || hit_count_bucket[0] >= 6)
		{
			if ((!_flag_car_2[0]) && hit_count_bucket[0] >= 6)
			{
				zombie[64].SetTopLeft(zombie[5].GetLeft() - 25, zombie[5].GetTop());
			}
			zombie[63].SetTopLeft(zombie[5].GetLeft() + 20, zombie[5].GetTop() - 25);

			if (zombie[63].IsAnimationDone())zombie[5].SetTopLeft(1500, 1500);
		}


		//旗幟殭屍換狀態
		if (wave4)
		{
			if ((!flag_zom_touch_plant[7]) && (!_flag_car_3[1]) && hit_count_flag[0] < 4)
			{
				if (zombie[35].GetLeft() > 100) zombie[35].SetTopLeft(zombie[35].GetLeft() - 1, zombie[35].GetTop());
				if (zombie[35].GetLeft() == 100 && zombie[35].GetTop() != 250) zombie[35].SetTopLeft(zombie[35].GetLeft(), zombie[35].GetTop() + 5);
				if (zombie[35].GetLeft() != 80 && zombie[35].GetTop() == 250) zombie[35].SetTopLeft(zombie[35].GetLeft() - 5, zombie[35].GetTop());
			}
			else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_3[1])
			{
				zombie[37].SetTopLeft(zombie[35].GetLeft() - 80, zombie[35].GetTop());
			}
			else if (_flag_car_3[1] || hit_count_flag[0] >= 4)
			{
				if ((!_flag_car_3[1]) && hit_count_flag[0] >= 4)
				{
					zombie[67].SetTopLeft(zombie[35].GetLeft() - 35, zombie[35].GetTop());
				}
				zombie[66].SetTopLeft(zombie[35].GetLeft() + 20, zombie[35].GetTop() - 35);

				if (zombie[66].IsAnimationDone())zombie[35].SetTopLeft(1500, 1500);
			}
		}
		}
		else if (!win4 && level == 4)
		{
		// 一般殭屍換狀態
		if ((!flag_zom_touch_plant[0]) && (!_flag_car_3[0]) && hit_count_normal[0] < 3)
		{
			zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
		}
		else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
		{
			zombie[1].SetTopLeft(zombie[0].GetLeft() - 75, zombie[0].GetTop());
		}
		else if (_flag_car_3[0] || hit_count_normal[0] >= 3)
		{
			if ((!_flag_car_3[0]) && hit_count_normal[0] >= 3)
			{
				zombie[72].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());
			}
			zombie[71].SetTopLeft(zombie[0].GetLeft() + 20, zombie[0].GetTop() - 25);

			if (zombie[71].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
		}

		//鐵桶殭屍換狀態
		if ((!flag_zom_touch_plant[1]) && (!_flag_car_2[0]) && hit_count_bucket[0] < 6)
		{
			zombie[5].SetTopLeft(zombie[5].GetLeft() - 1, zombie[5].GetTop());
		}
		else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
		{
			zombie[9].SetTopLeft(zombie[5].GetLeft() - 75, zombie[5].GetTop());
		}
		else if (_flag_car_2[0] || hit_count_bucket[0] >= 6)
		{
			if ((!_flag_car_2[0]) && hit_count_bucket[0] >= 6)
			{
				zombie[74].SetTopLeft(zombie[5].GetLeft() - 25, zombie[5].GetTop());
			}
			zombie[73].SetTopLeft(zombie[5].GetLeft() + 20, zombie[5].GetTop() - 25);

			if (zombie[73].IsAnimationDone())zombie[5].SetTopLeft(1500, 1500);
		}


		//旗幟殭屍換狀態
		if (wave4)
		{
			if ((!flag_zom_touch_plant[7]) && (!_flag_car_1[1]) && hit_count_flag[0] < 4)
			{
				if (zombie[35].GetLeft() > 100) zombie[35].SetTopLeft(zombie[35].GetLeft() - 1, zombie[35].GetTop());
				if (zombie[35].GetLeft() == 100 && zombie[35].GetTop() != 250) zombie[35].SetTopLeft(zombie[35].GetLeft(), zombie[35].GetTop() + 5);
				if (zombie[35].GetLeft() != 80 && zombie[35].GetTop() == 250) zombie[35].SetTopLeft(zombie[35].GetLeft() - 5, zombie[35].GetTop());
			}
			else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_1[1])
			{
				zombie[37].SetTopLeft(zombie[35].GetLeft() - 80, zombie[35].GetTop());
			}
			else if (_flag_car_1[1] || hit_count_flag[0] >= 4)
			{
				if ((!_flag_car_1[1]) && hit_count_flag[0] >= 4)
				{
					zombie[77].SetTopLeft(zombie[35].GetLeft() - 35, zombie[35].GetTop());
				}
				zombie[76].SetTopLeft(zombie[35].GetLeft() + 20, zombie[35].GetTop() - 35);

				if (zombie[76].IsAnimationDone())zombie[35].SetTopLeft(1500, 1500);
			}
		}
		}
		else if (!win5 && level == 5)
		{
			// 一般殭屍換狀態
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_4[0]) && hit_count_normal[0] < 7)
			{
				zombie[0].SetTopLeft(zombie[0].GetLeft() - 1, zombie[0].GetTop());
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 7)
			{
				zombie[1].SetTopLeft(zombie[0].GetLeft() - 75, zombie[0].GetTop());
			}
			else if (_flag_car_4[0] || hit_count_normal[0] >= 7)
			{
				if ((!_flag_car_4[0]) && hit_count_normal[0] >= 7)
				{
					zombie[13].SetTopLeft(zombie[0].GetLeft() - 25, zombie[0].GetTop());
				}
				zombie[6].SetTopLeft(zombie[0].GetLeft() + 20, zombie[0].GetTop() - 25);

				if (zombie[6].IsAnimationDone())zombie[0].SetTopLeft(1500, 1500);
			}

			// 一般殭屍2換狀態
			if (wave2)
			{
				if ((!flag_zom_touch_plant[3]) && (!_flag_car_0[0]) && hit_count_normal[1] < 7)
				{
					zombie[15].SetTopLeft(zombie[15].GetLeft() - 1, zombie[15].GetTop());
				}
				else if (flag_zom_touch_plant[3] && hit_count_normal[1] < 7)
				{
					zombie[17].SetTopLeft(zombie[15].GetLeft() - 75, zombie[15].GetTop());
				}
				else if (_flag_car_0[0] || hit_count_normal[1] >= 7)
				{
					if ((!_flag_car_0[0]) && hit_count_normal[1] >= 7)
					{
						zombie[19].SetTopLeft(zombie[15].GetLeft() - 25, zombie[15].GetTop());
					}
					zombie[21].SetTopLeft(zombie[15].GetLeft() + 20, zombie[15].GetTop() - 25);

					if (zombie[21].IsAnimationDone())zombie[15].SetTopLeft(1500, 1500);
				}
			}


			// 一般殭屍3換狀態
			if ((!flag_zom_touch_plant[4]) && (!_flag_car_1[0]) && hit_count_normal[2] < 7)
			{
				zombie[20].SetTopLeft(zombie[20].GetLeft() - 1, zombie[20].GetTop());
			}
			else if (flag_zom_touch_plant[4] && hit_count_normal[2] < 7)
			{
				zombie[22].SetTopLeft(zombie[20].GetLeft() - 75, zombie[20].GetTop());
			}
			else if (_flag_car_1[0] || hit_count_normal[2] >= 7)
			{
				if ((!_flag_car_1[0]) && hit_count_normal[2] >= 7)
				{
					zombie[24].SetTopLeft(zombie[20].GetLeft() - 25, zombie[20].GetTop());
				}
				zombie[23].SetTopLeft(zombie[20].GetLeft() + 20, zombie[20].GetTop() - 25);

				if (zombie[23].IsAnimationDone())zombie[20].SetTopLeft(1500, 1500);
			}


			//鐵桶殭屍換狀態
			if (wave3)
			{
				if ((!flag_zom_touch_plant[1]) && (!_flag_car_3[0]) && hit_count_bucket[0] < 11)
				{
					zombie[5].SetTopLeft(zombie[5].GetLeft() - 1, zombie[5].GetTop());
				}
				else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 11)
				{
					zombie[9].SetTopLeft(zombie[5].GetLeft() - 75, zombie[5].GetTop());
				}
				else if (_flag_car_3[0] || hit_count_bucket[0] >= 11)
				{
					if ((!_flag_car_3[0]) && hit_count_bucket[0] >= 11)
					{
						zombie[14].SetTopLeft(zombie[5].GetLeft() - 25, zombie[5].GetTop());
					}
					zombie[7].SetTopLeft(zombie[5].GetLeft() + 20, zombie[5].GetTop() - 25);

					if (zombie[7].IsAnimationDone())zombie[5].SetTopLeft(1500, 1500);
				}
			}


			//鐵桶殭屍2換狀態
			if (wave2)
			{
				if ((!flag_zom_touch_plant[6]) && (!_flag_car_4[1]) && hit_count_bucket[1] < 11)
				{
					if (zombie[30].GetLeft() > 80) zombie[30].SetTopLeft(zombie[30].GetLeft() - 1, zombie[30].GetTop());
					if (zombie[30].GetLeft() == 80 && zombie[30].GetTop() != 250) zombie[30].SetTopLeft(zombie[30].GetLeft(), zombie[30].GetTop() - 5);
				}
				else if (flag_zom_touch_plant[6] && hit_count_bucket[1] < 11)
				{
					zombie[33].SetTopLeft(zombie[30].GetLeft() - 75, zombie[30].GetTop());
				}
				else if (_flag_car_4[1] || hit_count_bucket[1] >= 11)
				{
					if ((!_flag_car_4[1]) && hit_count_bucket[1] >= 11)
					{
						zombie[36].SetTopLeft(zombie[30].GetLeft() - 25, zombie[30].GetTop());
					}
					zombie[34].SetTopLeft(zombie[30].GetLeft() + 20, zombie[30].GetTop() - 25);

					if (zombie[34].IsAnimationDone())zombie[30].SetTopLeft(1500, 1500);
				}
			}


			//三角錐殭屍換狀態
			if (wave2)
			{
				if ((!flag_zom_touch_plant[2]) && (!_flag_car_2[0]) && hit_count_tri[0] < 9)
				{
					zombie[10].SetTopLeft(zombie[10].GetLeft() - 1, zombie[10].GetTop());
				}
				else if (flag_zom_touch_plant[2] && hit_count_tri[0] < 9)
				{
					zombie[11].SetTopLeft(zombie[10].GetLeft() - 80, zombie[10].GetTop());
				}
				else if (_flag_car_2[0] || hit_count_tri[0] >= 9)
				{
					if ((!_flag_car_2[0]) && hit_count_tri[0] >= 9)
					{
						zombie[16].SetTopLeft(zombie[10].GetLeft() - 25, zombie[10].GetTop());
					}
					zombie[8].SetTopLeft(zombie[10].GetLeft(), zombie[10].GetTop());
					if (zombie[8].IsAnimationDone())zombie[10].SetTopLeft(1500, 1500);
				}
			}

			//三角錐殭屍2換狀態
			if (wave3)
			{
				if ((!flag_zom_touch_plant[5]) && (!_flag_car_3[1]) && hit_count_tri[1] < 9)
				{
					zombie[25].SetTopLeft(zombie[25].GetLeft() - 1, zombie[25].GetTop());
				}
				else if (flag_zom_touch_plant[5] && hit_count_tri[1] < 9 && !_flag_car_3[1])
				{
					zombie[28].SetTopLeft(zombie[25].GetLeft() - 80, zombie[25].GetTop());
				}
				else if (_flag_car_3[1] || hit_count_tri[1] >= 9)
				{
					if ((!_flag_car_3[1]) && hit_count_tri[1] >= 9)
					{
						zombie[31].SetTopLeft(zombie[25].GetLeft() - 25, zombie[25].GetTop());
					}
					zombie[29].SetTopLeft(zombie[25].GetLeft() + 20, zombie[25].GetTop() - 25);

					if (zombie[29].IsAnimationDone())zombie[25].SetTopLeft(1500, 1500);
				}
			}

			//旗幟殭屍換狀態
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_1[1]) && hit_count_flag[0] < 9)
				{
					if (zombie[35].GetLeft() > 100) zombie[35].SetTopLeft(zombie[35].GetLeft() - 1, zombie[35].GetTop());
					if (zombie[35].GetLeft() == 100 && zombie[35].GetTop() != 250) zombie[35].SetTopLeft(zombie[35].GetLeft(), zombie[35].GetTop() + 5);
					if (zombie[35].GetLeft() != 80 && zombie[35].GetTop() == 250) zombie[35].SetTopLeft(zombie[35].GetLeft() - 5, zombie[35].GetTop());
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 9 && !_flag_car_1[1])
				{
					zombie[37].SetTopLeft(zombie[35].GetLeft() - 80, zombie[35].GetTop());
				}
				else if (_flag_car_1[1] || hit_count_flag[0] >= 9)
				{
					if ((!_flag_car_1[1]) && hit_count_flag[0] >= 9)
					{
						zombie[39].SetTopLeft(zombie[35].GetLeft() - 35, zombie[35].GetTop());
					}
					zombie[38].SetTopLeft(zombie[35].GetLeft() + 20, zombie[35].GetTop() - 35);

					if (zombie[38].IsAnimationDone())zombie[35].SetTopLeft(1500, 1500);
				}
			}
		}
		
		
	}

	void Zombie::OnShow1() {
			for (int i = 2; i < 5; i++) 
			{
				zombie[i].ShowBitmap();
			}
			zombie[18].ShowBitmap();
			zombie[26].ShowBitmap();
			zombie[27].ShowBitmap();
			zombie[32].ShowBitmap();
		
		
	}

	void Zombie::OnShow2() {
		
		if (!win1 && level == 1)
		{
			if (zombie[41].IsAnimationDone())
			{
				zombie[59].SetFrameIndexOfBitmap(3);
				count_last_wave += 1;
				if (count_last_wave < 30 || (count_last_wave > 60 && count_last_wave < 90) || (count_last_wave > 120 && count_last_wave < 150)) zombie[57].ShowBitmap();
				wave4 = true;
			}
			else
			{
				zombie[59].SetFrameIndexOfBitmap(0);
			}
			zombie[59].ShowBitmap();


			// 遊戲獲勝
			if (zombie[43].IsAnimationDone())
			{
				win1 = true;
				wave2 = false;
				wave3 = false;
				wave4 = false;
			}

			// 遊戲敗北
			for (int i = 0; i < 36; i += 5)
			{
				if (zombie[i].GetLeft() == 80 && zombie[i].GetTop() == 250)
				{
					count_gameover += 1;
					zombie[56].ShowBitmap();
					CAudio::Instance()->Stop(0);
					if (count_gameover > 90)lose1 = true;
				}


			}

			// 一般殭屍走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_2[0]) && hit_count_normal[0] < 3) {
				zombie[0].ShowBitmap();
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
			{
				zombie[1].ShowBitmap();
			}
			else if ((_flag_car_2[0] || hit_count_normal[0] >= 3))
			{
				if ((!_flag_car_2[0]) && hit_count_normal[0] >= 3)
				{
					zombie[42].ShowBitmap();
				}
				zombie[41].ShowBitmap();
			}

			// 旗幟殭屍走路換吃東西的動畫，碰到車掉頭
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_2[1]) && hit_count_flag[0] < 4) {
					zombie[35].ShowBitmap();
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_2[1])
				{
					zombie[37].ShowBitmap();
				}
				else if (_flag_car_2[1] || hit_count_flag[0] >= 4)
				{
					if ((!_flag_car_2[1]) && hit_count_flag[0] >= 4)
					{
						zombie[44].ShowBitmap();
					}
					zombie[43].ShowBitmap();
				}

			}
		}
		else if (!win2 && level == 2)
		{
			if (zombie[46].IsAnimationDone() && zombie[51].IsAnimationDone())
			{
				zombie[59].SetFrameIndexOfBitmap(3);
				count_last_wave += 1;
				if (count_last_wave < 30 || (count_last_wave > 60 && count_last_wave < 90) || (count_last_wave > 120 && count_last_wave < 150)) zombie[57].ShowBitmap();
				wave4 = true;
			}
			else
			{
				zombie[59].SetFrameIndexOfBitmap(0);
			}
			zombie[59].ShowBitmap();


			// 遊戲獲勝
			if (zombie[48].IsAnimationDone())
			{
				win2 = true;
				wave2 = false;
				wave3 = false;
				wave4 = false;
			}

			// 遊戲敗北
			for (int i = 0; i < 36; i += 5)
			{
				if (zombie[i].GetLeft() == 80 && zombie[i].GetTop() == 250)
				{
					//CAudio::Instance()->Play(2, true);
					count_gameover += 1;
					zombie[56].ShowBitmap();
					CAudio::Instance()->Stop(0);
					if (count_gameover > 90)lose2 = true;
					
					
				}

			}

			// 一般殭屍走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_2[0]) && hit_count_normal[0] < 3) {
				zombie[0].ShowBitmap();
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
			{
				zombie[1].ShowBitmap();
			}
			else if ((_flag_car_2[0] || hit_count_normal[0] >= 3))
			{
				if ((!_flag_car_2[0]) && hit_count_normal[0] >= 3)
				{
					zombie[47].ShowBitmap();
				}
				zombie[46].ShowBitmap();
			}

			// 鐵桶殭屍走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[1]) && (!_flag_car_3[0]) && hit_count_bucket[0] < 6)
			{
				zombie[5].ShowBitmap();
			}
			else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
			{
				zombie[9].ShowBitmap();
			}
			else if (_flag_car_3[0] || hit_count_bucket[0] >= 6)
			{
				if ((!_flag_car_3[0]) && hit_count_bucket[0] >= 6)
				{
					zombie[52].ShowBitmap();
				}
				zombie[51].ShowBitmap();
			}

			// 旗幟殭屍走路換吃東西的動畫，碰到車掉頭
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_2[1]) && hit_count_flag[0] < 4) {
					zombie[35].ShowBitmap();
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_2[1])
				{
					zombie[37].ShowBitmap();
				}
				else if (_flag_car_2[1] || hit_count_flag[0] >= 4)
				{
					if ((!_flag_car_2[1]) && hit_count_flag[0] >= 4)
					{
						zombie[49].ShowBitmap();
					}
					zombie[48].ShowBitmap();
				}

			}
		}

		else if (!win3 && level == 3)
		{
		if (zombie[61].IsAnimationDone() && zombie[63].IsAnimationDone())
		{
			zombie[59].SetFrameIndexOfBitmap(3);
			count_last_wave += 1;
			if (count_last_wave < 30 || (count_last_wave > 60 && count_last_wave < 90) || (count_last_wave > 120 && count_last_wave < 150)) zombie[57].ShowBitmap();
			wave4 = true;
		}
		else
		{
			zombie[59].SetFrameIndexOfBitmap(0);
		}
		zombie[59].ShowBitmap();


		// 遊戲獲勝
		if (zombie[66].IsAnimationDone())
		{
			win3 = true;
			wave2 = false;
			wave3 = false;
			wave4 = false;
		}

		// 遊戲敗北
		for (int i = 0; i < 36; i += 5)
		{
			if (zombie[i].GetLeft() == 80 && zombie[i].GetTop() == 250)
			{
				//CAudio::Instance()->Play(2, true);
				count_gameover += 1;
				zombie[56].ShowBitmap();
				CAudio::Instance()->Stop(0);
				if (count_gameover > 90)lose3 = true;
			}

		}

		// 一般殭屍走路換吃東西的動畫，碰到車掉頭
		if ((!flag_zom_touch_plant[0]) && (!_flag_car_1[0]) && hit_count_normal[0] < 3) {
			zombie[0].ShowBitmap();
		}
		else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
		{
			zombie[1].ShowBitmap();
		}
		else if ((_flag_car_1[0] || hit_count_normal[0] >= 3))
		{
			if ((!_flag_car_1[0]) && hit_count_normal[0] >= 3)
			{
				zombie[62].ShowBitmap();
			}
			zombie[61].ShowBitmap();
		}

		// 鐵桶殭屍走路換吃東西的動畫，碰到車掉頭
		if ((!flag_zom_touch_plant[1]) && (!_flag_car_2[0]) && hit_count_bucket[0] < 6)
		{
			zombie[5].ShowBitmap();
		}
		else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
		{
			zombie[9].ShowBitmap();
		}
		else if (_flag_car_2[0] || hit_count_bucket[0] >= 6)
		{
			if ((!_flag_car_2[0]) && hit_count_bucket[0] >= 6)
			{
				zombie[64].ShowBitmap();
			}
			zombie[63].ShowBitmap();
		}

		// 旗幟殭屍走路換吃東西的動畫，碰到車掉頭
		if (wave4)
		{
			if ((!flag_zom_touch_plant[7]) && (!_flag_car_3[1]) && hit_count_flag[0] < 4) {
				zombie[35].ShowBitmap();
			}
			else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_3[1])
			{
				zombie[37].ShowBitmap();
			}
			else if (_flag_car_3[1] || hit_count_flag[0] >= 4)
			{
				if ((!_flag_car_3[1]) && hit_count_flag[0] >= 4)
				{
					zombie[67].ShowBitmap();
				}
				zombie[66].ShowBitmap();
			}

		}
		}
		else if (!win4 && level == 4)
		{
		if (zombie[71].IsAnimationDone() && zombie[73].IsAnimationDone())
		{
			zombie[59].SetFrameIndexOfBitmap(3);
			count_last_wave += 1;
			if (count_last_wave < 30 || (count_last_wave > 60 && count_last_wave < 90) || (count_last_wave > 120 && count_last_wave < 150)) zombie[57].ShowBitmap();
			wave4 = true;
		}
		else
		{
			zombie[59].SetFrameIndexOfBitmap(0);
		}
		zombie[59].ShowBitmap();


		// 遊戲獲勝
		if (zombie[76].IsAnimationDone())
		{
			win4 = true;
			wave2 = false;
			wave3 = false;
			wave4 = false;
		}

		// 遊戲敗北
		for (int i = 0; i < 36; i += 5)
		{
			if (zombie[i].GetLeft() == 80 && zombie[i].GetTop() == 250)
			{
				//CAudio::Instance()->Play(2, true);
				count_gameover += 1;
				zombie[56].ShowBitmap();
				CAudio::Instance()->Stop(0);
				if (count_gameover > 90)lose4 = true;
			}

		}

		// 一般殭屍走路換吃東西的動畫，碰到車掉頭
		if ((!flag_zom_touch_plant[0]) && (!_flag_car_3[0]) && hit_count_normal[0] < 3) {
			zombie[0].ShowBitmap();
		}
		else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 3)
		{
			zombie[1].ShowBitmap();
		}
		else if ((_flag_car_3[0] || hit_count_normal[0] >= 3))
		{
			if ((!_flag_car_3[0]) && hit_count_normal[0] >= 3)
			{
				zombie[72].ShowBitmap();
			}
			zombie[71].ShowBitmap();
		}

		// 鐵桶殭屍走路換吃東西的動畫，碰到車掉頭
		if ((!flag_zom_touch_plant[1]) && (!_flag_car_2[0]) && hit_count_bucket[0] < 6)
		{
			zombie[5].ShowBitmap();
		}
		else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 6)
		{
			zombie[9].ShowBitmap();
		}
		else if (_flag_car_2[0] || hit_count_bucket[0] >= 6)
		{
			if ((!_flag_car_2[0]) && hit_count_bucket[0] >= 6)
			{
				zombie[74].ShowBitmap();
			}
			zombie[73].ShowBitmap();
		}

		// 旗幟殭屍走路換吃東西的動畫，碰到車掉頭
		if (wave4)
		{
			if ((!flag_zom_touch_plant[7]) && (!_flag_car_1[0]) && hit_count_flag[0] < 4) {
				zombie[35].ShowBitmap();
			}
			else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 4 && !_flag_car_1[0])
			{
				zombie[37].ShowBitmap();
			}
			else if (_flag_car_1[0] || hit_count_flag[0] >= 4)
			{
				if ((!_flag_car_1[0]) && hit_count_flag[0] >= 4)
				{
					zombie[77].ShowBitmap();
				}
				zombie[76].ShowBitmap();
			}

		}
		}
		else if (!win5 && level == 5)
		{
			//進度條切換，畫面中間顯示最後一波
			if (zombie[6].IsAnimationDone() && zombie[23].IsAnimationDone())
			{
				zombie[59].SetFrameIndexOfBitmap(1);
				wave2 = true;

				if (zombie[21].IsAnimationDone() && zombie[8].IsAnimationDone() && zombie[34].IsAnimationDone())
				{
					zombie[59].SetFrameIndexOfBitmap(2);
					wave3 = true;
				}

				if (zombie[7].IsAnimationDone() && zombie[29].IsAnimationDone())
				{
					zombie[59].SetFrameIndexOfBitmap(3);
					count_last_wave += 1;
					if (count_last_wave < 30 || (count_last_wave > 60 && count_last_wave < 90) || (count_last_wave > 120 && count_last_wave < 150)) zombie[57].ShowBitmap();
					wave4 = true;
				}
			}
			else
			{
				zombie[59].SetFrameIndexOfBitmap(0);
			}
			zombie[59].ShowBitmap();


			// 遊戲獲勝
			if (zombie[38].IsAnimationDone())
			{
				win5 = true;
				wave2 = false;
				wave3 = false;
				wave4 = false;
			}

			// 遊戲敗北
			for (int i = 0; i < 36; i += 5)
			{
				if (zombie[i].GetLeft() == 80 && zombie[i].GetTop() == 250)
				{
					//CAudio::Instance()->Play(2, true);
					count_gameover += 1;
					zombie[56].ShowBitmap();
					CAudio::Instance()->Stop(0);
					if (count_gameover > 90)lose5 = true;
				}


			}


			// 一般殭屍走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[0]) && (!_flag_car_4[0]) && hit_count_normal[0] < 7) {
				zombie[0].ShowBitmap();
			}
			else if (flag_zom_touch_plant[0] && hit_count_normal[0] < 7)
			{
				zombie[1].ShowBitmap();
			}
			else if ((_flag_car_4[0] || hit_count_normal[0] >= 7))
			{
				if ((!_flag_car_4[0]) && hit_count_normal[0] >= 7)
				{
					zombie[13].ShowBitmap();
				}
				zombie[6].ShowBitmap();
			}

			// 一般殭屍2走路換吃東西的動畫，碰到車掉頭
			if (wave2)
			{
				if ((!flag_zom_touch_plant[3]) && (!_flag_car_0[0]) && hit_count_normal[1] < 7) {
					zombie[15].ShowBitmap();
				}
				else if (flag_zom_touch_plant[3] && hit_count_normal[1] < 7)
				{
					zombie[17].ShowBitmap();
				}
				else if ((_flag_car_0[0] || hit_count_normal[1] >= 7))
				{
					if ((!_flag_car_0[0]) && hit_count_normal[1] >= 7)
					{
						zombie[19].ShowBitmap();
					}
					zombie[21].ShowBitmap();
				}
			}


			// 一般殭屍3走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[4]) && (!_flag_car_1[0]) && hit_count_normal[2] < 7) {
				zombie[20].ShowBitmap();
			}
			else if (flag_zom_touch_plant[4] && hit_count_normal[2] < 7)
			{
				zombie[22].ShowBitmap();
			}
			else if ((_flag_car_1[0] || hit_count_normal[2] >= 7))
			{
				if ((!_flag_car_1[0]) && hit_count_normal[2] >= 7)
				{
					zombie[24].ShowBitmap();
				}
				zombie[23].ShowBitmap();
			}


			// 鐵桶殭屍走路換吃東西的動畫，碰到車掉頭
			if (wave3)
			{
				if ((!flag_zom_touch_plant[1]) && (!_flag_car_3[0]) && hit_count_bucket[0] < 11)
				{
					zombie[5].ShowBitmap();
				}
				else if (flag_zom_touch_plant[1] && hit_count_bucket[0] < 11)
				{
					zombie[9].ShowBitmap();
				}
				else if (_flag_car_3[0] || hit_count_bucket[0] >= 11)
				{
					if ((!_flag_car_3[0]) && hit_count_bucket[0] >= 11)
					{
						zombie[14].ShowBitmap();
					}
					zombie[7].ShowBitmap();
				}

			}


			// 鐵桶殭屍2走路換吃東西的動畫，碰到車掉頭
			if (wave2)
			{
				if ((!flag_zom_touch_plant[6]) && (!_flag_car_4[1]) && hit_count_bucket[1] < 11)
				{
					zombie[30].ShowBitmap();
				}
				else if (flag_zom_touch_plant[6] && hit_count_bucket[1] < 11)
				{
					zombie[33].ShowBitmap();
				}
				else if (_flag_car_4[1] || hit_count_bucket[1] >= 11)
				{
					if ((!_flag_car_4[1]) && hit_count_bucket[1] >= 11)
					{
						zombie[36].ShowBitmap();
					}
					zombie[34].ShowBitmap();
				}

			}



			// 三角錐殭屍走路換吃東西的動畫，碰到車掉頭
			if (wave2)
			{
				if ((!flag_zom_touch_plant[2]) && (!_flag_car_2[0]) && hit_count_tri[0] < 9)
				{
					zombie[10].ShowBitmap();
				}
				else if (flag_zom_touch_plant[2] && hit_count_tri[0] < 9)
				{
					zombie[11].ShowBitmap();
				}
				else if (_flag_car_2[0] || hit_count_tri[0] >= 9)
				{
					if ((!_flag_car_2[0]) && hit_count_tri[0] >= 9)
					{
						zombie[16].ShowBitmap();
					}
					zombie[8].ShowBitmap();
				}

			}


			// 三角錐殭屍2走路換吃東西的動畫，碰到車掉頭
			if ((!flag_zom_touch_plant[5]) && (!_flag_car_3[1]) && hit_count_tri[1] < 9) {
				zombie[25].ShowBitmap();
			}
			else if (flag_zom_touch_plant[5] && hit_count_tri[1] < 9 && !_flag_car_3[1])
			{
				zombie[28].ShowBitmap();
			}
			else if (_flag_car_3[1] || hit_count_tri[1] >= 9)
			{
				if ((!_flag_car_3[1]) && hit_count_tri[1] >= 9)
				{
					zombie[31].ShowBitmap();
				}
				zombie[29].ShowBitmap();
			}


			// 旗幟殭屍走路換吃東西的動畫，碰到車掉頭
			if (wave4)
			{
				if ((!flag_zom_touch_plant[7]) && (!_flag_car_1[1]) && hit_count_flag[0] < 9) {
					zombie[35].ShowBitmap();
				}
				else if (flag_zom_touch_plant[7] && hit_count_flag[0] < 9 && !_flag_car_1[1])
				{
					zombie[37].ShowBitmap();
				}
				else if (_flag_car_1[1] || hit_count_flag[0] >= 9)
				{
					if ((!_flag_car_1[1]) && hit_count_flag[0] >= 9)
					{
						zombie[39].ShowBitmap();
					}
					zombie[38].ShowBitmap();
				}

			}
		}
	}
}