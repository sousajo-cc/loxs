#include "Token.h"

std::string Tolkien::Token::toString()
{
    return (TokenTypeString(this->type) + " " + this->lexeme + " " + this->literal);
}