#include "OneGame.h"


OneGame::OneGame(Task task):
    _task(task)
{
}
const Task &OneGame::getTask()
{
    return _task;
}
