cmake_minimum_required(VERSION 3.5)

project(tst_validate_patient LANGUAGES CXX)

enable_testing()

include_directories("../..")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tst_validate_patient tst_tst_validate_patient.cpp ../../patient.cpp)
add_test(NAME tst_validate_patient COMMAND tst_validate_patient)

target_link_libraries(tst_validate_patient PRIVATE Qt${QT_VERSION_MAJOR}::Test)

