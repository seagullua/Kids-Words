#ifndef ONESEASON_H
#define ONESEASON_H
#include "Collection.h"
#include "Task.h"
#include "OneGame.h"
class OneSeason
{
public:
    OneSeason(CollectionID id, int difficult);

    void setSeasonsGame(OneGame current_one_game);
    const OneGame* getNextLevel();
    int getNumberWord(int difficult);
    void setTaskNumber();
private:
    CollectionID _collection_id;
    int _difficult;
    Task* _active_task;
    int _set_task_number;
    std::vector<OneGame> _seasons_games;


};

#endif // ONESEASON_H
