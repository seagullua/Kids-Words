#ifndef GAMENODE_H
#define GAMENODE_H
#include "Logic/Task.h"
#include "Logic/OneGame.h"
#include "Logic/Hint.h"
#include "LetterNode.h"

class GameNode: public cocos2d::CCNode, public HasSlots, public cocos2d::CCTouchDelegate
{
public:
    static GameNode* create(const OneGame *one_game, int use_h );
    GameNode(const OneGame *one_game, int  use_h );
    Signal<int, Letter> signalAddLetter;
    Signal<> signalGameEnd;
    //Signal<> signalOneGameEnd;
    Signal<int> signallStarsChanged;


    bool isSetEnd();
    void playAudio();
    void addLeter(int position, Letter letter);
    void signalAddLetterOn();
    void signallStarsChangedOn(int number_of_stars);
    void onExit();

    void showHint(OneHint current_hint);
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
    int _use_h;
    float _letter_size;
    cocos2d::CCSize _letter_zone_size;
    void moveLetterNodeBack(LetterNode* node);
    void moveLetterNodeBackByIndex(LetterNode* node,int index);
    cocos2d::CCPoint getLetterCordinates(int index);

    const OneGame* _one_game;
    cocos2d::CCNode* _node_in_use_letters;
    std::vector<LetterNode*> _letters_to_insert;
    std::vector<LetterNode*> _letters_qiuz;
    cocos2d::CCNode* _node_qiuz_word;
    bool _is_quiz_letter_selected;
    int _quiz_selection_index;
    LetterNode* _selected_letter;
    LetterNode* _selected_node_letter;
    bool _is_tracking_touch;
    int _stars;
    std::vector<int> _index_in_use_letter;

};

#endif // GAMENODE_H
