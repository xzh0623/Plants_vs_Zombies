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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int index=0;
int mouse_x1[45] =
{ 246,243,240,240,230,
 327,324,329,327,328,
 408,401,400,405,406,
 488,485,488,490,492,
 565,567,571,571,568,
 651,648,645,647,654,
 731,730,732,729,730,
 811,802,805,801,807,
 888,885,893,890,890 };
int mouse_x2[45] =
{ 314,317,317,317,321,
 387,389,392,394,395,
 477,476,478,480,485,
 559,556,559,556,560,
 641,635,636,638,644,
 718,719,723,718,722,
 794,790,795,799,801,
 872,872,880,878,880,
 962,972,972,975,984 };
int mouse_y1[45] =
{ 84,185,267,374,469,
 70,180,279,379,467,
 68,178,276,383,472,
 62,177,274,383,474,
 62,182,279,386,471,
 63,175,278,385,471,
 68,182,227,382,471,
 72,179,281,382,470,
 83,183,283,385,470 };
int mouse_y2[45] =
{ 161,268,365,463,562,
 166,267,365,454,564,
 165,264,374,460,564,
 169,263,372,463,563,
 165,268,371,460,559,
 166,267,376,460,559,
 171,268,376,460,562,
 168,267,373,458,561,
 175,267,372,462,564 };
