#ifndef TOPPANELL_H
#define TOPPANELL_H
#include "cocos2d.h"
#include <ADLib/ADSignals.h>
class TopPanell : public cocos2d::CCNode
{
public:
    static TopPanell* create(int word_number, int all_words, int star_number);

    TopPanell(int word_number, int all_words, int star_number);
    void drawPanel(int word_number, int all_words, int star_number);
    void starsDrawChanged(int star_number);
    //Signal<> signalAudioClicked;
    //Signal<> signalUseHint;
    void signalAudio();
};
#endif // TOPPANELL_H
