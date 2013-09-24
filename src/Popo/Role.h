#pragma once

class Role
{
public:
	Role(void);
	~Role(void);

	void Update(float fDelta);
	void Draw(Graphics* pGraph);

public:
	friend class RoleState;
	friend class RoleStateNormal;
	friend class RoleStateOnDie;

private:
	RoleState*			m_pRoleState;
};

class RoleState
{
public:
	RoleState(Role* pRole);
	virtual ~RoleState();

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