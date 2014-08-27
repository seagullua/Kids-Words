#ifndef WORD_H
#define WORD_H
#include <vector>
#include <string>
class Word
{
public:
    Word(std::string word="");
     const std::vector<std::string> getLettersOfWord() const;
private:
     std::vector<std::string> _letters_of_word;

};

#endif // WORD_H
