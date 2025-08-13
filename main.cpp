#include <iostream>
#include <ctime>
#include <cstdlib>
#include <optional>
#include <cxxopts.hpp>
#include <spng.h>
#include <characters.hpp>

static spng_ctx* ctx = nullptr;

std::optional<std::string> check_character_data(const std::string& character) {
  // TODO: check if the character name is valid
}

void print_character(const std::string& character) {
  ctx = spng_ctx_new(0);

  // TODO: print image

  spng_ctx_free(ctx);
}

int main(int argc, char* argv[]) {
  cxxopts::Options options("velvetget",
                           "show velvet assistant in your terminal");
  options.add_options()
    ("c,character", "Character", cxxopts::value<std::string>());

  auto result = options.parse(argc, argv);
  if (result.count("character")) {
    print_character(result["character"].as<std::string>());
  }
  else {
    std::srand(std::time({}));
    const size_t total = CHARACTERS.size();
    const int id = std::rand() % total;
    print_character(CHARACTERS[id]);
  }

  return 0;
}

