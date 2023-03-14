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
	/*
	if (character.Left() <= chest_and_key.Left() + chest_and_key.Width() && character.Top() <= chest_and_key.Top() + chest_and_key.Height()
		&& character.Left() >= chest_and_key.Left() - chest_and_key.Width() && character.Top() >= chest_and_key.Top() - chest_and_key.Height())

	{
		chest_and_key.SelectShowBitmap(1);
	}
	if (phase == 5)
	{
		for (int i = 0; i < 3; i++)
		{
			if (character.Left() <= door[i].Left() + (door[i].Width() / 2) && character.Top() <= door[i].Top() + (door[i].Height() / 2)
				&& character.Left() >= door[i].Left() - (door[i].Width() / 2) && character.Top() >= door[i].Top() - (door[i].Height() / 2))
			{
				door[i].SelectShowBitmap(1);
			}
		}
	}
	*/
	

}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({ 
		"resources/black.bmp", 
		"resources/phase12_background.bmp", 
		"resources/phase21_background.bmp", 
		"resources/phase22_background.bmp", 
		"resources/phase31_background.bmp", 
		"resources/phase32_background.bmp",
		"resources/phase41_background.bmp",
		"resources/phase42_background.bmp",
		"resources/phase51_background.bmp",
		"resources/phase52_background.bmp",
		"resources/phase61_background.bmp",
		"resources/phase62_background.bmp",
	});
	background.SetTopLeft(0, 0);
	
	/*    太陽
	character.LoadBitmapByString({ "resources/sun_0.bmp", "resources/sun_1.bmp", "resources/sun_2.bmp", "resources/sun_3.bmp", "resources/sun_4.bmp", "resources/sun_5.bmp", "resources/sun_6.bmp", "resources/sun_7.bmp", "resources/sun_8.bmp", "resources/sun_9.bmp", "resources/sun_10.bmp", "resources/sun_11.bmp", "resources/sun_12.bmp", "resources/sun_13.bmp", "resources/sun_14.bmp", "resources/sun_15.bmp", "resources/sun_16.bmp", "resources/sun_17.bmp", "resources/sun_18.bmp" , "resources/sun_19.bmp", "resources/sun_20.bmp" , "resources/sun_21.bmp" },RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(100, false);
	*/
	
	
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


	/*    太陽花
	character.LoadBitmapByString({ "resources/sunflower_0.bmp", "resources/sunflower_1.bmp", "resources/sunflower_2.bmp", "resources/sunflower_3.bmp", "resources/sunflower_4.bmp", "resources/sunflower_5.bmp", "resources/sunflower_6.bmp", "resources/sunflower_7.bmp", "resources/sunflower_8.bmp", "resources/sunflower_9.bmp", "resources/sunflower_10.bmp", "resources/sunflower_11.bmp", "resources/sunflower_12.bmp", "resources/sunflower_13.bmp", "resources/sunflower_14.bmp", "resources/sunflower_15.bmp", "resources/sunflower_16.bmp", "resources/sunflower_17.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    太陽花(要產太陽前)
	character.LoadBitmapByString({ "resources/sunflower_getsun_0.bmp", "resources/sunflower_getsun_1.bmp", "resources/sunflower_getsun_2.bmp", "resources/sunflower_getsun_3.bmp", "resources/sunflower_getsun_4.bmp", "resources/sunflower_getsun_5.bmp", "resources/sunflower_getsun_6.bmp", "resources/sunflower_getsun_7.bmp", "resources/sunflower_getsun_8.bmp", "resources/sunflower_getsun_9.bmp", "resources/sunflower_getsun_10.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_11.bmp", "resources/sunflower_getsun_12.bmp", "resources/sunflower_getsun_13.bmp", "resources/sunflower_getsun_14.bmp", "resources/sunflower_getsun_15.bmp", "resources/sunflower_getsun_16.bmp", "resources/sunflower_getsun_17.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	/*


	/*    一般殭屍
	character.LoadBitmapByString({ "resources/zom_0.bmp", "resources/zom_1.bmp", "resources/zom_2.bmp", "resources/zom_3.bmp", "resources/zom_4.bmp", "resources/zom_5.bmp", "resources/zom_6.bmp", "resources/zom_7.bmp", "resources/zom_8.bmp", "resources/zom_9.bmp", "resources/zom_10.bmp" ,"resources/zom_11.bmp","resources/zom_12.bmp","resources/zom_13.bmp","resources/zom_14.bmp","resources/zom_15.bmp","resources/zom_16.bmp","resources/zom_17.bmp","resources/zom_18.bmp","resources/zom_19.bmp","resources/zom_20.bmp","resources/zom_21.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/


	/*    一般殭屍吃東西
	character.LoadBitmapByString({ "resources/zom_eat_0.bmp", "resources/zom_eat_1.bmp", "resources/zom_eat_2.bmp", "resources/zom_eat_3.bmp", "resources/zom_eat_4.bmp", "resources/zom_eat_5.bmp", "resources/zom_eat_6.bmp", "resources/zom_eat_7.bmp", "resources/zom_eat_8.bmp", "resources/zom_eat_9.bmp", "resources/zom_eat_10.bmp" ,"resources/zom_eat_11.bmp","resources/zom_eat_12.bmp","resources/zom_eat_13.bmp","resources/zom_eat_14.bmp","resources/zom_eat_15.bmp","resources/zom_eat_16.bmp","resources/zom_eat_17.bmp","resources/zom_eat_18.bmp","resources/zom_eat_19.bmp","resources/zom_eat_20.bmp"}, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
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


	/*     鐵桶殭屍
	character.LoadBitmapByString({ "resources/bucket_zom_0.bmp", "resources/bucket_zom_1.bmp", "resources/bucket_zom_2.bmp", "resources/bucket_zom_3.bmp", "resources/bucket_zom_4.bmp", "resources/bucket_zom_5.bmp", "resources/bucket_zom_6.bmp", "resources/bucket_zom_7.bmp", "resources/bucket_zom_8.bmp", "resources/bucket_zom_9.bmp", "resources/bucket_zom_10.bmp", "resources/bucket_zom_11.bmp", "resources/bucket_zom_12.bmp", "resources/bucket_zom_13.bmp", "resources/bucket_zom_14.bmp" }, RGB(255, 255, 255));
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

	
	
	
	
	//    未完成(只要循環一次)---------------------------------------------------------------------------
	/*    掉頭
	using namespace std;
	character.LoadBitmapByString({ "resources/headfall_0.bmp", "resources/headfall_1.bmp", "resources/headfall_2.bmp", "resources/headfall_3.bmp", "resources/headfall_4.bmp", "resources/headfall_5.bmp", "resources/headfall_6.bmp", "resources/headfall_7.bmp", "resources/headfall_8.bmp", "resources/headfall_9.bmp", "resources/headfall_10.bmp", "resources/headfall_11.bmp"}, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);
	character.SetAnimation(135, false);
	*/
	

	
	

	
           
	
	


}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RETURN) {
		if (phase == 1) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_1();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		} else if (phase == 2) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_2();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 3) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_3();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 4) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_4();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 5) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_5();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 6) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_6();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
				GotoGameState(GAME_STATE_OVER);
			}
		}
	}
	if (nChar == VK_UP)
	{
		character.SetTopLeft(character.Left(),character.Top()-20);
	}

	if (nChar == VK_DOWN)
	{
		character.SetTopLeft(character.Left(),character.Top()+20);
	}

	if (nChar == VK_RIGHT)
	{
		character.SetTopLeft(character.Left()+20,character.Top());
	}

	if (nChar == VK_LEFT)
	{
		character.SetTopLeft(character.Left()-20, character.Top());
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	show_image_by_phase();
	show_text_by_phase();
}

