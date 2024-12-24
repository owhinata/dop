
cmake_minimum_required(VERSION 3.17.0)
project(klafim LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(_target ${PROJECT_NAME})

add_executable(${_target}
  src/main.c
  src/library.c
  src/catalog.c
  src/user_management.c
)

# target_compile_options(${_target}
#   PRIVATE
# )

target_include_directories(${_target}
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# target_link_libraries(${_target}
#   PUBLIC
# )

# set_target_properties(${_target} PROPERTIES
#   ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
#   CXX_CPPCHECK "${WITH_CPPCHECK}"
# )
