#include "ExitGamePopUp.h"
#include <ADLib/PopUp/ADPopUpWindow.h>
#include "InfoStyles.h"
#include <ADLib.h>

using namespace cocos2d;

ExitGamePopUp::ExitGamePopUp(cocos2d::CCNode* parent):
    IADStandardWindow(CCSize(1,1),
                      InfoStyles::COLOR_BLUE,
                      Animation::DownToTop),
    _parent(parent)
{}
void ExitGamePopUp::onNo()
{
    this->closeWindow();
}

void ExitGamePopUp::onYes()
{
    ADDeviceEvents::closeApp();
}

void ExitGamePopUp::onCreate(cocos2d::CCNode *parent)
{
    //background
    CCSprite* background = CCSprite::create("pop-ups/pop-up-background.png");

    background->setPosition(ccp(0,0));
    parent->addChild(background);
    cocos2d::CCSize size = background->getContentSize();
    float x_middle = size.width / 2;

    //label
    cocos2d::CCLabelTTF* label = cocos2d::CCLabelTTF::create(_("ExitGame.Sure"),
                                                             ADLanguage::getFontName(),
                                                             InfoStyles::SIZE_EXIT_TITLE);

    label->setColor(InfoStyles::COLOR_BLUE);
    label->setPosition(ccp(x_middle, size.height*0.65f));
    background->addChild(label);

    ///////////////////////////////////////////////////////

    cocos2d::CCMenu* menu = cocos2d::CCMenu::create();
    menu->setPosition(0,0);
    background->addChild(menu);

    float vertical = size.height * 0.3f;
    cocos2d::CCSize button_size(size.width*0.25,size.width*0.15);

    ///////////////////////////////////////////////////////

    // yes_button
    CCSprite* yes_button_image = CCSprite::create("pop-ups/exit/exit-button.png");

    ADMenuItem* yes_button = ADMenuItem::create(yes_button_image);


    yes_button->setPosition(ccp(size.width*0.3f, vertical));
    CONNECT(yes_button->signalOnClick,
            this,
            &ExitGamePopUp::onYes);
    yes_button->setColor(InfoStyles::COLOR_RED_LIGHT);
    CCLabelTTF* yes_button_title = CCLabelTTF::create(_("ExitGame.Yes"),
                                                      ADLanguage::getFontName(),
                                                      InfoStyles::SIZE_BUTTON_POP_UP);

    yes_button_title->setColor(InfoStyles::COLOR_WHITE);
    yes_button_title->setAnchorPoint(ccp(0.5f,0.5f));
    yes_button_title->setPosition(ccp(yes_button->getContentSize().width*0.5f,
                                      yes_button->getContentSize().height*0.5f));
    yes_button->addChild(yes_button_title);
    menu->addChild(yes_button);


    //////////////////////////////////////////////////////

    //no_button
    CCSprite* no_button_image = CCSprite::create("pop-ups/exit/exit-button.png");

    ADMenuItem* no_button = ADMenuItem::create(no_button_image);
    no_button->setPosition(ccp(size.width*0.7f, vertical));
    CONNECT(no_button->signalOnClick,
            this,
            &ExitGamePopUp::onNo);
    no_button->setColor(InfoStyles::COLOR_GREEN_LIGHT);
    CCLabelTTF* no_button_title = CCLabelTTF::create(_("ExitGame.No"),
                                                     ADLanguage::getFontName(),
                                                     InfoStyles::SIZE_BUTTON_POP_UP);

    no_button_title->setColor(InfoStyles::COLOR_WHITE);
    no_button_title->setAnchorPoint(ccp(0.5f,0.5f));
    no_button_title->setPosition(ccp(no_button->getContentSize().width*0.5f,
                                     no_button->getContentSize().height*0.5f));
    no_button->addChild(no_button_title);

    menu->addChild(no_button);


}

