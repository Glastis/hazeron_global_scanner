cmake_minimum_required(VERSION 3.5)
project(hazeron_global_scanner)
include_directories(${CMAKE_SOURCE_DIR}/includes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES    retreivers/online_players/get_online_players.c
                    retreivers/online_players/number_online_players.c
                    retreivers/fetch_player_data.c
                    retreivers/common/get_page.c
                    retreivers/common/utilities.c
                    includes/retreivers/online_players/online_players.h
                    includes/retreivers/common/common.h
                    includes/retreivers/common/utilities.h
                    includes/retreivers/fetch_player_data.h)

add_executable(hazeron_global_scanner ${SOURCE_FILES})
target_link_libraries(hazeron_global_scanner curl)
