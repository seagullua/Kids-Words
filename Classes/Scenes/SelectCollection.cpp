#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
using namespace cocos2d;

SelectCollection::SelectCollection()
{
}

CCScene* SelectCollection::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    SelectCollection *layer = SelectCollection::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


SelectCollection* SelectCollection::create()
{

    SelectCollection *pRet = new SelectCollection();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

void SelectCollection::onBackClick()
{

    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}


bool SelectCollection::init()

{
    if(!SceneStyle::init())
        return false;

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    showBackground(BackgroundType::Dark);

    showButtonBack();
    Card* card = Card::create(CCSprite::create("card/color.png"),
                              "dddd ",
                              2,CardType::WithBorder);
    //Card* card = Card::create(CCSprite::create("card/color.png"),
    //                          "dddd ",
    //                          2,CardType::WithoutBorder);
    card->setAnchorPoint(ccp(0,0));
    card->setPositionY(200/SCALE);
    card->setPositionX(200/SCALE);
    this->addChild(card);
    card->setCardColor(InfoStyles::COLOR_BLUE);
    card->setTitleColor(InfoStyles::COLOR_WHITE);
    return true;

}
