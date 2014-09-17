#ifndef ONEGAME_H
#define ONEGAME_H
#include "Task.h"
class OneSeason;
class OneGame
{
public:
    OneGame(Task task, OneSeason * season);
    const Task& getTask() const;
    int getNumberOfHint() const;
    bool isCanUseHint() const;

private:
    Task _task;
    OneSeason* _season;



};

#endif // ONEGAME_H
