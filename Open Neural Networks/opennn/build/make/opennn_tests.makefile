##################################################################################################################
#                                                                                                                # 
#   OpenNN: Open Neural Networks Library                                                                         #
#                                                                                                                #
#   O P E N N N   T E S T S   M A K E F I L E                                                                    #
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

SOURCE_DIR = $(OPENNN_DIR)/tests

SOURCE_DIRS = \
. \
opennn_tests \
utilities_tests \
data_set_tests\
mathematical_model_tests \
neural_network_tests \
training_strategy_tests \
performance_functional_tests\
model_selection_tests \
testing_analysis_tests \

INCLUDE_DIRS = ${SOURCE_DIRS:%=-I$(SOURCE_DIR)/%}

DESTINATION_DIR = debug

OBJECTS_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

OPENNN_BUILD_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

TINYXML_BUILD_DIR = $(OPENNN_DIR)/build/make/$(DESTINATION_DIR)

LIB_OPENNN = $(OPENNN_BUILD_DIR)/libopennn.a

LIB_TINYXML = $(TINYXML_BUILD_DIR)/libtinyxml.a

LIBS = $(LIB_OPENNN) $(LIB_TINYXML)

SOURCE_FILES =  \
data_set_tests/data_set_test.cpp \
unit_testing.cpp \
data_set_tests/instances_information_test.cpp \
data_set_tests/variables_information_test.cpp \
mathematical_model_tests/mathematical_model_test.cpp \
mathematical_model_tests/ordinary_differential_equations_test.cpp \
mathematical_model_tests/plug_in_test.cpp \
model_selection_tests/model_selection_test.cpp \
neural_network_tests/bounding_layer_test.cpp \
neural_network_tests/conditions_layer_test.cpp \
neural_network_tests/independent_parameters_test.cpp \
neural_network_tests/inputs_outputs_information_test.cpp \
neural_network_tests/multilayer_perceptron_test.cpp \
neural_network_tests/neural_network_test.cpp \
neural_network_tests/perceptron_layer_test.cpp \
neural_network_tests/perceptron_test.cpp \
neural_network_tests/probabilistic_layer_test.cpp \
neural_network_tests/scaling_layer_test.cpp \
neural_network_tests/unscaling_layer_test.cpp \
performance_functional_tests/mock_performance_term.cpp \
performance_functional_tests/performance_term_test.cpp \
performance_functional_tests/cross_entropy_error_test.cpp \
performance_functional_tests/final_solutions_error_test.cpp \
performance_functional_tests/independent_parameters_error_test.cpp \
performance_functional_tests/inverse_sum_squared_error_test.cpp \
performance_functional_tests/mean_squared_error_test.cpp \
performance_functional_tests/minkowski_error_test.cpp \
performance_functional_tests/neural_parameters_norm_test.cpp \
performance_functional_tests/outputs_integrals_test.cpp \
performance_functional_tests/normalized_squared_error_test.cpp \
performance_functional_tests/performance_functional_test.cpp \
performance_functional_tests/polynomial.cpp \
performance_functional_tests/root_mean_squared_error_test.cpp \
performance_functional_tests/sum_squared_error_test.cpp \
performance_functional_tests/solutions_error_test.cpp \
testing_analysis_tests/function_regression_testing_test.cpp \
testing_analysis_tests/inverse_problem_testing_test.cpp \
testing_analysis_tests/pattern_recognition_testing_test.cpp \
testing_analysis_tests/testing_analysis_test.cpp \
testing_analysis_tests/time_series_prediction_testing_test.cpp \
training_strategy_tests/conjugate_gradient_test.cpp \
training_strategy_tests/evolutionary_algorithm_test.cpp \
training_strategy_tests/gradient_descent_test.cpp \
training_strategy_tests/levenberg_marquardt_algorithm_test.cpp \
training_strategy_tests/mock_training_algorithm.cpp \
training_strategy_tests/newton_method_test.cpp \
training_strategy_tests/quasi_newton_method_test.cpp \
training_strategy_tests/random_search_test.cpp \
training_strategy_tests/training_algorithm_test.cpp \
training_strategy_tests/training_rate_algorithm_test.cpp \
training_strategy_tests/training_strategy_test.cpp \
utilities_tests/linear_algebraic_equations_test.cpp \
utilities_tests/matrix_test.cpp \
utilities_tests/numerical_differentiation_test.cpp \
utilities_tests/numerical_integration_test.cpp \
utilities_tests/vector_test.cpp \
suite_tests_application.cpp

