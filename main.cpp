#include <iostream>
#include <cxxopts.hpp>
#include <characters.hpp>

int main(int argc, char* argv[]) {
  cxxopts::Options options("velvetget",
                           "show velvet assistant in your terminal");
  options.add_options()
    ("c,character", "Character", cxxopts::value<std::string>());

  auto result = options.parse(argc, argv);
  if (result.count("character")) {
    std::cout << "welcome!" << std::endl; // TODO: read from text file
  }
  else {
    // TODO: random
  }

  return 0;
}
