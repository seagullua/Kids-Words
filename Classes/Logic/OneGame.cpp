#include "OneGame.h"


OneGame::OneGame(Task task):
    _task(task),
    _number_of_hint(10)
{
}
const Task &OneGame::getTask() const
{
    return _task;
}
void OneGame::setNumberOfHint()
{
    if (_number_of_hint > 0)
    {
        _number_of_hint = _number_of_hint - 1;
    }

}
int OneGame::getNumberOfHint()
{
    return _number_of_hint;
}
bool OneGame::isCanUseHint()
{
    if (_number_of_hint > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Hint OneGame::getHint()
{
    Hint current_hint(_task);
    return current_hint;
}
