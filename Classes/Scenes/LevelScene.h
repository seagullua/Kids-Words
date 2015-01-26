#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"
#include "Logic/Collection.h"
#include "Logic/OneGame.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"
#include "Draw/TopPanell.h"
#include "Managers/TutorialManager.h"

class LevelScene: public SceneStyle
{
public:
    LevelScene(CollectionID id, int difficult);
    static cocos2d::CCScene* scene(CollectionID id, int difficult);
    static LevelScene* create(CollectionID id, int difficult);
    void selectOneGame();
    void selectNextSeason();
private:
    void onOneGameEnd();
    void onOneGameEndTouch();
    bool init();
    void onBackClick();
    void EndLevel();
    void onSignalAudioClicked();
    void onSignalUseHintClicked();
    void onSignalNextLesson();
    void setOneGame(const OneGame *one_game);

    void hideEverything(ADCallFunc::Action action);

    void openNextLevel();
    int getStarNumber();


    CollectionID _collection_id;
    int _difficult;
    int _current_number_of_word;
    int _number_of_word;
    const OneGame* _one_game;
    GameNode* _game_node;
    OneSeason _current_one_season;
    float _use_h;
    float _use_w;
    TopPanell* _top_panel;
    bool _tutorial;
    bool _end_game_touch;


};

#endif // LEVELSCENE_H
