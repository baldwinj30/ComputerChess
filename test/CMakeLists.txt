include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  board_test
  Board_unittest.cpp
)

target_link_libraries(
  board_test
  gtest_main
)

include_directories(${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
gtest_discover_tests(board_test)
