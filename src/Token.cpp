#include "Token.h"

std::string loxs::Token::toString()
{
    return (TokenTypeString(this->type) +
                            " " + 
                            this->lexeme +
                            " " + 
                            ((std::string(this->stringLiteral.type().name())) == "d" ?
                            (std::to_string(std::any_cast<double>(this->stringLiteral))) :
                            (std::any_cast<std::string>(this->stringLiteral)))
                            //playing around
    );
}
