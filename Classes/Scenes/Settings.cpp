#include "Settings.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "developers.h"
#include "MainMenu.h"
#include "Managers/SettingsManager.h"
#include "PopUp/TurnOffPopUp.h"
#include "Managers/AdsManager.h"
using namespace cocos2d;


class TurnOffPopUpSure: public IADStandardWindow
{

public:
    TurnOffPopUpSure()
        : IADStandardWindow(getSize(),
                           ccc3(230,103,181),
                           Animation::TopToDown)
    {

    }
    static cocos2d::CCSize getSize()
    {
        CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
        return CCSize(VISIBLE_SIZE.width, VISIBLE_SIZE.height*0.4f);
    }

private:
    void onCreate(cocos2d::CCNode* parent)
    {
        CCMenu* menu = CCMenu::create();
        menu->setPosition(ccp(0,0));
        parent->addChild(menu);

        CCPoint ORIGIN = ADScreen::getOrigin();
        CCSize size = parent->getContentSize();
        float SCALE = ADScreen::getScaleFactor();

        //title
        CCLabelTTF* exit_title = CCLabelTTF::create(_("pop_up_turn_off.title"),
                                                    ADLanguage::getFontName(),
                                                    80);
        CCPoint target_exit_position(ccp(size.width*0.5f,
                                         size.height*0.65f + 50/SCALE));
        exit_title->setPosition(ccp(ORIGIN.x-exit_title->getContentSize().width,
                                    size.height*0.5f + 50/SCALE));
        parent->addChild(exit_title);
        exit_title->runAction(CCEaseBackOut::create(
                            CCMoveTo::create(1.2f,target_exit_position))
                         );

        CCLabelTTF* info_title = CCLabelTTF::create(_("pop_up_turn_off.click_green_button"),
                                                          ADLanguage::getFontName(),
                                                          40);
//        ADMenuItem* yes_button = ADMenuItem::create(yes_button_title);
//        CONNECT(yes_button->signalOnClick,
//                this,
//                &TurnOffPopUp::onNo);
        CCPoint info_title_position(ccp(size.width*0.5f,
                                 size.height*0.65f - 20/SCALE));
        info_title->setPosition(ccp(size.width*0.5f,
                                    size.height+info_title->getContentSize().height));
        parent->addChild(info_title);
        info_title->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,info_title_position))
                               );

        /////////////////////////////////
        CCSprite* bouble_1 = CCSprite::create("level-scene/bouble.png");
        bouble_1->setScale(0.8f);
        bouble_1->setColor(ccc3(43,255,21));
        ADMenuItem* bouble_1_button = ADMenuItem::create(bouble_1);
        CONNECT(bouble_1_button->signalOnClick,
                this,
                &TurnOffPopUpSure::onNo);
        CCPoint bouble_1_position(ccp(size.width*0.35f,
                                 size.height*0.45f - 70/SCALE));
        bouble_1_button->setPosition(ccp(size.width*0.45f,
                                    size.height+bouble_1_button->getContentSize().height));
        menu->addChild(bouble_1_button);
        bouble_1_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,bouble_1_position))
                               );

        /////////////////////////////////
        CCSprite* bouble_2 = CCSprite::create("level-scene/bouble.png");
        bouble_2->setColor(ccc3(98,216,255));
        bouble_2->setScale(0.8f);
        ADMenuItem* bouble_2_button = ADMenuItem::create(bouble_2);
        CONNECT(bouble_2_button->signalOnClick,
                this,
                &TurnOffPopUpSure::onAdd);
        CCPoint bouble_2_position(ccp(size.width*0.5f,
                                 size.height*0.45f - 70/SCALE));
        bouble_2_button->setPosition(ccp(size.width*0.45f,
                                    size.height+bouble_2_button->getContentSize().height));
        menu->addChild(bouble_2_button);
        bouble_2_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,bouble_2_position))
                               );

        /////////////////////////////////
        CCSprite* bouble_3 = CCSprite::create("level-scene/bouble.png");
        bouble_3->setColor(ccc3(255,138,0));
        bouble_3->setScale(0.8f);
        ADMenuItem* bouble_3_button = ADMenuItem::create(bouble_3);
        CONNECT(bouble_3_button->signalOnClick,
                this,
                &TurnOffPopUpSure::onNo);
        CCPoint bouble_3_position(ccp(size.width*0.65f,
                                 size.height*0.45f - 70/SCALE));
        bouble_3_button->setPosition(ccp(size.width*0.45f,
                                    size.height+bouble_3_button->getContentSize().height));
        menu->addChild(bouble_3_button);
        bouble_3_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,bouble_3_position))
                               );

    }


    void onNo()
    {
        CCDirector::sharedDirector()->replaceScene(Settings::scene());
    }

    void onAdd()
    {
        ADInApp::buyProduct(InfoStyles::getPurchaseID());

    }

};

