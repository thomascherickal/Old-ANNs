##################################################################################################################
#                                                                                                                # 
#   OpenNN: Open Neural Networks Library                                                                         #
#                                                                                                                #
#   D E   J O N G   F U N C T I O N   M A K E F I L E                                                            #
#                                                                                                                #
#   Roberto Lopez and Miguel Pasenau                                                                             #
#   International Center for Numerical Methods in Engineering (CIMNE)                                            #
#   Technical University of Catalonia (UPC)                                                                      #
#   Barcelona, Spain                                                                                             #
#   E-mail: rlopez@cimne.upc.edu                                                                                 #
#                                                                                                                #
##################################################################################################################

# VARIABLES 

# Compiler to use

CXX = g++

# Flags to the compiler

WARNINGS = \
-pedantic \
-Wextra \
-Wall \
-Wreturn-type \
-Wswitch \
-Wformat \
-Wcast-align \
-Wcomment \
-Wchar-subscripts \
-Wmissing-braces \
-Wno-long-long \
-Wno-unused-result \
-fstack-protector \
-fstack-protector-all \
-Wno-unknown-pragmas

FLAGS = -g $(WARNINGS)

# Optimization flags

FLAGS_O = -O3 $(WARNINGS)

# TARGETS

OPENNN_DIR = ../../../opennn

SOURCE_DIR = $(OPENNN_DIR)/examples

SOURCE_DIRS = \
de_jong_function \

INCLUDE_DIRS = ${SOURCE_DIRS:%=-I$(SOURCE_DIR)/%}

DESTINATION_DIR = debug

OBJECTS_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

OPENNN_BUILD_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

TINYXML_BUILD_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

LIB_OPENNN = $(OPENNN_BUILD_DIR)/libopennn.a

LIB_TINYXML = $(TINYXML_BUILD_DIR)/libtinyxml.a

LIBS = $(LIB_OPENNN) $(LIB_TINYXML)

SOURCE_FILES =  \
de_jong_function.cpp \
de_jong_function_application.cpp

INCLUDE_FILES = \
de_jong_function.h \

SOURCES_WITHOUT_DIRECTORIES = $(notdir $(SOURCE_FILES))

VPATH = ${SOURCE_DIRS:%=$(SOURCE_DIR)/%}

OBJS_EXE = ${SOURCES_WITHOUT_DIRECTORIES:%.cpp=$(OBJECTS_DIR)/%.o}
EXE_NAME = $(OBJECTS_DIR)/de_jong_function.exe

.SUFFIXES : .o .cpp

.cpp.o : $(INCLUDE_FILES)
	$(CXX) -c $(FLAGS) -I. $(INCLUDE_DIRS) $< -o $@

$(OBJECTS_DIR)/%.o : %.cpp
	$(CXX) -c $(FLAGS) -I. $(INCLUDE_DIRS) $< -o $@

all:
	$(MAKE) -f de_jong_function.makefile deb

deb:
	+( make -f tinyxml.makefile)
	+( make -f opennn.makefile)
	$(MAKE) -f de_jong_function.makefile exe

rel:
	+(make -f opennn.makefile rel)
	+(make -f tinyxml.makefile rel)
	$(MAKE) -f de_jong_function.makefile exe "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

exe: $(EXE_NAME)
	echo $(EXE_NAME) build.

clean:
	+(make -f opennn.makefile clean)
	+(make -f tinyxml.makefile clean)
	rm -f $(EXE_NAME) $(OBJS_EXE)
	$(MAKE) -f de_jong_function.makefile clean_rel "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

clean_rel:
	rm -f $(EXE_NAME) $(OBJS_EXE)

$(EXE_NAME): $(OBJS_EXE) $(LIB_OPENNN) $(LIB_TINYXML)
	rm -f $@
	$(CXX) -o $@ $(FLAGS) $(OBJS_EXE) $(LIBS)

$(LIB_OPENNN):
	+(make -f opennn.makefile)
	+(make -f opennn.makefile rel)

$(LIB_TINYXML):
	+(make -f tinyxml.makefile)
	+(make -f tinyxml.makefile rel)


# OpenNN: Open Neural Networks Library
# Copyright (C) 2005-2012 Roberto Lopez 
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

