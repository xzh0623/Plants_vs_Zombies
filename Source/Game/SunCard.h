#ifndef SUNCARD_H
#define SUNCARD_H
#pragma once
namespace game_framework {
	class SunCard {
	public:
		SunCard() {
		
		};
		~SunCard() {}
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
		void OnShow();
		CMovingBitmap suncard[1];
	protected:

	private:

	};

}
#endif