class TurnOffPopUp: public IADStandardWindow
{

public:
    TurnOffPopUp()
        : IADStandardWindow(getSize(),
                           ccc3(230,103,181),
                           Animation::TopToDown)
    {

    }
    static cocos2d::CCSize getSize()
    {
        CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
        return CCSize(VISIBLE_SIZE.width, VISIBLE_SIZE.height*0.4f);
    }

private:
    void onCreate(cocos2d::CCNode* parent)
    {
        CCMenu* menu = CCMenu::create();
        menu->setPosition(ccp(0,0));
        parent->addChild(menu);

        CCPoint ORIGIN = ADScreen::getOrigin();
        CCSize size = parent->getContentSize();
        float SCALE = ADScreen::getScaleFactor();

        //title
        CCLabelTTF* exit_title = CCLabelTTF::create(_("pop_up_turn_off.title"),
                                                    ADLanguage::getFontName(),
                                                    80);
        CCPoint target_exit_position(ccp(size.width*0.5f,
                                         size.height*0.5f + 50/SCALE));
        exit_title->setPosition(ccp(ORIGIN.x-exit_title->getContentSize().width,
                                    size.height*0.5f + 50/SCALE));
        parent->addChild(exit_title);
        exit_title->runAction(CCEaseBackOut::create(
                            CCMoveTo::create(1.2f,target_exit_position))
                         );

        CCLabelTTF* yes_button_title = CCLabelTTF::create(_("pop_up_turn_off.no"),
                                                          ADLanguage::getFontName(),
                                                          InfoStyles::SIZE_BUTTON_POP_UP);
        ADMenuItem* yes_button = ADMenuItem::create(yes_button_title);
        CONNECT(yes_button->signalOnClick,
                this,
                &TurnOffPopUp::onNo);
        CCPoint yes_position(ccp(size.width*0.25f,
                                 size.height*0.5f - 70/SCALE));
        yes_button->setPosition(ccp(size.width*0.45f,
                                    size.height+yes_button->getContentSize().height));
        menu->addChild(yes_button);
        yes_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,yes_position))
                               );


        std::string price = "$0.99";
        const char* turn_adds = _("pop_up_turn_off.add");//+price;
        CCLabelTTF* no_button_title = CCLabelTTF::create(turn_adds,
                                                          ADLanguage::getFontName(),
                                                          InfoStyles::SIZE_BUTTON_POP_UP);
        ADMenuItem* no_button = ADMenuItem::create(no_button_title);
        CONNECT(no_button->signalOnClick,
                this,
                &TurnOffPopUp::onAdd);
        CCPoint no_position(ccp(size.width*0.75f,
                                size.height*0.5f - 70/SCALE));
        no_button->setPosition(ccp(size.width*0.55f,
                                   size.height+no_button->getContentSize().height));
        no_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,no_position))
                               );
        menu->addChild(no_button);

    }


    void onNo()
    {
        CCDirector::sharedDirector()->replaceScene(Settings::scene());

    }

    void onAdd()
    {

        ADInApp::buyProduct(InfoStyles::getPurchaseID());
        //

    }
    void setPrice(std::string price)
    {
        //_price = price;
        //_price_label->setString(_price.c_str());

    }

};

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
    hideEverything([](){
            CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
        });
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

    _button_x4enjoy = ADMenuItem::create(button_x4enjoy_image);
    float padding4enjoy = 5/SCALE;
    float padding = 20/SCALE;
    _button_x4enjoy->setAnchorPoint(ccp(0,0));
    _button_x4enjoy->setScale(_button_x4enjoy->getScale()*0.9f);
    _button_x4enjoy->setPositionX(
                ORIGIN.x + VISIBLE_SIZE.width
                - padding4enjoy
                - _button_x4enjoy->getContentSize().width);

    _button_x4enjoy->setPositionY(ORIGIN.y + padding4enjoy );
    CONNECT(_button_x4enjoy->signalOnClick, this, &Settings::onX4EnjoyClick);

    menu->addChild(_button_x4enjoy);
    //animation
    _button_x4enjoy->setOpacity(0);
    _button_x4enjoy->runAction(CCSequence::create(
                     CCDelayTime::create(0.2f),
                     CCFadeTo::create(0.8f,255),
                     NULL
                 ));


    ////////////////////////////////////////////////
    // author of music
    _author_of_music_title = CCLabelTTF::create(" Music MarcoKuell Cute",
                                               ADLanguage::getFontName(),
                                               InfoStyles::SIZE_LINE_TITLE);

    _author_of_music_title->setColor(InfoStyles::COLOR_TITLE);
    _author_of_music_title->setAnchorPoint(ccp(0,0));
    _author_of_music_title->setPositionX(
                ORIGIN.x + padding4enjoy*4);

    _author_of_music_title->setPositionY(ORIGIN.y
                                        + padding4enjoy);

    this->addChild(_author_of_music_title);

    //animation
    _author_of_music_title->setOpacity(0);
    _author_of_music_title->runAction(CCSequence::create(
                     CCDelayTime::create(0.4f),
                     CCFadeTo::create(0.8f,255),
                     NULL
                 ));


    ////////////////////////////////////////////////////
    //music_on
    _button_music_on_image = CCSprite::create("settings/music-on.png");

    _button_music_on = ADMenuItem::create(_button_music_on_image);
    //music_off
    _button_music_off_image = CCSprite::create("settings/music-off.png");
    _button_music_off_image->setAnchorPoint(ccp(0,0));
    float padding_x2 = VISIBLE_SIZE.width/2;
    float padding_music_x = 160/SCALE;
    float padding_music_y = 30/SCALE;
    _button_music_on->setPosition(ccp(ORIGIN.x + padding_x2-padding_music_x,
                                    ORIGIN.y + VISIBLE_SIZE.height+ _button_music_on->getContentSize().height));
    CONNECT(_button_music_on->signalOnClick, this, &Settings::onMusicOnClick);

    menu->addChild(_button_music_on);
    _button_music_on->addChild(_button_music_off_image);
    //animation
    CCPoint music_target_pos = ccp(ORIGIN.x + padding_x2-padding_music_x,
                                   ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                 _button_music_on->getContentSize().height*0.5f);
    _button_music_on->runAction(CCSequence::create(
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,music_target_pos)),
                               NULL
                           ));


    ///////////////////////////////////////////////
    //sounds_on
    _button_sounds_on_image = CCSprite::create("settings/sounds-on.png");

    //sounds_off
    _button_sounds_off_image = CCSprite::create("settings/sounds-off.png");
    _button_sounds_off_image->setAnchorPoint(ccp(0,0));

    _button_sounds_on = ADMenuItem::create(_button_sounds_on_image);

    _button_sounds_on->setPosition(ccp(ORIGIN.x +  padding_x2+padding_music_x,
                                      ORIGIN.y + VISIBLE_SIZE.height + _button_music_on->getContentSize().height));
    CONNECT(_button_sounds_on->signalOnClick, this, &Settings::onSoundsOnClick);

    _button_sounds_on->addChild(_button_sounds_off_image);
    menu->addChild(_button_sounds_on);

    CCPoint sound_target_pos = ccp(ORIGIN.x +  padding_x2+padding_music_x,
                                   ORIGIN.y + VISIBLE_SIZE.height- padding_music_y -
                                   _button_music_on->getContentSize().height*0.5f);
    _button_sounds_on->runAction(CCSequence::create(
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,sound_target_pos)),
                               NULL
                           ));


    ///////////////////////////////////////////////////

    correctMusicEffects(EffectsType::Sound);
    correctMusicEffects(EffectsType::Music);
    float empty_space = VISIBLE_SIZE.height - _button_music_on->getContentSize().height
            - padding_music_y - button_x4enjoy_image->getContentSize().height;
    bool show_purchase = InfoStyles::showPurchase();

    ////////////////////////////////////////////////////

    //developers
    cocos2d::CCLabelTTF* settings_scene_developers_title;
    settings_scene_developers_title = CCLabelTTF::create(_("settings_scene_developers.title"),
                                                         ADLanguage::getFontName(),
                                                         InfoStyles::SIZE_SETTINGS_BUTTON);

    settings_scene_developers_title->setColor(InfoStyles::COLOR_TITLE);
    _button_developers = ADMenuItem::create(settings_scene_developers_title);

    _button_developers->setPositionX(ORIGIN.x - settings_scene_developers_title->getContentSize().width);
    empty_space -= _button_developers->getContentSize().height*3;
    if(empty_space < 0)
    {
        empty_space = 0;
    }
    float button_sounds_on_position =0;
    button_sounds_on_position = sound_target_pos.y-_button_sounds_on->getContentSize().height*0.5f - empty_space;
    if (!show_purchase)
    {
        button_sounds_on_position -= _button_developers->getContentSize().height;

    }

    _button_developers->setPositionY(button_sounds_on_position);
    CONNECT(_button_developers->signalOnClick, this, &Settings::onDevelopersClick);

    menu->addChild(_button_developers);
    float button_developers_height = _button_developers->getContentSize().height;

    _button_developers->runAction(CCSequence::create(
                     CCDelayTime::create(0.5f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.4f,
                                         ccp(ORIGIN.x +  padding_x2,
                                             button_sounds_on_position))
                         ),
                     NULL
                 ));

    ////////////////////////////////////////////////
    if (show_purchase)
    {
        CONNECT(AdsManager::getInstance()->signalAdsWasDisabled, this, &Settings::onAdsWasDisabled);
        //restore_purchase

        cocos2d::CCLabelTTF* settings_scene_restore_purchase_title;
        settings_scene_restore_purchase_title = CCLabelTTF::create(_("settings_scene_restore_purchase.title"),
                                                                   ADLanguage::getFontName(),
                                                                   InfoStyles::SIZE_SETTINGS_BUTTON);

        settings_scene_restore_purchase_title->setColor(InfoStyles::COLOR_TITLE);
        _button_restore_purchase = ADMenuItem::create(settings_scene_restore_purchase_title);

        _button_restore_purchase->setPositionX(ORIGIN.x - settings_scene_developers_title->getContentSize().width);


        float button_developers_position = _button_developers->getPositionY()-button_developers_height;

        _button_restore_purchase->setPositionY(button_developers_position);
        CONNECT(_button_restore_purchase->signalOnClick,
                this,
                &Settings::onRestorePurchaseClick);

        menu->addChild(_button_restore_purchase);
        _button_restore_purchase->runAction(CCSequence::create(
                         CCDelayTime::create(1.1f),
                         CCEaseElasticOut::create(
                            CCMoveTo::create(1.4f,
                                             ccp(ORIGIN.x +  padding_x2,
                                                 button_developers_position))
                             ),
                         NULL
                     ));


        /////////////////////////////////////////////////////
        //turn_off_ads
        CCSprite* button_turn_off_ads_image = CCSprite::create("settings/no_ads_tile.png");

        _button_turn_off_ads = ADMenuItem::create(button_turn_off_ads_image);

        _button_turn_off_ads->setPositionX(ORIGIN.x -  settings_scene_developers_title->getContentSize().width);
        float button_restore_purchase_position = _button_restore_purchase->getPositionY()-button_developers_height-padding;

        _button_turn_off_ads->setPositionY(button_restore_purchase_position);
        CONNECT(_button_turn_off_ads->signalOnClick, this, &Settings::onTurnOffAdsClick);


        CCSprite* button_pinguine_image = CCSprite::create("settings/pinguine.png");

        CCSize button_size(button_turn_off_ads_image->getContentSize());
        button_pinguine_image->setScale(0.8f * button_size.height / button_pinguine_image->getContentSize().height);
        float button_half_height = button_size.height * 0.5f;
        button_pinguine_image->setPosition(ccp(button_half_height, button_half_height));
        _button_turn_off_ads->addChild(button_pinguine_image);

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

        _button_turn_off_ads->addChild(turn_off_ads_title);
        //settings_scene_turn_off_ads_title->setPositionX();
        menu->addChild(_button_turn_off_ads);

        //animation
        _button_turn_off_ads->runAction(CCSequence::create(
                         CCDelayTime::create(1.6f),
                         CCEaseElasticOut::create(
                            CCMoveTo::create(1.4f,
                                             ccp(ORIGIN.x +  padding_x2,
                                                 button_restore_purchase_position))
                             ),
                         NULL
                     ));
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
    hideEverything([](){
            CCDirector::sharedDirector()->replaceScene(Developers::scene());
        });
}

