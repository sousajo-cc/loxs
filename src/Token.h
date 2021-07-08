#ifndef TOKEN_H
#define TOKEN_H

#include "TokenType.h"
#include <any>
#include <string>
namespace Loxs {
    class Token {
        private:
            const TokenType m_type;
            const std::string m_lexeme;
            const std::any m_literal;
            const int m_line;
        public:
            Token(TokenType type, std::string lexeme, std::any literal, int line) :
                    m_type(type), 
                    m_lexeme(lexeme), 
                    m_literal(literal), 
                    m_line(line) {};

            std::string toString();
    };
}

#endif // END TOKEN_H
