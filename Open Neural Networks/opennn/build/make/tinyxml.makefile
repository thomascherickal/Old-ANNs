##################################################################################################################
#                                                                                                                # 
#   OpenNN: Open Neural Networks Library                                                                         #
#                                                                                                                #
#   T I N Y X M L   M A K E F I L E                                                                              #
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

BASE_DIR = ../../../opennn

SOURCES_DIR = $(BASE_DIR)/parsers/tinyxml

INCLUDES_DIR = -I. -I$(SOURCES_DIR)

DESTINATION_DIR = debug

OBJECTS_DIR = $(BASE_DIR)/build/make/$(DESTINATION_DIR)

# Directory to locate the sources (dont't change name)

VPATH = $(SOURCES_DIR)

SOURCE_FILES = \
tinystr.cpp \
tinyxml.cpp \
tinyxmlerror.cpp \
tinyxmlparser.cpp

INCLUDE_FILES = \
tinystr.h \
tinyxml.h

# Change extension cpp to o and add destination of objects 

LIB_OBJECTS = ${SOURCE_FILES:%.cpp=$(OBJECTS_DIR)/%.o}

LIB_NAME = $(DESTINATION_DIR)/libtinyxml.a

# RULES (targets: dependencies). If not hold, commands to update the target.

all: $(LIB_NAME)
	echo $(LIB_NAME) build.

rel:
	$(MAKE) -f tinyxml.makefile all "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

clean:
	rm -f $(LIB_NAME) $(LIB_OBJECTS)
	$(MAKE) -f tinyxml.makefile clean_rel "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

clean_rel:
	rm -f $(LIB_NAME) $(LIB_OBJECTS)

$(OBJECTS_DIR)/%.o : %.cpp
	$(CXX) -c $(FLAGS) $(INCLUDES_DIR) $< -o $@

$(LIB_NAME): $(LIB_OBJECTS)
	rm -f $@
	ar rcv $@ $(LIB_OBJECTS)
	ranlib $@

# OpenNN: Open Neural Networks Library.
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

