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

    //float padding_shadow =45/SCALE;
    //float padding =15/SCALE;
    float padding_node_x = _paper_image->getContentSize().width;
    //float padding_node_y = _paper_image->getContentSize().height;
//    this->setContentSize(ccp(padding_node_x, padding_node_y));
//    this->addChild(_paper_image);
//    //line
//    _line_image = CCSprite::create("card/line.png");
//    _line_image->setAnchorPoint(ccp(0,0));
//    _line_image->setPositionX(0);
//    _line_image->setPositionY(padding_node_y*0.25f);


    ///////////////////////////////////////
    //title
    _line_image_title = CCLabelTTF::create(title.c_str(),
                                           ADLanguage::getFontName(),
                                           35);

    //float line_image_height = _line_image->getContentSize().height;
    //float line_image_title_width = _paper_image->getContentSize().width;
    //float line_image_width = _line_image->getContentSize().width-padding_shadow;
    //if (line_image_title_width>line_image_width)
    //{
        //_line_image_title->setScale(line_image_title_width/ _line_image_title->getContentSize().width);
   // }
    this->addChild(_line_image_title);

    _line_image_title->setAnchorPoint(ccp(0.5f,0.5f));
    _line_image_title->setPositionX(padding_node_x*0.5f);
    _line_image_title->setPositionY(-30/SCALE);
    //this->addChild(_line_image);


    ////////////////////////////////////////////
    //image
    image->setAnchorPoint(ccp(0.5f,0.5f));
    image->setPositionX(padding_node_x*0.5f);
    image->setPositionY(_paper_image->getContentSize().height*0.5);

    //image->setScale( (padding_node_y-padding_shadow*1.2f-(padding_node_y*0.25f+line_image_height))/image->getContentSize().height );
    this->addChild(image);



    /////////////////////////////////////////////
    //stars
    Stars* stars_node = Stars::create(stars_number);
    stars_node->setAnchorPoint(ccp(0.5f,0.5f));
    stars_node->setPositionX(padding_node_x*0.5f);
    stars_node->setPositionY(-100/SCALE);
   //float stars_node_width = stars_node->getContentSize().width;

   // if (stars_node_width>line_image_width-padding_shadow*0.5f)
    //{
    //    stars_node->setScale((line_image_width-padding_shadow*0.5f)/ stars_node_width);
    //}

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
//    if (type == BorderType::Easy)
//    {
//        _border_image->setColor(InfoStyles::COLOR_YELLOW);
//    }
//    else if (type == BorderType::Middle)
//    {
//        _border_image->setColor(InfoStyles::COLOR_GREEN);
//    }
//    else if (type == BorderType::Difficult)
//    {
//        _border_image->setColor(InfoStyles::COLOR_RED);
//    }


}
