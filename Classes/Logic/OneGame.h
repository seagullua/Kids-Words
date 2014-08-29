#ifndef ONEGAME_H
#define ONEGAME_H
#include "Task.h"
class OneGame
{
public:
    OneGame(Task task);
    const Task& getTask() const;
private:
    Task _task;

};

#endif // ONEGAME_H
