cmake_minimum_required(VERSION 3.20)

# Khai báo project
project(Tetris LANGUAGES CXX)

# Sử dụng chuẩn C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Tìm thư viện raylib
find_package(raylib CONFIG REQUIRED)

# Khai báo file thực thi
add_executable(Tetris
    src/main.cpp
)

# Khai báo thư mục chứa header
target_include_directories(Tetris PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Liên kết raylib
target_link_libraries(Tetris PRIVATE raylib)