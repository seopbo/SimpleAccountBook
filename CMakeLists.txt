# CMake 프로그램의 최소버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
    SimpleAccountBook
    VERSION 0.1.0
    DESCRIPTION "SimpleAccountBook"
    LANGUAGES CXX
)

# binary를 만드는데 필요한 cpp 파일들을 변수로 저장
set(ENTRY_FILES main.cpp)
file(GLOB SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# add_executable (<실행 파일 이름> <소스1> <소스2> ... <소스들>)
add_executable(program ${ENTRY_FILES} ${SRC_FILES})

# target_include_directories(<실행 파일 이름> PUBLIC <경로 1> <경로 2> ...)
target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/include)

# target_compile_options(<실행 파일 이름> PUBLIC <컴파일 옵션1> <컴파일 옵션2> ...)
target_compile_options(program PUBLIC -Wall -Werror -std=c++11)
