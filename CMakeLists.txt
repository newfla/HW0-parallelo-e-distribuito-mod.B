cmake_minimum_required(VERSION 3.9)
project(HW0 C)

set(CMAKE_C_STANDARD 11)

# aggiungo la directory-root da dove pescare le librerie
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# aggiungo la libreria specifica
add_library(Timer include/Timer/c_timer.c)
add_library(Mat_Mat include/Mat_Mat/mat_mat.c)
add_library(Mat_Vet include/Mat_Vet/mat_vet.c)
add_library(Varie include/Varie/varie.c)

add_executable(HW0 main.c)

# linko le librerie
target_link_libraries(HW0 Timer Mat_Mat Mat_Vet Varie m)