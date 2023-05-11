#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include <string>
#include <random>
#include <iostream>
#include <ctime> 
#include <Windows.h>
#include "PlantsCard.h"


namespace game_framework {
	void PlantsCard::OnBeginState() {
		for (int i = 0; i < 4; i++) {
			count[i] = 0;
			iscount[i] = false;
			scorecost[i] = false;
		}
		score = 50;
		for (int i = 0; i < 4; i++) {
			plantscard[i].SetTopLeft(0, 65 * i);
		}
	}
	void PlantsCard::OnInit() {
		plantscard[0].LoadBitmapByString({ "card/SunFlower_1.bmp","card/SunFlower_2.bmp" }, RGB(182, 185, 184));
		plantscard[1].LoadBitmapByString({ "card/PlantsCard_1.bmp","card/PlantsCard_2.bmp" }, RGB(182, 185, 184));
		plantscard[2].LoadBitmapByString({ "card/WallNut_1.bmp","card/WallNut_2.bmp" }, RGB(182, 185, 184));
		plantscard[3].LoadBitmapByString({ "card/Repeater_1.bmp","card/Repeater_2.bmp"}, RGB(182, 185, 184));

		for (int i = 0; i < 4; i++) {
			plantscard[i].SetTopLeft(0, 65 * i);
		}
	}
	void PlantsCard::OnMove(int index,int scorelimit) {
		
		if (score < scorelimit) {
			plantscard[index].SetFrameIndexOfBitmap(1);
			if (iscount[index]) count[index] += 1;
		}
		else if (iscount[index]) {
			count[index] += 1;
			if ((count[index] > 500) && (score >= scorelimit)) {
				plantscard[index].SetFrameIndexOfBitmap(0);
				iscount[index] = false;
				count[index] = 0;
			}
		}
		else {
			plantscard[index].SetFrameIndexOfBitmap(0);
		}
	}
	void PlantsCard::OnLButtonDown(int index,int scorelimit) {
		if ((score >= scorelimit) && (plantscard[index].GetFrameIndexOfBitmap() != 1)) {
			iscount[index] = true;
			plantscard[index].SetFrameIndexOfBitmap(1);
			score -= scorelimit;
			scorecost[index] = true;
		}
		
	}
	void PlantsCard::OnShow() {
		for (int i = 0; i < 4; i++) {
			plantscard[i].ShowBitmap();
		}
	}

}