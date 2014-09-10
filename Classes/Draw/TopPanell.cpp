#include "TopPanell.h"
#include <ADLib.h>
#include "InfoStyles.h"


using namespace cocos2d;

TopPanell* TopPanell::create(int word_number, int all_words, int star_number)
{
    TopPanell* obj = new TopPanell( word_number, all_words, star_number);
    obj->autorelease();
    obj->init();
    return obj;
}

TopPanell::TopPanell(int word_number, int all_words, int star_number):
    _number_words(nullptr),
    _all_words(all_words),
    _star_number(star_number),
    _title_number_word("")
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
    //cocos2d::CCLabelTTF* number_words;
    //std::string title_number_word= "5/10";

    _title_number_word= AD_to_string(word_number)+"/"+AD_to_string(_all_words);
    //
    if (!_number_words)
    {


        _number_words = CCLabelTTF::create(_title_number_word.c_str(),
                                           ADLanguage::getFontName(),
                                           InfoStyles::SIZE_DEVELOPERS_TITLE);


        _number_words->setColor(InfoStyles::COLOR_ORANGE);

        _number_words->setAnchorPoint(ccp(0,0.5f));
        _number_words->setPositionX(padding*7);

        _number_words->setPositionY(padding_node_y*0.5f);

        panel_image->addChild(_number_words);
    }
    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    panel_image->addChild(menu);

    //audio

    CCSprite* button_audio_image = CCSprite::create("level-scene/audio.png");


    ADMenuItem* button_audio = ADMenuItem::create(button_audio_image);
    button_audio->setAnchorPoint(ccp(0.5f,0.5f));
    button_audio->setPositionX(padding*7+_number_words->getContentSize().width+
                               padding*17);

    button_audio->setPositionY(padding_node_y*0.5f);

    CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudioOnClicked);

    menu->addChild(button_audio);



    //hint-lamp

    CCSprite* hint_lamp_image = CCSprite::create("level-scene/hint-lamp.png");


    hint_lamp_image->setAnchorPoint(ccp(0,0.5f));

    ADMenuItem* hint_lamp = ADMenuItem::create(hint_lamp_image);
    hint_lamp->setAnchorPoint(ccp(0.5f,0.5f));

    hint_lamp->setPositionX(button_audio->getPositionX()+button_audio->getContentSize().width+padding);

    hint_lamp->setPositionY(padding_node_y*0.5f);

    CONNECT(hint_lamp->signalOnClick, this, &TopPanell::signalUseHintOnClicked);


    menu->addChild(hint_lamp);


    _stars_node = Stars::create(_star_number);
    _stars_node->setAnchorPoint(ccp(0,0.5f));
    _stars_node->setPositionX(hint_lamp->getPositionX()+hint_lamp->getContentSize().width+padding*2);
    _stars_node->setPositionY(padding_node_y*0.5f);

    panel_image->addChild(_stars_node);


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
void TopPanell::setTitleNumberWord(int word_number)
{

    _title_number_word= AD_to_string(word_number)+"/"+AD_to_string(_all_words);

    _number_words->setString(_title_number_word.c_str());
}

