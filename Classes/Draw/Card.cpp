#include "Card.h"
#include "Stars.h"
#include "InfoStyles.h"
#include <ADLib.h>
using namespace cocos2d;
Card* Card::create(cocos2d::CCSprite* image,
                   std::string title,
                   int stars_number,
                   CardType _card_type)
{
    Card* obj = new Card(image, title, stars_number,_card_type);
    obj->autorelease();
    obj->init();
    return obj;
}

Card::Card(cocos2d::CCSprite *image, std::string title, int stars_number, CardType _card_type)
    :
      _border_image(nullptr)
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const float SCALE = ADScreen::getScaleFactor();


    ////////////////////////////////////
    //paper
    _paper_image = CCSprite::create("card/card-paper.png");
    _paper_image->setAnchorPoint(ccp(0,0));
    _paper_image->setPositionX(0);
    _paper_image->setPositionY(0);
    this->addChild(_paper_image);
    this->setContentSize(_paper_image->getContentSize());


    //////////////////////////////////////////
    float padding_node_x = _paper_image->getContentSize().width;


    ///////////////////////////////////////
    //title
    _line_image_title = CCLabelTTF::create(title.c_str(),
                                           ADLanguage::getFontName(),
                                           35);
    this->addChild(_line_image_title);

    _line_image_title->setAnchorPoint(ccp(0.5f,0.5f));
    _line_image_title->setPositionX(padding_node_x*0.5f);
    _line_image_title->setPositionY(-30/SCALE);

    ////////////////////////////////////////////
    //image
    image->setAnchorPoint(ccp(0.5f,0.5f));
    image->setPositionX(padding_node_x*0.5f);
    image->setPositionY(_paper_image->getContentSize().height*0.5);
    image->setScale(image->getContentSize().width/_paper_image->getContentSize().width*0.8);
    this->addChild(image);

    /////////////////////////////////////////////
    //stars
    Stars* stars_node = Stars::create(stars_number);
    stars_node->setAnchorPoint(ccp(0.5f,0.5f));
    stars_node->setPositionX(padding_node_x*0.5f);
    stars_node->setPositionY(-100/SCALE);
    this->addChild(stars_node);

}

void Card::setCardColor(ccColor3B color)
{
    //_line_image->setColor(color);
    _paper_image->setColor(color);
    _line_image_title->setColor(color);

}
void Card::setTitleColor(ccColor3B color)
{
    //_line_image_title->setColor(color);

}

void Card::setBorderType(BorderType type)
{
}
