project('velvetget', 'cpp', default_options: [
  'cpp_std=c++17'
  ])

cxxopt_include = include_directories('cxxopts/include')

libspng_sp = subproject('libspng')
libspng_dep = libspng_sp.get_variable('spng_dep')
spng_include = include_directories('subprojects/libspng/spng')

velvetget_src = files('main.cpp', 'image.cpp', 'showie.cpp')

executable('velvetget', velvetget_src,
  include_directories: [cxxopt_include, spng_include],
  dependencies: [libspng_dep])

