##################################################################################################################
#                                                                                                                # 
#   OpenNN: Open Neural Networks Library                                                                         #
#                                                                                                                #
#   O P E N N N   M A K E F I L E                                                                                #
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

# definitions

BASE_DIR = ../../../opennn

SOURCE_DIR = $(BASE_DIR)/source

SOURCE_DIRS = \
utilities \
data_set \
mathematical_model \
neural_network \
performance_functional \
training_strategy \
model_selection \
testing_analysis 

INCLUDE_DIRS = -I. ${SOURCE_DIRS:%=-I$(SOURCE_DIR)/%}

DESTINATION_DIR = debug

OBJECTS_DIR = $(BASE_DIR)/build/make/$(DESTINATION_DIR)

# Directory to locate the sources (dont't change name)

VPATH = ${SOURCE_DIRS:%=$(SOURCE_DIR)/%}

SOURCE_FILES = \
utilities/linear_algebraic_equations.cpp \
utilities/numerical_differentiation.cpp	\
utilities/numerical_integration.cpp \
data_set/data_set.cpp \
data_set/variables_information.cpp \
data_set/instances_information.cpp \
mathematical_model/mathematical_model.cpp \
mathematical_model/ordinary_differential_equations.cpp \
mathematical_model/plug_in.cpp \
neural_network/neural_network.cpp \
neural_network/perceptron.cpp \
neural_network/perceptron_layer.cpp \
neural_network/multilayer_perceptron.cpp \
neural_network/scaling_layer.cpp \
neural_network/unscaling_layer.cpp \
neural_network/bounding_layer.cpp \
neural_network/conditions_layer.cpp \
neural_network/probabilistic_layer.cpp \
neural_network/inputs_outputs_information.cpp \
neural_network/independent_parameters.cpp \
performance_functional/performance_functional.cpp \
performance_functional/performance_term.cpp \
performance_functional/sum_squared_error.cpp \
performance_functional/root_mean_squared_error.cpp \
performance_functional/mean_squared_error.cpp \
performance_functional/normalized_squared_error.cpp \
performance_functional/minkowski_error.cpp \
performance_functional/cross_entropy_error.cpp \
performance_functional/neural_parameters_norm.cpp \
performance_functional/outputs_integrals.cpp \
performance_functional/final_solutions_error.cpp \
performance_functional/solutions_error.cpp \
performance_functional/independent_parameters_error.cpp \
performance_functional/inverse_sum_squared_error.cpp \
training_strategy/training_strategy.cpp \
training_strategy/training_algorithm.cpp \
training_strategy/training_rate_algorithm.cpp \
training_strategy/random_search.cpp \
training_strategy/evolutionary_algorithm.cpp \
training_strategy/gradient_descent.cpp \
training_strategy/conjugate_gradient.cpp \
training_strategy/quasi_newton_method.cpp \
training_strategy/levenberg_marquardt_algorithm.cpp \
training_strategy/newton_method.cpp \
model_selection/model_selection.cpp \
testing_analysis/testing_analysis.cpp \
testing_analysis/function_regression_testing.cpp \
testing_analysis/pattern_recognition_testing.cpp \
testing_analysis/time_series_prediction_testing.cpp \
testing_analysis/inverse_problem_testing.cpp \

SOURCES_WITHOUT_DIRECTORIES = $(notdir $(SOURCE_FILES))

INCLUDE_FILES = \
opennn.h \
utilities/vector.h \
utilities/matrix.h \
utilities/numerical_differentiation.h \
utilities/numerical_integration.h \
utilities/ordinary_differential_equations.h \
utilities/linear_algebraic_equations.h \
data_set/data_set.h \
data_set/variables_information.h \
data_set/instances_information.h \
mathematical_model/mathematical_model.h	\
mathematical_model/ordinary_differential_equations_model.h \
mathematical_model/plug_in.h \
neural_network/bounding_layer.h \
neural_network/conditions_layer.h \
neural_network/independent_parameters.h \
neural_network/inputs_outputs_information.h \
neural_network/multilayer_perceptron.h \
neural_network/neural_network.h \
neural_network/perceptron.h \
neural_network/perceptron_layer.h \
neural_network/probabilistic_layer.h \
neural_network/scaling_layer.h \
neural_network/unscaling_layer.h \
performance_functional/neural_network_outputs_integrals.h \
performance_functional/constraints_functional.h \
performance_functional/cross_entropy_error.h \
performance_functional/final_state_error.h \
performance_functional/independent_parameters_error.h \
performance_functional/inverse_sum_squared_error.h \
performance_functional/mean_squared_error.h \
performance_functional/minkowski_error.h \
performance_functional/multilayer_perceptron_parameters_norm.h \
performance_functional/normalized_squared_error.h \
performance_functional/objective_functional.h \
performance_functional/performance_functional.h \
performance_functional/regularization_functional.h \
performance_functional/root_mean_squared_error.h \
performance_functional/sum_squared_error.h \
performance_functional/trajectory_error.h \
testing_analysis/function_regression_testing.h \
testing_analysis/inverse_problem_testing.h \
testing_analysis/pattern_recognition_testing.h \
testing_analysis/testing_analysis.h \
testing_analysis/time_series_prediction_testing.h \
training_strategy/training_strategy.h \
training_strategy/training_algorithm.h \
training_strategy/training_rate_algorithm.h \
training_strategy/conjugate_gradient.h \
training_strategy/evolutionary_algorithm.h \
training_strategy/gradient_descent.h \
training_strategy/levenberg_marquardt_algorithm.h \
training_strategy/newton_method.h \
training_strategy/quasi_newton_method.h \
training_strategy/random_search.h \
model_selection/model_selection.h \

LIB_OBJECTS = ${SOURCES_WITHOUT_DIRECTORIES:%.cpp=$(OBJECTS_DIR)/%.o}

LIB_NAME = $(DESTINATION_DIR)/libopennn.a

# RULES

all: $(LIB_NAME)
	echo $(LIB_NAME) build.

rel:
	$(MAKE) -f opennn.makefile all "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

clean:
	rm -f $(LIB_NAME) $(LIB_OBJECTS)
	$(MAKE) -f opennn.makefile clean_rel "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

clean_rel:
	rm -f $(LIB_NAME) $(LIB_OBJECTS)

$(OBJECTS_DIR)/%.o : %.cpp
	$(CXX) -c $(FLAGS) $(INCLUDE_DIRS) $< -o $@

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

