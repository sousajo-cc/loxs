#include <functional>
#include <iostream>
#include "Scanner.h"
#include "Token.h"

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

static constexpr auto USAGE =
  R"(loxs.

    Usage:
          loxs --source <path>
          loxs --input 
    Options:
          -h --help     Show this screen.
          -s --source   Path to source file.
          -i --input    Text a line of code.
)";

int main()
{
  std::list<loxs::Token> go;
  /*std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    "loxs 2.0");// version string
  for (auto const &arg : args) {
    std::cout << arg.first << arg.second << std::endl;
  }


  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {}!", "World");

  fmt::print("Hello, from {}\n", "{fmt}");*/

  loxs::Scanner s("( == )");
  go = s.scanTokens();
  for (auto &t: go)
    std::cout << t.toString() << std::endl;
}
