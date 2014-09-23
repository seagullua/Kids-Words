#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <ADLib/Storage.h>

class TutorialManager: public HasSlots
{
    static const int BLOCK_TUTORIAL = 40001;
public:
    static TutorialManager* getInstance();

    bool isFirstGame();
    void setIsNotFirstGame();

private:
    static TutorialManager instance;

    TutorialManager();
    TutorialManager(TutorialManager const&);
    void operator=(TutorialManager const&);

    bool _first_game;

    void updateValues();

    void initStorageBlocks();
    void initDefaultValues();
};
#endif // TUTORIAL_H
