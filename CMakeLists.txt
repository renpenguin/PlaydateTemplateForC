cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)

set(ENVSDK $ENV{PLAYDATE_SDK_PATH})

if (NOT ${ENVSDK} STREQUAL "")
	# Convert path from Windows
	file(TO_CMAKE_PATH ${ENVSDK} SDK)
else()
	execute_process(
			COMMAND bash -c "egrep '^\\s*SDKRoot' $HOME/.Playdate/config"
			COMMAND head -n 1
			COMMAND cut -c9-
			OUTPUT_VARIABLE SDK
			OUTPUT_STRIP_TRAILING_WHITESPACE
	)
endif()

if (NOT EXISTS ${SDK})
	message(FATAL_ERROR "SDK Path not found; set ENV value PLAYDATE_SDK_PATH")
	return()
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

# Game Name - edit this to change the name of the output PDX
set(PLAYDATE_GAME_NAME PlaydateTemplate)

project(${PLAYDATE_GAME_NAME} C ASM)

file(GLOB SRC
	"src/**/*.c"
	"src/*.c"
)

set(PLAYDATE_GAME_DEVICE ${PLAYDATE_GAME_NAME}_DEVICE)
if (TOOLCHAIN STREQUAL "armgcc")
	target_compile_options(${PLAYDATE_GAME_DEVICE} PUBLIC -fsingle-precision-constant)
	add_executable($(PLAYDATE_GAME_DEVICE) ${SRC})
else()
	add_library(${PLAYDATE_GAME_NAME} SHARED ${SRC})
endif()

include(${SDK}/C_API/buildsupport/playdate_game.cmake)
