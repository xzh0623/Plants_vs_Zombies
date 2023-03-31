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
#include <ctime> 
#include <Windows.h>

using namespace game_framework;



/*
void   Delay(int   time)//time*1000為秒數 
{
	clock_t now = clock();
	while (clock() - now < time);
}
*/



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
				z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
				z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
				z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);
			}
			else {
				background.SetTopLeft(background.GetLeft() + 3, 0);
				z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
				z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
				z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);
			}
		}
		else {
			background.SetTopLeft(background.GetLeft() - 3, 0);
			z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
			z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
			z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);

			if (background.GetLeft() < -300) {
				backgroundmove = true;
			}
			
		}
		
	}
	
	if (phase == 2 && background.GetLeft() == -9)
	{
//這個count是給太陽花變橘色然後產太陽的計時器
		if (count > 600) count = 0;
		count += 1;
		
		s.OnMove();
		z.OnMove();

// 第四台車子撞鐵桶殭屍
		if (!z._flag_car_4)
		{
			if (CMovingBitmap::IsOverlap(z.zombie[5], c.car[3]))
			{
				z._flag_car_4 = true;
				z.flag_headfall_0 = true;
				z.zombie[6].SetTopLeft(z.zombie[5].GetLeft(), z.zombie[5].GetTop());
				z.zombie[6].SetFrameIndexOfBitmap(0);
			}
		}
		else
		{
			c.car[3].SetTopLeft(c.car[3].GetLeft() + 10, c.car[3].GetTop());

		}

// 第5台車子撞一般殭屍
		if (!z._flag_car_5)
		{
			if (CMovingBitmap::IsOverlap(z.zombie[0], c.car[4]))
			{
				z._flag_car_5 = true;
				z.zombie[6].SetTopLeft(z.zombie[0].GetLeft(), z.zombie[0].GetTop());
				z.zombie[6].SetFrameIndexOfBitmap(0);
			}
		}
		else
		{
			c.car[4].SetTopLeft(c.car[4].GetLeft() + 10, c.car[4].GetTop());
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
	c.OnInit();
	z.OnInit();
	s.OnInit();
	

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
			if (MouseIsOverlap(s.sun[0])) {
				s.flag2 = TRUE;
				score += 50;
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
	if ((phase == 2)&&(background.GetLeft() == -9)) {
		CTextDraw::Print(pDC, 185, 19, to_string(score));
		//CTextDraw::Print(pDC, 180, 19, to_string(delay2));
	}
	CDDraw::ReleaseBackCDC();
}


	
void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SetFrameIndexOfBitmap(phase - 1);
		background.ShowBitmap();
		if (phase == 1) {
			one[0].ShowBitmap();
		}
		else if (phase == 2 && background.GetLeft() != -9) {
			z.OnShow1();
		}
		else if ((phase == 2) && (background.GetLeft() == -9)) {
			Sleep(1);
			for (int i = 0; i < 4; i++) {
				PlantsCard[i].ShowBitmap();
			}
			for (int i = 0; i < 1; i++) {
				SunCard[i].ShowBitmap();
			}

			c.OnShow();
			z.OnShow2();


			//太陽花起始顏色，過幾秒太陽花變色，再過幾秒太陽花產太陽，同時變回起始顏色
			if (count >= 0 && count <= 210)
			{
				z.zombie[7].ShowBitmap();
			}
			else if (count > 210 && count <= 420)
			{
				s.Onshow1();
			}
			else if (count > 420 && count <= 600)
			{
				s.flag_sun = true;
				z.zombie[7].ShowBitmap();
			}

			s.OnShow2();

		}
		s.OnShow3();
	}
}
/*
bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}*/
