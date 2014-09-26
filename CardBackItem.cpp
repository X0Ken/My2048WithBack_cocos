#include "CardBackItem.h"

bool CardBackItem::init()
{
	data = new int[16];
	return true;
}

void CardBackItem::AddData(int* d)
{
	for (int i = 0; i < 16; i++)
	{
		data[i] = d[i];
	}
}

int* CardBackItem::GetData()
{
	return data;
}

CardBackItem::~CardBackItem()
{
	CC_SAFE_DELETE(data);
}