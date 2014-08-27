#include "Task.h"
#include "Word.h"
#include "Alphabete.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "StatusLetter.h"
#include <algorithm>

Task::Task(Level level, int difficult):
    _level(level),
    _difficult(difficult)
{

}


void Task::setTask(Level level, int difficult)
{

    std::vector<std::string>  letters_of_words_str = _level.getWord().getLettersOfWord();
    std::vector<int>  number_letter;

    for (int i = 0 ; i<letters_of_words_str.size(); ++i )
    {
        _solution.push_back(Letter(letters_of_words_str[i]));
        number_letter.push_back(i);

    }
    std::random_shuffle(number_letter.begin(), number_letter.end());

    int number_of_letter = getNumberOfLetter(difficult,number_letter.size())-1;
    for (int i = 0 ; number_of_letter; ++i )
    {
        Letter x = _solution[number_letter[i]];
        _in_use_letters.push_back(x);

    }
    _qiuz_word = _solution;
    for (int i = 0 ; i<_qiuz_word.size(); ++i )
    {
        _qiuz_word[i].setLetterStatus(LetterStatus::Frozen);
    }
    for (int i = 0 ; number_of_letter; ++i )
    {
        _qiuz_word[number_letter[i]].setLetterStatus(LetterStatus::Empty);
    }


    //_in_use_letters = letters_of_words;
    // _qiuz_word = letters_of_words;
    //audio_name = _level.;

    _translated_word = _level.getTranslation();
    _image_file = _level.getImage();

}

const std::vector<Letter> &Task::getSolution()
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
int Task::getNumberOfLetter(int difficult,int word_size)
{
    int number_of_letter = 1 ;
    int percentage = 0;
    if (difficult == 0)
    {
        percentage = InfoStyles::EASY;
    }
    else if (difficult == 1)
    {
        percentage = InfoStyles::MIDDLE;
    }
    else if (difficult == 2)
    {
        percentage = InfoStyles::DIFFICULT;
    }
    number_of_letter = percentage * word_size / 100;
    if (number_of_letter == 0)
    {
        number_of_letter = 1 ;
    }
    return number_of_letter;
}
