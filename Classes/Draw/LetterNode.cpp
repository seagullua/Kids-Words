#include "LetterNode.h"
#include "Logic/StatusLetter.h"
#include <algorithm>
#include "InfoStyles.h"
#include "Logic/Alphabete.h"
using namespace cocos2d;

LetterNode* LetterNode::create(Letter letter)
{
    LetterNode* obj = new LetterNode( letter);
    obj->autorelease();
    obj->init();
    return obj;
}
bool LetterNode::canInsertLetter(Letter letter)
{
    LetterStatus status = _active_letter.getLetterStatus();
    if (status == LetterStatus::Frozen)
    {
        return false;
    }

    return true;
}

LetterNode::LetterNode(Letter letter):
    _active_letter(letter),
    _selected_letter(letter),
    _letter_is_selected (false),
    _index_selected_letter(10000),
    _letter_image(nullptr),
    _current_letter(nullptr),
    _just_selected(false)
{
    ShowLetter();
}

const Letter LetterNode::getActiveLetter()
{
    return  _active_letter;
}

const Letter LetterNode::getSelectedLetter()
{
    return _selected_letter;
}
void LetterNode::setSelectedLetter(Letter selected_letter)
{
    _selected_letter = selected_letter;

    ShowLetter();


}
inline int makeLighter(int b, float coef)
{
    if(b == 0) {
        b+=1;
    }
    return b + (255 - b)*coef;
}

void LetterNode::ShowLetter()
{
    this->setCascadeOpacityEnabled(true);
    this->setOpacity(255);
    LetterStatus status = _active_letter.getLetterStatus();
    std:: string letter_string = _active_letter.getLetterString();
    std:: string image_name = "";
    if  (_just_selected)
    {
        _just_selected = false;
        _letter_image = nullptr;
        _current_letter = nullptr;

    }

    if (_letter_is_selected )
    {
        if(letter_string != _selected_letter.getLetterString())

        {
            status = LetterStatus::Normal;

        }

        letter_string = _selected_letter.getLetterString();

    }
    else
    {
        status = _active_letter.getLetterStatus();
        letter_string = _active_letter.getLetterString();
    }  \

    if (status == LetterStatus::Empty)
    {
        image_name =  "letter/letter-fill-border.png";
    }
    else if (status == LetterStatus::Frozen)
    {
        image_name =  "letter/letter-fill-frozen.png";
    }
    else if (status == LetterStatus::Normal)
    {
        image_name =  "letter/letter-fill.png";
    }

    if(!_letter_image)
    {
        _letter_image = CCSprite::create(image_name.c_str());
        this->addChild(_letter_image);
    }
    CCSprite* letter_image = _letter_image;
    letter_image->setAnchorPoint(ccp(0,0));
    letter_image->setPositionX(0);
    letter_image->setPositionY(0);
    float padding_node_x = letter_image->getContentSize().width;
    float padding_node_y = letter_image->getContentSize().height;

    this->setContentSize(ccp(padding_node_x, padding_node_y));

    static std::string LETTER_FONT = "fonts/Berlin Sans FB.ttf";
    if(ADInfo::getPlatform() == ADPlatform::iOS)
    {
        //LETTER_FONT = "fonts/Roboto Slab.ttf";
    }
    if(!_current_letter)
    {
        _current_letter = CCLabelTTF::create(letter_string.c_str(),
                                             LETTER_FONT.c_str(),
                                             InfoStyles::SIZE_LETTER);

        //        float padding_node_xl = _current_letter->getContentSize().width;
        //        float padding_node_yl = _current_letter->getContentSize().height;
        //        float node_scale_x = padding_node_xl/padding_node_x;
        //        float node_scale_y = padding_node_yl/padding_node_y;
        //        float node_scale = MIN(node_scale_x,node_scale_y);

        //        if(node_scale_x < 1)
        //        {
        //            _current_letter->setScale(node_scale_x);

        //        }

        _current_letter->setScale(0.87f);

        this->addChild(_current_letter);
    }

    cocos2d::CCLabelTTF* current_letter = _current_letter;
    if (status != LetterStatus::Empty)
    {
        std::vector<std::string> current_alphabete;
        current_alphabete =Alphabete::getInstance().getAlphabete();

        std::vector<cocos2d::ccColor3B > current_alphabete_color;
        current_alphabete_color =Alphabete::getInstance().getAlphabeteColor();

        int it;
        for (int i = 0 ; i < current_alphabete.size(); ++i )
        {
            std::string cl = letter_string.c_str() ;
            std::string ca = current_alphabete[i].c_str() ;
            if ( cl == ca )
            {
                it = i;

            }
        }

        cocos2d::ccColor3B col;
        col = current_alphabete_color[it];


        current_letter->setString(letter_string.c_str());
        current_letter->setColor(col);


        if(status == LetterStatus::Frozen)
        {
            float coef = 0.8f;
            cocos2d::ccColor3B lighter=ccc3(makeLighter(col.r, coef),
                                            makeLighter(col.g, coef),
                                            makeLighter(col.b, coef));
            _letter_image->setColor(lighter);
        }

        current_letter->setAnchorPoint(ccp(0.5f,0.5f));
        current_letter->setPositionX(letter_image->getContentSize().width*0.5f);
        current_letter->setPositionY(letter_image->getContentSize().height*0.5f);


    }
    else
    {
        current_letter->setString("");
    }
}
void LetterNode::setLetterIsSelected(bool is_selected)
{
    _letter_is_selected = is_selected;
    if(!is_selected)
    {
        setSelectedLetter(_active_letter);
        ShowLetter();
    }

}
bool LetterNode::isSelectedLetter()
{
    return _letter_is_selected;
}
void LetterNode::setIndexSelectedLetter(int index)
{
    _index_selected_letter = index;
}

int LetterNode::getIndexSelectedLetter()
{
    return _index_selected_letter;
}
bool LetterNode::isLetterTrueforHint()
{
    bool letter_true = false;
    std::string active_letter_str = _active_letter.getLetterString().c_str();
    std::string selected_letter_str = _selected_letter.getLetterString().c_str();

    if  (_letter_is_selected)
    {
        if (active_letter_str != selected_letter_str)
        {
            letter_true = true;
        }
    }
    else
    {
        LetterStatus status = _active_letter.getLetterStatus();

        if (status != LetterStatus::Frozen)
        {
            letter_true = true;
        }
    }
    return letter_true;
}
void LetterNode::setNodeColor(cocos2d::ccColor3B  color)
{
    _letter_image->setColor(color);

}
void LetterNode::setJustSelected(LetterStatus status)
{
    _active_letter.setLetterStatus(status);
    _index_selected_letter = 10000;
    _just_selected = true;
}
