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
            bool end_of_file();
            char peek();
            void string_literal();
            void number_literal();
            void identify_literal();
            bool match(char expected);
            char next_char();
            std::size_t current = 0; //Points the current char of lexeme
            std::size_t start = 0;  //Points to the first char of lexem
            std::size_t line = 1;  //Points to the line where current is
        public:
            explicit Scanner(std::string code) : source(std::move(code)) {}
            std::vector<Token> scanTokens();
            void addToken(TokenType type, std::any literal);
            void addToken(TokenType type);
            char get_curr_char() { return source.at(current++); }
            std::size_t get_line() const { return line; }
    };
}
#endif //END SCANNER_H