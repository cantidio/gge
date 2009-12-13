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
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/sprite_manager.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/tests/background.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/animation_manager.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/player.o \
	${OBJECTDIR}/_ext/_DOTDOT/tools/background_generator.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer.o \
	${OBJECTDIR}/_ext/_DOTDOT/tests/enemy_teste.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/background/src/tile.o \
	${OBJECTDIR}/_ext/_DOTDOT/tests/character.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer_lua.o \
	${OBJECTDIR}/_ext/_DOTDOT/tests/player.o \
	${OBJECTDIR}/_ext/_DOTDOT/tests/resource_manager.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/rabbitz

dist/Release/GNU-Linux-x86/rabbitz: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rabbitz ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/sprite_manager.o: nbproject/Makefile-${CND_CONF}.mk ../src/resource_manager/src/sprite_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/sprite_manager.o ../src/resource_manager/src/sprite_manager.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/objects/src/character_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character_lua.o ../src/objects/src/character_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/tests/background.o: nbproject/Makefile-${CND_CONF}.mk ../tests/background.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tests/background.o ../tests/background.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/animation_manager.o: nbproject/Makefile-${CND_CONF}.mk ../src/resource_manager/src/animation_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/resource_manager/src/animation_manager.o ../src/resource_manager/src/animation_manager.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background.o: nbproject/Makefile-${CND_CONF}.mk ../src/background/src/background.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background.o ../src/background/src/background.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/src/text_window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window.o ../src/core/src/text_window.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character.o: nbproject/Makefile-${CND_CONF}.mk ../src/objects/src/character.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/character.o ../src/objects/src/character.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input.o: nbproject/Makefile-${CND_CONF}.mk ../src/input/src/input.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/input/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input.o ../src/input/src/input.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/player.o: nbproject/Makefile-${CND_CONF}.mk ../src/objects/src/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/player.o ../src/objects/src/player.cpp

${OBJECTDIR}/_ext/_DOTDOT/tools/background_generator.o: nbproject/Makefile-${CND_CONF}.mk ../tools/background_generator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tools
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tools/background_generator.o ../tools/background_generator.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer.o: nbproject/Makefile-${CND_CONF}.mk ../src/background/src/layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer.o ../src/background/src/layer.cpp

${OBJECTDIR}/_ext/_DOTDOT/tests/enemy_teste.o: nbproject/Makefile-${CND_CONF}.mk ../tests/enemy_teste.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tests/enemy_teste.o ../tests/enemy_teste.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/input/src/input_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/input/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/input/src/input_lua.o ../src/input/src/input_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object.o: nbproject/Makefile-${CND_CONF}.mk ../src/objects/src/object.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object.o ../src/objects/src/object.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/background/src/tile.o: nbproject/Makefile-${CND_CONF}.mk ../src/background/src/tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/background/src/tile.o ../src/background/src/tile.cpp

${OBJECTDIR}/_ext/_DOTDOT/tests/character.o: nbproject/Makefile-${CND_CONF}.mk ../tests/character.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tests/character.o ../tests/character.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/background/src/background_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/background/src/background_lua.o ../src/background/src/background_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/core/src/text_window_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/core/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/core/src/text_window_lua.o ../src/core/src/text_window_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/objects/src/object_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/objects/src/object_lua.o ../src/objects/src/object_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer_lua.o: nbproject/Makefile-${CND_CONF}.mk ../src/background/src/layer_lua.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/src/background/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/src/background/src/layer_lua.o ../src/background/src/layer_lua.cpp

${OBJECTDIR}/_ext/_DOTDOT/tests/player.o: nbproject/Makefile-${CND_CONF}.mk ../tests/player.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tests/player.o ../tests/player.cpp

${OBJECTDIR}/_ext/_DOTDOT/tests/resource_manager.o: nbproject/Makefile-${CND_CONF}.mk ../tests/resource_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/_DOTDOT/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/_DOTDOT/tests/resource_manager.o ../tests/resource_manager.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/rabbitz

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
