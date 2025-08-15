#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <optional>
#include <cxxopts.hpp>
#include <spng.h>
#include "image.h"

static const std::string CHAR_FILE = "characters.dat";
static constexpr size_t MAX_BUFFER_LEN = 128;

static spng_ctx* ctx = nullptr;
static std::vector<std::pair<std::string, std::string>> characters;


static void preload_characters() {
  characters.clear();

  FILE* fp = fopen(CHAR_FILE.c_str(), "r");
  if (fp == nullptr) {
    std::cout << "the character data file is broken." << std::endl;
    exit(1);
  }

  char cmd_buffer[MAX_BUFFER_LEN];
  char name_buffer[MAX_BUFFER_LEN];

  while (!feof(fp)) {
    fscanf(fp, "%s\n%s\n", cmd_buffer, name_buffer);
    characters.emplace_back(cmd_buffer, name_buffer);
  }

  fclose(fp);
}


static void print_list() {
  for (const auto& p : characters) {
    std::cout << p.first << " ~> " << p.second << std::endl;
  }
}


static std::optional<std::string> get_character_name(const std::string& ch) {
  for (const auto& p : characters) {
    if (p.first == ch) {
      return p.second;
    }
  }

  return {};
}


// TODO: get image path


static void print_character(const std::string& character) {
  auto name_res = get_character_name(character);
  if (!name_res.has_value()) {
    print_list();
    exit(1);
  }

  Image img;

  ctx = spng_ctx_new(0);

  std::cout << name_res.value() << std::endl;
  // TODO: print image

  spng_ctx_free(ctx);
}

int main(int argc, char* argv[]) {
  preload_characters();

  cxxopts::Options options("velvetget",
                           "show velvet assistant in your terminal");
  options.add_options()
    ("a,all", "List all characters")
    ("c,character", "Character", cxxopts::value<std::string>());

  auto result = options.parse(argc, argv);
  if (result.count("all")) {
    print_list();
  }
  else if (result.count("character")) {
    print_character(result["character"].as<std::string>());
  }
  else {
    std::srand(std::time({}));
    const size_t total = characters.size();
    const int id = std::rand() % total;
    print_character(characters[id].first);
  }

  return 0;
}

