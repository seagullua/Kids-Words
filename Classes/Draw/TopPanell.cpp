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
    _panel_image(nullptr),
    _all_words(all_words),
    _star_number(star_number),
    _padding_node_star_y(0),
    _padding_node_star_x(0),
    _title_number_word("")
{

    drawPanel(word_number,  all_words, star_number);


}
void TopPanell::drawPanel(int word_number, int all_words, int star_number)

{
    const float SCALE = ADScreen::getScaleFactor();
    float padding = 25/SCALE;
    float padding_node_x = 0;
    float padding_node_y = 0;

    //panel
    if (!_panel_image)
    {
        _panel_image = CCSprite::create("level-scene/top-panel.png");
        _panel_image->setAnchorPoint(ccp(0,0));
        _panel_image->setPositionX(0);
        _panel_image->setPositionY(0);
        padding_node_x = _panel_image->getContentSize().width;
        padding_node_y = _panel_image->getContentSize().height;
        this->setContentSize(ccp(padding_node_x, padding_node_y));
        this->setContentSize(ccp(padding_node_x, padding_node_y));
        this->addChild(_panel_image);
    }


    //number word
    _title_number_word= AD_to_string(word_number)+"/"+AD_to_string(_all_words);
    if (!_number_words)
    {


        _number_words = CCLabelTTF::create(_title_number_word.c_str(),
                                           "fonts/Berlin Sans FB.ttf",
                                           InfoStyles::SIZE_DEVELOPERS_TITLE);


        _number_words->setColor(ccc3(246,223,195));

        _number_words->setAnchorPoint(ccp(0,0.5f));
        _number_words->setPositionX(padding*7);

        _number_words->setPositionY(padding_node_y*0.5f);

        _panel_image->addChild(_number_words);
    }

    static std::string LETTER_FONT = "fonts/Roboto Slab Bold.ttf";

    _translation_word_label = CCLabelTTF::create(" ",
                                                 LETTER_FONT.c_str(),
                                                 InfoStyles::SIZE_BUTTON_POP_UP);


    _translation_word_label->setColor(ccc3(246,206,195));

    _translation_word_label->setAnchorPoint(ccp(0,0.5f));
    _translation_word_label->setPositionX(padding*12);

    _translation_word_label->setPositionY(padding_node_y*0.5f);

    _panel_image->addChild(_translation_word_label);
    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    _panel_image->addChild(menu);

    //audio

    CCSprite* button_audio_image = CCSprite::create("level-scene/audio.png");


    ADMenuItem* button_audio = ADMenuItem::create(button_audio_image);
    button_audio->setAnchorPoint(ccp(0.5f,0.5f));
    button_audio->setPositionX(padding*7+_number_words->getContentSize().width+
                               padding*17);

    button_audio->setPositionY(padding_node_y*0.5f);

    CONNECT(button_audio->signalOnClick, this, &TopPanell::signalAudioOnClicked);
    button_audio->setVisible(false);
    menu->addChild(button_audio);



    //hint-lamp

    CCSprite* hint_lamp_image = CCSprite::create("level-scene/hint-lamp.png");


    hint_lamp_image->setAnchorPoint(ccp(0,0.5f));

    ADMenuItem* hint_lamp = ADMenuItem::create(hint_lamp_image);
    hint_lamp->setAnchorPoint(ccp(0.5f,0.5f));

    hint_lamp->setPositionX(button_audio->getPositionX()+padding*5.5f);

    hint_lamp->setPositionY(padding_node_y*0.5f);

    CONNECT(hint_lamp->signalOnClick, this, &TopPanell::signalUseHintOnClicked);
//    float translation_label_size_free = hint_lamp->getPositionX()-_number_words->getPositionX();
//    float translation_label_size =_translation_word_label->getContentSize().width;

//    if (translation_label_size>translation_label_size_free)
//    {
//        _translation_word_label->setScale(translation_label_size/ translation_label_size_free);
//    }

    menu->addChild(hint_lamp);

    _padding_node_star_y = padding_node_y;
    _padding_node_star_x = hint_lamp->getPositionX()+hint_lamp->getContentSize().width*0.5f;
    drawStarsNode(_star_number);


}
void TopPanell::drawStarsNode(int star_number)
{

    _stars_node = Stars::create(star_number);
    _stars_node->setAnchorPoint(ccp(0,0.5f));
    _stars_node->setPositionX(_padding_node_star_x);
    _stars_node->setPositionY(_padding_node_star_y*0.5f);

    _panel_image->addChild(_stars_node);

}

void TopPanell::starsDrawChanged(int star_number)
{
    _stars_node->removeFromParent();
    drawStarsNode(star_number);


}
void TopPanell::signalAudioOnClicked()
{
    emit signalAudioClicked();

}
void TopPanell::signalUseHintOnClicked()
{
    emit signalUseHint();

}
void TopPanell::setTitleNumberWord(int word_number)
{

    _title_number_word= AD_to_string(word_number)+"/"+AD_to_string(_all_words);

    _number_words->setString(_title_number_word.c_str());
}
void TopPanell::setTranslationWord(std::string translation_word)
{
    _translation_word = translation_word;
    _translation_word_label->setString(_translation_word.c_str());

}
