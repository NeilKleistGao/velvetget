#include "image.h"

#include <cstdio>
#include <cstdlib>


Image::~Image() {
  if (_image) {
    delete []  _image;
    _image = nullptr;
  }
}


bool Image::open(const std::string& filename, spng_ctx* ctx) {
  return true;
}


Color Image::operator[] (const vec2d& pos) {
  return Color(255, 255, 255, 255); // TODO
}


