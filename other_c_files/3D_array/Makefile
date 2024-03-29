# ######################################################
# Define design information
# - assumes the design files are .c (update to .cpp for C++ and SystemC)
# - assumes test bench is <design>_test.c

DESIGN		 := dwt
SOURCES		 := $(DESIGN).c $(DESIGN)_test.c
OBJECTS		 := $(SOURCES:.c=.o)
INCLUDES		 := image_aux.h image_read.h print3D.h comp_str.h directories_dim.h directories_in.h directories_out.h directories_out_gold_r.h
CLEAN_FILES  := $(OBJECTS) $(DESIGN) $(DESIGN).exe
CLEAN_FILES  += out_images
VIVADO_HLS_CLEANUP := $(DESIGN)_prj $(DESIGN).log vivado_hls.log 
# Change to true if using ap[u]int in ISO-C project
USE_ARBITRARY_PRECISION = false
# Change to true if using SystemC types or SC_MODULE, etc.
USE_SYSTEMC 				= false

# ######################################################
# Automatically setup the software paths
SHELL           := sh
KERNEL          := $(shell if [[ $$(uname -s) == Linux ]];then echo Linux; else echo Win; fi)
ARCH            := $(shell if [[ $$(uname -m) =~ 64$$ ]];then echo x86_64; else echo x86; fi)
OS              := $(KERNEL)_$(ARCH)
ifeq ($(KERNEL), Win)
VIVADO_HLS_EXE_FILENAME := vivado_hls.bat
APCC= $(VIVADO_HLS_ROOT)/$(OS)/bin/apcc_bin.exe
else
VIVADO_HLS_EXE_FILENAME := vivado_hls
APCC:= apcc
endif
VIVADO_HLS_EXE   := $(shell which $(VIVADO_HLS_EXE_FILENAME))
VIVADO_HLS_ROOT  := $(VIVADO_HLS_EXE:/bin/$(VIVADO_HLS_EXE_FILENAME)=)
VIVADO_HLS_INC_PATH := $(VIVADO_HLS_ROOT)/include
SYSTEMC_INC_PATH := $(VIVADO_HLS_ROOT)/$(OS)/tools/systemc/include
SYSTEMC_LIB_PATH := $(VIVADO_HLS_ROOT)/$(OS)/tools/systemc/lib

# ######################################################
# Setup C compiler and options
#
# Use APCC for ISO-C projects that use ap[u]int types; gcc otherwise
ifeq ($(USE_ARBITRARY_PRECISION),true)
CC				:= $(APCC)
CFLAGS		+= -DBIT_ACCURATE
else
CC				:= gcc
endif
CXX			:= g++
# C compiler flags
CFLAGS		+= -ggdb
CFLAGS		+= -w
CFLAGS		+= -I$(VIVADO_HLS_INC_PATH)
# C++ compiler flags
CXXFLAGS		+= -ggdb
CXXFLAGS		+= -I$(VIVADO_HLS_INC_PATH)
# Linker flags
LDFLAGS		+= -lm 
# # SystemC additional flags
ifeq ($(USE_SYSTEMC), true)
CXXFLAGS		+= -I$(SYSTEMC_INC_PATH)
LDFLAGS		+= -L$(SYSTEMC_LIB_PATH)
LDLIBS		+= -lsystemc
endif

# ######################################################
# Rules

all: sim

clean:
	rm -rf $(CLEAN_FILES) $(VIVADO_HLS_CLEANUP)

VIVADO_HLS: $(DESIGN).tcl
	VIVADO_HLS $<

sim: $(DESIGN)
	./$(DESIGN)
    
$(OBJECTS): $(SOURCES) $(INCLUDES)

$(DESIGN): $(OBJECTS)
# Uses implicit recipes, i.e.:
# $([CC|CXX]) $(CPPFLAGS) $([CFLAGS|CXXFLAGS]) -c # For each SOURCE
# $(CC) $(LDFLAGS) $(OBJECTS) $(LOADLIBES) $(LDLIBS) # To link OBJECTS

# TODO: add rule to rebuild OBJECT when its .h file changes

