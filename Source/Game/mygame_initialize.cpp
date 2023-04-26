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
	//圖鑑
	picture[0].LoadBitmapByString({ "resources/option1_3_1.bmp" }, RGB(128, 128, 128));
	picture[0].SetTopLeft(10, 10);
	picture[1].LoadBitmapByString({ "resources/option1_3_2.bmp" }, RGB(128, 128, 128));
	picture[1].SetTopLeft(128, 320);
	picture[2].LoadBitmapByString({ "resources/option1_3_3.bmp" }, RGB(128, 128, 128));
	picture[2].SetTopLeft(490, 320);
	picture[3].LoadBitmapByString({ "resources/option1_3_4.bmp" }, RGB(128, 128, 128));
	picture[3].SetTopLeft(625, 505);
	//植物圖鑑
	plant_picture[0].LoadBitmapByString({ "resources/option1_3_5.bmp" }, RGB(128, 128, 128));
	plant_picture[0].SetTopLeft(10, 10);
	plant_picture[1].LoadBitmapByString({ "resources/option1_3_6.bmp" }, RGB(212, 161, 116));
	plant_picture[1].SetTopLeft(30, 546);
	plant_picture[2].LoadBitmapByString({ "resources/option1_3_7.bmp" }, RGB(212, 161, 116));
	plant_picture[2].SetTopLeft(640, 546);

	//植物介紹
	plant_intro[0].LoadBitmapByString({ "card/SunFlower_1.bmp" }, RGB(182, 185, 184));
	plant_intro[0].SetTopLeft(80, 100);
	plant_intro[1].LoadBitmapByString({ "card/PlantsCard_1.bmp"}, RGB(182, 185, 184));
	plant_intro[1].SetTopLeft(180, 100);
	plant_intro[2].LoadBitmapByString({ "card/WallNut_1.bmp"}, RGB(182, 185, 184));
	plant_intro[2].SetTopLeft(280, 100);
	plant_intro[3].LoadBitmapByString({ "card/Repeater_1.bmp"}, RGB(182, 185, 184));
	plant_intro[3].SetTopLeft(80, 160);
	//介紹卡
	plant_intro[4].LoadBitmapByString({ "resources/plant_intro1.bmp" }, RGB(182, 185, 184));
	plant_intro[4].SetTopLeft(450, 96);
	plant_intro[5].LoadBitmapByString({ "resources/plant_intro2.bmp" }, RGB(182, 185, 184));
	plant_intro[5].SetTopLeft(447, 94);

	for (int i = 0; i < 10; i++) plantIntro[i] = false;
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

			if ((MouseIsOverlap(one[5])) || ((MouseIsOverlap(menu[3])) && (option_show))|| ((MouseIsOverlap(menu[4])) && (option_show))) {
				option_show = false;
				phase = 1;
			}
			if ((MouseIsOverlap(one[3]))||(MouseIsOverlap(one[8])&&(option_show))) {
				option_show = !option_show;
			}
			if (MouseIsOverlap(menu[2]) && (option_show)) {
				option_show = !option_show;
				picture_show = !picture_show;
			}
			if (MouseIsOverlap(picture[3])&&(picture_show)) picture_show = !picture_show;
			if (MouseIsOverlap(picture[1]) && (picture_show) || ((MouseIsOverlap(plant_picture[1]) && (plant_picture_show)))) {
				plant_picture_show = !plant_picture_show;
				picture_show = !picture_show;
			}
			if ((MouseIsOverlap(plant_picture[2])) && (plant_picture_show)) {
				plant_picture_show = !plant_picture_show;
			}
			for (int i = 0; i < 2; i++) {
				if ((MouseIsOverlap(plant_intro[i])) && (plant_picture_show)) {
					plantIntro[i] = true;
					for (int j = 0; j < 2; j++) {
						if (j!=i) plantIntro[j] = false;
					}
				}
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
		if (picture_show) {
			picture[0].ShowBitmap();
			picture[1].ShowBitmap();
			picture[2].ShowBitmap();
			picture[3].ShowBitmap();
		}
		if (plant_picture_show) {
			plant_picture[0].ShowBitmap();
			plant_picture[1].ShowBitmap();
			plant_picture[2].ShowBitmap();
			plant_intro[0].ShowBitmap();
			plant_intro[1].ShowBitmap();
			plant_intro[2].ShowBitmap();
			plant_intro[3].ShowBitmap();

			if (plantIntro[0]) {
				plant_intro[4].ShowBitmap();
				
			}
			if (plantIntro[1]) {
				plant_intro[5].ShowBitmap();
				
			}
		}
	}
}


