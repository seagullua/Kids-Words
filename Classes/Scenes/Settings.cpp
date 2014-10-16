#include "Settings.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "developers.h"
#include "MainMenu.h"
#include "Managers/SettingsManager.h"
#include "PopUp/TurnOffPopUp.h"
#include "Managers/AdsManager.h"
//using namespace cocos2d;

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

    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}


bool Settings::init()
{
    if(!SceneStyle::init())
        return false;

    ADSoundManager::playMusic(InfoStyles::MENU_MUSIC);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    showBackground(BackgroundType::Dark);

    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    this->addChild(menu);

    showButtonBack();

    // 4 enjoy
    CCSprite* button_x4enjoy_image = CCSprite::create("universal/x4enjoy_small.png");

    ADMenuItem* button_x4enjoy = ADMenuItem::create(button_x4enjoy_image);
    float padding4enjoy = 5/SCALE;
    button_x4enjoy->setPositionX(
                ORIGIN.x + VISIBLE_SIZE.width
                - padding4enjoy
                - button_x4enjoy->getContentSize().width*0.45f);

    button_x4enjoy->setPositionY(ORIGIN.y + padding4enjoy +
                                 button_x4enjoy->getContentSize().height*0.45f);
    CONNECT(button_x4enjoy->signalOnClick, this, &Settings::onX4EnjoyClick);

    menu->addChild(button_x4enjoy);

    //music_on
    _button_music_on_image = CCSprite::create("settings/music-on.png");

    ADMenuItem* button_music_on = ADMenuItem::create(_button_music_on_image);
    //music_off
    _button_music_off_image = CCSprite::create("settings/music-off.png");
    _button_music_off_image->setAnchorPoint(ccp(0,0));
    float padding_x2 = VISIBLE_SIZE.width/2;
    float padding_music_x = 160/SCALE;
    float padding_music_y = 30/SCALE;
    button_music_on->setPositionX(
                ORIGIN.x + padding_x2-padding_music_x);

    button_music_on->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                  button_music_on->getContentSize().height*0.5f);
    CONNECT(button_music_on->signalOnClick, this, &Settings::onMusicOnClick);

    menu->addChild(button_music_on);
    button_music_on->addChild(_button_music_off_image);

    //sounds_on
    _button_sounds_on_image = CCSprite::create("settings/sounds-on.png");

    //sounds_off
    _button_sounds_off_image = CCSprite::create("settings/sounds-off.png");
    _button_sounds_off_image->setAnchorPoint(ccp(0,0));

    ADMenuItem* button_sounds_on = ADMenuItem::create(_button_sounds_on_image);

    button_sounds_on->setPositionX(
                ORIGIN.x +  padding_x2+padding_music_x);

    button_sounds_on->setPositionY(ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                   button_music_on->getContentSize().height*0.5f);
    CONNECT(button_sounds_on->signalOnClick, this, &Settings::onSoundsOnClick);

    button_sounds_on->addChild(_button_sounds_off_image);
    menu->addChild(button_sounds_on);
    correctMusicEffects(EffectsType::Sound);
    correctMusicEffects(EffectsType::Music);
    float empty_space = VISIBLE_SIZE.height - button_music_on->getContentSize().height
            - padding_music_y - button_x4enjoy_image->getContentSize().height;
    bool show_purchase = InfoStyles::showPurchase();

    //developers

    cocos2d::CCLabelTTF* settings_scene_developers_title;
    settings_scene_developers_title = CCLabelTTF::create(_("settings_scene_developers.title"),
                                                         ADLanguage::getFontName(),
                                                         InfoStyles::SIZE_SETTINGS_BUTTON);

    settings_scene_developers_title->setColor(InfoStyles::COLOR_WHITE);
    ADMenuItem* button_developers = ADMenuItem::create(settings_scene_developers_title);

    button_developers->setPositionX(
                ORIGIN.x +  padding_x2);

    empty_space -= button_developers->getContentSize().height*3;
    if(empty_space < 0)
    {
        empty_space = 0;
    }
    float button_sounds_on_position =0;
    button_sounds_on_position = button_sounds_on->getPositionY()-button_sounds_on->getContentSize().height*0.5f - empty_space;
    if (!show_purchase)
    {
        button_sounds_on_position -= button_developers->getContentSize().height;

    }


    button_developers->setPositionY(button_sounds_on_position);
    CONNECT(button_developers->signalOnClick, this, &Settings::onDevelopersClick);

    menu->addChild(button_developers);

    if (show_purchase)
    {
        CONNECT(AdsManager::getInstance()->signalAdsWasDisabled, this, &Settings::onAdsWasDisabled);
        //restore_purchase

        cocos2d::CCLabelTTF* settings_scene_restore_purchase_title;
        settings_scene_restore_purchase_title = CCLabelTTF::create(_("settings_scene_restore_purchase.title"),
                                                                   ADLanguage::getFontName(),
                                                                   InfoStyles::SIZE_SETTINGS_BUTTON);

        settings_scene_restore_purchase_title->setColor(InfoStyles::COLOR_WHITE);
        ADMenuItem* button_restore_purchase = ADMenuItem::create(settings_scene_restore_purchase_title);

        button_restore_purchase->setPositionX(
                    ORIGIN.x +  padding_x2);


        float button_developers_position = button_developers->getPositionY()-button_developers->getContentSize().height;

        button_restore_purchase->setPositionY(button_developers_position);
        CONNECT(button_restore_purchase->signalOnClick, this, &Settings::onRestorePurchaseClick);

        menu->addChild(button_restore_purchase);

        //turn_off_ads
        CCSprite* button_turn_off_ads_image = CCSprite::create("settings/no_ads_tile.png");

        ADMenuItem* button_turn_off_ads = ADMenuItem::create(button_turn_off_ads_image);

        button_turn_off_ads->setPositionX(
                    ORIGIN.x +  padding_x2);

        float button_restore_purchase_position = button_restore_purchase->getPositionY()-button_turn_off_ads->getContentSize().height;

        button_turn_off_ads->setPositionY(button_restore_purchase_position);
        CONNECT(button_turn_off_ads->signalOnClick, this, &Settings::onTurnOffAdsClick);


        CCSprite* button_pinguine_image = CCSprite::create("settings/pinguine.png");

        CCSize button_size(button_turn_off_ads_image->getContentSize());
        button_pinguine_image->setScale(0.8f * button_size.height / button_pinguine_image->getContentSize().height);
        float button_half_height = button_size.height * 0.5f;
        button_pinguine_image->setPosition(ccp(button_half_height, button_half_height));
        button_turn_off_ads->addChild(button_pinguine_image);

        cocos2d::CCLabelTTF* turn_off_ads_title;
        turn_off_ads_title = CCLabelTTF::create(_("settings_scene_turn_off_ads_title.title"),
                                                ADLanguage::getFontName(),
                                                InfoStyles::SIZE_SETTINGS_BUTTON_TURN);
        turn_off_ads_title->setAnchorPoint(ccp(0, 0.5f));
        turn_off_ads_title->setPosition(ccp(button_half_height*2,
                                            button_half_height));
        turn_off_ads_title->setColor(InfoStyles::COLOR_BLUE);

        float label_max_width = button_size.width - button_half_height*2.5f;
        float label_width = turn_off_ads_title->getContentSize().width;
        if(label_width > label_max_width)
        {
            turn_off_ads_title->setScale(label_max_width/turn_off_ads_title->getContentSize().width);
        }

        button_turn_off_ads->addChild(turn_off_ads_title);
        //settings_scene_turn_off_ads_title->setPositionX();
        menu->addChild(button_turn_off_ads);
    }


    return true;
}
void Settings::onMusicOnClick()
{
    SettingsManager::getInstance()->setMusic(!SettingsManager::getInstance()->isMusicOn());
    Settings::correctMusicEffects(EffectsType::Music);
}

