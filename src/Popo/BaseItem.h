#ifndef _BASE_ITEM_H_
#define _BASE_ITEM_H_

class BaseItem
{
public:
	BaseItem(void) {}
	virtual ~BaseItem(void) {}

	virtual void Draw(Graphics* pGraph) = 0;
	virtual BaseItem* Clone() = 0;
	virtual void Update(float fDelta) = 0;
};

#endif //_BASE_ITEM_H_