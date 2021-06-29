#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"
#include <any>
#include <string>

class Token {
    private:
        TokenType type;
        std::string lexeme;
        std::any literal;
        int line;
    public:
        Token (TokenType, std::string, std::any, int);
        std::string toString();

};

#endif // END TOKEN_H