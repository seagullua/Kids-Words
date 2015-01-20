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

    ///////////////////////////////////
    //english word
    image_name = "main-menu/name_en.png";
    CCSprite* logo = CCSprite::create(image_name.c_str());

    logo->setPosition(ccp(ORIGIN.x - 200,
                          ORIGIN.y + VISIBLE_SIZE.height*0.6f));
    this->addChild(logo);
    logo->runAction(CCSequence::create(
                     CCDelayTime::create(2.9f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.4f,
                                         ccp(ORIGIN.x + VISIBLE_SIZE.width*0.7f,
                                             ORIGIN.y + VISIBLE_SIZE.height*0.6f))
                         ),
                     NULL
                 ));

    //////////////////////////////////////////////////////////
    //LEARN word

    float letter_y = ORIGIN.y+VISIBLE_SIZE.height*0.9;
    float letter_scale = (VISIBLE_SIZE.height/6);

    CCSprite* l = CCSprite::create("main-menu/l.png");
    l->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.2,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(l);
    l->setScale(letter_scale/l->getContentSize().height);
    l->runAction(CCSequence::create(
                     CCDelayTime::create(1.0f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.2,
                                             letter_y))
                         ),
                     NULL
                 ));
    ///////////////////////////////////

    CCSprite* e = CCSprite::create("main-menu/e.png");
    e->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.35,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(e);
    e->setScale(letter_scale/e->getContentSize().height);
    e->runAction(CCSequence::create(
                     CCDelayTime::create(1.4f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.35,
                                             letter_y))
                         ),
                     NULL
                 ));

    ///////////////////////////////
    CCSprite* a = CCSprite::create("main-menu/a.png");
    a->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(a);
    a->setScale(letter_scale/a->getContentSize().height);
    a->runAction(CCSequence::create(
                     CCDelayTime::create(1.8f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5,
                                             letter_y))
                         ),
                     NULL
                 ));

    ////////////////////////////////
    CCSprite* r = CCSprite::create("main-menu/r.png");
    r->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.65,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(r);
    r->setScale(letter_scale/r->getContentSize().height);
    r->runAction(CCSequence::create(
                     CCDelayTime::create(2.2f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.65,
                                             letter_y))
                         ),
                     NULL
                 ));

    ////////////////////////////////
    CCSprite* n = CCSprite::create("main-menu/n.png");
    n->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.8,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(n);
    n->setScale(letter_scale/n->getContentSize().height);
    n->runAction(CCSequence::create(
                     CCDelayTime::create(2.6f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.8,
                                             letter_y))
                         ),
                     NULL
                 ));

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
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,button_play_position)),
                               NULL
                           ));

    /////////////////////////////////////////////////
    CCSprite* button_settings_image = CCSprite::create("main-menu/settings-button.png");
    ADMenuItem* button_settings = ADMenuItem::create(button_settings_image);
    float padding = 35/SCALE;

    CCPoint button_settings_position = (ccp(ORIGIN.x + VISIBLE_SIZE.width - padding - button_settings->getContentSize().width*0.5f,
                                            ORIGIN.y + padding + button_settings->getContentSize().height*0.5f));

    button_settings->setPosition(ccp(button_settings_position.x,
                                     ORIGIN.y + VISIBLE_SIZE.height + button_settings->getContentSize().height/2));
    CONNECT(button_settings->signalOnClick, this, &MainMenu::onSettingsClick);
    menu->addChild(button_settings);

    //animation
    button_settings->runAction(CCSequence::create(
                               CCDelayTime::create(0.6f),
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,button_settings_position)),
                               NULL
                           ));

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
