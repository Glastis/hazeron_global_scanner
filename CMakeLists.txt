cmake_minimum_required(VERSION 3.5)
project(hazeron_global_scanner)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    retreivers/online_players/get_online_players.c
                    retreivers/online_players/number_online_players.c
                    retreivers/online_players/online_players.h
                    retreivers/common/get_page.c
                    retreivers/common/common.h
                    retreivers/common/utilities.c
                    retreivers/common/utilities.h)

add_executable(hazeron_global_scanner ${SOURCE_FILES})
target_link_libraries(hazeron_global_scanner curl)
