#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.h"
#include <any>
#include <string>
namespace Loxs {
    class Token {
        private:
            const TokenType type;
            const std::string lexeme;
            const std::any literal;
            const int line;
        public:
            Token(TokenType type, std::string lexeme, std::any literal, int line) :
                    type(type), 
                    lexeme(lexeme), 
                    literal(literal), 
                    line(line) {};

            std::string toString();
    };
}

#endif // END TOKEN_H
