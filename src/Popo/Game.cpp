#include "StdAfx.h"
#include "Game.h"
#include "Map.h"

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::Draw(Graphics* pGraph)
{
	Map::GetInstance()->Draw(pGraph);
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
