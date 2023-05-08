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
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483,
87, 181, 296, 380, 483 };
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


	
	//第二關遊戲背景移動
	if (phase == 1) {
		if (backgroundmove) {

			if (background.GetLeft() > -10) {
				background.SetTopLeft(background.GetLeft(), 0);
				z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
				z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
				z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);
				z.zombie[18].SetTopLeft(background.GetLeft() + 1025, 400);
				z.zombie[26].SetTopLeft(background.GetLeft() + 975, 10);
				z.zombie[27].SetTopLeft(background.GetLeft() + 1075, 400);
				z.zombie[32].SetTopLeft(background.GetLeft() + 1150, 300);
			}
			else {
				background.SetTopLeft(background.GetLeft() + 3, 0);
				z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
				z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
				z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);
				z.zombie[18].SetTopLeft(background.GetLeft() + 1025, 400);
				z.zombie[26].SetTopLeft(background.GetLeft() + 975, 10);
				z.zombie[27].SetTopLeft(background.GetLeft() + 1075, 400);
				z.zombie[32].SetTopLeft(background.GetLeft() + 1150, 300);
			}
		}
		else {
			background.SetTopLeft(background.GetLeft() - 3, 0);
			z.zombie[2].SetTopLeft(background.GetLeft() + 1100, 100);
			z.zombie[3].SetTopLeft(background.GetLeft() + 1000, 200);
			z.zombie[4].SetTopLeft(background.GetLeft() + 1050, 300);
			z.zombie[18].SetTopLeft(background.GetLeft() + 1025, 400);
			z.zombie[26].SetTopLeft(background.GetLeft() + 975, 10);
			z.zombie[27].SetTopLeft(background.GetLeft() + 1075, 400);
			z.zombie[32].SetTopLeft(background.GetLeft() + 1150, 300);

			if (background.GetLeft() < -300) {
				backgroundmove = true;
			}

		}

	}

	if (phase == 1 && background.GetLeft() == -9)
	{
		s.OnMove();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < 100; i++) {
			//殭屍碰撞
			if (p[i].SetPosDone) {
				// 一般殭屍與植物相撞
				z._flag = IsOverlap(z._flag, z._flag_car_4, 0, i);
				// 一般殭屍2與植物相撞
				z._flag3 = IsOverlap(z._flag3, z._flag_car_0, 15, i);
				// 一般殭屍3與植物相撞
				z._flag4 = IsOverlap(z._flag4, z._flag_car_1, 20, i);
				// 鐵桶殭屍與植物相撞
				z._flag1 = IsOverlap(z._flag1, z._flag_car_3, 5, i);
				// 三角錐殭屍與植物相撞
				z._flag2 = IsOverlap(z._flag2, z._flag_car_2, 10, i);
				// 三角錐殭屍2與植物相撞
				z._flag5 = IsOverlap(z._flag5, z._flag_car_3_1, 25, i);
				
				if ((z._flag) || (z._flag1) || (z._flag2) || (z._flag3) || (z._flag4) || (z._flag5)) {
					p[i].vanish = true;
					
				}
				//設定植物1子彈
				if (p[i].turnToplant[1]) {
					SetBean(i, 1);
				}
				//設定植物3子彈
				if (p[i].turnToplant[3]) {
					SetBean(i, 3);
				}
				if (p[i].delay1 >= 1000) {
					p[i].delay1 += 1;
					if ((p[i].delay1 == 1420) || (p[i].delay1 == 1840)) {//當到1420秒時太陽出現
						p[i].flag_sun = false;
					}
					for (int k = 0; k < 50; k++) {
						if (p[i].plantToZombie[k]) {
							if ((k == 0) && (z.hit_count_normal >= 7)) {
								p[i].plantToZombie[0] = false;
								p[i].delay1 = 0;
							}
							if ((k == 15) && (z.hit_count_normal_1 >= 7)) {
								p[i].plantToZombie[15] = false;
								p[i].delay1 = 0;
							}
							if ((k == 20) && (z.hit_count_normal_2 >= 7)) {
								p[i].plantToZombie[20] = false;
								p[i].delay1 = 0;
							}
							if ((k == 5) && (z.hit_count_bucket >= 11)) {
								p[i].plantToZombie[5] = false;
								p[i].delay1 = 0;
							}
							if ((k == 10) && (z.hit_count_tri >= 9)) {
								p[i].plantToZombie[10] = false;
								p[i].delay1 = 0;
							}
							if ((k == 25) && (z.hit_count_tri_1 >= 9)) {
								p[i].plantToZombie[25] = false;
								p[i].delay1 = 0;
							}
						}
					}
				}
				else if (((p[i].flag_sun) && (p[i].twiceflag) || (p[i].turnToplant[1]) || (p[i].turnToplant[2]) || (p[i].turnToplant[3])) && (p[i].delay1 != -1)) {
					p[i].delay1 += 1;
					if ((p[i].delay1 == 420)) {//當到420秒時太陽出現
						p[i].flag_sun = false;

						// 一般殭屍與植物相撞
						z._flag = IsOverlap(z._flag, z._flag_car_4, 0, i);
						// 鐵桶殭屍與植物相撞
						z._flag1 = IsOverlap(z._flag1, z._flag_car_3, 5, i);
						// 三角錐殭屍與植物相撞
						z._flag2 = IsOverlap(z._flag2, z._flag_car_2, 10, i);
						// 三角錐殭屍2與植物相撞
						z._flag5 = IsOverlap(z._flag5, z._flag_car_3_1, 25, i);
						// 一般殭屍2與植物相撞
						z._flag3 = IsOverlap(z._flag3, z._flag_car_0, 15, i);
						// 一般殭屍3與植物相撞
						z._flag4 = IsOverlap(z._flag4, z._flag_car_1, 20, i);

						if ((z._flag) || (z._flag1) || (z._flag2) || (z._flag3) || (z._flag4) || (z._flag5)) {
							p[i].vanish = true;
							
						}



					}
					if (p[i].delay1 == 600) {
						p[i].delay1 = 0;
					}


				}
			}
			
			/*else if ((p[i].delay1 == -1) && (p[i].vanish)) {
				for (int j = 0; j < 4; j++) {
					if (p[i].turnToplant[j]) {
						p[i].clean = false;
						break;
					}
					else {
						p[i].clean = true;
					}
				}
				if (p[i].clean) {//勿動
					for (int k = 4; k < 10; k++) {
						if (Distance(p[i].plants[k], z.zombie[0]) != 1000) {
							z._flag = false;
						}
						if (Distance(p[i].plants[k], z.zombie[5]) != 1000) {
							z._flag1 = false;
						}
						if (Distance(p[i].plants[k], z.zombie[10]) != 1000) {
							z._flag2 = false;
						}
						if (Distance(p[i].plants[k], z.zombie[15]) != 1000) {
							z._flag3 = false;
						}
						if (Distance(p[i].plants[k], z.zombie[20]) != 1000) {
							z._flag4 = false;
						}
						if (Distance(p[i].plants[k], z.zombie[25]) != 1000) {
							z._flag5 = false;
						}
					}
				}
			}*/
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//一般殭屍與index 4 車相撞，車前進
		if (!z._flag && !z._flag_car_4)
		{
			if (CMovingBitmap::IsOverlap(c.car[4], z.zombie[0])) z._flag_car_4 = true;
		}
		if (z._flag_car_4) c.car[4].SetTopLeft(c.car[4].GetLeft() + 20, c.car[4].GetTop());
		
//一般殭屍2與index 0 車相撞，車前進
		if (!z._flag3 && !z._flag_car_0)
		{
			if (CMovingBitmap::IsOverlap(c.car[0], z.zombie[15])) z._flag_car_0 = true;
		}
		if (z._flag_car_0) c.car[0].SetTopLeft(c.car[0].GetLeft() + 20, c.car[0].GetTop());

//一般殭屍3與index 1 車相撞，車前進
		if (!z._flag4 && !z._flag_car_1)
		{
			if (CMovingBitmap::IsOverlap(c.car[1], z.zombie[20])) z._flag_car_1 = true;
		}
		if (z._flag_car_1) c.car[1].SetTopLeft(c.car[1].GetLeft() + 20, c.car[1].GetTop());

//鐵桶殭屍與index 3 車相撞，車前進
		if (!z._flag1 && !z._flag_car_3)
		{
			if (CMovingBitmap::IsOverlap(c.car[3], z.zombie[5])) z._flag_car_3 = true;
		}
		if (z._flag_car_3) c.car[3].SetTopLeft(c.car[3].GetLeft() + 20, c.car[3].GetTop());
		
//三角錐殭屍與index 2 車相撞，車前進
		if (!z._flag2 && !z._flag_car_2)
		{
			if (CMovingBitmap::IsOverlap(c.car[2], z.zombie[10])) z._flag_car_2 = true;
		}
		if (z._flag_car_2) c.car[2].SetTopLeft(c.car[2].GetLeft() + 20, c.car[2].GetTop());

//三角錐殭屍與index 2 車相撞，車前進
		if (!z._flag5 && !z._flag_car_3_1)
		{
			if (CMovingBitmap::IsOverlap(c.car[3], z.zombie[25])) z._flag_car_3_1 = true;
		}
		if (z._flag_car_3_1 && !z._flag_car_3) c.car[3].SetTopLeft(c.car[3].GetLeft() + 20, c.car[3].GetTop());

		z.OnMove();
		p_c.OnMove(0,50);
		
		p_c.OnMove(1, 100);
		p_c.OnMove(2, 50);
		p_c.OnMove(3, 200);
	}

}

