#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <string>
#include <cstring>
#include <spng.h>

using byte = unsigned char;
using vec2d = std::pair<int, int>;

struct Color {
  byte r, g, b, a;

  Color(byte pr, byte pg, byte pb, byte pa): r{pr}, g{pg}, b{pb}, a{pa} {}
};

class Image {
private:
  byte* _image;
  size_t _width, _height;
public:
  Image() : _image{nullptr}, _width{0}, _height{0} {}
  ~Image();

  bool open(const std::string&, spng_ctx*);

  Color operator[] (const vec2d& pos);
};

#endif // __IMAGE_H__

