#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Token.hpp"


constexpr char NULLITERAL[] = " ";
namespace loxs {
    class Scanner {
        private:
            const std::string source; //Code source
            std::vector<Token> tokens; //List of tokens
            void scanToken();
            bool endOfFile();
            char peek();
            void stringLiteral();
            void numberLiteral();
            void identifyLiteral();
            bool match(char expected);
            char nextChar();
            std::size_t current; //Points the current char of lexeme
            std::size_t start;  //Points to the first char of lexem
            std::size_t line ;  //Points to the line where current is
        public:
            explicit Scanner(std::string code) : source(std::move(code)),
                                                  current(0),
                                                  start(0),
                                                  line(1){}
            std::vector<Token> scanTokens();
            void addToken(TokenType type, std::any literal);
            void addToken(TokenType type);
            char get_curr_char() { return source.at(current++); }
            [[nodiscard]] std::size_t get_line() const { return line; }
    };
}
#endif //END SCANNER_H