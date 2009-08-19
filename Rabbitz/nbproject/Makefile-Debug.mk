#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Macros
PLATFORM=GNU-Linux-x86

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Debug/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window_lua.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character_lua.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/player.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background_lua.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/tile.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/layer.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/input/src/input.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object_lua.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/Rabbitz/../src/input/src/input_lua.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/background.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath /home/cantidio/Development/gorgon++/Gorgon++/dist/Debug/GNU-Linux-x86 -L/home/cantidio/Development/gorgon++/Gorgon++/dist/Debug/GNU-Linux-x86 -lgorgon `allegro-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/${PLATFORM}/rabbitz

dist/Debug/${PLATFORM}/rabbitz: /home/cantidio/Development/gorgon++/Gorgon++/dist/Debug/GNU-Linux-x86/libgorgon.so

dist/Debug/${PLATFORM}/rabbitz: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/${PLATFORM}
	${LINK.cc} -o dist/Debug/${PLATFORM}/rabbitz ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character.o: /home/cantidio/Development/rabbitz/src/objects/src/character.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character.o /home/cantidio/Development/rabbitz/src/objects/src/character.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window_lua.o: /home/cantidio/Development/rabbitz/src/core/src/text_window_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window_lua.o /home/cantidio/Development/rabbitz/src/core/src/text_window_lua.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character_lua.o: /home/cantidio/Development/rabbitz/src/objects/src/character_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/character_lua.o /home/cantidio/Development/rabbitz/src/objects/src/character_lua.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/player.o: /home/cantidio/Development/rabbitz/src/objects/src/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/player.o /home/cantidio/Development/rabbitz/src/objects/src/player.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background_lua.o: /home/cantidio/Development/rabbitz/src/background/src/background_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background_lua.o /home/cantidio/Development/rabbitz/src/background/src/background_lua.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/tile.o: /home/cantidio/Development/rabbitz/src/background/src/tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/tile.o /home/cantidio/Development/rabbitz/src/background/src/tile.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/layer.o: /home/cantidio/Development/rabbitz/src/background/src/layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/layer.o /home/cantidio/Development/rabbitz/src/background/src/layer.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background.o: /home/cantidio/Development/rabbitz/src/background/src/background.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/background/src/background.o /home/cantidio/Development/rabbitz/src/background/src/background.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/input/src/input.o: /home/cantidio/Development/rabbitz/src/input/src/input.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/input/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/input/src/input.o /home/cantidio/Development/rabbitz/src/input/src/input.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o: /home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o /home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o: /home/cantidio/Development/rabbitz/src/objects/src/object.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o /home/cantidio/Development/rabbitz/src/objects/src/object.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object_lua.o: /home/cantidio/Development/rabbitz/src/objects/src/object_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object_lua.o /home/cantidio/Development/rabbitz/src/objects/src/object_lua.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window.o: /home/cantidio/Development/rabbitz/src/core/src/text_window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/core/src/text_window.o /home/cantidio/Development/rabbitz/src/core/src/text_window.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/Rabbitz/../src/input/src/input_lua.o: ../src/input/src/input_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/Rabbitz/../src/input/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/Rabbitz/../src/input/src/input_lua.o ../src/input/src/input_lua.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o: /home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o /home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/background.o: /home/cantidio/Development/rabbitz/tests/background.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/home/cantidio/Development -I../src -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/background.o /home/cantidio/Development/rabbitz/tests/background.cpp

# Subprojects
.build-subprojects:
	cd /home/cantidio/Development/gorgon++/Gorgon++ && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/${PLATFORM}/rabbitz

# Subprojects
.clean-subprojects:
	cd /home/cantidio/Development/gorgon++/Gorgon++ && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
