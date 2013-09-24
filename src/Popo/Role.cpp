#include "StdAfx.h"
#include "Role.h"

Role::Role(void)
{
	m_pRoleState = new RoleStateNormal(this);
}

Role::~Role(void)
{
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