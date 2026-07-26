cmake_minimum_required(VERSION 3.10)
project(PokemonBattleSimulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/Move.cpp
    src/Pokemon.cpp
    src/Team.cpp
    src/Trainer.cpp
    src/Battle.cpp
    src/TypeChart.cpp
)

add_executable(PokemonBattleSimulator ${SOURCES})
