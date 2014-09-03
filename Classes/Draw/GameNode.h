#ifndef GAMENODE_H
#define GAMENODE_H
#include "Logic/Task.h"
#include "Logic/OneGame.h"
#include "LetterNode.h"

class GameNode: public cocos2d::CCNode, public HasSlots
{
public:
    static GameNode* create(const OneGame *one_game );
    GameNode(const OneGame *one_game );
    Signal<int, Letter> signalAddLetter;
    Signal<> signalGameEnd;
    //Signal<> signalOneGameEnd;
    Signal<int> signallStarsChanged;


    bool isSetEnd();
    void playAudio();
    void addLeter(int position, Letter letter);
    void signalAddLetterOn();
    void signalGameEndOn();
    void signalOneGameOn();
    void signallStarsChangedOn(int number_of_stars);

private:

    const OneGame* _one_game;
    int _stars;

};

#endif // GAMENODE_H
