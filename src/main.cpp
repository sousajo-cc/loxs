#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Scanner.h"
#include "Token.h"

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

static constexpr auto USAGE =
  R"(loxs.

    Usage:
        loxs input <input>
        loxs source <file>

    Options:
          -h --help     Show this screen.
)";

int main(int argc, const char** argv)
{
  std::vector<loxs::Token> token_list;
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    "loxs 2.0");// version string
  
  if(args.find("source")->second.asBool())
  {
      std::ifstream source_file(args["<file>"].asString());
      std::ostringstream ss;
      ss << source_file.rdbuf();
      loxs::Scanner s(ss.str());
      token_list = s.scanTokens();
      for (auto &t: token_list)
        std::cout << t.toString() << std::endl;
  }
  else if (args.find("input")->second.asBool()) {
      loxs::Scanner s(args["<input>"].asString());
      token_list = s.scanTokens();
      for (auto &t: token_list)
        std::cout << t.toString() << std::endl;
  }
}
