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
    return true;
}

LetterNode::LetterNode(Letter letter):
    _active_letter(letter),
    _selected_letter(letter)
{
    //letter
    LetterStatus status = _active_letter.getLetterStatus();
    std:: string letter_string = _active_letter.getLetterString();
    std:: string image_name;

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
    CCSprite* letter_image = CCSprite::create(image_name.c_str());
    letter_image->setAnchorPoint(ccp(0,0));
    letter_image->setPositionX(0);
    letter_image->setPositionY(0);
    float padding_node_x = letter_image->getContentSize().width;
    float padding_node_y = letter_image->getContentSize().height;
    this->setContentSize(ccp(padding_node_x, padding_node_y));
    this->addChild(letter_image);
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

        cocos2d::CCLabelTTF* current_letter;
        current_letter = CCLabelTTF::create(letter_string.c_str(),
                                            ADLanguage::getFontName(),
                                            InfoStyles::SIZE_LETTER);

        current_letter->setColor(col);
        //current_letter->setString(letter_string.c_str());
        current_letter->setAnchorPoint(ccp(0.5f,0.5f));
        current_letter->setPositionX(letter_image->getContentSize().width*0.5f);
        current_letter->setPositionY(letter_image->getContentSize().height*0.5f);

        this->addChild(current_letter);
    }
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

}
