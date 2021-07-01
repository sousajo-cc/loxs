#include "Token.h"

std::string Loxs::Token::toString()
{
    return (TokenTypeString(this->type) + " " + this->lexeme + " " + this->literal);
}