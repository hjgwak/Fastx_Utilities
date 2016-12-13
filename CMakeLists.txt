cmake_minimum_required(VERSION 3.5)
project(Fastx_Utilities)

set(CMAKE_CXX_STANDARD 11)

#setting build mode
IF ("${build}" MATCHES "debug")
    SET(CMAKE_BUILD_TYPE "debug")
ELSE ("${build}" MATCHES "release")
    SET(CMAKE_BUILD_TYPE "release")
ENDIF ()

#setting build bit information
IF ("${bit}" MATCHES "32")
	ADD_DEFINITIONS(-DCALIB_CFG_COMPILE_BIT=32 -m32)
	SET(CMAKE_EXE_LINKER_FLAGS -m32)
ELSE ("${bit}" MATCHES "64")
	ADD_DEFINITIONS(-DCALIB_CFG_COMPILE_BIT=64 -m64)
	SET(CMAKE_EXE_LINKER_FLAGS -m64)
ENDIF ()

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)