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
    void LetterNode::ShowLetter();
private:
    Letter _active_letter;
    Letter _selected_letter;

};

#endif // LETTERNODE_H
