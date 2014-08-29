#ifndef LETTERNODE_H
#define LETTERNODE_H
#include "Logic/Letter.h"
#include "Logic/StatusLetter.h"

class LetterNode : public cocos2d::CCNode
{
public:
    static LetterNode* create(Letter letter );
    LetterNode(Letter letter);
private:
    Letter _active_letter;



};

#endif // LETTERNODE_H
