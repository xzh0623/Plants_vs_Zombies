#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}
void CGameStateInit::OnMove()							// 移動遊戲元素
{

	//判斷第一關且滑鼠是否碰到圖片
	if ((phase == 2) && (MouseIsOverlap(one[0]))) {
		one[0].SetFrameIndexOfBitmap(1);
	}
	else {
		one[0].SetFrameIndexOfBitmap(0);
	}

}
void CGameStateInit::OnInit()
{

	background.LoadBitmapByString({ "resources/initialize_background.bmp" });
	background.SetTopLeft(0, 0);
	//載入遊戲背景
	background1.LoadBitmapByString({
		"resources/menu_background.bmp"
		});
	background1.SetTopLeft(0, 0);

	//載入遊戲圖片
	one[0].LoadBitmapByString({ "resources/menu_title1_1.bmp","resources/menu_title1.bmp" }, RGB(0, 0, 0));
	one[0].SetTopLeft(520, 60);
	one[3].LoadBitmapByString({ "resources/option.bmp" }, RGB(128, 128, 128));
	one[3].SetTopLeft(730, 490);
	one[4].LoadBitmapByString({ "resources/help.bmp" }, RGB(182, 185, 184));
	one[4].SetTopLeft(823, 522);
	one[5].LoadBitmapByString({ "resources/skip.bmp" }, RGB(128, 128, 128));
	one[5].SetTopLeft(905, 500);
	one[6].LoadBitmapByString({ "resources/help1.bmp" }, RGB(255, 255, 255));
	one[6].SetTopLeft(60, 10);
	one[7].LoadBitmapByString({ "resources/option1.bmp" }, RGB(128, 128, 128));
	one[7].SetTopLeft(200, 10);
	one[8].LoadBitmapByString({ "resources/option2.bmp" }, RGB(128, 128, 128));
	one[8].SetTopLeft(300, 460);
	//菜單
	menu[0].LoadBitmapByString({ "resources/option1_1.bmp" }, RGB(128, 128, 128));
	menu[0].SetTopLeft(405, 230);
	menu[1].LoadBitmapByString({ "resources/option1_2.bmp" }, RGB(128, 128, 128));
	menu[1].SetTopLeft(405, 270);
	menu[2].LoadBitmapByString({ "resources/option1_3.bmp" }, RGB(128, 128, 128));
	menu[2].SetTopLeft(405, 310);
	menu[3].LoadBitmapByString({ "resources/option1_4.bmp" }, RGB(128, 128, 128));
	menu[3].SetTopLeft(405, 350);
	menu[4].LoadBitmapByString({ "resources/option1_5.bmp" }, RGB(128, 128, 128));
	menu[4].SetTopLeft(405, 390);
	


}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}
void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	mouse_x = point.x;
	mouse_y = point.y;


}
void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{

	if (nFlags == VK_LBUTTON) {
		if (phase==1) phase += 1;
		if (phase == 2) {
			if ((MouseIsOverlap(one[0]))) {	//判斷第一關且滑鼠左鍵且滑鼠與圖片重疊 到下一關
				GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
				phase += 1;
			}
			if ((MouseIsOverlap(one[4]))) {
				help_show = !help_show;
			}

			if ((MouseIsOverlap(one[5]))) {
				phase = 1;
			}
			if ((MouseIsOverlap(one[3]))||(MouseIsOverlap(one[8])&&(option_show))) {
				option_show = !option_show;
			}
		}
	}

}
bool CGameStateInit::MouseIsOverlap(CMovingBitmap bmp1) { //判斷滑鼠是否在物件範圍內
	if ((mouse_x < bmp1.GetLeft() + bmp1.GetWidth()) && (mouse_x > bmp1.GetLeft()) &&
		(mouse_y < bmp1.GetTop() + bmp1.GetHeight()) && (mouse_y > bmp1.GetTop())) {
		return TRUE;
	}
	return FALSE;
}
void CGameStateInit::OnShow()
{
	

	if (phase == 1) background.ShowBitmap();
	if (phase == 2) {
		background1.ShowBitmap();
		one[0].ShowBitmap();
		one[3].ShowBitmap();
		one[4].ShowBitmap();
		one[5].ShowBitmap();
		
		if (option_show) {
			one[7].ShowBitmap();
			one[8].ShowBitmap();
			menu[0].ShowBitmap();
			menu[1].ShowBitmap();
			menu[2].ShowBitmap();
			menu[3].ShowBitmap();
			menu[4].ShowBitmap();
		}
		if (help_show) one[6].ShowBitmap();
	}
}


