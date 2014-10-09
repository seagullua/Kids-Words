#include "Task.h"
#include "Word.h"
#include "Alphabete.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "StatusLetter.h"
#include <algorithm>

using namespace cocos2d;

Task::Task(Level level, int difficult):
    _level(level),
    _difficult(difficult)
{

    std::vector<std::string>  letters_of_words_str = _level.getWord().getLettersOfWord();
    std::vector<int>  number_letter;

    //solution
    for (int i = 0 ; i < letters_of_words_str.size(); ++i )
    {
        _solution.push_back(Letter(letters_of_words_str[i]));
        number_letter.push_back(i);

    }
    std::random_shuffle(number_letter.begin(), number_letter.end());

    //in_use_letters
    int number_of_letter = getNumberOfLetter(difficult,number_letter.size());
    int min_number_of_letter = getMinNumberOfLetter(difficult);
    int use_number_of_letter = number_of_letter;
    int total = number_of_letter + use_number_of_letter;
    if (total < min_number_of_letter )
    {
        total = min_number_of_letter ;
    }
    use_number_of_letter = total - number_of_letter;
    for (int i = 0 ; i < number_of_letter; ++i )
    {
        Letter x = _solution[number_letter[i]];
        _in_use_letters.push_back(x);

    }
    std::vector<std::string> alphabet =Alphabete::getInstance().getAlphabete();
    std::vector<int>  number_letter_from_alphabete;
    number_letter_from_alphabete = Alphabete::getInstance().getNumberLetterFromAlphabete(use_number_of_letter + 1);
    for (int i = 0 ; i < use_number_of_letter; ++i )
    {
        _in_use_letters.push_back(Alphabete::getInstance().getLetterById(number_letter_from_alphabete[i]));

    }
    std::random_shuffle(_in_use_letters.begin(), _in_use_letters.end());

    // qiuz_word
    _qiuz_word = _solution;
    for (int i = 0 ; i < _qiuz_word.size(); ++i )
    {
        _qiuz_word[i].setLetterStatus(LetterStatus::Frozen);
    }
    for (int i = 0 ; i < number_of_letter; ++i )
    {
        _qiuz_word[number_letter[i]].setLetterStatus(LetterStatus::Empty);
    }


    _translated_word = _level.getTranslation();
    _image_file = _level.getImage();

}




const std::vector<Letter> &Task::getSolution() const
{
    return _solution;

}
const std::vector<Letter> &Task::getInUseLetters() const
{
    return _in_use_letters;
}
const std::vector<Letter> &Task::getQiuzWord() const
{
    return _qiuz_word;
}
const std::string Task::getAudioName() const
{
    return _audio_name;
}
const std::string Task::getTranslatedWord() const
{
    return _translated_word;
}
const std::string Task::getImageFile() const
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
int Task::getMinNumberOfLetter(int difficult)
{
    int min_number_of_letter = 1 ;
    if (difficult == 0)
    {
        min_number_of_letter =InfoStyles::EASY_NUMBER;
    }
    else if (difficult == 1)
    {
        min_number_of_letter =InfoStyles::MIDDLE_NUMBER;
    }
    else if (difficult == 2)
    {
        min_number_of_letter =InfoStyles::DIFFICULT_NUMBER;
    }
    return  min_number_of_letter;

}
