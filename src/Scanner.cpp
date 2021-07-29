#include "Scanner.hpp"

namespace loxs {
    /* Helper functions to add tokens to tokens list */
    void Scanner::addToken(TokenType type, std::any literal) {
        auto sub_string = source.substr(start, current-start);
        tokens.emplace_back(Token(type, sub_string, std::move(literal), line));
    }

    /* Helper functions to add tokens to tokens list */
     void Scanner::addToken(TokenType type) {
        auto sub_string = source.substr(start, current-start);
        //fixme: we should improve the std::any is not good I prefer to have it
        // here the constructor of the string so we know this is a pain point
        tokens.emplace_back(Token(type, sub_string, std::string{" "}, line));
    }

    /* Helper functions to check if end of file was reached */
    bool Scanner::endOfFile() {
        return (current >= source.length());
    }

    /* Helper function to read chars */
    char Scanner::peek() {
        if(endOfFile()) {
            return '\0';
        }
        return source.at(current);
    }

    /* Helper functions to check if a next char is an operator e.g: == , != */
    bool Scanner::match(char expected) {
        if(endOfFile()) {
            return false;
        }
        if(source.at(current) != expected) {
            return false;
        }
        current++;
        return true;
    }

    /* Helper function to fetch next char */
    char Scanner::nextChar() {
        if((current + 1) >= source.length()) {
            return '\0';
        }
        return source.at(current + 1);
    }

    /* This function catch a string literal */
    void Scanner::stringLiteral() {
        while(peek() != '"' && !endOfFile()) {
            if(peek() == '\n') {
                line++;
            }
            current++;
        }
        if(endOfFile()) {};
            //return error

        current++; //Catch the "
        std::string string_literal = source.substr(start+1, ((current-1) - (start+1)));
        addToken(TokenType::STRING, string_literal);  
    }

    /* This function catch a number literal */
    void Scanner::numberLiteral() {
        while(peek() != '\n' && !endOfFile() && (isdigit(peek()) != 0)) {
                current++;
        }

        if(peek() == '.' && (isdigit(nextChar()) != 0)) {
            current++;
            while(isdigit(peek()) != 0) {
                current++;
            }
        }

        std::string number_literal = source.substr(start, current-start);
        addToken(TokenType::NUMBER, stod(number_literal));
    }

    /* This function catch an indentifier */
    void Scanner::identifyLiteral() {
         // Map for special Keywords
        static const std::map<std::string, TokenType> keywords {
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

        while((isalpha(peek()) != 0) || peek() == '_') {
            current++;
        }
        std::string keyword = source.substr(start, current - start);

        if (keywords.find(keyword) != keywords.end()) {
            addToken(keywords.find(keyword)->second);
        }
        else {
            addToken(TokenType::IDENTIFIER);
        }
    }

    /* This function scan the token of each lexeme
    *   accordingly with the TokenType.
    */
    void Scanner::scanToken() {
        const char curr_char = get_curr_char();
        switch (curr_char)
        {
            case '(': addToken(TokenType::LEFT_PAREN); break;
            case ')': addToken(TokenType::RIGHT_PAREN); break;
            case '{': addToken(TokenType::LEFT_BRACE); break;
            case '}': addToken(TokenType::RIGHT_BRACE); break;
            case ',': addToken(TokenType::COMMA); break;
            case '.': addToken(TokenType::DOT); break;
            case '-': addToken(TokenType::MINUS); break;
            case '+': addToken(TokenType::PLUS); break;
            case ';': addToken(TokenType::SEMICOLON); break;
            case '*': addToken(TokenType::STAR); break;
            case '!':
                addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
                break;
            case '=':
                addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
                break;
            case '<':
                addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
                break;
            case '>':
                addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
                break;
            case '/':
                if (match('/')) {
                  // A comment goes until the end of the line.
                  while (peek() != '\n' && !endOfFile()) {
                    current++;
                  }
                } else {
                  addToken(TokenType::SLASH);
                }
                break;
            case ' ':
            case '\r':
            case '\t':
              // Ignore whitespace.
              break;
            case '\n':
              line++;
              break;
            case '"':
              stringLiteral(); break;
            case '|':
                addToken(match('|') ? TokenType::OR : TokenType::NIL);
                break;
            case '&':
                addToken(match('&') ? TokenType::AND : TokenType::SUPER);
                break;
            default:
             if (isdigit(curr_char) != 0) {
               numberLiteral();
             } else { 
                if(isalpha(curr_char) != 0) {
                  identifyLiteral();
                }
            }
            //Add Try catch here maybe, in case the token isnt recognized
                break;
        }
    }

    /* This function scan the tokens of a source code file.
    *   Starting in the first line, having a "pointer" for
    *   both start of the lexeme and current char of it.
    *       int i = 1;
    *   Three lexames: 'int', 'i' and '1'
    */    
    std::vector<Token> Scanner::scanTokens() {
        while(!endOfFile())
        {
            start = current;
            scanToken();
        }
        tokens.emplace_back(Token(TokenType::EoF,"",line));
        return tokens;
    }
}
