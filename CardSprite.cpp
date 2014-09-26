#include "CardSprite.h"

USING_NS_CC;

CardSprite* CardSprite::createCardSprite(int numbers, int width, int height, float CardSpriteX, float CardSpriteY)
{
	CardSprite* enemy = new CardSprite();
	if (enemy && enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(numbers, width, height, CardSpriteX, CardSpriteY);

		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return NULL;
}

bool CardSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

void CardSprite::enemyInit(int numbers, int width, int height, float CardSpriteX, float CardSpriteY)
{
	//设置初始化值  
	number = numbers;

	//加入游戏的背景颜色  
	layerColorBG = cocos2d::LayerColor::create(cocos2d::Color4B(200, 190, 180, 255), width - 15, height - 15);
	layerColorBG->setPosition(Point(CardSpriteX, CardSpriteY));

	//判断如果大于0就显示，否则显示空  
	if (number > 0)
	{
		//加入中间字体  
		labelTTFCardNumber = LabelTTF::create(String::createWithFormat("%i", number)->getCString(), "HiraKakuProN-W6", 100);
		labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width / 2, layerColorBG->getContentSize().height / 2));
		labelTTFCardNumber->setTag(8);
		layerColorBG->addChild(labelTTFCardNumber);
	}
	else
	{
		//加入中间字体  
		labelTTFCardNumber = LabelTTF::create("", "HiraKakuProN-W6", 100);
		labelTTFCardNumber->setPosition(Point(layerColorBG->getContentSize().width / 2, layerColorBG->getContentSize().height / 2));
		labelTTFCardNumber->setTag(8);
		layerColorBG->addChild(labelTTFCardNumber);
	}

	this->addChild(layerColorBG);
}

//获取数字  
int CardSprite::getNumber()
{
	return number;
}

//设置数字  
void CardSprite::setNumber(int num)
{
	number = num;

	if (number > 0)
	{
		//获取数字重新更新数字  
		labelTTFCardNumber->setString(String::createWithFormat("%i", number)->getCString());
	}
	else
	{
		labelTTFCardNumber->setString("");
	}
	//判断数字的大小来调整字体  
	if (number >= 0) {
		labelTTFCardNumber->setFontSize(100);
	}
	if (number >= 16) {
		labelTTFCardNumber->setFontSize(90);
	}
	if (number >= 128){
		labelTTFCardNumber->setFontSize(60);
	}
	if (number >= 1024){
		labelTTFCardNumber->setFontSize(40);
	}

	//判断数字的大小来调整颜色  
	if (number == 0){
		layerColorBG->setColor(cocos2d::Color3B(200, 190, 180));
	}
	if (number == 2) {
		layerColorBG->setColor(cocos2d::Color3B(240, 230, 220));
	}
	if (number == 4) {
		layerColorBG->setColor(cocos2d::Color3B(240, 220, 200));
	}
	if (number == 8) {
		layerColorBG->setColor(cocos2d::Color3B(240, 180, 120));
	}
	if (number == 16) {
		layerColorBG->setColor(cocos2d::Color3B(240, 140, 90));
	}
	if (number == 32) {
		layerColorBG->setColor(cocos2d::Color3B(240, 120, 90));
	}
	if (number == 64) {
		layerColorBG->setColor(cocos2d::Color3B(240, 90, 60));
	}
	if (number == 128) {
		layerColorBG->setColor(cocos2d::Color3B(240, 90, 60));
	}
	if (number == 256) {
		layerColorBG->setColor(cocos2d::Color3B(240, 200, 70));
	}
	if (number == 512) {
		layerColorBG->setColor(cocos2d::Color3B(240, 200, 70));
	}
	if (number == 1024) {
		layerColorBG->setColor(cocos2d::Color3B(0, 130, 0));
	}
	if (number == 2048) {
		layerColorBG->setColor(cocos2d::Color3B(0, 130, 0));
	}
}