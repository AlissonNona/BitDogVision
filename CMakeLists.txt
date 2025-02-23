# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(BitDogVision C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add all source files
file(GLOB_RECURSE SOURCES 
    "src/*.c"
    "src/*.cpp"
    "src/*.S"
)

add_executable(BitDogVision ${SOURCES})

pico_set_program_name(BitDogVision "BitDogVision")
pico_set_program_version(BitDogVision "0.1")

# Enable USB para saída de voz via printf
pico_enable_stdio_uart(BitDogVision 0)
pico_enable_stdio_usb(BitDogVision 1)

# Configurações de diretórios
target_include_directories(BitDogVision PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src
)

# Bibliotecas necessárias
target_link_libraries(BitDogVision
    pico_stdlib
    hardware_pwm
    hardware_gpio
    hardware_adc
    hardware_timer
)

pico_add_extra_outputs(BitDogVision)