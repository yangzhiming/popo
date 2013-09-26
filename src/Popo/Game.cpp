#include "StdAfx.h"
#include "Game.h"
#include "Map.h"

Game::Game(void) : m_gsState(gsStart)
{
}

Game::~Game(void)
{
}

void Game::Draw(Graphics* pGraph)
{
	Map::GetInstance()->Draw(pGraph);

	switch ( m_gsState )
	{
	case gsStart:
		DrawStart(pGraph);
		break;

	case gsNormal:
		DrawNormal(pGraph);
		break;

	case gsEnd:
		DrawEnd(pGraph);
		break;

	default:
		ASSERT(FALSE);
		break;
	}
}

void Game::DrawStart(Graphics* pGraph)
{

}

void Game::DrawNormal(Graphics* pGraph)
{

}

void Game::DrawEnd(Graphics* pGraph)
{

}

void Game::Update(float fDelta)
{

}

void Game::Init()
{
	Map::GetInstance()->LoadFromFile("stage1.map");
}

void Game::Uninit()
{

}
