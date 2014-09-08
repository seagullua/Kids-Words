#ifndef LETTERNODE_H
#define LETTERNODE_H
#include "Logic/Letter.h"
#include "Logic/StatusLetter.h"

class LetterNode : public cocos2d::CCNode
{
public:
    static LetterNode* create(Letter letter );
    LetterNode(Letter letter);
    const Letter getActiveLetter();
    const Letter getSelectedLetter();
    bool canInsertLetter(Letter letter);
    void setSelectedLetter(Letter selected_letter);
    void setLetterIsSelected(bool is_selected);
    void LetterNode::ShowLetter();
    bool isSelectedLetter();
    void setIndexSelectedLetter(int index);
    int getIndexSelectedLetter();
private:
    cocos2d::CCSprite* _letter_image;
    cocos2d::CCLabelTTF* _current_letter;
    Letter _active_letter;
    Letter _selected_letter;
    bool _letter_is_selected;
    int _index_selected_letter;

};

#endif // LETTERNODE_H
