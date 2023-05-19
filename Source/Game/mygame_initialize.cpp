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
	if ((menu_phase == 2) && (MouseIsOverlap(one[0]))) {
		one[0].SetFrameIndexOfBitmap(1);
	}
	else {
		one[0].SetFrameIndexOfBitmap(0);
	}
	if ((menu_phase == 2) && (MouseIsOverlap(one[1]))) {
		one[1].SetFrameIndexOfBitmap(1);
	}
	else {
		one[1].SetFrameIndexOfBitmap(0);
	}
	if ((menu_phase == 2) && (MouseIsOverlap(one[2]))) {
		one[2].SetFrameIndexOfBitmap(1);
	}
	else {
		one[2].SetFrameIndexOfBitmap(0);
	}
	if ((menu_phase == 2) && (MouseIsOverlap(one[9]))) {
		one[9].SetFrameIndexOfBitmap(1);
	}
	else {
		one[9].SetFrameIndexOfBitmap(0);
	}

}
void CGameStateInit::OnInit()
{
	//menu_phase = 1;
	help_show = false;
	option_show = false;
	picture_show = false;
	plant_picture_show = false;
	zombie_picture_show = false;
	level_show = false;
	for (int i = 0; i < 10; i++) {
		plantIntro[i] = false;
		zombieIntro[i] = false;
	}
	background.LoadBitmapByString({ "resources/initialize_background.bmp" });
	background.SetTopLeft(0, 0);
	//載入遊戲背景
	background1.LoadBitmapByString({
		"resources/menu_background.bmp"
		});
	background1.SetTopLeft(0, 0);

	//載入遊戲圖片
	one[0].LoadBitmapByString({ "resources/menu_title1.bmp","resources/menu_title1_1.bmp" }, RGB(0, 0, 0));
	one[0].SetTopLeft(520, 60);
	one[1].LoadBitmapByString({ "resources/menu_title2.bmp","resources/menu_title2_1.bmp" }, RGB(128, 128, 128));
	one[1].SetTopLeft(525, 200);
	one[2].LoadBitmapByString({ "resources/menu_title3.bmp","resources/menu_title3_1.bmp" }, RGB(128, 128, 128));
	one[2].SetTopLeft(530, 300);
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
	one[9].LoadBitmapByString({ "resources/book1.bmp","resources/book2.bmp" }, RGB(128, 128, 128));
	one[9].SetTopLeft(420, 400);
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
	//選關
	level_select[0].LoadBitmapByString({ "resources/option1_1_1.bmp" }, RGB(128, 128, 128));
	level_select[0].SetTopLeft(10, 10);
	level_select[1].LoadBitmapByString({ "resources/option1_3_7.bmp" }, RGB(212, 161, 116));
	level_select[1].SetTopLeft(620, 542);
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
	plant_picture[0].LoadBitmapByString({ "resources/option1_3_5.bmp" }, RGB(256, 256, 256));
	plant_picture[0].SetTopLeft(10, 10);
	plant_picture[1].LoadBitmapByString({ "resources/option1_3_6.bmp" }, RGB(212, 161, 116));
	plant_picture[1].SetTopLeft(30, 540);
	plant_picture[2].LoadBitmapByString({ "resources/option1_3_7.bmp" }, RGB(212, 161, 116));
	plant_picture[2].SetTopLeft(640, 540);
	//殭屍圖鑑
	zombie_picture[0].LoadBitmapByString({ "resources/option1_3_8.bmp" }, RGB(256, 256, 256));
	zombie_picture[0].SetTopLeft(10, 10);
	zombie_picture[1].LoadBitmapByString({ "resources/option1_3_6.bmp" }, RGB(212, 161, 116));
	zombie_picture[1].SetTopLeft(30, 542);
	zombie_picture[2].LoadBitmapByString({ "resources/option1_3_7.bmp" }, RGB(212, 161, 116));
	zombie_picture[2].SetTopLeft(640, 542);
	//植物介紹
	plant_intro[0].LoadBitmapByString({ "card/SunFlower_1.bmp" }, RGB(182, 185, 184));
	plant_intro[0].SetTopLeft(80, 100);
	plant_intro[1].LoadBitmapByString({ "card/PlantsCard_1.bmp"}, RGB(182, 185, 184));
	plant_intro[1].SetTopLeft(180, 100);
	plant_intro[2].LoadBitmapByString({ "card/WallNut_1.bmp"}, RGB(182, 185, 184));
	plant_intro[2].SetTopLeft(280, 100);
	plant_intro[3].LoadBitmapByString({ "card/Repeater_1.bmp"}, RGB(182, 185, 184));
	plant_intro[3].SetTopLeft(80, 170);
	//殭屍介紹
	zombie_intro[0].LoadBitmapByString({ "zombiecard/zombie1.bmp" }, RGB(128, 128, 128));
	zombie_intro[0].SetTopLeft(80, 100);
	zombie_intro[1].LoadBitmapByString({ "zombiecard/zombie2.bmp" }, RGB(128, 128, 128));
	zombie_intro[1].SetTopLeft(180, 102);
	zombie_intro[2].LoadBitmapByString({ "zombiecard/zombie3.bmp" }, RGB(128, 128, 128));
	zombie_intro[2].SetTopLeft(280, 103);
	zombie_intro[3].LoadBitmapByString({ "zombiecard/zombie4.bmp" }, RGB(128, 128, 128));
	zombie_intro[3].SetTopLeft(80, 170);
	//介紹卡
	plant_intro[4].LoadBitmapByString({ "resources/plant_intro1.bmp" }, RGB(182, 185, 184));
	plant_intro[4].SetTopLeft(450, 91);
	plant_intro[5].LoadBitmapByString({ "resources/plant_intro2.bmp" }, RGB(182, 185, 184));
	plant_intro[5].SetTopLeft(452, 96);
	plant_intro[6].LoadBitmapByString({ "resources/plant_intro3.bmp" }, RGB(182, 185, 184));
	plant_intro[6].SetTopLeft(450, 96);
	plant_intro[7].LoadBitmapByString({ "resources/plant_intro4.bmp" }, RGB(182, 185, 184));
	plant_intro[7].SetTopLeft(450, 95);
	//介紹卡(殭屍)
	zombie_intro[4].LoadBitmapByString({ "zombiecard/zombie1_1.bmp" }, RGB(128, 128, 128));
	zombie_intro[4].SetTopLeft(450,110);
	zombie_intro[5].LoadBitmapByString({ "zombiecard/zombie2_1.bmp" }, RGB(128, 128, 128));
	zombie_intro[5].SetTopLeft(450, 111);
	zombie_intro[6].LoadBitmapByString({ "zombiecard/zombie3_1.bmp" }, RGB(128, 128, 128));
	zombie_intro[6].SetTopLeft(450, 113);
	zombie_intro[7].LoadBitmapByString({ "zombiecard/zombie4_1.bmp" }, RGB(128, 128, 128));
	zombie_intro[7].SetTopLeft(449, 111);
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
		if (menu_phase==1) menu_phase += 1;
		else if (menu_phase == 2) {
			if ((MouseIsOverlap(one[0]))) {	//判斷第一關且滑鼠左鍵且滑鼠與圖片重疊 到下一關
				//game_phase = 1;
				GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
			}
			else if ((MouseIsOverlap(one[4]))) {
				help_show = !help_show;
			}

			else if ((MouseIsOverlap(one[5])) || ((MouseIsOverlap(menu[3])) && (option_show))|| ((MouseIsOverlap(menu[4])) && (option_show))) {
				option_show = false;
				menu_phase = 1;
				help_show = false;
				picture_show = false;
				plant_picture_show = false;
				zombie_picture_show = false;
				for (int i = 0; i < 10; i++) {
					plantIntro[i] = false;
					zombieIntro[i] = false;
				}
				level_show = false;
			}
			else if ((MouseIsOverlap(one[3]))||((MouseIsOverlap(one[8]))&&(option_show))) {
				option_show = !option_show;
			}
			else if ((MouseIsOverlap(one[9]))&&(!picture_show)&&(!option_show)) {
				picture_show = !picture_show;
			}
			else if (MouseIsOverlap(menu[2]) && (option_show)) {
				option_show = !option_show;
				picture_show = !picture_show;
			}
			else if (MouseIsOverlap(picture[3])&&(picture_show)) picture_show = !picture_show;
			else if (MouseIsOverlap(picture[1]) && (picture_show) || ((MouseIsOverlap(plant_picture[1]) && (plant_picture_show)))) {
				plant_picture_show = !plant_picture_show;
				picture_show = !picture_show;
			}
			else if ((MouseIsOverlap(plant_picture[2])) && (plant_picture_show)) {
				plant_picture_show = !plant_picture_show;
			}
			for (int i = 0; i < 4; i++) {
				if ((MouseIsOverlap(plant_intro[i])) && (plant_picture_show)) {
					plantIntro[i] = true;
					for (int j = 0; j < 4; j++) {
						if (j!=i) plantIntro[j] = false;
					}
				}
			}
			if (((MouseIsOverlap(picture[2])) && (picture_show)) || ((MouseIsOverlap(zombie_picture[1]) && (zombie_picture_show)))) zombie_picture_show = !zombie_picture_show;
			if ((MouseIsOverlap(zombie_picture[2])) && (zombie_picture_show)) {
				zombie_picture_show = !zombie_picture_show;
				picture_show = !picture_show;
			}
			for (int i = 0; i < 4; i++) {
				if ((MouseIsOverlap(zombie_intro[i])) && (zombie_picture_show)) {
					zombieIntro[i] = true;
					for (int j = 0; j < 4; j++) {
						if (j != i) zombieIntro[j] = false;
					}
				}
			}
			//////////////選關
			if (MouseIsOverlap(menu[0]) && (option_show)) {
				option_show = !option_show;
				level_show = !level_show;
			}
			if ((MouseIsOverlap(level_select[1])) && (level_show)) {
				level_show = !level_show;
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
	

	if (menu_phase == 1) background.ShowBitmap();
	if (menu_phase == 2) {
		background1.ShowBitmap();
		one[0].ShowBitmap();
		one[1].ShowBitmap();
		one[2].ShowBitmap();
		one[3].ShowBitmap();
		one[4].ShowBitmap();
		one[5].ShowBitmap();
		one[9].ShowBitmap();
		
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
		if (level_show) {
			level_select[0].ShowBitmap();
			level_select[1].ShowBitmap();
		}
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
			if (plantIntro[2]) {
				plant_intro[6].ShowBitmap();

			}
			if (plantIntro[3]) {
				plant_intro[7].ShowBitmap();

			}
		}
		if (zombie_picture_show) {
			zombie_picture[0].ShowBitmap();
			zombie_picture[1].ShowBitmap();
			zombie_picture[2].ShowBitmap();
			zombie_intro[0].ShowBitmap();
			zombie_intro[1].ShowBitmap();
			zombie_intro[2].ShowBitmap();
			zombie_intro[3].ShowBitmap();
			if (zombieIntro[0]) {
				zombie_intro[4].ShowBitmap();

			}
			if (zombieIntro[1]) {
				zombie_intro[5].ShowBitmap();

			}
			if (zombieIntro[2]) {
				zombie_intro[6].ShowBitmap();

			}
			if (zombieIntro[3]) {
				zombie_intro[7].ShowBitmap();

			}
		}

	}
}


