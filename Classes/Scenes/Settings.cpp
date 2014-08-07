#include "Settings.h"
#include <ADLib/ADString.h>

using namespace cocos2d;

Settings::Settings()
{
}

CCScene* Settings::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Settings *layer = Settings::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


Settings* Settings::create()
{

    Settings *pRet = new Settings();
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

void Settings::onBackClick()
{
    CCLog("Back clicked");
}

bool Settings::init()
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
     float padding = 35/SCALE;
    button_back->setPositionX(
                ORIGIN.x
                + padding
                + button_back->getContentSize().width*0.5f);

    button_back->setPositionY(ORIGIN.y +
                              + VISIBLE_SIZE.height-padding -
                                  button_back->getContentSize().height*0.5f);
    CONNECT(button_back->signalOnClick, (SceneStyle*)this, &SceneStyle::simulateBackClick);

    menu->addChild(button_back);

    CCSprite* button_music_on_image = CCSprite::create("settings/music-on.png");

    ADMenuItem* button_music_on = ADMenuItem::create(button_music_on_image);
    float padding_music_x = VISIBLE_SIZE.width/3;
    float padding_music_y = 55/SCALE;
    button_music_on->setPositionX(
                ORIGIN.x + padding_music_x);

    button_music_on->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                  button_music_on->getContentSize().height*0.5f);
    CONNECT(button_music_on->signalOnClick, this, &Settings::onMusicOnClick);

    menu->addChild(button_music_on);



    CCSprite* button_sounds_on_image = CCSprite::create("settings/sounds-on.png");

    ADMenuItem* button_sounds_on = ADMenuItem::create(button_sounds_on_image);

    button_sounds_on->setPositionX(
                ORIGIN.x + 2*padding_music_x);

    button_sounds_on->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                  button_music_on->getContentSize().height*0.5f);
    CONNECT(button_sounds_on->signalOnClick, this, &Settings::onSoundsOnClick);

    menu->addChild(button_sounds_on);

    return true;
}
void Settings::onMusicOnClick()
{
    CCLog("MusicOn Clicked");
}
void Settings::onSoundsOnClick()
{
    CCLog("Sounds Clicked");
}
