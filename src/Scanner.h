#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <list>
#include "Token.h"
namespace loxs {
    class Scanner {
        private:
            std::string source;
            std::list<Token> tokens;
            void scanToken();   //Function to scan tokens of lexeme
            bool end_of_file();
            bool match();
            int current = 0; //Points the current char of lexeme
            int start = 0;  //Points to the first char of lexem
            int line = 1;  //Points to the line where current is
        public:
            Scanner(std::string code) : source(code) {}
            std::list<Token> scanTokens();
            void addToken(TokenType type, std::any literal);
            void addToken(TokenType type);
            const char get_curr_char();
            const int get_line() { return line; }
    };
}
#endif //END SCANNER_H