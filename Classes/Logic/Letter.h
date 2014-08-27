#ifndef LETTER_H
#define LETTER_H
#include <string>
#include "cocos2d.h"
#include <ADLib.h>
#include "StatusLetter.h"

class Letter
{
public:
    Letter(std::string string_letter);
    void setLetterStatus(LetterStatus status);
    LetterStatus _status;
    const LetterStatus getLetterStatus();

private:
    std::string _string_letter;

};

#endif // LETTER_H