//植物跟殭屍碰撞
bool CGameStateRun::IsOverlap(bool flag_1,bool flag_2,int zombie_num,int i) {
	if (!flag_1 && !flag_2)
	{
		for (int j = 0; j < 4; j++)
		{
			if (p[i].turnToplant[j])
			{
				if (CMovingBitmap::IsOverlap(p[i].plants[j], z.zombie[zombie_num]) && z.zombie[zombie_num].GetTop() < p[i].plants[j].GetTop()&& (p[i].plants[j].GetTop()+ p[i].plants[j].GetHeight()) <= (z.zombie[zombie_num].GetTop() + z.zombie[zombie_num].GetHeight()))
				{
					if(p[i].delay1<1000) p[i].delay1 = 1000;
					p[i].plantToZombie[zombie_num] = true;
					return true;
				}
				
				/*
				if (!CMovingBitmap::IsOverlap(p[i].plants[j], z.zombie[zombie_num]))
				{
					return false;
				}
				*/

				/*
				for (int k = 0; k < 45; k++) {
					if (map[k]==i)
				}
				*/

				/*
				for (int k = 0, k < 45, k++)
				{
					if(map[k] == -1 )
				}
				*/
				
			}
		
		}
	}
	return flag_1;
}
//兩物件平行距離
int CGameStateRun::Distance(CMovingBitmap bmp1, CMovingBitmap bmp2) {
	if ((bmp2.GetTop() == 30) && (bmp1.GetTop() == 87)) {
		if (bmp1.GetLeft() > bmp2.GetLeft()) return 1000;
		return bmp2.GetLeft() - bmp1.GetLeft();
	}
	else if ((bmp2.GetTop() == 120) && (bmp1.GetTop() == 181)) {
		if (bmp1.GetLeft() > bmp2.GetLeft()) return 1000;
		return bmp2.GetLeft() - bmp1.GetLeft();
	}
	else if ((bmp2.GetTop() == 230) && (bmp1.GetTop() == 296)) {
		if (bmp1.GetLeft() > bmp2.GetLeft()) return 1000;
		return bmp2.GetLeft() - bmp1.GetLeft();
	}
	else if ((bmp2.GetTop() == 320) && (bmp1.GetTop() == 380)) {
		if (bmp1.GetLeft() > bmp2.GetLeft()) return 1000;
		return bmp2.GetLeft() - bmp1.GetLeft();
	}
	else if ((bmp2.GetTop() == 420) && (bmp1.GetTop() == 483)) {
		if (bmp1.GetLeft() > bmp2.GetLeft()) return 1000;
		return bmp2.GetLeft() - bmp1.GetLeft();
	}
	

	

}
//子彈設定
void CGameStateRun::SetBean(int i,int bean_index) {
	if (bean_index == 1) {
		for (int k = 0; k < 26; k = k + 5) {
			if (p[i].bean1_delay >= 0) {
				if ((Distance(p[i].plants[1], z.zombie[k]) < 600) && (!p[i].bean1_show) && (p[i].bean1_delay>=700)) {
					p[i].bean1_delay = 0;
					p[i].bean1_show = true;
					p[i].bean1_isoverlap = false;
				}
				if (p[i].bean1_delay<700) {
					p[i].bean1_delay += 2;
					p[i].plants[7].SetTopLeft(p[i].plants[1].GetLeft() + 40 + p[i].bean1_delay, p[i].plants[1].GetTop() + 2);
					
					if (CMovingBitmap::IsOverlap(p[i].plants[7], z.zombie[k]) && (z.zombie[k].GetTop() < p[i].plants[7].GetTop())&&(!p[i].bean1_isoverlap)) {
						p[i].bean1_isoverlap = true;
						p[i].bean1_show = false;
						if ((!p[i].bean1_show) && k == 0) z.hit_count_normal += 1;
						if ((!p[i].bean1_show) && k == 5) z.hit_count_bucket += 1;
						if ((!p[i].bean1_show) && k == 10) z.hit_count_tri += 1;
						if ((!p[i].bean1_show) && k == 15) z.hit_count_normal_1 += 1;
						if ((!p[i].bean1_show) && k == 20) z.hit_count_normal_2 += 1;
						if ((!p[i].bean1_show) && k == 25) z.hit_count_tri_1 += 1;
						z.zombiegotbean[0].SetTopLeft(z.zombie[k].GetLeft() + 10, z.zombie[k].GetTop() + 70);
						z.ZombieGotBean1 = true;
					}
				}

			}

		}
	}
	if (bean_index == 3) {
		for (int k = 0; k < 26; k = k + 5) {
			if (p[i].bean2_delay >= 0) {
				if ((Distance(p[i].plants[3], z.zombie[k]) < 600) && (!p[i].bean2_show) && (p[i].bean2_delay >= 700)) {
					p[i].bean2_delay = 0;
					p[i].bean2_show = true;
					p[i].bean2_isoverlap = false;
				}
				if (p[i].bean2_delay < 700) {
					p[i].bean2_delay += 2;
					p[i].plants[8].SetTopLeft(p[i].plants[3].GetLeft() + 40 + p[i].bean2_delay, p[i].plants[3].GetTop() + 2);
					p[i].plants[9].SetTopLeft(p[i].plants[8].GetLeft() - 50, p[i].plants[8].GetTop());
					if (CMovingBitmap::IsOverlap(p[i].plants[8], z.zombie[k]) && z.zombie[k].GetTop() < p[i].plants[8].GetTop() && (!p[i].bean2_isoverlap)) {
						p[i].bean2_isoverlap = true;
						p[i].bean2_show = false;
						if ((!p[i].bean2_show) && k == 0) z.hit_count_normal += 2;
						if ((!p[i].bean2_show) && k == 5) z.hit_count_bucket += 2;
						if ((!p[i].bean2_show) && k == 10) z.hit_count_tri += 2;
						if ((!p[i].bean2_show) && k == 15) z.hit_count_normal_1 += 2;
						if ((!p[i].bean2_show) && k == 20) z.hit_count_normal_2 += 2;
						if ((!p[i].bean2_show) && k == 25) z.hit_count_tri_1 += 2;
						z.zombiegotbean[0].SetTopLeft(z.zombie[k].GetLeft() + 10, z.zombie[k].GetTop() + 70);
						z.ZombieGotBean1 = true;
					}
				}

			}
			
		}
	}

}
void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	//載入遊戲背景
	background.LoadBitmapByString({
		"resources/phase2_background_1.bmp",
	});
	background.SetTopLeft(0, 0);

	//////////////////////////////////
	c.OnInit();
	z.OnInit();
	s.OnInit();
	for(int i=0;i<100;i++) p[i].OnInit();
	for (int i = 0; i < 45; i++) map[i] = -1;
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
	if (phase == 1) {
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
	if ((phase == 1)&&(background.GetLeft() == -9)) {
		CTextDraw::Print(pDC, 185, 19, to_string(p_c.score));
		CTextDraw::Print(pDC, 700, 19, to_string(p[0].turnToplant[2]));
		//CTextDraw::Print(pDC, 700, 50, to_string(z._flag));
		CTextDraw::Print(pDC, 700, 100, to_string(z._flag1));
		CTextDraw::Print(pDC, 700, 150, to_string(p[1].plantToZombie[0]));
		CTextDraw::Print(pDC, 700, 200, to_string(p[0].vanish));
		CTextDraw::Print(pDC, 700, 250, to_string(p[0].plantToZombie[0]));
		CTextDraw::Print(pDC, 700, 300, to_string(p[0].delay1));
		CTextDraw::Print(pDC, 700, 350, to_string(p[1].delay1));
		//CTextDraw::Print(pDC, 700, 350, to_string(p[0].isflag));
		CTextDraw::Print(pDC, 700, 400, to_string(p[2].delay1));
		CTextDraw::Print(pDC, 700, 450, to_string(p[3].delay1));
		//CTextDraw::Print(pDC, 700, 450, to_string(p[1].isflag));
		CTextDraw::Print(pDC, 700, 500, to_string(p[4].delay1));

		CTextDraw::Print(pDC, 0, 500, to_string(z.hit_count_normal));

	}
	CDDraw::ReleaseBackCDC();
}


	
void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SetFrameIndexOfBitmap(phase - 1);
		background.ShowBitmap();
		if (phase == 1 && background.GetLeft() != -9) {
			z.OnShow1();
		}
		else if ((phase == 1) && (background.GetLeft() == -9)) {
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
								if (map[j] == -1) {
									p[index].plants[4].SetTopLeft(x[j], y[j]);
									p[index].plants[5].SetTopLeft(p[index].plants[4].GetLeft(), p[index].plants[4].GetTop());
									p[index].plants[6].SetTopLeft(p[index].plants[4].GetLeft() + 5, p[index].plants[4].GetTop() + 7);
									map[j] = index;
									p[index].SetPosDone = true;
									index += 1;
									
								}
								else {
									p[index].twiceflag = false;
									p[index].isflag = 1;
									p_c.scorecost[0] = true;
									p[index].delay1 = 0;
								}
								
								
							}
							
						}
						
					}
					for (int i = 1; i < 4; i++) {
						if (p[index].turnToplant[i]) {
							for (int j = 0; j < 45; j++) {
								if (((mouse_x) >= mouse_x1[j]) && ((mouse_x) <= mouse_x2[j]) && ((mouse_y) >= mouse_y1[j]) && ((mouse_y) <= mouse_y2[j])) {
									if (map[j] == -1) {
										p[index].plants[i].SetTopLeft(x[j], y[j]);
										if (i != 2) p[index].plants[7].SetTopLeft(p[index].plants[1].GetLeft() + 60, p[index].plants[1].GetTop() + 2);//豆豆位置//顯示時間用殭屍判斷
										map[j] = index;
										p[index].SetPosDone = true;
										index += 1;
									}
									else {
										p[index].twiceflag = false;
										p[index].isflag = 1;
										p_c.scorecost[i] = true;
										p[index].delay1 = 0;
									}
									
								}
								
								
							}
							
							
						}
					}
					
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
					else if ((p[i].delay1 > 210 && p[i].delay1 <= 420) || (p[i].delay1 > 1210 && p[i].delay1 < 1420) || (p[i].delay1 > 1630 && p[i].delay1 < 1840))
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
					if (p[i].vanish) {//不顯示//秒數也要暫停
						//if ((z.hit_count_normal >= 333) || (z.hit_count_normal_1 >= 333) || (z.hit_count_normal_2 >= 333)) p[i].delay1 = 0;
						//if (z.hit_count_bucket >= 333) p[i].delay1 = 0;
						//if ((z.hit_count_tri >= 333) || (z.hit_count_tri_1 >= 333)) p[i].delay1 = 0;
			
						if (p[i].delay1 > 1500) {
							p[i].turnToplant[0] = false;
							p[i].delay1 = -1;
							p[i].plants[4].SetTopLeft(1000,1000);
							p[i].plants[5].SetTopLeft(1000,1000);
							p[i].plants[6].SetTopLeft(1000,1000);
							for (int k = 0; k < 50; k++) {
								if (p[i].plantToZombie[k]) {
									if (k == 0) z._flag = !z._flag;
									if (k == 5) z._flag1 = !z._flag1;
									if (k == 10) z._flag2 = !z._flag2;
									if (k == 15) z._flag3 = !z._flag3;
									if (k == 20) z._flag4 = !z._flag4;
									if (k == 25) z._flag5 = !z._flag5;
									p[i].plantToZombie[k] = false;
								}
							}
							for (int j = 0; j < 45; j++) {
								if (map[j] == i) map[j] = -1;
							}
							//p[i].vanish = false;
						}
						/*else {
							for (int k = 0; k < 50; k++) {
								if (!p[i].plantToZombie[k]) {
									p[i].delay1 = 0;
								}
							}
						}*/
					}
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
						if (p[i].delay1 > 0) {
							p[i].plants[x].ShowBitmap();
							if((x==1)&&(p[i].bean1_show))p[i].plants[7].ShowBitmap();
							if (z.ZombieGotBean1) {
								z.zombiegotbean[0].ShowBitmap();
								z.ZombieGotBean1 = false;
							}
							if ((x == 3) && (p[i].bean2_show)) {
								p[i].plants[8].ShowBitmap();
								if ((p[i].plants[9].GetLeft() > p[i].plants[3].GetLeft() + 60)) p[i].plants[9].ShowBitmap();
							}
						}
						if (p[i].vanish) {//不顯示//秒數也要暫停
							//if ((z.hit_count_normal >= 333)||(z.hit_count_normal_1 >= 333)||(z.hit_count_normal_2 >= 333)) p[i].delay1 = 0;
							//if (z.hit_count_bucket >= 333) p[i].delay1 = 0;
							//if ((z.hit_count_tri >= 333)||(z.hit_count_tri_1 >= 333)) p[i].delay1 = 0;
							
							if (p[i].delay1 > 1500) {
								p[i].turnToplant[x] = false;
								p[i].delay1 = -1;
								p[i].plants[x].SetTopLeft(1000, 1000);
								for (int k = 0; k < 50; k++) {
									if (p[i].plantToZombie[k]) {
										if (k == 0) z._flag = !z._flag;
										if (k == 5) z._flag1 = !z._flag1;
										if (k == 10) z._flag2 = !z._flag2;
										if (k == 15) z._flag3 = !z._flag3;
										if (k == 20) z._flag4 = !z._flag4;
										if (k == 25) z._flag5 = !z._flag5;
										p[i].plantToZombie[k] = false;
									}
								}
								if(x==1) p[i].plants[7].SetTopLeft(1000, 1000);
								if (x == 3) {
									p[i].plants[8].SetTopLeft(1000, 1000);
									p[i].plants[9].SetTopLeft(1000, 1000);
								}
								for (int j = 0; j < 45; j++) {
									if (map[j] == i) map[j] = -1;
								}
								//p[i].vanish = false;
							}
							/*else {
								for (int k = 0; k < 50; k++) {
									if (p[i].plantToZombie[k]) {
										if ((k == 0) && (z.hit_count_normal>=333)) p[i].plantToZombie[0] = false;
										//p[i].delay1 = 0;
									}
								}
							}*/
						}
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
