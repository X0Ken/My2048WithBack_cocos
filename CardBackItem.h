#ifndef __CARDBACKITEM__H__
#define __CARDBACKITEM__H__

#include "cocos2d.h"

class CardBackItem :
	public cocos2d::Ref
{
public:
	CREATE_FUNC(CardBackItem);
	bool init();
	void AddData(int*);
	int* GetData();
	~CardBackItem();
private:
	int* data;
};

#endif // !__CARDBACKITEM__H__
