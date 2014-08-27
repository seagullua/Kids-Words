#include "Word.h"
#include <vector>

Word::Word(std::string word)

{
    std::string current_word;
    current_word=word;
    for (int i = 0 ; i<current_word.size(); ++i )
    {
        std::string ch = " ";
        ch[0] = current_word[i];
        _letters_of_word.push_back(ch);
    }
}
const std::vector<std::string>  Word::getLettersOfWord() const
{
    return _letters_of_word;
}
