#ifndef HINT_H
#define HINT_H
#include "Task.h"
#include <vector>
typedef std::pair<int,int> OneHint ;
class Hint
{
public:

    Hint(Task task);
    void setTask(Task task);
    OneHint getOneHint();

private:
    Task _task;
    std::vector<std::pair<int,int>> _hint_pairs;


};

#endif // HINT_H
