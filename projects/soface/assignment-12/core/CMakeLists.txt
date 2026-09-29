cmake_minimum_required(VERSION 3.10)
project(template)
include(CTest)

set(CMAKE_CXX_STANDARD 17)

# static checks
# if(MSVC)
#   add_compile_options(/W4 /WX)
# else()
#   add_compile_options(-Wall -Wextra -pedantic -Werror)
# endif()

# set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy;
#   -checks=*;
# )

# set(CMAKE_CXX_CPPCHECK
#   cppcheck;
#   --error-exitcode=1;
# )


# set include directory of all targets to the 'include' folder, this is similar
# to '-I include' in gcc
include_directories(include)


add_library(core INTERFACE)
target_include_directories(core INTERFACE include)

