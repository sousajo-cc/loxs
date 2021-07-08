#include <catch2/catch.hpp>
#include "../../src/Token.h"
#include "../../src/TokenType.h"

TEST_CASE( "Check TokenType string", "[tokentype]" ) {
    Loxs::Token Test_Token(TokenType::LEFT_PAREN, "(", std::string(""), 0);
    INFO(Test_Token.toString())
    REQUIRE( Test_Token.toString() == "LEFT_PAREN ( " );
}

TEST_CASE( "Check TokenType int", "[tokentype]" ) {
    Loxs::Token Test_Token(TokenType::NUMBER, "int", 20, 0);
    INFO(Test_Token.toString())
    REQUIRE( Test_Token.toString() == "NUMBER int 20" );
}