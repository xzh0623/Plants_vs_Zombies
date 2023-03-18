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
			}
			else {
				background.SetTopLeft(background.GetLeft() + 3, 0);
			}
		}
		else {
			background.SetTopLeft(background.GetLeft() - 3, 0);
			if (background.GetLeft() < -300) {
				backgroundmove = true;
			}
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
	
	
	PlantsCard[0].LoadBitmapByString({ "resources/SunFlower_1.bmp","resources/SunFlower_2.bmp" }, RGB(182, 185, 184));
	PlantsCard[0].SetTopLeft(0, 0);
	PlantsCard[1].LoadBitmapByString({ "resources/PlantsCard_1.bmp","resources/PlantsCard_2.bmp" }, RGB(182, 185, 184));
	PlantsCard[1].SetTopLeft(0, 65);
	PlantsCard[2].LoadBitmapByString({ "resources/WallNut_1.bmp","resources/WallNut_2.bmp" }, RGB(182, 185, 184));
	PlantsCard[2].SetTopLeft(0, 130);
	PlantsCard[3].LoadBitmapByString({ "resources/Repeater_1.bmp","resources/Repeater_2.bmp" }, RGB(182, 185, 184));
	PlantsCard[3].SetTopLeft(0, 195);

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
			for (int i = 0; i < 4; i++) {
				if (MouseIsOverlap(PlantsCard[i])) {
					PlantsCard[i].SetAnimation(10, TRUE);
					PlantsCard[i].ToggleAnimation();
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
		else if ((phase == 2)&&(background.GetLeft()==-9)) {
			Sleep(1);
			for (int i = 0; i < 4; i++) {
				PlantsCard[i].ShowBitmap();
			}
			for (int i = 0; i < 1; i++) {
				SunCard[i].ShowBitmap();
			}
		}
		
		
	}
}

bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}