INCLUDE_FILES = \
utilities_tests/vector_test.h \
utilities_tests/matrix_test.h \
utilities_tests/numerical_differentiation_test.h \
utilities_tests/numerical_integration_test.h \
utilities_tests/linear_algebraic_equations_test.h \
unit_testing.h \
data_set_tests/data_set_test.h \
data_set_tests/variables_information_test.h	\
data_set_tests/instances_information_test.h \
mathematical_model_tests/mathematical_model_test.h \
mathematical_model_tests/ordinary_differential_equations_test.h \
mathematical_model_tests/plug_in_test.h \
neural_network_tests/neural_network_test.h \
neural_network_tests/perceptron_test.h \
neural_network_tests/perceptron_layer_test.h \
neural_network_tests/multilayer_perceptron_test.h \
neural_network_tests/scaling_layer_test.h \
neural_network_tests/unscaling_layer_test.h \
neural_network_tests/bounding_layer_test.h \
neural_network_tests/probabilistic_layer_test.h \
neural_network_tests/conditions_layer_test.h \
neural_network_tests/independent_parameters_test.h \
neural_network_tests/inputs_outputs_information_test.h \
performance_functional_tests/mock_performance_term.h \
performance_functional_tests/performance_term_test.h \
performance_functional_tests/cross_entropy_error_test.h \
performance_functional_tests/final_solutions_error_test.h \
performance_functional_tests/independent_parameters_error_test.h \
performance_functional_tests/inverse_sum_squared_error_test.h \
performance_functional_tests/mean_squared_error_test.h \
performance_functional_tests/minkowski_error_test.h \
performance_functional_tests/neural_parameters_norm_test.h \
performance_functional_tests/normalized_squared_error_test.h \
performance_functional_tests/performance_functional_test.h \
performance_functional_tests/outputs_integrals_test.h \
performance_functional_tests/polynomial.h \
performance_functional_tests/root_mean_squared_error_test.h \
performance_functional_tests/sum_squared_error_test.h \
performance_functional_tests/solutions_error_test.h \
model_selection_tests/model_selection_test.h \
testing_analysis_tests/function_regression_testing_test.h \
testing_analysis_tests/inverse_problem_testing_test.h \
testing_analysis_tests/pattern_recognition_testing_test.h \
testing_analysis_tests/testing_analysis_test.h \
testing_analysis_tests/time_series_prediction_testing_test.h \
training_strategy_tests/conjugate_gradient_test.h \
training_strategy_tests/evolutionary_algorithm_test.h \
training_strategy_tests/gradient_descent_test.h \
training_strategy_tests/levenberg_marquardt_algorithm_test.h \
training_strategy_tests/mock_training_algorithm.h \
training_strategy_tests/newton_method_test.h \
training_strategy_tests/quasi_newton_method_test.h \
training_strategy_tests/random_search_test.h \
training_strategy_tests/training_algorithm_test.h \
training_strategy_tests/training_rate_algorithm_test.h \
training_strategy_tests/training_strategy_test.h 

SOURCES_WITHOUT_DIRECTORIES = $(notdir $(SOURCE_FILES))

VPATH = ${SOURCE_DIRS:%=$(SOURCE_DIR)/%}

OBJS_EXE = ${SOURCES_WITHOUT_DIRECTORIES:%.cpp=$(OBJECTS_DIR)/%.o}

EXE_NAME = $(OBJECTS_DIR)/opennn_tests.exe

.SUFFIXES : .o .cpp

.cpp.o : $(INCLUDE_FILES)
	$(CXX) -c $(FLAGS) -I. $(INCLUDE_DIRS) $< -o $@

$(OBJECTS_DIR)/%.o : %.cpp
	$(CXX) -c $(FLAGS) -I. $(INCLUDE_DIRS) $< -o $@

all:
	$(MAKE) -f opennn_tests.makefile deb

deb:
	+( make -f tinyxml.makefile)
	+( make -f opennn.makefile)
	$(MAKE) -f opennn_tests.makefile exe

rel:
	+(make -f opennn.makefile rel)
	+(make -f tinyxml.makefile rel)
	$(MAKE) -f opennn_tests.makefile exe "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

exe: $(EXE_NAME)
	echo $(EXE_NAME) build.

clean:
	+(make -f opennn.makefile clean)
	+(make -f tinyxml.makefile clean)
	rm -f $(EXE_NAME) $(OBJS_EXE)
	$(MAKE) -f opennn_tests.makefile clean_rel "FLAGS=$(FLAGS_O)" "DESTINATION_DIR=release"

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

