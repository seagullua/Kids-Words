#include "MainMenu.h"
#include "Settings.h"
#include "SelectCollection.h"
#include <ADLib/ADString.h>
#include "PopUp/ExitGamePopUp.h"
#include "InfoStyles.h"


using namespace cocos2d;

MainMenu::MainMenu()
{
}

CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


MainMenu* MainMenu::create()
{

    MainMenu *pRet = new MainMenu();
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

void MainMenu::onBackClick()
{
    _pop_up_manager.openWindow(new ExitGamePopUp(this));

}

bool MainMenu::init()
{
    if(!SceneStyle::init())
        return false;


    ADSoundManager::playMusic(InfoStyles::MENU_MUSIC);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    showBackground(BackgroundType::Light);
    std::string image_name;

    //logo
    image_name = "main-menu/name_en.png";
    CCSprite* logo = CCSprite::create(image_name.c_str());

    logo->setPositionX(ORIGIN.x + VISIBLE_SIZE.width*0.7f);
    logo->setPositionY(ORIGIN.y + VISIBLE_SIZE.height*0.6f);
    this->addChild(logo);

    //////////////////////////////////////////////////////////
    //main logo
    CCSprite* l = CCSprite::create("main-menu/l.png");
    l->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.2,
                             ORIGIN.y+VISIBLE_SIZE.height*0.85));
    this->addChild(l);
//    l->runAction(CCRepeatForever::create(
//                               CCSequence::create(
//                                    (CCRotateTo::create(0.3,-10.0f)),
//                                    (CCRotateTo::create(0.6,+20.0f)),
//                                    (CCRotateTo::create(0.3,-10.0f)),
//                                    NULL)
//                               )
//                            );

    CCSprite* e = CCSprite::create("main-menu/e.png");
    e->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.35,
                             ORIGIN.y+VISIBLE_SIZE.height*0.85));
    this->addChild(e);

    CCSprite* a = CCSprite::create("main-menu/a.png");
    a->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5,
                             ORIGIN.y+VISIBLE_SIZE.height*0.85));
    this->addChild(a);

    CCSprite* r = CCSprite::create("main-menu/r.png");
    r->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.65,
                             ORIGIN.y+VISIBLE_SIZE.height*0.85));
    this->addChild(r);

    CCSprite* n = CCSprite::create("main-menu/n.png");
    n->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.8,
                             ORIGIN.y+VISIBLE_SIZE.height*0.85));
    this->addChild(n);

    ///////////////////////////////////////////////////////////
    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));
    this->addChild(menu);


    ////////////////////////////////////////////////////
    CCSprite* button_play_image = CCSprite::create("main-menu/play-button.png");
    ADMenuItem* button_play = ADMenuItem::create(button_play_image);
    button_play->setPosition(ccp(ORIGIN.x + VISIBLE_SIZE.width*0.5f,
                                 ORIGIN.y + VISIBLE_SIZE.height + button_play_image->getContentSize().height));
    CCPoint button_play_position = (ccp(ORIGIN.x + VISIBLE_SIZE.width*0.5f,
                                        ORIGIN.y + VISIBLE_SIZE.height*0.3f));
    CONNECT(button_play->signalOnClick, this, &MainMenu::onPlayClick);
    menu->addChild(button_play);

    //animation
    button_play->runAction(CCSequence::create(
                               CCDelayTime::create(0.2f),
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,button_play_position)),
                               NULL
                           ));

    /////////////////////////////////////////////////
    CCSprite* button_settings_image = CCSprite::create("main-menu/settings-button.png");
    ADMenuItem* button_settings = ADMenuItem::create(button_settings_image);
    float padding = 35/SCALE;
    button_settings->setPositionX(
                ORIGIN.x + VISIBLE_SIZE.width
                - padding
                - button_settings->getContentSize().width*0.5f);
    button_settings->setPositionY(ORIGIN.y + padding +
                                  button_settings->getContentSize().height*0.5f);
    CONNECT(button_settings->signalOnClick, this, &MainMenu::onSettingsClick);
    menu->addChild(button_settings);

    return true;
}


void MainMenu::onPlayClick()
{
    CCDirector::sharedDirector()->replaceScene(SelectCollection::scene());

}
void MainMenu::onSettingsClick()
{

    CCDirector::sharedDirector()->replaceScene(Settings::scene());
}
