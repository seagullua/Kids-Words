#include "SceneStyle.h"
#include <ADLib/Device/ADDeviceEvents.h>
using namespace cocos2d;
SceneStyle::SceneStyle()
    : _pop_up_manager(this)
{
    CONNECT(ADDeviceEvents::signalOnBackClicked, this, &SceneStyle::simulateBackClick);
}
void SceneStyle::showButtonBack()
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

  //  button_back->setAnchorPoint(ccp(0,1));
    button_back->setPositionX(
                ORIGIN.x
                + padding
                + button_back->getContentSize().width*0.5f);

    button_back->setPositionY(ORIGIN.y +
                              + VISIBLE_SIZE.height-padding -
                                  button_back->getContentSize().height*0.5f);



                CONNECT(button_back->signalOnClick, (SceneStyle*)this, &SceneStyle::simulateBackClick);

    menu->addChild(button_back);
}
void SceneStyle::showBackground(const BackgroundType type)
{
    if(type != BackgroundType::None)
    {
        std::string image_name;
        if(type  == BackgroundType::Light)
        {
            image_name = "universal/background_day.jpg";
        }
        else if(type  == BackgroundType::Dark)
        {
            image_name = "universal/background_night.jpg";
        }
        const CCPoint ORIGIN = ADScreen::getOrigin();
        const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
        //background
        CCSprite* background = CCSprite::create(image_name.c_str());

        background->setPosition(ORIGIN + VISIBLE_SIZE*0.5f);
        this->addChild(background);

    }
}

bool SceneStyle::init()
{
    bool res = initWithColor(ccc4(255,255,255,255));
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
