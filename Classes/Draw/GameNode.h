#ifndef GAMENODE_H
#define GAMENODE_H
#include "Logic/Task.h"
#include "Logic/OneGame.h"
#include "LetterNode.h"

class GameNode: public cocos2d::CCNode, public HasSlots, public cocos2d::CCTouchDelegate
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
    void onExit();
private:
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    cocos2d::CCPoint touchToInsertCords(cocos2d::CCTouch* touch);
    cocos2d::CCPoint touchToQuizCords(cocos2d::CCTouch* touch);
    void startTrackingTouch();
    void stopTrackingTouch();
    int _letters_in_row;
    float _letter_size;
    cocos2d::CCSize _letter_zone_size;
    void moveLetterNodeBack(LetterNode* node);
    cocos2d::CCPoint getLetterCordinates(int index);

    const OneGame* _one_game;
    cocos2d::CCNode* _node_in_use_letters;
    std::vector<LetterNode*> _letters_to_insert;
    std::vector<LetterNode*> _letters_qiuz;
    cocos2d::CCNode* _node_qiuz_word;
    LetterNode* _selected_letter;
    bool _is_tracking_touch;
    int _stars;

};

#endif // GAMENODE_H
