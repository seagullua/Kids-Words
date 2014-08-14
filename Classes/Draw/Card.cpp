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

    if (_card_type == CardType::WithBorder )
    {
        //border
        _border_image = CCSprite::create("card/paper.png");
        _border_image->setAnchorPoint(ccp(0.5f,0.5f));
        _border_image->setPosition(_border_image->getContentSize()*0.5f);
        _border_image->setScale(1.075f);
        this->addChild(_border_image);
    }
    //paper
    CCSprite* paper_image = CCSprite::create("card/paper.png");
    paper_image->setAnchorPoint(ccp(0,0));
    paper_image->setPositionX(0);
    paper_image->setPositionY(0);
    float padding_shadow =45;
    float padding_node_x = paper_image->getContentSize().width;
    float padding_node_y = paper_image->getContentSize().height;
    this->setContentSize(ccp(padding_node_x, padding_node_y));
    this->addChild(paper_image);
    //line
    const float SCALE = ADScreen::getScaleFactor();
    _line_image = CCSprite::create("card/line.png");
    _line_image->setAnchorPoint(ccp(0,0));
    _line_image->setPositionX(0);
    _line_image->setPositionY(padding_node_y*0.25f);

    _line_image_title = CCLabelTTF::create(title.c_str(),
                                           ADLanguage::getFontName(),
                                           InfoStyles::SIZE_LINE_TITLE);

    float line_image_height = _line_image->getContentSize().height;
    float line_image_title_width = _line_image_title->getContentSize().width;
    float line_image_width = _line_image->getContentSize().width-padding_shadow;
    if (line_image_title_width>line_image_width)
    {
        _line_image_title->setScale((line_image_width-padding_shadow)/ line_image_title_width);
    }
    _line_image->addChild(_line_image_title);

    _line_image_title->setAnchorPoint(ccp(0.5f,0.5f));
    _line_image_title->setPositionX(padding_node_x*0.5f);
    _line_image_title->setPositionY(line_image_height*0.5f);
    this->addChild(_line_image);

    //image
    image->setAnchorPoint(ccp(0.5f,0));
    image->setPositionX(padding_node_x*0.5f);
    image->setPositionY(padding_node_y*0.25f
                        +line_image_height);

    image->setScale( (padding_node_y-padding_shadow/SCALE-(padding_node_y*0.25f+line_image_height))/image->getContentSize().height );
    this->addChild(image);
    Stars* stars_node = Stars::create(3);
    stars_node->setAnchorPoint(ccp(0.5f,0.5f));
    stars_node->setPositionX(padding_node_x*0.45f);
    stars_node->setPositionY(padding_node_y*0.25f*0.6f);
    float stars_node_width = stars_node->getContentSize().width;

    if (stars_node_width>line_image_width-padding_shadow*0.5f)
    {
        stars_node->setScale((line_image_width-padding_shadow*0.5f)/ stars_node_width);
    }

    this->addChild(stars_node);

}

void Card::setCardColor(ccColor3B color)
{
    _line_image->setColor(color);
}
void Card::setTitleColor(ccColor3B color)
{
    _line_image_title->setColor(color);
}
void Card::setStarsNumber(int stars_number)
{


}
void Card::setBorderType(BorderType type)
{
    if (type == BorderType::Easy)
    {
     _border_image->setColor(InfoStyles::COLOR_YELLOW);
    }
    else if (type == BorderType::Middle)
    {
       _border_image->setColor(InfoStyles::COLOR_GREEN);
    }
    else if (type == BorderType::Difficult)
    {
         _border_image->setColor(InfoStyles::COLOR_RED);
    }
}
