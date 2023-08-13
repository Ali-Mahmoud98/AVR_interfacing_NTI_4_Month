cmake_minimum_required(VERSION 3.26.4)

project(timer8)

# Set the MCU and F_CPU
set(MCU atmega32)
set(F_CPU 8000000UL)

# Compiler settings
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)

set(CFLAGS -x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=${MCU} -c -std=gnu99)


# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug/lib)

# Layers folders
set(MCALDIR ../../MCAL)
set(HALDIR ../../HAL)
set(STDLIBS ../../LIB)

# Include directories
include_directories(${STDLIBS} ${MCALDIR}/DIO ${HALDIR}/LCD ${MCALDIR}/ADC ${MCALDIR}/TIMER ${MCALDIR}/EXT ${MCALDIR}/GIE ${MCALDIR}/DIO)


# Add subdirectories for libraries
add_subdirectory(${MCALDIR}/DIO)
add_subdirectory(${HALDIR}/LCD)
add_subdirectory(${MCALDIR}/ADC)
add_subdirectory(${MCALDIR}/KPD)
add_subdirectory(${MCALDIR}/TIMER)
add_subdirectory(${MCALDIR}/EXT)
add_subdirectory(${MCALDIR}/GIE)

# Main executable
add_executable(Main main.c)
target_compile_options(Main PRIVATE ${CFLAGS})
target_link_libraries(Main PRIVATE ${LIBS} ${LIBFILES})

# AVRDUDE flash target
add_custom_target(flash
    COMMAND avrdude -c usbasp -p m32 -B 0.5 -U flash:w:Main.hex:a
    DEPENDS Main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/clean-all.cmake
)
