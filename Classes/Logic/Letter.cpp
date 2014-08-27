#include "Letter.h"
#include "StatusLetter.h"

Letter::Letter(std::string string_letter="")

{
    _string_letter = string_letter;
    _status = LetterStatus::Normal;
}
void Letter::setLetterStatus(LetterStatus status)
{
   _status= status;
}
const LetterStatus Letter::getLetterStatus()
{
    return _status;
}
