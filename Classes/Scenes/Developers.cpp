#include "developers.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "Settings.h"
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
    CCDirector::sharedDirector()->replaceScene(Settings::scene());
}



bool Developers::init()
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
    float padding = 25/SCALE;
    showButtonBack();

    CCNode* node = CCNode::create();
    //node->setContentSize(ccp(400, 500));
    node->setAnchorPoint(ccp(0.5f,0.5f));
    //node->setScale(0.5f);
    this->addChild(node);
    //ruslana
    CCSprite* ruslana_image = CCSprite::create("developers/ruslana.png");

    ruslana_image->setPositionX(0);

    ruslana_image->setPositionY(0);
    ruslana_image->setAnchorPoint(ccp(0,0));

    node->addChild(ruslana_image);
    cocos2d::CCLabelTTF* developers_scene_ruslana_title;
    developers_scene_ruslana_title = CCLabelTTF::create(_("developers_scene_ruslana.title"),
                                                        ADLanguage::getFontName(),
                                                        InfoStyles::SIZE_DEVELOPERS_TITLE);

    developers_scene_ruslana_title->setColor(InfoStyles::COLOR_WHITE);

    developers_scene_ruslana_title->setAnchorPoint(ccp(0,0));
    developers_scene_ruslana_title->setPositionX(
                ruslana_image->getContentSize().width+padding);

    developers_scene_ruslana_title->setPositionY(ruslana_image->getContentSize().height*0.4f);

    node->addChild(developers_scene_ruslana_title);

    //andrii
    cocos2d::CCLabelTTF* developers_scene_andrii_title;
    developers_scene_andrii_title = CCLabelTTF::create(_("developers_scene_andrii.title"),
                                                       ADLanguage::getFontName(),
                                                       InfoStyles::SIZE_DEVELOPERS_TITLE);
    developers_scene_andrii_title->setColor(InfoStyles::COLOR_WHITE);
    developers_scene_andrii_title->setPositionX(padding);
    developers_scene_andrii_title->setAnchorPoint(ccp(0,0));
    node->addChild(developers_scene_andrii_title);

    CCSprite* andrii_image = CCSprite::create("developers/andrii.png");
    andrii_image->setAnchorPoint(ccp(0,0));

    andrii_image->setPositionX(
                developers_scene_andrii_title->getContentSize().width+padding);
    andrii_image->setPositionY(ruslana_image->getContentSize().height*0.75f);
    developers_scene_andrii_title->setPositionY(ruslana_image->getContentSize().height*0.75f+andrii_image->getContentSize().height*0.4f);

    node->addChild(andrii_image);


    //diana
    CCSprite* diana_image = CCSprite::create("developers/diana.png");

    diana_image->setPositionX(0);

    diana_image->setPositionY(0);
    diana_image->setAnchorPoint(ccp(0,0));
    diana_image->setPositionY(ruslana_image->getContentSize().height*1.5);

    node->addChild(diana_image);
    cocos2d::CCLabelTTF* developers_scene_diana_title;
    developers_scene_diana_title = CCLabelTTF::create(_("developers_scene_diana.title"),
                                                      ADLanguage::getFontName(),
                                                      InfoStyles::SIZE_DEVELOPERS_TITLE);

    developers_scene_diana_title->setColor(InfoStyles::COLOR_WHITE);

    developers_scene_diana_title->setAnchorPoint(ccp(0,0));
    developers_scene_diana_title->setPositionX(
                ruslana_image->getContentSize().width+padding);

    developers_scene_diana_title->setPositionY(ruslana_image->getContentSize().height*1.9f);

    node->addChild(developers_scene_diana_title);
    float padding_node_x = ruslana_image->getContentSize().width*2.5f+padding;
    float padding_node_y = ruslana_image->getContentSize().height*2.5f;


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
    node->setContentSize(ccp(padding_node_x, padding_node_y));
    //node->setPosition(button_back->getContentSize().width,button_x4enjoy->getContentSize().height+ padding4enjoy);
    node->setPositionX(ORIGIN.x +VISIBLE_SIZE.width*0.5f);
    node->setPositionY(ORIGIN.y +VISIBLE_SIZE.height*0.5f);
    float padding_node = 15/SCALE;
    float node_scale = (VISIBLE_SIZE.height-padding_node)/padding_node_y;
    if(node_scale < 1)
    {
        node->setScale(node_scale);
    }

    return true;
}

void Developers::onX4EnjoyClick()
{
    ADBrowser::openWebURL("http://4enjoy.com");
}
