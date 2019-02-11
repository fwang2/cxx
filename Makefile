# -----------------------------------------------------------------------------
# CMake project wrapper Makefile
#
# prefix @ to suppress the output from shell command
# prefix @- to ignore errors from shell command
#
# Calling this Makefile wrapper with 'make all' or 'make' is equivalent to:
#
# 		mkdir build
# 		cd build
# 		cmake ..
# 		make
#
# -----------------------------------------------------------------------------

SHELL := /bin/bash
RM    := rm -rf
MKDIR := mkdir -p

all: ./build/Makefile
#
# -H specify source
# -B specify binary
	@- $(RM) ./CMakeCache.txt
	@- $(RM) -r ./CMakeFiles
	cmake -H. -Bbuild
	@ $(MAKE) -C build

./build/Makefile:
	@  ($(MKDIR) build > /dev/null)
	@  (cd build > /dev/null 2>&1 && cmake ..)

distclean:
	@  ($(MKDIR) build > /dev/null)
	@  (cd build > /dev/null 2>&1 && cmake .. > /dev/null 2>&1)
	@- $(MAKE) --silent -C build clean || true
	@- $(RM) ./build/Makefile
	@- $(RM) ./build/src
	@- $(RM) ./build/test
	@- $(RM) ./build/CMake*
	@- $(RM) ./build/cmake.*
	@- $(RM) ./build/*.cmake
	@- $(RM) ./build/*.txt

ifeq ($(findstring distclean,$(MAKECMDGOALS)),)
	$(MAKECMDGOALS): ./build/Makefile
	@ $(MAKE) -C build $(MAKECMDGOALS)
endif
