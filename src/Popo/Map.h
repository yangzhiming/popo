#pragma once

#include "Singleton.h"

const int CELL_SIZE = 40;
const int CELL_X = 15;
const int CELL_Y = 13;
const int CELL_X_ALL = 17;
const int CELL_Y_ALL = 15;
const int CELL_NUM = CELL_X_ALL * CELL_Y_ALL;
const int SCENE_LEFT = 20;
const int SCENE_TOP = 41;

//Иёзг
struct CELL
{
	unsigned int row;
	unsigned int col;
};

class Map : public SingletonT<Map>
{
public:
	void LoadFromFile(const char* lpFileName);
	void LoadFromIni(const char* lpIniName);
	
	void Draw(Graphics* pGraph);
	void Update(float fDelta);

	CELL* operator[](int row) { return m_vtCells + CELL_X_ALL*row; }
public:
	Map(void);
	~Map(void);

private:
	Bitmap*			m_pBmBkg;
	CELL			m_vtCells[CELL_NUM];
};
