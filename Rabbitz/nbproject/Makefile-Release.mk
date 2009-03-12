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
OBJECTDIR=build/Release/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/resource_manager.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/enemy_teste.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o \
	${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/${PLATFORM}/rabbitz

dist/Release/${PLATFORM}/rabbitz: ${OBJECTFILES}
	${MKDIR} -p dist/Release/${PLATFORM}
	${LINK.cc} -o dist/Release/${PLATFORM}/rabbitz ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/resource_manager.o: /home/cantidio/Development/rabbitz/tests/resource_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/resource_manager.o /home/cantidio/Development/rabbitz/tests/resource_manager.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/enemy_teste.o: /home/cantidio/Development/rabbitz/tests/enemy_teste.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/tests/enemy_teste.o /home/cantidio/Development/rabbitz/tests/enemy_teste.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o: /home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.o /home/cantidio/Development/rabbitz/src/resource_manager/src/animation_manager.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o: /home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.o /home/cantidio/Development/rabbitz/src/resource_manager/src/sprite_manager.cpp

${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o: /home/cantidio/Development/rabbitz/src/objects/src/object.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/home/cantidio/Development/rabbitz/src/objects/src/object.o /home/cantidio/Development/rabbitz/src/objects/src/object.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/${PLATFORM}/rabbitz

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
