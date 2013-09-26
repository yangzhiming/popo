#ifndef _GAME_H_
#define _GAME_H_

enum GState
{
	gsStart,
	gsNormal,
	gsEnd
};

class Game
{
public:
	Game(void);
	~Game(void);

	void Init();
	void Uninit();

	void Draw(Graphics* pGraph);
	void Update(float fDelta);

private:
	void DrawStart(Graphics* pGraph);
	void DrawNormal(Graphics* pGraph);
	void DrawEnd(Graphics* pGraph);

protected:
	GState		m_gsState;
};

#endif