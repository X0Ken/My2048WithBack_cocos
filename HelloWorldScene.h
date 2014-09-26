#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CardSprite.h"
#include "CardBackItem.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	//�������������ʶ����¼����  
	//�����¼��ص���������ʼ�ʹ�������  
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	//�����������ҵķ���  
	bool doUp();
	bool doDown();
	bool doLeft();
	bool doRight();

	void createCardSprite(cocos2d::Size size);

	//�Զ����ɿ�Ƭ  
	void autoCreateCardNumber();

	//�ж���Ϸ�Ƿ��ܼ���  
	void doCheckGameOver();

	void btnCallback(Ref* pSender);
	void backDate();
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);

private:
	//���Ԫ��  
	int firstX, firstY, endX, endY;
	CardSprite* cardArr[4][4];
	cocos2d::Vector<CardBackItem*> cardBackArr;
	//��Ϸ�ܷ�  
	int score;

	//������ʾ�����Ŀؼ�  
	cocos2d::LabelTTF* labelTTFCardNumber;
};

#endif // __HELLOWORLD_SCENE_H__
