add_executable(MyLabs Third.cpp)
target_include_directories(MyLabs PUBLIC ../LibraryCPP)
target_link_libraries(MyLabs LibraryCPP)