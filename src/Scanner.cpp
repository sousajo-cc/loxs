#include "Scanner.h"
namespace loxs {
    /* Helper function to get current char */
    const char Scanner::get_curr_char() {
        return source.at(current++);
    }

    /* Helper functions to add tokens to tokens list */
    void Scanner::addToken(TokenType type, std::any literal) {
        std::string sub_string = source.substr(start, current);
        tokens.push_front(Token(type, sub_string, literal, line));
    }

    /* Helper functions to add tokens to tokens list */
     void Scanner::addToken(TokenType type) {
        addToken(type, NULL);
    }

    bool Scanner::end_of_file() {
        return (this->current >= this->source.length());
    }
    bool Scanner::match() {
        if(end_of_file()) return false;
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
            default:
            //Add Try catch here maybe
                break;
        }
    }

    /* This function scan the tokens of a source code file.
    *   Starting in the first line, having a "pointer" for
    *   both start of the lexeme and current char of it.
    *       int i = 1;
    *   Three lexames: 'int', 'i' and '1'
    */    
    std::list<Token> Scanner::scanTokens() {
        while(!end_of_file())
        {
            start = current;
            scanToken();
        }
        tokens.push_front(Token(TokenType::EoF,"",NULL,line));
    }
}