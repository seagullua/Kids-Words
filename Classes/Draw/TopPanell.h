#ifndef TOPPANELL_H
#define TOPPANELL_H
#include "cocos2d.h"
#include <ADLib/ADSignals.h>
#include "Stars.h"
class TopPanell : public cocos2d::CCNode, public HasSlots
{
public:
    static TopPanell* create(int word_number, int all_words, int star_number);

    std::string _title_number_word;
    cocos2d::CCLabelTTF* _number_words;
    int _all_words;
    int _star_number;
    Stars* _stars_node;
    TopPanell(int word_number, int all_words, int star_number);
    void drawPanel(int word_number, int all_words, int star_number);
    void starsDrawChanged(int star_number);
    Signal<> signalAudioClicked;
    Signal<> signalUseHint;
    void signalAudioOnClicked();
    void signalUseHintOnClicked();
    void setTitleNumberWord(int word_number);

};
#endif // TOPPANELL_H
