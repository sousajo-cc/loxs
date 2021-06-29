#include "Token.h"

Token::Token (TokenType type, std::string lexeme, std::any literal = "", int line)
{
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
} 

std::string Token::toString()
{
    return (TokenString[this->type] + " " + this->lexeme + " " + this->literal);
}