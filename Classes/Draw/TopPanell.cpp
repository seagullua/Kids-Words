#include "TopPanell.h"
using namespace cocos2d;
#include <ADLib.h>
#include "InfoStyles.h"
#include "Stars.h"

TopPanell* TopPanell::create(int word_number, int all_words, int star_number)
{
    TopPanell* obj = new TopPanell( word_number, all_words, star_number);
    obj->autorelease();
    obj->init();
    return obj;
}

TopPanell::TopPanell(int word_number, int all_words, int star_number)
{

drawPanel(word_number,  all_words, star_number);


}
void TopPanell::drawPanel(int word_number, int all_words, int star_number)
{
     const float SCALE = ADScreen::getScaleFactor();

    //panel
    CCSprite* panel_image = CCSprite::create("level-scene/top-panel.png");
    panel_image->setAnchorPoint(ccp(0,0));
    panel_image->setPositionX(200/SCALE);
    panel_image->setPositionY(0);
    float padding_node_x = panel_image->getContentSize().width;
    float padding_node_y = panel_image->getContentSize().height;
    this->setContentSize(ccp(padding_node_x, padding_node_y));
        this->setContentSize(ccp(padding_node_x, padding_node_y));
    this->addChild(panel_image);
        //number word
    cocos2d::CCLabelTTF* number_words;
    std::string title_number_word= "5/10";
    //Руслана не можу сформувати рядок
        //std::string title_number_word= ""+word_number+"/"+all_words;
//
    number_words = CCLabelTTF::create(title_number_word.c_str(),
                                      ADLanguage::getFontName(),
                                      InfoStyles::SIZE_DEVELOPERS_TITLE);

    number_words->setColor(InfoStyles::COLOR_ORANGE);

    number_words->setAnchorPoint(ccp(0,0.5f));
    number_words->setPositionX(0);

    number_words->setPositionY(padding_node_y*0.5f);

    panel_image->addChild(number_words);

    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    this->addChild(menu);

    //audio
        float padding = 25/SCALE;
    CCSprite* button_audio_image = CCSprite::create("level-scene/audio.png");


          button_audio_image->setAnchorPoint(ccp(0,0.5f));
           button_audio_image->setPositionX(number_words->getContentSize().width+
                   padding*10);

        button_audio_image->setPositionY(padding_node_y*0.5f);
        float button_audio_image_y=button_audio_image->getContentSize().width;

//        float node_scale = (panel_image->getContentSize().height/button_audio_image_y);
//        if(node_scale < 1)
//        {
            button_audio_image->setScale(0.7f);
 //       }

    panel_image->addChild(button_audio_image);

    //    ADMenuItem* button_audio = ADMenuItem::create(button_audio_image);
//        button_audio->setAnchorPoint(ccp(0,0));
//        button_audio->setPositionX(panel_image->getContentSize().width+
//                padding);

//    button_audio->setPositionY(0);
//        //emit SignalAudioClicked();
//   // CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudioClicked);
//    CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudio);

//    menu->addChild(button_audio);



    //hint-lamp

    CCSprite* hint_lamp_image = CCSprite::create("level-scene/hint-lamp.png");


          hint_lamp_image->setAnchorPoint(ccp(0,0.5f));
        float hint_lamp_image_x=number_words->getContentSize().width+
                padding*10+button_audio_image->getContentSize().width+padding;
           hint_lamp_image->setPositionX(hint_lamp_image_x);

        hint_lamp_image->setPositionY(padding_node_y*0.5f);
        float hint_lamp_image_y=hint_lamp_image->getContentSize().height;

        float node_scale_h = (panel_image->getContentSize().height/hint_lamp_image_y);
        if(node_scale_h < 1)
        {
          hint_lamp_image->setScale(node_scale_h*0.45f);
        }

    panel_image->addChild(hint_lamp_image);

    Stars* stars_node = Stars::create(7);
    stars_node->setAnchorPoint(ccp(0,0.5f));
    stars_node->setPositionX(hint_lamp_image_x+button_audio_image->getContentSize().width);
    stars_node->setPositionY(padding_node_y*0.5f);
 //   float stars_node_height = stars_node->getContentSize().height;

//    if (stars_node_width>line_image_width-padding_shadow*0.5f)
//    {
//        stars_node->setScale((line_image_width-padding_shadow*0.5f)/ stars_node_width);
//    }

    panel_image->addChild(stars_node);


}
void TopPanell::starsDrawChanged(int star_number)
{

}
void TopPanell::signalAudio()
{

}
