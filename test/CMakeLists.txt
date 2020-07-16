find_package(GTest REQUIRED)
add_executable(test main.cpp)
target_link_libraries(test PocoOverlay GTest::GTest GTest::Main)