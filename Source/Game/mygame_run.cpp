#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <string>

using namespace game_framework;
bool backgroundmove = false;
bool flag = false;
bool flag1 = false;
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
	if ((phase==1)&&(MouseIsOverlap(one[0]))) {
		one[0].SetAnimation(10, TRUE);
		one[0].ToggleAnimation();
	}
	else if (phase==2) 
	{
		if (backgroundmove) 
		{
			
			if (background.GetLeft() > -10) 
			{
				background.SetTopLeft(background.GetLeft(), 0);
				one[8].SetTopLeft(background.GetLeft() + 1100, 100);
				one[9].SetTopLeft(background.GetLeft() + 1000, 200);
				one[10].SetTopLeft(background.GetLeft() + 1050, 300);
			}
			else 
			{
				background.SetTopLeft(background.GetLeft() + 3, 0);
				one[8].SetTopLeft(background.GetLeft() + 1100, 100);
				one[9].SetTopLeft(background.GetLeft() + 1000, 200);
				one[10].SetTopLeft(background.GetLeft() + 1050, 300);
				
			}
		}
		else 
		{
			background.SetTopLeft(background.GetLeft() - 3, 0);
			one[8].SetTopLeft(background.GetLeft() + 1100, 100);
			one[9].SetTopLeft(background.GetLeft() + 1000, 200);
			one[10].SetTopLeft(background.GetLeft() + 1050, 300);
			
			if (background.GetLeft() < -300) 
			{
				backgroundmove = true;
			}
		}
	}
	//殭屍移動code，定點吃東西
	if (phase == 2 && background.GetLeft() == -9) 
	{
		if (!flag) 
		{
			one[6].SetAnimation(100, false);
			one[6].SetTopLeft(one[6].GetLeft() - 1, one[6].GetTop());

			if (one[6].GetLeft() == 300) flag = true;
		}
		if (flag) 
		{
			//要改寫碰撞
			one[7].SetTopLeft(300, 400);
			one[7].SetAnimation(135, false);
		}

		if (!flag1)
		{
			one[11].SetAnimation(100, false);
			one[11].SetTopLeft(one[11].GetLeft() - 1, one[11].GetTop());
			if (one[11].GetLeft() == 170) flag1 = true;
		}
		else
		{
			one[4].SetTopLeft(one[4].GetLeft() + 10, one[4].GetTop());
			

		}
	}
	

	

	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	
	background.LoadBitmapByString({ 
		"resources/menu_background.bmp",
		"resources/phase2_background_1.bmp",
	});
	background.SetTopLeft(0, 0);

	
	one[0].LoadBitmapByString({ "resources/menu_title1_1.bmp","resources/menu_title1.bmp" }, RGB(0, 0, 0));
	one[0].SetTopLeft(520, 60);

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

}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if ((nFlags == VK_LBUTTON)&&(MouseIsOverlap(one[0]))&&(phase==1)) {
		phase += 1;
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
	//CTextDraw::Print(pDC, 100, 0, to_string(one[0].GetLeft()));
	//CTextDraw::Print(pDC, 150, 0, to_string(one[0].GetLeft()+one[0].GetWidth()));
	//CTextDraw::Print(pDC, 200, 0, to_string(one[0].GetTop()));
	//CTextDraw::Print(pDC, 250, 0, to_string(one[0].GetTop() + one[0].GetHeight()));
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
			for (int i = 8 ; i < 11 ; i++) one[i].ShowBitmap();
		}
		else if (phase == 2&& background.GetLeft() == -9) {
			Sleep(1);
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
				
			
			
			
			//background.SetTopLeft(background.GetLeft() + 1, 80);
		}


		
		
	}
}

bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}