void Settings::onRestorePurchaseClick()
{
    ADInApp::restorePurchases();
}

void Settings::onTurnOffAdsClick()
{

    _pop_up_manager.openWindow(new TurnOffPopUpSure());

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

void Settings::hideEverything(ADCallFunc::Action action)
{
    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    bool show_purchase = InfoStyles::showPurchase();


    this->stopAllActions();
    /////////////////////////////////////////////////
    //sound
    CCPoint sound_target_pos = ccp(_button_sounds_on->getPositionX(),
                                   ORIGIN.y - _button_sounds_on->getContentSize().height);
    _button_sounds_on->runAction(CCSequence::create(
                               CCDelayTime::create(0.5f),
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(0.6f,sound_target_pos)),
                               NULL
                           ));

    ///////////////////////////////////////////////
    //music
    CCPoint music_target_pos = ccp(_button_music_on->getPositionX(),
                                   ORIGIN.y - _button_music_on->getContentSize().height);
    _button_music_on->runAction(CCSequence::create(
                               CCDelayTime::create(0.5f),
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(0.6f,music_target_pos)),
                               NULL
                           ));

    /////////////////////////////////////////////////////
    //music author
    _author_of_music_title->runAction(CCSequence::create(
                     CCDelayTime::create(0.0f),
                     CCFadeTo::create(0.6f,0),
                     NULL
                 ));

    ////////////////////////////////////////
    //x4enjoy
    _button_x4enjoy->runAction(CCSequence::create(
                     CCDelayTime::create(0.0f),
                     CCFadeTo::create(0.6f,0),
                     NULL
                 ));

    //////////////////////////////////////
    //developers
    CCPoint dev_target_pos = ccp(ORIGIN.x+VISIBLE_SIZE.width+_button_developers->getContentSize().width,
                                 _button_developers->getPositionY());
    _button_developers->runAction(CCSequence::create(
                     CCDelayTime::create(0.0f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,dev_target_pos)
                         ),
                     NULL
                 ));

    /////////////////////////////////////////
    if(show_purchase)
    {
        CCPoint dev_restore_pos = ccp(ORIGIN.x+VISIBLE_SIZE.width+_button_restore_purchase->getContentSize().width,
                                     _button_restore_purchase->getPositionY());
        _button_restore_purchase->runAction(CCSequence::create(
                         CCDelayTime::create(0.2f),
                         CCEaseElasticOut::create(
                            CCMoveTo::create(1.0f,dev_restore_pos)
                             ),
                         NULL
                     ));

        CCPoint dev_turnoff_pos = ccp(ORIGIN.x+VISIBLE_SIZE.width+_button_turn_off_ads->getContentSize().width,
                                     _button_turn_off_ads->getPositionY());
        _button_turn_off_ads->runAction(CCSequence::create(
                         CCDelayTime::create(0.3f),
                         CCEaseElasticOut::create(
                            CCMoveTo::create(1.0f,dev_turnoff_pos)
                             ),
                         NULL
                     ));
    }


    ///////////////////////////////////////////////////////////
    //next action
    this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(1.0f),
                    ADCallFunc::create(action)
                    )
                );
}
