#include "Task.h"

Task::Task(CollectionID id, int difficult)

{
    _collection_id = id;
    _difficult = difficult;
}


void Task::setTask(CollectionID id, int difficult)
{
    // Руслана як правильно заповнити Task та отримувати його дані
}

std::vector<Letter> Task::getSolution()
{
    return _solution;

}
std::vector<Letter> Task::getInUseLetters()
{
    return _in_use_letters;
}
std::vector<Letter> Task::getQqiuzWord()
{
    return _qiuz_word;
}
std::string Task::getAudioName()
{
    return _audio_name;
}
std::string Task::geTTranslatedWord()
{
    return _translated_word;
}
std::string Task::getImageFile()
{
    return _image_file;
}