void Settings::onSoundsOnClick()
{
    SettingsManager::getInstance()->setSound(!SettingsManager::getInstance()->isSoundOn());
    Settings::correctMusicEffects(EffectsType::Sound);
}

void Settings::onDevelopersClick()
{
    CCDirector::sharedDirector()->replaceScene(Developers::scene());
}

void Settings::onRestorePurchaseClick()
{
    ADInApp::restorePurchases();
}

void Settings::onTurnOffAdsClick()
{

    _pop_up_manager.openWindow(new TurnOffPopUp(this));

}
void Settings::onX4EnjoyClick()
{
    ADBrowser::openWebURL("http://4enjoy.com");

}
void Settings::correctMusicEffects(EffectsType type)
{
    if(type==EffectsType::Music)
    {
        if(SettingsManager::getInstance()->isMusicOn())
        {
            _button_music_off_image->setVisible(false);
            _button_music_on_image->setVisible(true);
        }
        else
        {
            _button_music_on_image->setVisible(false);
            _button_music_off_image->setVisible(true);
        }
    }
    else
    {
        if(SettingsManager::getInstance()->isSoundOn())
        {
            _button_sounds_off_image->setVisible(false);
            _button_sounds_on_image->setVisible(true);
        }
        else
        {
            _button_sounds_on_image->setVisible(false);
            _button_sounds_off_image->setVisible(true);
        }
    }
}

void Settings::onAdsWasDisabled()
{
    CCDirector::sharedDirector()->replaceScene(Settings::scene());
}
