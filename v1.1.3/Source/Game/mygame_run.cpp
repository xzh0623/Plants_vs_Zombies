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
		s.OnMove();
		if ((s.flag_sun) && (p.twiceflag)) {
			s.delay1 += 1;
			if (s.delay1 == 420) {//當到420秒時太陽出現
				s.flag_sun = false;
			}
			if (s.delay1 == 600) {
				s.delay1 = 0;
			}
			//殭屍碰撞+過幾秒後歸0消失
		}
		z.OnMove();
		p_c.OnMove(0,50);
		
		p_c.OnMove(1, 100);
		p_c.OnMove(2, 50);
		p_c.OnMove(3, 200);
// 車子撞鐵桶殭屍
		if (!z._flag1)
		{
			z.zombie[5].SetTopLeft(z.zombie[5].GetLeft() - 1, z.zombie[5].GetTop());
			if (CMovingBitmap::IsOverlap(z.zombie[5], c.car[3])) z._flag1 = true;
		}
		else
		{
			c.car[3].SetTopLeft(c.car[3].GetLeft() + 10, c.car[3].GetTop());
			//Delay(5000);
			
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
	p.OnInit();
	//////////////////////////////////
	p_c.OnInit();
	s_c.OnInit();

	
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
			if (MouseIsOverlap(p_c.plantscard[0])) {
				p_c.OnLButtonDown(0,50);
			}
			
			if (MouseIsOverlap(p_c.plantscard[1])) {
				p_c.OnLButtonDown(1,100);
			}
			if (MouseIsOverlap(p_c.plantscard[2])) {
				p_c.OnLButtonDown(2,50);
			}
			if (MouseIsOverlap(p_c.plantscard[3])) {
				p_c.OnLButtonDown(3,200);
			}
			if (MouseIsOverlap(s.sun[0])) {
				s.flag2 = TRUE;
				p_c.score += 50;
			}
			if (MouseIsOverlap(s.sun[2])&&(s.IsShowBitmap)) {
				s.flag_sun = TRUE;
				p_c.score += 50;
			}
			if (p_c.scorecost[0]) {
				if ((nFlags == VK_LBUTTON)&& ((MouseIsOverlap(p_c.plantscard[0])) || (((mouse_x) >= 241) && ((mouse_x) <= 983) && ((mouse_y) >= 74) && ((mouse_y) <= 564)))) {
					p.isflag += 1;
					if (p.isflag == 2) {
						p.twiceflag = true;
						p.isflag = 0;
						p_c.scorecost[0] = false;
					}
				}
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
		CTextDraw::Print(pDC, 185, 19, to_string(p_c.score));
		CTextDraw::Print(pDC, 700, 19, to_string(p_c.count[0]));
		CTextDraw::Print(pDC, 700, 50, to_string(p_c.count[1]));
		CTextDraw::Print(pDC, 700, 100, to_string(p_c.count[2]));
		CTextDraw::Print(pDC, 700, 150, to_string(p_c.count[3]));
		CTextDraw::Print(pDC, 700, 200, to_string(z.zombie[7].GetLeft()));
		CTextDraw::Print(pDC, 700, 250, to_string(z.zombie[7].GetTop()));
		CTextDraw::Print(pDC, 700, 300, to_string(s.delay1));
		CTextDraw::Print(pDC, 700, 350, to_string(p.isflag));

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
			p_c.OnShow();
			s_c.OnShow();
			c.OnShow();
			z.OnShow2();
			for (int i = 0; i < 1; i++) {
				
				if (p.twiceflag){
					if (((mouse_x) >= 246) && ((mouse_x) <= 314) && ((mouse_y) >= 84) && ((mouse_y) <= 161)) {
						z.zombie[7].SetTopLeft(249, 87);
						s.sun[1].SetTopLeft(249, 87);
					}
					if (((mouse_x) >= 243) && ((mouse_x) <= 317) && ((mouse_y) >= 185) && ((mouse_y) <= 268)) {
						z.zombie[7].SetTopLeft(255, 181);
						s.sun[1].SetTopLeft(255, 181);
					}
				}
				if (p_c.scorecost[i]&&(p.isflag==1)) {
					p.plants[i].SetTopLeft(mouse_x - 30, mouse_y - 30);
					p.OnShow(i);
				}
			}
			//太陽花起始顏色，過幾秒太陽花變色，再過幾秒太陽花產太陽，同時變回起始顏色//OnMove2
			if (s.delay1 > 0 && s.delay1 <= 210)
			{
				z.zombie[7].ShowBitmap();
			}
			else if (s.delay1 > 210 && s.delay1 <= 420)
			{
				
				s.Onshow1();
				s.OnShow3();
			}
			else if (s.delay1 > 420)
			{
				z.zombie[7].ShowBitmap();
			}
			s.OnShow2();
			s.OnShow3();
		}
	}
}
/*
bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}*/
