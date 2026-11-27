cmake_minimum_required(VERSION 3.30)


project("crucible")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


find_package("CLI11" CONFIG REQUIRED)
find_package("yaml-cpp" CONFIG REQUIRED)


add_executable(${PROJECT_NAME})

if (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	target_compile_options(${PROJECT_NAME} PRIVATE 
		/W3 # high warning level
		/MP # multithreaded build
		# /WX # warnings as errors
	)
endif()


target_sources(${PROJECT_NAME} PRIVATE 
	
"src/main.cpp"
	
    )

target_include_directories(${PROJECT_NAME} PUBLIC "src")
target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11 yaml-cpp::yaml-cpp)


if(DEFINED ENV{KILNWARE_BIN_ROOT} AND NOT "$ENV{KILNWARE_BIN_ROOT}" STREQUAL "")
	file(TO_CMAKE_PATH "$ENV{KILNWARE_BIN_ROOT}" _env_bin_root)
	set(BIN_ROOT "${_env_bin_root}" CACHE PATH "Directory where built executables are installed")
else()
	set(BIN_ROOT "C:/kilnware/bin" CACHE PATH "Directory where built executables are installed")
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${BIN_ROOT}")

install(IMPORTED_RUNTIME_ARTIFACTS yaml-cpp::yaml-cpp
    RUNTIME DESTINATION "${BIN_ROOT}"
)
