#include "TopPanell.h"
#include <ADLib.h>
#include "InfoStyles.h"
#include "Stars.h"

using namespace cocos2d;

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
    float padding = 25/SCALE;
    //panel
    CCSprite* panel_image = CCSprite::create("level-scene/top-panel.png");
    panel_image->setAnchorPoint(ccp(0,0));
    panel_image->setPositionX(0);
    panel_image->setPositionY(0);
    float padding_node_x = panel_image->getContentSize().width;
    float padding_node_y = panel_image->getContentSize().height;
    this->setContentSize(ccp(padding_node_x, padding_node_y));
    this->setContentSize(ccp(padding_node_x, padding_node_y));
    this->addChild(panel_image);
    //number word
    cocos2d::CCLabelTTF* number_words;
    //std::string title_number_word= "5/10";

    std::string title_number_word= AD_to_string(word_number)+"/"+AD_to_string(all_words);
    //
    number_words = CCLabelTTF::create(title_number_word.c_str(),
                                      ADLanguage::getFontName(),
                                      InfoStyles::SIZE_DEVELOPERS_TITLE);

    number_words->setColor(InfoStyles::COLOR_ORANGE);

    number_words->setAnchorPoint(ccp(0,0.5f));
    number_words->setPositionX(padding*7);

    number_words->setPositionY(padding_node_y*0.5f);

    panel_image->addChild(number_words);

    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    panel_image->addChild(menu);

    //audio

    CCSprite* button_audio_image = CCSprite::create("level-scene/audio.png");


    ADMenuItem* button_audio = ADMenuItem::create(button_audio_image);
    // button_audio->setAnchorPoint(ccp(0,0));
     button_audio->setAnchorPoint(ccp(0,0.5f));
     button_audio->setPositionX(padding*7+number_words->getContentSize().width+
                                     padding*17);

    button_audio->setPositionY(padding_node_y*0.5f);


    //emit SignalAudioClicked();
    CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudioOnClicked);
    //     CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudio);

    menu->addChild(button_audio);



    //hint-lamp

    CCSprite* hint_lamp_image = CCSprite::create("level-scene/hint-lamp.png");


    hint_lamp_image->setAnchorPoint(ccp(0,0.5f));
//    float hint_lamp_image_x=number_words->getContentSize().width+
//            padding*3+button_audio->getContentSize().width+padding;


    ADMenuItem* hint_lamp = ADMenuItem::create(hint_lamp_image);
     hint_lamp->setAnchorPoint(ccp(0,0.5f));

     hint_lamp->setPositionX(button_audio->getPositionX()+button_audio->getContentSize().width+padding);

     hint_lamp->setPositionY(padding_node_y*0.5f);

    CONNECT(hint_lamp->signalOnClick, this, &TopPanell::signalUseHintOnClicked);
    //     CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudio);

    float hint_lamp_y=hint_lamp->getContentSize().height;
    float node_scale_h = (panel_image->getContentSize().height/hint_lamp_y);
    if(node_scale_h < 1)
    {
        hint_lamp->setScale(node_scale_h*0.6f);
    }
    else
    {
        node_scale_h=1;
    }
    menu->addChild(hint_lamp);




//    panel_image->addChild(hint_lamp_image);

    Stars* stars_node = Stars::create(star_number);
    stars_node->setAnchorPoint(ccp(0,0.5f));
    stars_node->setPositionX(hint_lamp->getPositionX()+hint_lamp->getContentSize().width*0.1f+padding*2);
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
void TopPanell::signalAudioOnClicked()
{
    emit signalAudioClicked();
    CCLog("gggg");
}
void TopPanell::signalUseHintOnClicked()
{
    emit signalUseHint();
    CCLog("ffff");
}