void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		background.ShowBitmap();
		character.ShowBitmap();
		if (phase == 3 && sub_phase == 1) {
			chest_and_key.ShowBitmap();
		}
		if (phase == 4 && sub_phase == 1) {
			bee.ShowBitmap();
		}
		if (phase == 5 && sub_phase == 1) {
			for (int i = 0; i < 3; i++) {
				door[i].ShowBitmap();
			}
		}
		if (phase == 6 && sub_phase == 1) {
			ball.ShowBitmap();
		}
	}
}

void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	CTextDraw::ChangeFontLog(pDC, fp, 21, "微軟正黑體", RGB(0, 0, 0), 800);
	
	
	/*
	if (phase == 1 && sub_phase == 1) {
		CTextDraw::Print(pDC, 237, 128, "修改你的主角！");
		CTextDraw::Print(pDC, 55, 163, "將灰色方格換成 resources 內的 giraffe.bmp 圖樣！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 2 && sub_phase == 1) {
		CTextDraw::Print(pDC, 26, 128, "下一個階段，讓長頸鹿能夠透過上下左右移動到這個位置！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 3 && sub_phase == 1) {
		CTextDraw::Print(pDC, 205, 128, "幫你準備了一個寶箱");
		CTextDraw::Print(pDC, 68, 162, "設計程式讓長頸鹿摸到寶箱後，將寶箱消失！");
		CTextDraw::Print(pDC, 68, 196, "記得寶箱要去背，使用 RGB(255, 255, 255)");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 4 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了一個蜜蜂好朋友");
		CTextDraw::Print(pDC, 89, 162, "已經幫它做了兩幀的動畫，讓它可以上下移動");
		CTextDraw::Print(pDC, 110, 196, "寫個程式來讓你的蜜蜂好朋友擁有動畫！");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 5 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了三扇門");
		CTextDraw::Print(pDC, 89, 162, "設計程式讓長頸鹿摸到門之後，門會打開");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (phase == 6 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "幫你準備了一顆會倒數的球");
		CTextDraw::Print(pDC, 89, 162, "設計程式讓球倒數，然後顯示 OK 後停止動畫");
		CTextDraw::Print(pDC, 373, 537, "按下 Enter 鍵來驗證");
	} else if (sub_phase == 2) {
		CTextDraw::Print(pDC, 268, 128, "完成！");
	}
	*/
	

	CDDraw::ReleaseBackCDC();
}


bool CGameStateRun::validate_phase_1() {
	return character.GetImageFilename() == "resources/giraffe.bmp";
}

bool CGameStateRun::validate_phase_2() {
	return character.Top() > 204 && character.Top() < 325 && character.Left() > 339 && character.Left() < 459;
}

bool CGameStateRun::validate_phase_3() {
	return (
		character.Top() + character.Height() >= chest_and_key.Top()
		&& character.Left() + character.Width() >= chest_and_key.Left()
		&& chest_and_key.GetSelectShowBitmap() == 1
		&& chest_and_key.GetFilterColor() == RGB(255, 255, 255)
	);
}

bool CGameStateRun::validate_phase_4() {
	return bee.IsAnimation() && bee.GetMovingBitmapFrame() == 2;
}

bool CGameStateRun::validate_phase_5() {
	bool check_all_door_is_open = true;
	for (int i = 0; i < 3; i++) {
		check_all_door_is_open &= (door[i].GetSelectShowBitmap() == 1);
	}
	return check_all_door_is_open;
}

bool CGameStateRun::validate_phase_6() {
	return ball.IsAnimationDone() && !ball.IsAnimation();
}