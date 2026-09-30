add_executable(main.cpp)

target_include_directories(Lab2 PUBLIC ../LibraryCPP)

target_link_libraries(Lab2 LibraryCPP)

#add_subdirectory(Tests)