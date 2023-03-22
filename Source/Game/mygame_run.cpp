#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <string>
#include <random>
#include <iostream>


using namespace game_framework;
bool backgroundmove = false;
bool flag = false;
bool flag1 = false;

std::random_device rd;
std::mt19937 gen(rd());


//  隨機生成數字
int random(int low, int high) 
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
	
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//判斷第一關且滑鼠是否碰到圖片
	if ((phase==1)&&(MouseIsOverlap(one[0]))) {
		one[0].SetAnimation(10, TRUE);
		one[0].ToggleAnimation();
	}
	//第二關遊戲背景移動
	else if (phase==2) {
		if (backgroundmove) {
			
			if (background.GetLeft() > -10) {
				background.SetTopLeft(background.GetLeft(), 0);
				one[8].SetTopLeft(background.GetLeft() + 1100, 100);
				one[9].SetTopLeft(background.GetLeft() + 1000, 200);
				one[10].SetTopLeft(background.GetLeft() + 1050, 300);
			}
			else {
				background.SetTopLeft(background.GetLeft() + 3, 0);
				one[8].SetTopLeft(background.GetLeft() + 1100, 100);
				one[9].SetTopLeft(background.GetLeft() + 1000, 200);
				one[10].SetTopLeft(background.GetLeft() + 1050, 300);
			}
		}
		else {
			background.SetTopLeft(background.GetLeft() - 3, 0);
			one[8].SetTopLeft(background.GetLeft() + 1100, 100);
			one[9].SetTopLeft(background.GetLeft() + 1000, 200);
			one[10].SetTopLeft(background.GetLeft() + 1050, 300);

			if (background.GetLeft() < -300) {
				backgroundmove = true;
			}
		}
		
	}
	
	if (phase == 2 && background.GetLeft() == -9)
	{
		// 太陽掉落
		if(one[14].GetTop() < 500) one[14].SetTopLeft(one[14].GetLeft(), one[14].GetTop() + 1);
		
		// 殭屍移動code，定點吃東西
		if (!flag)
		{
			one[6].SetAnimation(100, false);
			one[6].SetTopLeft(one[6].GetLeft() - 1, one[6].GetTop());

			if (CMovingBitmap::IsOverlap(one[13], one[6])) flag = true;
		}
		if (flag)
		{
			one[7].SetTopLeft(one[13].GetLeft(), one[6].GetTop());
			one[7].SetAnimation(135, false);
		}

		// 車子撞鐵桶殭屍
		if (!flag1)
		{
			one[11].SetAnimation(100, false);
			one[11].SetTopLeft(one[11].GetLeft() - 1, one[11].GetTop());
			if (CMovingBitmap::IsOverlap(one[11], one[4])) flag1 = true;
		}
		else
		{
			one[4].SetTopLeft(one[4].GetLeft() + 10, one[4].GetTop());
		}
	}
	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//載入遊戲背景
	background.LoadBitmapByString({ 
		"resources/menu_background.bmp",
		"resources/phase2_background_1.bmp",
	});
	background.SetTopLeft(0, 0);

	//載入遊戲圖片
	one[0].LoadBitmapByString({ "resources/menu_title1_1.bmp","resources/menu_title1.bmp" }, RGB(0, 0, 0));
	one[0].SetTopLeft(520, 60);
	//////////////////////////////////
	// 第一輛車
	one[1].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
	one[1].SetTopLeft(170, 90);

	// 第二輛車
	one[2].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
	one[2].SetTopLeft(170, 180);

	// 第三輛車
	one[3].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
	one[3].SetTopLeft(170, 280);

	// 第四輛車
	one[4].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
	one[4].SetTopLeft(170, 390);

	// 第五輛車
	one[5].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
	one[5].SetTopLeft(160, 490);

	// 一般殭屍走路
	one[6].LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
	one[6].SetTopLeft(1200, 400);

	// 一般殭屍吃
	one[7].LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp" }, RGB(255, 255, 255));

	// 一般殭屍休息
	one[8].LoadBitmapByString({ "resources/zom_relax_0.bmp","resources/zom_relax_1.bmp","resources/zom_relax_2.bmp","resources/zom_relax_3.bmp","resources/zom_relax_4.bmp","resources/zom_relax_5.bmp","resources/zom_relax_6.bmp","resources/zom_relax_7.bmp","resources/zom_relax_8.bmp","resources/zom_relax_9.bmp","resources/zom_relax_10.bmp" }, RGB(255, 255, 255));
	one[8].SetAnimation(135, false);

	// 鐵桶殭屍休息
	one[9].LoadBitmapByString({ "resources/bucket_zom_relax_0.bmp","resources/bucket_zom_relax_1.bmp","resources/bucket_zom_relax_2.bmp","resources/bucket_zom_relax_3.bmp","resources/bucket_zom_relax_4.bmp","resources/bucket_zom_relax_5.bmp" }, RGB(255, 255, 255));
	one[9].SetAnimation(135, false);

	// 三角錐殭屍休息
	one[10].LoadBitmapByString({ "resources/tri_zom_relax_0.bmp","resources/tri_zom_relax_1.bmp","resources/tri_zom_relax_2.bmp","resources/tri_zom_relax_3.bmp","resources/tri_zom_relax_4.bmp","resources/tri_zom_relax_5.bmp","resources/tri_zom_relax_6.bmp","resources/tri_zom_relax_7.bmp" }, RGB(255, 255, 255));
	one[10].SetAnimation(135, false);

	// 鐵桶殭屍走路
	one[11].LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
	one[11].SetTopLeft(1000, 300);

	// 掉頭
	one[12].LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp" }, RGB(255, 255, 255));
	one[12].SetTopLeft(230, 305);
	one[12].SetAnimation(135, true);
	one[12].ToggleAnimation();

	//  太陽花
	one[13].LoadBitmapByString({ "resources/sunflower_0.bmp", "resources/sunflower_1.bmp", "resources/sunflower_2.bmp", "resources/sunflower_3.bmp", "resources/sunflower_4.bmp", "resources/sunflower_5.bmp", "resources/sunflower_6.bmp", "resources/sunflower_7.bmp", "resources/sunflower_8.bmp", "resources/sunflower_9.bmp", "resources/sunflower_10.bmp", "resources/sunflower_11.bmp", "resources/sunflower_12.bmp", "resources/sunflower_13.bmp", "resources/sunflower_14.bmp", "resources/sunflower_15.bmp", "resources/sunflower_16.bmp", "resources/sunflower_17.bmp" }, RGB(255, 255, 255));
	one[13].SetTopLeft(410, 470);
	one[13].SetAnimation(135, false);

	//   太陽
	one[14].LoadBitmapByString({ "resources/sun_0.bmp", "resources/sun_1.bmp", "resources/sun_2.bmp", "resources/sun_3.bmp", "resources/sun_4.bmp", "resources/sun_5.bmp", "resources/sun_6.bmp", "resources/sun_7.bmp", "resources/sun_8.bmp", "resources/sun_9.bmp", "resources/sun_10.bmp", "resources/sun_11.bmp", "resources/sun_12.bmp", "resources/sun_13.bmp", "resources/sun_14.bmp", "resources/sun_15.bmp", "resources/sun_16.bmp", "resources/sun_17.bmp", "resources/sun_18.bmp" , "resources/sun_19.bmp", "resources/sun_20.bmp" , "resources/sun_21.bmp" },RGB(255, 255, 255));
	one[14].SetTopLeft(random(250,900), 0);
	one[14].SetAnimation(100, false);
	


	/*    豌豆
	character.LoadBitmapByString({ "resources/bean_0.bmp", "resources/bean_1.bmp", "resources/bean_2.bmp", "resources/bean_3.bmp", "resources/bean_4.bmp", "resources/bean_5.bmp", "resources/bean_6.bmp", "resources/bean_7.bmp", "resources/bean_8.bmp", "resources/bean_9.bmp", "resources/bean_10.bmp", "resources/bean_11.bmp", "resources/bean_12.bmp" },RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(125, false);
	*/


	/*    二連發豌豆
	character.LoadBitmapByString({ "resources/double_bean_0.bmp", "resources/double_bean_1.bmp", "resources/double_bean_2.bmp", "resources/double_bean_3.bmp", "resources/double_bean_4.bmp", "resources/double_bean_5.bmp", "resources/double_bean_6.bmp", "resources/double_bean_7.bmp", "resources/double_bean_8.bmp", "resources/double_bean_9.bmp", "resources/double_bean_10.bmp" ,"resources/double_bean_11.bmp","resources/double_bean_12.bmp","resources/double_bean_13.bmp","resources/double_bean_14.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/

	
	


	/*    太陽花(要產太陽前)
	character[4].LoadBitmapByString({ "resources/sunflower_getsun_0.bmp", "resources/sunflower_getsun_1.bmp", "resources/sunflower_getsun_2.bmp", "resources/sunflower_getsun_3.bmp", "resources/sunflower_getsun_4.bmp", "resources/sunflower_getsun_5.bmp", "resources/sunflower_getsun_6.bmp", "resources/sunflower_getsun_7.bmp", "resources/sunflower_getsun_8.bmp", "resources/sunflower_getsun_9.bmp", "resources/sunflower_getsun_10.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_12.bmp", "resources/sunflower_getsun_13.bmp", "resources/sunflower_getsun_14.bmp", "resources/sunflower_getsun_15.bmp", "resources/sunflower_getsun_16.bmp", "resources/sunflower_getsun_17.bmp" }, RGB(255, 255, 255));
	//character[4].SetTopLeft(310, 335);
	//character[4].SetAnimation(135, false);
	*/


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


	/*     堅果牆(未傷)
	character.LoadBitmapByString({ "resources/nut_one_0.bmp", "resources/nut_one_1.bmp", "resources/nut_one_2.bmp", "resources/nut_one_3.bmp", "resources/nut_one_4.bmp", "resources/nut_one_5.bmp", "resources/nut_one_6.bmp", "resources/nut_one_7.bmp", "resources/nut_one_8.bmp", "resources/nut_one_9.bmp", "resources/nut_one_10.bmp", "resources/nut_one_11.bmp", "resources/nut_one_12.bmp", "resources/nut_one_13.bmp", "resources/nut_one_14.bmp", "resources/nut_one_15.bmp" }, RGB(0, 0, 0));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


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
	//////////////////////////////////
	
	PlantsCard[0].LoadBitmapByString({ "card/SunFlower_1.bmp","card/SunFlower_2.bmp","card/SunFlower_1.bmp" }, RGB(182, 185, 184));
	PlantsCard[1].LoadBitmapByString({ "card/PlantsCard_1.bmp","card/PlantsCard_2.bmp","card/PlantsCard_1.bmp" }, RGB(182, 185, 184));
	PlantsCard[2].LoadBitmapByString({ "card/WallNut_1.bmp","card/WallNut_2.bmp","card/WallNut_1.bmp" }, RGB(182, 185, 184));
	PlantsCard[3].LoadBitmapByString({ "card/Repeater_1.bmp","card/Repeater_2.bmp","card/Repeater_1.bmp" }, RGB(182, 185, 184));

	for (int i = 0; i < 4; i++) {
		PlantsCard[i].SetTopLeft(0, 65 * i);
	}

	SunCard[0].LoadBitmapByString({ "resources/Sun.bmp" }, RGB(182, 185, 184));
	SunCard[0].SetTopLeft(112, 11);

	
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//判斷第一關且滑鼠左鍵且滑鼠與圖片重疊 到下一關
	if ((nFlags == VK_LBUTTON)&&(MouseIsOverlap(one[0]))&&(phase==1)) {
		phase += 1;
	}
	if (phase == 2) {
		if (nFlags == VK_LBUTTON) {
			if (MouseIsOverlap(PlantsCard[0])) {
				PlantsCard[0].SetAnimation(20000, TRUE);
				PlantsCard[0].ToggleAnimation();
				PlantsCard[0].SetFrameIndexOfBitmap(1);
			}
			
			
			if (MouseIsOverlap(PlantsCard[1])) {
				PlantsCard[1].SetAnimation(20000, TRUE);
				PlantsCard[1].ToggleAnimation();
				PlantsCard[1].SetFrameIndexOfBitmap(1);
			}
			if (MouseIsOverlap(PlantsCard[2])) {
				PlantsCard[2].SetAnimation(60000, TRUE);
				PlantsCard[2].ToggleAnimation();
				PlantsCard[2].SetFrameIndexOfBitmap(1);
			}
			if (MouseIsOverlap(PlantsCard[3])) {
				PlantsCard[3].SetAnimation(20000, TRUE);
				PlantsCard[3].ToggleAnimation();
				PlantsCard[3].SetFrameIndexOfBitmap(1);
			}
			
		}
	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{

}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	mouse_x = point.x;
	mouse_y = point.y;

}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}


bool CGameStateRun::MouseIsOverlap(CMovingBitmap bmp1) { //判斷滑鼠是否在物件範圍內
	
	if ((mouse_x < bmp1.GetLeft() + bmp1.GetWidth()) && (mouse_x > bmp1.GetLeft()) &&
		(mouse_y < bmp1.GetTop() + bmp1.GetHeight()) && (mouse_y > bmp1.GetTop())) {
		return TRUE;
	}
	return FALSE;
}

void CGameStateRun::OnShow()
{
	show_image_by_phase();
	show_text_by_phase();
}

void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();
	CTextDraw::ChangeFontLog(pDC, 21, "微軟正黑體", RGB(0, 0, 0), 800);

	CTextDraw::Print(pDC, 0, 0, to_string(mouse_x));
	CTextDraw::Print(pDC, 50, 0, to_string(mouse_y));

	CTextDraw::Print(pDC, 100, 0, to_string(background.GetLeft()));
	//CTextDraw::Print(pDC, 150, 0, to_string(one[0].GetLeft()+one[0].GetWidth()));
	//CTextDraw::Print(pDC, 200, 0, to_string(one[0].GetTop()));
	//CTextDraw::Print(pDC, 250, 0, to_string(one[0].GetTop() + one[0].GetHeight()));
	if (phase == 2) {
		//CTextDraw::Print(pDC, 72, 39, "50");
	}
	CDDraw::ReleaseBackCDC();
}


	
void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SetFrameIndexOfBitmap(phase-1);
		background.ShowBitmap();					
		if (phase == 1) {
			
			for (int i = 0; i < 1; i++) {
				one[i].ShowBitmap();
			}
		}
		else if (phase == 2 && background.GetLeft() != -9)
		{
			for (int i = 8; i < 11; i++) {
				one[i].ShowBitmap();
			}
		}
		else if ((phase == 2)&&(background.GetLeft()==-9)) {
			Sleep(1);
			for (int i = 0; i < 4; i++) {
				PlantsCard[i].ShowBitmap();
			}
			for (int i = 0; i < 1; i++) {
				SunCard[i].ShowBitmap();
			}
			// 車定點
			for (int i = 1; i < 6; i++)
			{
				one[i].ShowBitmap();
			}

			// 殭屍換吃
			if (!flag) {
				one[6].ShowBitmap();
			}
			else {
				one[7].ShowBitmap();
			}

			// 殭屍被車輾消失並掉頭
			if (!flag1)
			{
				one[11].ShowBitmap();
			}
			else

			{
				if (!(one[12].IsAnimationDone())) one[12].ShowBitmap();
			}

			for (int i = 13; i < 14; i++) {
				one[i].ShowBitmap();
			}
			

			//寫滑鼠點擊消失的flag，我相信庠姊你可以的!!!
			one[14].ShowBitmap();
			
		}
		
		
	}
}
/*
bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}*/
