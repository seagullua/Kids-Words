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

    //ADSoundManager::playMusic(GameInfo::MENU_MUSIC);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    showBackground(BackgroundType::Light);
    std::string GAME_VERSION = "uk";
    std::string image_name;

    //logo

    if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
    {
        image_name = "main-menu/name_en.png";
    }
    else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
    {
        image_name = "main-menu/name_uk.png";
    }
    else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
    {
        image_name = "main-menu/name_ru.png";
    }

    CCSprite* logo = CCSprite::create(image_name.c_str());

    logo->setPositionX(ORIGIN.x + VISIBLE_SIZE.width*0.5f);
    logo->setPositionY(ORIGIN.y + VISIBLE_SIZE.height*0.75f);
    this->addChild(logo);
    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    this->addChild(menu);
    CCSprite* button_play_image = CCSprite::create("main-menu/play-button.png");

    ADMenuItem* button_play = ADMenuItem::create(button_play_image);
    button_play->setPositionX(ORIGIN.x + VISIBLE_SIZE.width*0.5f);
    button_play->setPositionY(ORIGIN.y + VISIBLE_SIZE.height*0.35f);
    CONNECT(button_play->signalOnClick, this, &MainMenu::onPlayClick);

    menu->addChild(button_play);

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
