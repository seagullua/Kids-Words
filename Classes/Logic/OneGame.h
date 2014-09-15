#ifndef ONEGAME_H
#define ONEGAME_H
#include "Task.h"
#include "Hint.h"
class OneGame
{
public:
    OneGame(Task task);
    const Task& getTask() const;
    void setNumberOfHint() const;
    int getNumberOfHint() const;
    bool isCanUseHint() const;
    Hint getHint() const;
private:
    Task _task;
    mutable int _number_of_hint;




};

#endif // ONEGAME_H
