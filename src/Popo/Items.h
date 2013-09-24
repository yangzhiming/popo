#pragma once
#include "baseitem.h"

class PopoItem : public BaseItem
{
public:
	PopoItem(void);
	virtual ~PopoItem(void);

	virtual void Draw(Graphics* pGraph);
	virtual BaseItem* Clone() { return new PopoItem(*this); }
	virtual void Update(float fDelta);
};

class GiftItem : public BaseItem
{
public:
	GiftItem(void);
	virtual ~GiftItem(void);

	virtual void Draw(Graphics* pGraph);
	virtual BaseItem* Clone() { return new GiftItem(*this); }
	virtual void Update(float fDelta);
};
