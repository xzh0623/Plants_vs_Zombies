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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateChoose::CGameStateChoose(CGame *g) : CGameState(g)
{
}
CGameStateChoose::~CGameStateChoose()
{
}
void CGameStateChoose::OnInit() 
{
	//CAudio::Instance()->game_phase += 1;
}
void CGameStateChoose::OnBeginState() 
{
	
	
	GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN

}
void CGameStateChoose::OnKeyUp(UINT, UINT, UINT)
{
}
void CGameStateChoose::OnKeyDown(UINT, UINT, UINT)
{
	
}
void CGameStateChoose::OnMouseMove(UINT nFlags, CPoint point)
{
}
void CGameStateChoose::OnLButtonDown(UINT nFlags, CPoint point)
{
}
void CGameStateChoose::OnMove()
{
}
void CGameStateChoose::OnShow()
{
}
