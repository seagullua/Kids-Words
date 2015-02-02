#include "SceneStyle.h"
#include <ADLib/Device/ADDeviceEvents.h>
using namespace cocos2d;
#include "InfoStyles.h"

SceneStyle::SceneStyle()
    : _pop_up_manager(this)
{
    CONNECT(ADDeviceEvents::signalOnBackClicked, this, &SceneStyle::simulateBackClick);
}
void SceneStyle::showButtonBack(const BackgroundType type)
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();
    float padding = 25/SCALE;

    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));
    this->addChild(menu);

    //button back
    CCSprite* button_back_image = CCSprite::create("universal/back-button.png");
    ADMenuItem* button_back = ADMenuItem::create(button_back_image);
    button_back->setPositionX(ORIGIN.x+ padding + button_back->getContentSize().width*0.5f);
    button_back->setPositionY(ORIGIN.y + VISIBLE_SIZE.height + button_back_image->getContentSize().height);

    CCPoint back_target_pos = ccp(ORIGIN.x+ padding + button_back->getContentSize().width*0.5f,
                                  ORIGIN.y + VISIBLE_SIZE.height-35/SCALE -
                                         button_back->getContentSize().height*0.5f
                                  );

    if(type==BackgroundType::LevelScene)
    {
        back_target_pos.y = ORIGIN.y + VISIBLE_SIZE.height-20/SCALE -
                            button_back->getContentSize().height*0.5f;
    }

    button_back->setColor(InfoStyles::COLOR_TITLE);

    CONNECT(button_back->signalOnClick,
            (SceneStyle*)this,
            &SceneStyle::simulateBackClick);

    menu->addChild(button_back);

    //animation
    button_back->runAction(CCSequence::create(
                               CCEaseElasticOut::create(
                                 CCMoveTo::create(1.0f,back_target_pos)),
                               NULL
                           ));
}
void SceneStyle::showBackground(const BackgroundType type)
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();

    CCSprite* background_up = CCSprite::create("universal/background_up.png");
    background_up->setAnchorPoint(ccp(0.5f,0.0f));
    this->addChild(background_up);

    if(type==BackgroundType::LevelScene)
    {
        background_up->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width/2,
                                       ORIGIN.y+VISIBLE_SIZE.height-180/SCALE));
    }
    else
    {
        background_up->setPosition(ccp(ORIGIN.x+VISIBLE_SIZE.width/2,
                                       ORIGIN.y+VISIBLE_SIZE.height-220/SCALE));
     }
}

bool SceneStyle::init()
{
    bool res = initWithColor(ccc4(246,223,195,255));
    this->setKeypadEnabled(true);

    return res;
}
void SceneStyle::simulateBackClick()
{
    if(!_pop_up_manager.backAction())
    {
        onBackClick();
    }
}

void SceneStyle::keyBackClicked()
{
    simulateBackClick();
}
