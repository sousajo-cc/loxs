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
            const std::size_t line;
        public:
            Token(TokenType tokenType, std::string lex, std::any literal, std::size_t lineToParse) :
                    type(tokenType),
                    lexeme(std::move(lex)),
                    stringLiteral(std::move(literal)),
                    line(lineToParse) {};

            std::string toString();
    };
}

#endif // END TOKEN_H
