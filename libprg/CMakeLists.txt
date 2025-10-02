cmake_minimum_required(VERSION 3.21)
project(libprg C)

set(CMAKE_C_STANDARD 17)

set(HEADERS
        "${CMAKE_CURRENT_LIST_DIR}/src/include/libprg/libprg.h"
)

set(SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/pilha.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/fila.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/lista_linear.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/libprg/lista_encadeada.c"
)

add_library(libprg ${SOURCES}
        src/include/libprg/libprg.h
)

target_include_directories(libprg PUBLIC "${CMAKE_CURRENT_LIST_DIR}/src/include")

source_group(
        TREE "${CMAKE_CURRENT_LIST_DIR}/src/include"
        PREFIX "Header Files"
        FILES ${HEADERS}
)

install(TARGETS libprg DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