int x[45] = {
249,249,249,249,249,
327,327,327,327,327,
404,404,404,404,404,
492,492,492,492,492,
568,568,568,568,568,
655,655,655,655,655,
732,732,732,732,732,
811,811,811,811,811,
893,893,893,893,893 };
int y[45] = {
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483,
87,181,296,380,483 };
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 100; i++) {
			if ((p[i].flag_sun) && (p[i].twiceflag)||(p[i].turnToplant[1])||(p[i].turnToplant[2])||(p[i].turnToplant[3])) {
				p[i].delay1 += 1;
				if (p[i].delay1 == 420) {//當到420秒時太陽出現
					p[i].flag_sun = false;
				}
				if (p[i].delay1 == 600) {
					p[i].delay1 = 0;
				}
				//殭屍碰撞+過幾秒後歸0消失
				
				// 一般殭屍與植物相撞
				if (!z._flag && !z._flag_car_4)
				{
					for (int j = 0; j < 4; j++)
					{
						if (p[i].turnToplant[j])
						{
							if (CMovingBitmap::IsOverlap(p[i].plants[j], z.zombie[0])) z._flag = true;
						}
					}					
				}
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//一般殭屍與index 4 車相撞，車前進
		if (!z._flag && !z._flag_car_4)
		{
			if (CMovingBitmap::IsOverlap(c.car[4], z.zombie[0])) z._flag_car_4 = true;
		}
		if (z._flag_car_4) c.car[4].SetTopLeft(c.car[4].GetLeft() + 10, c.car[4].GetTop());


		z.OnMove();
		p_c.OnMove(0,50);
		
		p_c.OnMove(1, 100);
		p_c.OnMove(2, 50);
		p_c.OnMove(3, 200);
		





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
	for(int i=0;i<100;i++) p[i].OnInit();
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int i = 0; i < 100; i++) {
				if (MouseIsOverlap(p[i].plants[6]) && (p[i].IsShowBitmap)) {
					p[i].flag_sun = TRUE;
					p_c.score += 50;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (p_c.scorecost[i]) {
					p[index].turnToplant[i] = true;
					if ((nFlags == VK_LBUTTON) && ((MouseIsOverlap(p_c.plantscard[i])) || (((mouse_x) >= 241) && ((mouse_x) <= 983) && ((mouse_y) >= 74) && ((mouse_y) <= 564)))) {
						p[index].isflag += 1;
						if (p[index].isflag == 2) {
							p[index].twiceflag = true;
							p[index].isflag = 0;
							p_c.scorecost[i] = false;

						}
					}
				}
			}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
		//CTextDraw::Print(pDC, 700, 200, to_string(z.zombie[7].GetLeft()));
		//CTextDraw::Print(pDC, 700, 250, to_string(z.zombie[7].GetTop()));
		CTextDraw::Print(pDC, 700, 300, to_string(p[0].delay1));
		CTextDraw::Print(pDC, 700, 350, to_string(p[0].isflag));
		CTextDraw::Print(pDC, 700, 400, to_string(p[1].delay1));
		CTextDraw::Print(pDC, 700, 450, to_string(p[1].isflag));
		CTextDraw::Print(pDC, 700, 500, to_string(index));

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			for (int k = 0; k < 4; k++) {
				if ((p[index].twiceflag)&&(!p[index].SetPosDone)) {
					if (p[index].turnToplant[0]) {
						for (int j = 0; j < 45; j++) {
							if (((mouse_x) >= mouse_x1[j]) && ((mouse_x) <= mouse_x2[j]) && ((mouse_y) >= mouse_y1[j]) && ((mouse_y) <= mouse_y2[j])) {
								p[index].plants[4].SetTopLeft(x[j], y[j]);
							}
						}
						p[index].plants[5].SetTopLeft(p[index].plants[4].GetLeft(), p[index].plants[4].GetTop());
						p[index].plants[6].SetTopLeft(p[index].plants[4].GetLeft() + 5, p[index].plants[4].GetTop() + 7);
					}
					for (int i = 1; i < 4; i++) {
						if (p[index].turnToplant[i]) {
							for (int j = 0; j < 45; j++) {
								if (((mouse_x) >= mouse_x1[j]) && ((mouse_x) <= mouse_x2[j]) && ((mouse_y) >= mouse_y1[j]) && ((mouse_y) <= mouse_y2[j])) {
									p[index].plants[i].SetTopLeft(x[j], y[j]);
								}
							}
							//if(i!=2) p[index].plants[7].SetTopLeft(p[index].plants[i].GetLeft() + 5, p[index].plants[i].GetTop() + 7);//豆豆位置//顯示時間用殭屍判斷
						}
					}
					p[index].SetPosDone = true;
					index += 1;
				}
				if (p_c.scorecost[k] && (p[index].isflag == 1)) {
					p[index].plants[k].SetTopLeft(mouse_x - 30, mouse_y - 30);
					p[index].OnShow(k);
				}
					
			}
			for (int i = 0; i < 100; i++) {
				if (p[i].turnToplant[0]) {
					//太陽花起始顏色，過幾秒太陽花變色，再過幾秒太陽花產太陽，同時變回起始顏色//OnMove2
					if (p[i].delay1 > 0 && p[i].delay1 <= 210)
					{
						p[i].plants[4].ShowBitmap();
					}
					else if (p[i].delay1 > 210 && p[i].delay1 <= 420)
					{

						//s.Onshow1();
						p[i].plants[5].ShowBitmap();
						if ((!p[i].flag_sun)) {
							p[i].plants[6].ShowBitmap();
							p[i].IsShowBitmap = true;
						}
						else {
							p[i].IsShowBitmap = false;
						}
					}
					else if (p[i].delay1 > 420)
					{
						p[i].plants[4].ShowBitmap();
					}
					//else if () {//不顯示//秒數也要暫停
					//	p[i].turnToplant[0] = false;
					//}
					if ((!p[i].flag_sun)) {
						p[i].plants[6].ShowBitmap();
						p[i].IsShowBitmap = true;
					}
					else {
						p[i].IsShowBitmap = false;
					}
				}
				for (int x = 1; x < 4; x++) {
					if (p[i].turnToplant[x]) {
						if (p[i].delay1 > 0) p[i].plants[x].ShowBitmap();
						//else if () {//不顯示
						//	p[i].turnToplant[x] = false;
						//}
					}
				}
				
			}
			s.OnShow2();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
}
/*
bool CGameStateRun::validate_phase_1() {
	//return character.GetImageFilename() == "resources/giraffe.bmp";
	return 1;
}*/
