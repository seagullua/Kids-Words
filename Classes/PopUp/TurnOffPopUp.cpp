#include "TurnOffPopUp.h"
#include <ADLib/PopUp/ADPopUpWindow.h>
#include "InfoStyles.h"
#include "ADLib.h"
#include "Scenes/Settings.h"
#include "Managers/AdsManager.h"
using namespace cocos2d;



//TurnOffPopUp::TurnOffPopUp(cocos2d::CCNode* parent):
//    IADStandardWindow(CCSize(1,1),
//                      InfoStyles::COLOR_BLUE,
//                      Animation::DownToTop),
//    _parent(parent)
//{
//}
//void TurnOffPopUp::onCreate(cocos2d::CCNode *parent)
//{

//    const float SCALE = ADScreen::getScaleFactor();
//    float padding = 25/SCALE;

//    //background
//    CCSprite* background = CCSprite::create("pop-ups/pop-up-background.png");

//    background->setPosition(ccp(0,0));
//    parent->addChild(background);


//    cocos2d::CCSize size = background->getContentSize();
//    float x_middle = size.width / 2;
//    float label_max_width = size.width*0.8f;


//    //label
//    cocos2d::CCLabelTTF* label = cocos2d::CCLabelTTF::create(_("pop_up_turn_off.title"),
//                                                             ADLanguage::getFontName(),
//                                                             InfoStyles::SIZE_MENU_TITLE_POP_UP);
//    float label_width = label->getContentSize().width;
//    if(label_width > label_max_width)
//    {
//        label->setScale(label_max_width/label_width);
//    }

//    label->setColor(InfoStyles::COLOR_BLUE);
//    label->setPosition(ccp(x_middle, size.height*0.8f));
//    background->addChild(label);

//    ///////////////////////////////////////////////////////

//    cocos2d::CCMenu* menu = cocos2d::CCMenu::create();
//    menu->setPosition(0,0);
//    background->addChild(menu);

//    float vertical = size.height * 0.25f;
//    cocos2d::CCSize button_size(size.width*0.25,size.width*0.15);

//    ///////////////////////////////////////////////////////
//    // button no later
//    CCSprite* button_no_image = CCSprite::create("pop-ups/no-ads/no-ads-button.png");

//    ADMenuItem* button_no = ADMenuItem::create(button_no_image);


//    button_no->setPosition(ccp(size.width*0.275f, vertical));
//    CONNECT(button_no->signalOnClick,
//            this,
//            &TurnOffPopUp::onNo);
//    button_no->setColor(InfoStyles::COLOR_DARK_LIGHT);
//    CCLabelTTF* button_no_title = CCLabelTTF::create(_("pop_up_turn_off.no"),
//                                                     ADLanguage::getFontName(),
//                                                     InfoStyles::SIZE_BUTTON_POP_UP);

//    button_no_title->setColor(InfoStyles::COLOR_WHITE);
//    button_no_title->setAnchorPoint(ccp(0.5f,0.5f));
//    button_no_title->setPosition(ccp(button_no->getContentSize().width*0.5f,
//                                     button_no->getContentSize().height*0.5f));
//    button_no->addChild(button_no_title);

//    menu->addChild(button_no);


//    //////////////////////////////////////////////////////

//    //button add
//    CCSprite* button_add_image = CCSprite::create("pop-ups/no-ads/no-ads-button.png");

//    ADMenuItem* button_add = ADMenuItem::create(button_add_image);
//    button_add->setPosition(ccp(size.width*0.725f, vertical));
//    CONNECT(button_add->signalOnClick,
//            this,
//            &TurnOffPopUp::onAdd);
//    button_add->setColor(InfoStyles::COLOR_YELLOW_LIGHT);
//    CCLabelTTF* button_add_title = CCLabelTTF::create(_("pop_up_turn_off.add"),
//                                                      ADLanguage::getFontName(),
//                                                      InfoStyles::SIZE_BUTTON_POP_UP);


//    float label_add_max_width = button_add->getContentSize().width*0.8f;
//    float label_width_add_title = button_add_title->getContentSize().width;
//    if(label_width_add_title > label_add_max_width)
//    {
//        button_add_title->setScale(label_add_max_width/label_width_add_title);
//    }

//    button_add_title->setColor(InfoStyles::COLOR_BLUE);
//    button_add_title->setAnchorPoint(ccp(0.5f,0));
//    button_add_title->setPosition(ccp(button_add->getContentSize().width*0.5f,
//                                      button_add->getContentSize().height*0.5f));
//    button_add->addChild(button_add_title);

//    menu->addChild(button_add);
//    _price = "$0.99";
//    _price_label= CCLabelTTF::create(_price.c_str(),
//                                     ADLanguage::getFontName(),
//                                     InfoStyles::SIZE_BUTTON_POP_UP*0.7f);

//    _price_label->setColor(InfoStyles::COLOR_BLUE);
//    _price_label->setAnchorPoint(ccp(0.5f,0));
//    _price_label->setPosition(ccp(button_no->getContentSize().width*0.5f,button_add->getContentSize().height*0.15f));
//    button_add->addChild(_price_label);
//    // pinguine and text add


//    CCSprite* button_pinguine_image = CCSprite::create("settings/pinguine.png");

//    button_pinguine_image->setScale(0.5f);
//    button_pinguine_image->setAnchorPoint(ccp(0,0));
//    button_pinguine_image->setPositionX(padding*5);
//    button_pinguine_image->setPositionY(button_no->getPositionY()+padding*3.5f);
//    background->addChild(button_pinguine_image);
//    cocos2d::CCLabelTTF* turn_off_ads_title;
//    turn_off_ads_title = CCLabelTTF::create(_("pop_up_turn_off.text"),
//                                            ADLanguage::getFontName(),
//                                            InfoStyles::SIZE_BUTTON_POP_UP);
//    turn_off_ads_title->setAnchorPoint(ccp(0, 0));
//    turn_off_ads_title->setPositionX(padding*14);
//    turn_off_ads_title->setPositionY(button_no->getPositionY()+padding+button_pinguine_image->getContentSize().height*0.25f);
//    turn_off_ads_title->setColor(InfoStyles::COLOR_BLUE);


//    float label_turn_off_max_width = size.width*0.55f;
//    float label_width_turn_off = turn_off_ads_title->getContentSize().width;
//    if(label_width_turn_off > label_turn_off_max_width)
//    {
//        turn_off_ads_title->setScale(label_turn_off_max_width/label_width_turn_off);
//    }

//    background->addChild(turn_off_ads_title);

//}

//void TurnOffPopUp::onNo()
//{
//    CCDirector::sharedDirector()->replaceScene(Settings::scene());

//}

//void TurnOffPopUp::onAdd()
//{

//    ADInApp::buyProduct(InfoStyles::getPurchaseID());
//    //

//}
//void TurnOffPopUp::setPrice(std::string price)
//{
//    _price = price;
//    _price_label->setString(_price.c_str());

//}
