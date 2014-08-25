#ifndef TASK_H
#define TASK_H
#include <vector>
#include <string>
#include "Letter.h"
#include "Logic/Collection.h"
class Task
{
public:
        Task(CollectionID id, int difficult);
       void setTask(CollectionID id, int difficult);
private:

    std::vector<Letter> _solution;
    std::vector<Letter> _in_use_letters;
    std::vector<Letter> _qiuz_word;
    std::string _audio_name;
    std::string _translated_word;
    std::string _image_file;
    CollectionID _collection_id;
    int _difficult;
    std::vector<Letter> getSolution();
    std::vector<Letter> getInUseLetters();
    std::vector<Letter> getQqiuzWord();
    std::string getAudioName();
    std::string geTTranslatedWord();
    std::string getImageFile();
};

#endif // TASK_H
