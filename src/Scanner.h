#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Token.h"


constexpr char NULLITERAL[] = " ";
namespace loxs {
    class Scanner {
        private:
            std::string source; //Code source
            std::list<Token> tokens; //List of tokens
            void scanToken();
            bool end_of_file();
            char peek();
            void string_literal();
            void number_literal();
            void identify_literal();
            bool match(char expected);
            char next_char();
            long unsigned current = 0; //Points the current char of lexeme
            long unsigned start = 0;  //Points to the first char of lexem
            long unsigned line = 1;  //Points to the line where current is
        public:
            explicit Scanner(std::string code) : source(code) {}
            std::list<Token> scanTokens();
            void addToken(TokenType type, std::any literal);
            void addToken(TokenType type);
            char get_curr_char() { return source.at(current++); }
            long unsigned get_line() { return line; }
    };

    // Map for special Keywords
    inline const std::map<std::string, TokenType> keywords {
        {"class",  TokenType::CLASS},
        {"else",   TokenType::ELSE},
        {"false",  TokenType::FALSE},
        {"for",    TokenType::FOR},
        {"fun",    TokenType::FUN},
        {"if",     TokenType::IF},
        {"nil",    TokenType::NIL},
        {"print",  TokenType::PRINT},
        {"return", TokenType::RETURN},
        {"super",  TokenType::SUPER},
        {"this",   TokenType::THIS},
        {"true",   TokenType::TRUE},
        {"var",    TokenType::VAR},
        {"while",  TokenType::WHILE}
    };
}
#endif //END SCANNER_H