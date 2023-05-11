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
#include "SunCard.h"

namespace game_framework {
	void SunCard::OnBeginState() {

	}
	void SunCard::OnInit() {
		suncard[0].LoadBitmapByString({ "resources/Sun.bmp" }, RGB(182, 185, 184));
		suncard[0].SetTopLeft(112, 11);
	}
	void SunCard::OnShow() {
		for (int i = 0; i < 1; i++) {
			suncard[i].ShowBitmap();
		}
	}
}