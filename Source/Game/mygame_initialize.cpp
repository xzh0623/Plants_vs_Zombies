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
		if ((MouseIsOverlap(one[0])) && (phase == 2)) {	//判斷第一關且滑鼠左鍵且滑鼠與圖片重疊 到下一關
			GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
		}
		phase += 1;
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
	}
}


