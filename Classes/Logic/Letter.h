#ifndef LETTER_H
#define LETTER_H
#include <string>
#include "cocos2d.h"
#include <ADLib.h>
#include "StatusLetter.h"

class Letter
{
public:
    Letter();
    std::string _string_letter;
    LetterStatus _status;
};

#endif // LETTER_H
