#include "Token.h"

std::string Loxs::Token::toString()
{
    return (TokenTypeString(this->m_type) + 
                            " " + 
                            this->m_lexeme + 
                            " " + 
                            ((std::string(this->m_literal.type().name())) == "i" ? 
                            (std::to_string(std::any_cast<int>(this->m_literal))) : 
                            (std::any_cast<std::string>(this->m_literal)))
                            //playing around
    );
}
