# Project details

cmake_minimum_required(VERSION 3.20)
project(ctest)

# Global options

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC "${SRC_DIR}/${PROJECT_NAME}.c")
set(INC "${INC_DIR}/${PROJECT_NAME}.h")
set(LIB_SH "${PROJECT_NAME}")
set(LIB_ST "${PROJECT_NAME}-static")
set(EXAMPLE_MAIN "${CMAKE_SOURCE_DIR}/example/example.c")

# Targets
add_library(${LIB_SH} SHARED ${SRC})
add_library(${LIB_ST} STATIC ${SRC})
add_executable(example EXCLUDE_FROM_ALL ${EXAMPLE_MAIN})

# Target options

set_target_properties(${LIB_ST} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_link_libraries(example PRIVATE ${PROJECT_NAME})
target_include_directories(${LIB_SH} PRIVATE ${INC_DIR})
target_include_directories(${LIB_ST} PRIVATE ${INC_DIR})
install(TARGETS ${LIB_SH} LIBRARY DESTINATION lib)
install(TARGETS ${LIB_ST} ARCHIVE DESTINATION lib)
install(FILES ${INC} DESTINATION include)

# Compiler options

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
	target_compile_options(example PRIVATE -Wall -Wextra -Werror -Wunused-result -Wconversion)
	target_compile_options(
		${LIB_SH}
		PRIVATE
		-Wall -Wextra -Werror -Wunused-result -Wconversion
		-O3 -march=native -flto)
	target_compile_options(
		${LIB_ST}
		PRIVATE
		-Wall -Wextra -Werror -Wunused-result -Wconversion
		-O3 -march=native -flto)
endif ()
