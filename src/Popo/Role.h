#pragma once

enum DIRECTION
{
	Dir_Left,
	Dir_Up,
	Dir_Right,
	Dir_Down
};

class Role
{
public:
	Role(void);
	~Role(void);

	void Move(DIRECTION dir);
	void Update(float fDelta);
	void Draw(Graphics* pGraph);

public:
	friend class RoleState;
	friend class RoleStateNormal;
	friend class RoleStateOnDie;

private:
	RoleState*			m_pRoleState;
	DIRECTION			m_dir;
	int					m_xPos;
	int					m_yPos;
	int					m_speed;
};

class RoleState
{
public:
	RoleState(Role* pRole);
	virtual ~RoleState();

	virtual void Move() {}
	virtual void Draw(Graphics* pGraph) {}
	virtual void Update(float fDelta) {}
	
protected:
	Role*		m_pRole;
};

class RoleStateNormal : public RoleState
{
public:
	RoleStateNormal(Role* pRole);
	virtual ~RoleStateNormal();

	virtual void Move();
	virtual void Draw(Graphics* pGraph);
	virtual void Update(float fDelta);
};

class RoleStateOnDie : public RoleState
{
public:
	RoleStateOnDie(Role* pRole);
	virtual ~RoleStateOnDie();

	virtual void Draw(Graphics* pGraph);
	virtual void Update(float fDelta);
};