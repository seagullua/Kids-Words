#include "Stars.h"
using namespace cocos2d;
Stars* Stars::create(int stars_number)
{
    Stars* obj = new Stars(stars_number);
    obj->autorelease();
    obj->init();
    return obj;
}

Stars::Stars(int stars_number)
{
    float node_width = 0;
    float node_height = 0;
    for(int i=0; i<5; ++i)
    {
        CCSprite* color_star;
        if (i<stars_number)
        {
            //color_star
            color_star = CCSprite::create("card/color.png");
        }
        else
        {
            //black_star
            color_star = CCSprite::create("card/black.png");

        }
        color_star->setAnchorPoint(ccp(0,0));
        color_star->setPositionY(0);
        color_star->setPositionX(color_star->getContentSize().width*(i)*0.75f);
        node_width = node_width+color_star->getContentSize().width*0.75f;
        node_height = color_star->getContentSize().height;


        this->addChild(color_star);

    }
    this->setContentSize(ccp(node_width, node_height));

}
