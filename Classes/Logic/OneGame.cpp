#include "OneGame.h"
#include "OneSeason.h"

OneGame::OneGame(Task task, OneSeason* season):
    _task(task),
    _season(season)
{
}
const Task &OneGame::getTask() const
{
    return _task;
}

int OneGame::getNumberOfHint() const
{
    return _season->getNumberOfHint();
}


bool OneGame::isCanUseHint() const
{
    int number_of_hint =_season->getNumberOfHint();
    if (number_of_hint > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
