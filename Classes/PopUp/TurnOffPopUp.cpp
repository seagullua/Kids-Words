#include "TurnOffPopUp.h"
#include <ADLib/PopUp/ADPopUpWindow.h>
#include "InfoStyles.h"
#include "ADLib.h"
#include "Scenes/Settings.h"


using namespace cocos2d;

TurnOffPopUp::TurnOffPopUp(cocos2d::CCNode* parent):
    IADStandardWindow(CCSize(1,1),
                      InfoStyles::COLOR_BLUE,
                      Animation::DownToTop),
    _parent(parent)
{
}
void TurnOffPopUp::onCreate(cocos2d::CCNode *parent)
{

    const float SCALE = ADScreen::getScaleFactor();
    float padding = 25/SCALE;

    //background
    CCSprite* background = CCSprite::create("pop-ups/pop-up-background.png");

    background->setPosition(ccp(0,0));
    parent->addChild(background);


    cocos2d::CCSize size = background->getContentSize();
    float x_middle = size.width / 2;

    //label
    cocos2d::CCLabelTTF* label = cocos2d::CCLabelTTF::create(_("pop_up_turn_off.title"),
                                                             ADLanguage::getFontName(),
                                                             InfoStyles::SIZE_MENU_TITLE_POP_UP);

    label->setColor(InfoStyles::COLOR_BLUE);
    label->setPosition(ccp(x_middle, size.height*0.8f));
    background->addChild(label);

    ///////////////////////////////////////////////////////

    cocos2d::CCMenu* menu = cocos2d::CCMenu::create();
    menu->setPosition(0,0);
    background->addChild(menu);

    float vertical = size.height * 0.25f;
    cocos2d::CCSize button_size(size.width*0.25,size.width*0.15);

    ///////////////////////////////////////////////////////
    // button no later
    CCSprite* button_no_image = CCSprite::create("pop-ups/no-ads/no-ads-button.png");

    ADMenuItem* button_no = ADMenuItem::create(button_no_image);


    button_no->setPosition(ccp(size.width*0.275f, vertical));
    CONNECT(button_no->signalOnClick,
            this,
            &TurnOffPopUp::onNo);
    button_no->setColor(InfoStyles::COLOR_LIGHT_DARK);
    CCLabelTTF* button_no_title = CCLabelTTF::create(_("pop_up_turn_off.no"),
                                                     ADLanguage::getFontName(),
                                                     InfoStyles::SIZE_BUTTON_POP_UP);

    button_no_title->setColor(InfoStyles::COLOR_WHITE);
    button_no_title->setAnchorPoint(ccp(0.5f,0.5f));
    button_no_title->setPosition(ccp(button_no->getContentSize().width*0.5f,
                                     button_no->getContentSize().height*0.5f));
    button_no->addChild(button_no_title);
    menu->addChild(button_no);


    //////////////////////////////////////////////////////

    //button add
    CCSprite* button_add_image = CCSprite::create("pop-ups/no-ads/no-ads-button.png");

    ADMenuItem* button_add = ADMenuItem::create(button_add_image);
    button_add->setPosition(ccp(size.width*0.725f, vertical));
    CONNECT(button_add->signalOnClick,
            this,
            &TurnOffPopUp::onAdd);
    button_add->setColor(InfoStyles::COLOR_LIGHT_YELLOW);
    CCLabelTTF* button_add_title = CCLabelTTF::create(_("pop_up_turn_off.add"),
                                                      ADLanguage::getFontName(),
                                                      InfoStyles::SIZE_BUTTON_POP_UP);

    button_add_title->setColor(InfoStyles::COLOR_BLUE);
    button_add_title->setAnchorPoint(ccp(0.5f,0.5f));
    button_add_title->setPosition(ccp(button_add->getContentSize().width*0.5f,
                                      button_add->getContentSize().height*0.5f));
    button_add->addChild(button_add_title);

    menu->addChild(button_add);
    // pinguine and text add


    CCSprite* button_pinguine_image = CCSprite::create("settings/pinguine.png");

    button_pinguine_image->setScale(0.5f);
    button_pinguine_image->setAnchorPoint(ccp(0,0));
    button_pinguine_image->setPositionX(padding*5);
    button_pinguine_image->setPositionY(button_no->getPositionY()+padding*3.5f);
    background->addChild(button_pinguine_image);
    cocos2d::CCLabelTTF* turn_off_ads_title;
    turn_off_ads_title = CCLabelTTF::create(_("pop_up_turn_off.text"),
                                            ADLanguage::getFontName(),
                                            InfoStyles::SIZE_BUTTON_POP_UP);
    turn_off_ads_title->setAnchorPoint(ccp(0, 0));
    turn_off_ads_title->setPositionX(padding*14);
    turn_off_ads_title->setPositionY(button_no->getPositionY()+padding+button_pinguine_image->getContentSize().height*0.25f);
    turn_off_ads_title->setColor(InfoStyles::COLOR_BLUE);

    background->addChild(turn_off_ads_title);



}

void TurnOffPopUp::onNo()
{
    CCDirector::sharedDirector()->replaceScene(Settings::scene());

}

void TurnOffPopUp::onAdd()
{

}
