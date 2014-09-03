#ifndef TASK_H
#define TASK_H
#include <vector>
#include <string>
#include "Letter.h"
#include "Logic/Collection.h"
#include "Logic/Level.h"
class Task
{
public:
    Task(Level level, int difficult);
    void setTask(Level level, int difficult);
    int getNumberOfLetter(int difficult,int word_size);
    int getMinNumberOfLetter(int difficult);
    const std::vector<Letter>& getSolution() const;
    const std::vector<Letter>& getInUseLetters() const ;
    const std::vector<Letter>& getQiuzWord() const ;
    const std::string getAudioName() const ;
    const std::string getTranslatedWord() const ;
    const std::string getImageFile() const ;

private:

    std::vector<Letter> _solution;
    std::vector<Letter> _in_use_letters;
    std::vector<Letter> _qiuz_word;
    std::string _audio_name;
    std::string _translated_word;
    std::string _image_file;
    Level _level;
    int _difficult;
  };

#endif // TASK_H
