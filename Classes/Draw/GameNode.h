#ifndef GAMENODE_H
#define GAMENODE_H
#include "Logic/Task.h"
#include "Logic/OneGame.h"

class GameNode: public cocos2d::CCNode, public HasSlots
{
public:
    GameNode(const OneGame *one_game );
private:

    const OneGame* _one_game;

};

#endif // GAMENODE_H
