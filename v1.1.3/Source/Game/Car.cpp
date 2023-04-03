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
#include "Car.h"

namespace game_framework {
	void Car::OnInit() {
		// �Ĥ@����
		car[0].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
		car[0].SetTopLeft(170, 90);

		// �ĤG����
		car[1].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
		car[1].SetTopLeft(170, 180);

		// �ĤT����
		car[2].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
		car[2].SetTopLeft(170, 280);

		// �ĥ|����
		car[3].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
		car[3].SetTopLeft(170, 390);

		// �Ĥ�����
		car[4].LoadBitmapByString({ "resources/car.bmp" }, RGB(255, 255, 255));
		car[4].SetTopLeft(160, 490);
	}

// ���_�l��m���
	void Car::OnShow() {
		for (int i = 0; i < 5; i++)
		{
			car[i].ShowBitmap();
		}
	}
}