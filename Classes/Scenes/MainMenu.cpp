#include "MainMenu.h"
#include "Settings.h"
#include "SelectCollection.h"
#include <ADLib/ADString.h>
#include "PopUp/ExitGamePopUp.h"
#include "InfoStyles.h"
using namespace cocos2d;



class ExitPopUp: public IADStandardWindow
{

public:
    ExitPopUp()
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
        CCLabelTTF* exit_title = CCLabelTTF::create(_("ExitGame.Sure"),
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

        CCLabelTTF* yes_button_title = CCLabelTTF::create(_("ExitGame.Yes"),
                                                          ADLanguage::getFontName(),
                                                          InfoStyles::SIZE_BUTTON_POP_UP);
        ADMenuItem* yes_button = ADMenuItem::create(yes_button_title);
        CONNECT(yes_button->signalOnClick,
                this,
                &ExitPopUp::onYesClick);
        CCPoint yes_position(ccp(size.width*0.45f,
                                 size.height*0.5f - 70/SCALE));
        yes_button->setPosition(ccp(size.width*0.45f,
                                    size.height+yes_button->getContentSize().height));
        menu->addChild(yes_button);
        yes_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,yes_position))
                               );


        CCLabelTTF* no_button_title = CCLabelTTF::create(_("ExitGame.No"),
                                                          ADLanguage::getFontName(),
                                                          InfoStyles::SIZE_BUTTON_POP_UP);
        ADMenuItem* no_button = ADMenuItem::create(no_button_title);
        CONNECT(no_button->signalOnClick,
                this,
                &ExitPopUp::onNoClick);
        CCPoint no_position(ccp(size.width*0.55f,
                                size.height*0.5f - 70/SCALE));
        no_button->setPosition(ccp(size.width*0.55f,
                                   size.height+no_button->getContentSize().height));
        no_button->runAction(CCEaseBackOut::create(
                                  CCMoveTo::create(0.8f,no_position))
                               );
        menu->addChild(no_button);

    }

    void onYesClick()
    {
        ADDeviceEvents::closeApp();
    }

    void onNoClick()
    {
        this->closeWindow();
    }
};

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
    _pop_up_manager.openWindow(new ExitPopUp());

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
    _english_logo = CCSprite::create(image_name.c_str());

    _english_logo->setPosition(ccp(ORIGIN.x - _english_logo->getContentSize().width,
                          ORIGIN.y + VISIBLE_SIZE.height*0.6f));
    this->addChild(_english_logo);
    _english_logo->runAction(CCSequence::create(
                     CCDelayTime::create(2.1f),
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

    _l = CCSprite::create("main-menu/l.png");
    _l->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.2,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(_l);
    _l->setScale(letter_scale/_l->getContentSize().height);
    _l->runAction(CCSequence::create(
                     CCDelayTime::create(0.5f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.2,
                                             letter_y))
                         ),
                     NULL
                 ));
    ///////////////////////////////////

    _e = CCSprite::create("main-menu/e.png");
    _e->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.35,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(_e);
    _e->setScale(letter_scale/_e->getContentSize().height);
    _e->runAction(CCSequence::create(
                     CCDelayTime::create(0.8f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.35,
                                             letter_y))
                         ),
                     NULL
                 ));

    ///////////////////////////////
    _a = CCSprite::create("main-menu/a.png");
    _a->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(_a);
    _a->setScale(letter_scale/_a->getContentSize().height);
    _a->runAction(CCSequence::create(
                     CCDelayTime::create(1.1f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.5,
                                             letter_y))
                         ),
                     NULL
                 ));

    ////////////////////////////////
    _r = CCSprite::create("main-menu/r.png");
    _r->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.65,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(_r);
    _r->setScale(letter_scale/_r->getContentSize().height);
    _r->runAction(CCSequence::create(
                     CCDelayTime::create(1.4f),
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(ORIGIN.x+VISIBLE_SIZE.width*0.65,
                                             letter_y))
                         ),
                     NULL
                 ));

    ////////////////////////////////
    _n = CCSprite::create("main-menu/n.png");
    _n->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width*0.8,
                             ORIGIN.y+VISIBLE_SIZE.height+100));
    this->addChild(_n);
    _n->setScale(letter_scale/_n->getContentSize().height);
    _n->runAction(CCSequence::create(
                     CCDelayTime::create(1.7f),
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
    _button_play = ADMenuItem::create(button_play_image);
    _button_play->setPosition(ccp(ORIGIN.x + VISIBLE_SIZE.width*0.5f,
                                 ORIGIN.y + VISIBLE_SIZE.height + button_play_image->getContentSize().height));
    CCPoint button_play_position = (ccp(ORIGIN.x + VISIBLE_SIZE.width*0.5f,
                                        ORIGIN.y + VISIBLE_SIZE.height*0.3f));
    CONNECT(_button_play->signalOnClick, this, &MainMenu::onPlayClick);
    menu->addChild(_button_play);

    //animation
    _button_play->runAction(CCSequence::create(
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,button_play_position)),
                               NULL
                           ));

    /////////////////////////////////////////////////

    CCSprite* button_settings_image = CCSprite::create("main-menu/settings-button.png");
    _button_settings = ADMenuItem::create(button_settings_image);
    float padding = 35/SCALE;

    CCPoint button_settings_position = (ccp(ORIGIN.x + VISIBLE_SIZE.width - padding - _button_settings->getContentSize().width*0.5f,
                                            ORIGIN.y + padding + _button_settings->getContentSize().height*0.5f));

    _button_settings->setPosition(ccp(button_settings_position.x,
                                     ORIGIN.y + VISIBLE_SIZE.height + _button_settings->getContentSize().height/2));
    CONNECT(_button_settings->signalOnClick, this, &MainMenu::onSettingsClick);
    menu->addChild(_button_settings);

    //animation
    _button_settings->runAction(CCSequence::create(
                               CCDelayTime::create(0.6f),
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,button_settings_position)),
                               NULL
                           ));

    return true;
}


