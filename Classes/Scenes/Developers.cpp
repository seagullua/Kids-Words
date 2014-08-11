#include "developers.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
using namespace cocos2d;

Developers::Developers()
{
}

CCScene* Developers::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Developers *layer = Developers::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



Developers* Developers::create()
{

    Developers *pRet = new Developers();
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

void Developers::onBackClick()
{
    CCLog("Back clicked");
}

bool Developers::init()
{
    if(!SceneStyle::init())
        return false;

    //ADSoundManager::playMusic(GameInfo::MENU_MUSIC);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    //background
    CCSprite* background = CCSprite::create("universal/background_night.jpg");

    background->setPosition(ORIGIN + VISIBLE_SIZE*0.5f);
    this->addChild(background);


    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    this->addChild(menu);
    CCSprite* button_back_image = CCSprite::create("universal/back-button.png");

    ADMenuItem* button_back = ADMenuItem::create(button_back_image);
    float padding = 25/SCALE;
    //button back
    button_back->setPositionX(
                ORIGIN.x
                + padding
                + button_back->getContentSize().width*0.5f);

    button_back->setPositionY(ORIGIN.y +
                              + VISIBLE_SIZE.height-padding -
                              button_back->getContentSize().height*0.5f);
    CONNECT(button_back->signalOnClick, (SceneStyle*)this, &SceneStyle::simulateBackClick);

    menu->addChild(button_back);

    //diana
    CCSprite* diana_image = CCSprite::create("developers/diana.png");

    float padding_x2 = VISIBLE_SIZE.width/3;
    float padding_image_x = 160/SCALE;
    float padding_image_y = VISIBLE_SIZE.height/4;
    diana_image->setPositionX(
                ORIGIN.x + padding_x2-padding_image_x);

    diana_image->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y -
                              diana_image->getContentSize().height*0.5f);

    this->addChild(diana_image);
    cocos2d::CCLabelTTF* developers_scene_diana_title;
    developers_scene_diana_title = CCLabelTTF::create(_("developers_scene_diana.title"),
                                                      ADLanguage::getFontName(),
                                                      InfoStyles::SIZE_DEVELOPERS_TITLE);

    developers_scene_diana_title->setColor(InfoStyles::COLOR_WHITE);

    developers_scene_diana_title->setPositionX(
                ORIGIN.x + padding_x2*2);

    developers_scene_diana_title->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y -
                              diana_image->getContentSize().height*0.5f);

    this->addChild(developers_scene_diana_title);
    //andrii
    CCSprite* andrii_image = CCSprite::create("developers/andrii.png");

    andrii_image->setPositionX(
                ORIGIN.x + padding_x2-padding_image_x);

    andrii_image->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y*2 -
                               andrii_image->getContentSize().height*0.5f);

    this->addChild(andrii_image);
    cocos2d::CCLabelTTF* developers_scene_andrii_title;
    developers_scene_andrii_title = CCLabelTTF::create(_("developers_scene_andrii.title"),
                                                       ADLanguage::getFontName(),
                                                       InfoStyles::SIZE_DEVELOPERS_TITLE);

    developers_scene_andrii_title->setColor(InfoStyles::COLOR_WHITE);
    developers_scene_andrii_title->setPositionX(
                ORIGIN.x + padding_x2*3);

    developers_scene_andrii_title->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y*2 -
                               andrii_image->getContentSize().height*0.5f);


    this->addChild(developers_scene_andrii_title);
    //ruslana
    CCSprite* ruslana_image = CCSprite::create("developers/ruslana.png");

    ruslana_image->setPositionX(
                ORIGIN.x + padding_x2-padding_image_x);

    ruslana_image->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y*3 -
                               ruslana_image->getContentSize().height*0.5f);

    this->addChild(ruslana_image);
    cocos2d::CCLabelTTF* developers_scene_ruslana_title;
    developers_scene_ruslana_title = CCLabelTTF::create(_("developers_scene_ruslana.title"),
                                                       ADLanguage::getFontName(),
                                                       InfoStyles::SIZE_DEVELOPERS_TITLE);

    developers_scene_ruslana_title->setColor(InfoStyles::COLOR_WHITE);
    developers_scene_ruslana_title->setPositionX(
                ORIGIN.x + padding_x2*2);

    developers_scene_ruslana_title->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_image_y*3 -
                               ruslana_image->getContentSize().height*0.5f);

    this->addChild(developers_scene_ruslana_title);

    // 4 enjoy
    CCSprite* button_x4enjoy_image = CCSprite::create("universal/x4enjoy_small.png");

    ADMenuItem* button_x4enjoy = ADMenuItem::create(button_x4enjoy_image);
    float padding4enjoy = 5/SCALE;
    button_x4enjoy->setPositionX(
                ORIGIN.x + VISIBLE_SIZE.width
                - padding4enjoy
                - button_x4enjoy->getContentSize().width*0.45f);

    button_x4enjoy->setPositionY(ORIGIN.y + padding4enjoy +
                                 button_x4enjoy->getContentSize().height*0.5f);
    CONNECT(button_x4enjoy->signalOnClick, this, &Developers::onX4EnjoyClick);

    menu->addChild(button_x4enjoy);

    return true;
}

void Developers::onX4EnjoyClick()
{
    CCLog("X4Enjoy Clicked");
}
