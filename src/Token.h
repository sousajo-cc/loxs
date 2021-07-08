#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.h"
#include <any>
#include <string>

namespace loxs {
    class Token {
        private:
            const TokenType type;
            const std::string lexeme;
            const std::any stringLiteral;
            const int line;
        public:
            Token(TokenType tokenType, std::string lex, std::any literal, int lineToParse) :
                    type(tokenType),
                    lexeme(lex),
                    stringLiteral(literal),
                    line(lineToParse) {};

            std::string toString();
    };
}

#endif // END TOKEN_H
