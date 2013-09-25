#include "StdAfx.h"
#include "Role.h"

Role::Role(void) : m_dir(Dir_Down)
{
	m_pRoleState = new RoleStateNormal(this);
}

Role::~Role(void)
{
}

void Role::Draw(Graphics* pGraph)
{
	m_pRoleState->Draw(pGraph);
}

void Role::Update(float fDelta)
{

}

void Role::Move(DIRECTION dir)
{
	m_dir = dir;

	switch(dir)
	{
	case Dir_Left:
		m_xPos -= m_speed;
		break;
	case Dir_Up:
		m_yPos -= m_speed;
		break;
	case Dir_Right:
		m_xPos += m_speed;
		break;
	case Dir_Down:
		m_yPos += m_speed;
		break;
	default:
		ASSERT(FALSE);
		break;
	}

	if (m_xPos <= 0)
		m_xPos = 0;

	if (m_yPos >= MAX_WND_HEIGHT)
		m_yPos = MAX_WND_HEIGHT;
}

RoleState::RoleState(Role* pRole)
{

}

RoleState::~RoleState()
{

}

RoleStateNormal::RoleStateNormal(Role* pRole)
: RoleState(pRole)
{

}

RoleStateNormal::~RoleStateNormal()
{

}

void RoleStateNormal::Draw(Graphics* pGraph)
{

}

void RoleStateNormal::Update(float fDelta)
{

}

RoleStateOnDie::RoleStateOnDie(Role* pRole)
: RoleState(pRole)
{

}

RoleStateOnDie::~RoleStateOnDie()
{

}

void RoleStateOnDie::Draw(Graphics* pGraph)
{

}

void RoleStateOnDie::Update(float fDelta)
{

}