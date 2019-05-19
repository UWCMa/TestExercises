cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)
target_link_libraries(main social_network story_board test)

add_subdirectory(impl)
include_directories(impl/SocialNetwork)
include_directories(impl/StoryBoard)
include_directories(impl/test)