void MainMenu::onPlayClick()
{
    hideEverything([](){
            CCDirector::sharedDirector()->replaceScene(SelectCollection::scene());
        });

}
void MainMenu::onSettingsClick()
{
    hideEverything([](){
            CCDirector::sharedDirector()->replaceScene(Settings::scene());
        });
}

void MainMenu::hideEverything(ADCallFunc::Action action)
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();


    this->stopAllActions();
    //_english_logo
    CCPoint english_logo_position = CCPoint(ORIGIN.x+VISIBLE_SIZE.width+_english_logo->getContentSize().width,
                                            _english_logo->getPositionY());
    _english_logo->runAction(CCSequence::create(
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,english_logo_position)),
                                   NULL
                               ));

    /////////////////////////////////////////////////////////
    //settings -> down
    CCPoint settings_position = CCPoint(_button_settings->getPositionX(),
                                            ORIGIN.y-_button_settings->getContentSize().height);
    _button_settings->runAction(CCSequence::create(
                                   CCDelayTime::create(0.1f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,settings_position)),
                                   NULL
                               ));

    ////////////////////////////////////////////////////////
    //play -> down
    CCPoint play_position = CCPoint(_button_play->getPositionX(),
                                            ORIGIN.y-_button_play->getContentSize().height);
    _button_play->runAction(CCSequence::create(
                                   CCDelayTime::create(0.2f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,play_position)),
                                   NULL
                               ));

    //////////////////////////////////////////////////////////
    //word -> fade out
    CCPoint l_position = CCPoint(_l->getPositionX(),
                                    ORIGIN.y-300/SCALE);
    _l->runAction(CCSequence::create(
                                   CCDelayTime::create(0.3f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,l_position)),
                                   NULL
                               ));


    CCPoint e_position = CCPoint(_e->getPositionX(),
                                    ORIGIN.y-300/SCALE);
    _e->runAction(CCSequence::create(
                                   CCDelayTime::create(0.4f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,e_position)),
                                   NULL
                               ));


    CCPoint a_position = CCPoint(_a->getPositionX(),
                                    ORIGIN.y-300/SCALE);
    _a->runAction(CCSequence::create(
                                   CCDelayTime::create(0.5f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,a_position)),
                                   NULL
                               ));


    CCPoint r_position = CCPoint(_r->getPositionX(),
                                    ORIGIN.y-300/SCALE);
    _r->runAction(CCSequence::create(
                                   CCDelayTime::create(0.6f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,r_position)),
                                   NULL
                               ));


    CCPoint n_position = CCPoint(_n->getPositionX(),
                                    ORIGIN.y-300/SCALE);
    _n->runAction(CCSequence::create(
                                   CCDelayTime::create(0.7f),
                                   CCEaseBackOut::create(
                                        CCMoveTo::create(0.4f,n_position)),
                                   NULL
                               ));

    ///////////////////////////////////////////////////////////
    //next action
    this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(0.9f),
                    ADCallFunc::create(action)
                    )
                );

}
