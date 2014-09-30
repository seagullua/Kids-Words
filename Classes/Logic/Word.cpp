#include "Word.h"
#include <vector>
#include <ADLib/UTF8/ADUTF8.h>
Word::Word(std::string word)

{
    _letters_of_word = ADUTF8::splitToChars(word);
}
const std::vector<std::string>  Word::getLettersOfWord() const
{
    return _letters_of_word;
}
