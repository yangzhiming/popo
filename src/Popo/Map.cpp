#include "StdAfx.h"
#include "Map.h"

Map::Map(void)
{
}

Map::~Map(void)
{
}

void Map::LoadFromFile(const char* lpFileName)
{
	m_pBmBkg = Bitmap::FromFile(L"..//Pic//BG.bmp");
}

void Map::LoadFromIni(const char* lpIniName)
{
}

void Map::Draw(Graphics* pGraph)
{
	pGraph->DrawImage(m_pBmBkg, 0, 0);
}