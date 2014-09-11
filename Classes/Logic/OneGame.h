#ifndef ONEGAME_H
#define ONEGAME_H
#include "Task.h"
#include "Hint.h"
class OneGame
{
public:
    OneGame(Task task);
    const Task& getTask() const;
private:
    Task _task;
    int _number_of_hint;
    void setNumberOfHint();
    int getNumberOfHint();
    bool isCanUseHint();
    Hint getHint();


};

#endif // ONEGAME_H
