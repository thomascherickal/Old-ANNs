/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                       */
/*                                                                                                              */
/*   V E C T O R   T E S T   C L A S S                                                                          */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.edu                                                                               */ 
/*                                                                                                              */
/****************************************************************************************************************/

// System includes

#include <iostream>

// OpenNN includes 

#include "../../source/utilities/vector.h"

// Unit testing includes

#include "vector_test.h"

// TinyXml includes

#include "../../parsers/tinyxml/tinyxml.h"

using namespace OpenNN;


// GENERAL CONSTRUCTOR

VectorTest::VectorTest(void) : UnitTesting() 
{   
}


// DESTRUCTOR

VectorTest::~VectorTest(void)
{
}


// METHODS

// void test_constructor(void)

void VectorTest::test_constructor(void)
{
   message += "test_constructor\n";

   // Default 

   Vector<bool> v1;

   assert_true(v1.size() == 0, LOG);

   // Size

   Vector<bool> v2(1);

   assert_true(v2.size() == 1, LOG);

   // Size initialization

   Vector<bool> v3(1, false);

   assert_true(v3.size() == 1, LOG);
   assert_true(v3[0] == false, LOG);

   // File

   Vector<int> v4(3, 0);
   v4.save("../data/opennn_tests/vector.dat");

   Vector<int> w4("../data/opennn_tests/vector.dat");
   
   assert_true(w4.size() == 3, LOG);
   assert_true(w4 == 0, LOG);

   // Sequential

   Vector<int> v6(10, 5, 50);

   assert_true(v6.size() == 9, LOG);
   assert_true(v6[0] == 10, LOG);
   assert_true(v6[8] == 50, LOG);

//   Vector<double> v7(3.0, 0.2, 3.8);

//   assert_true(v7.size() == 5, LOG);
//   assert_true(v7[0] == 3.0, LOG);
//   assert_true(v7[4] == 3.8, LOG);

   Vector<int> v8(9, -1, 1);

   assert_true(v8.size() == 9, LOG);
   assert_true(v8[0] == 9, LOG);
   assert_true(v8[8] == 1, LOG);

   // Copy

   Vector<std::string> v5(1, "hello");

   Vector<std::string> w5(v5);

   assert_true(w5.size() == 1, LOG);
   assert_true(w5[0] == "hello", LOG);
}


// void test_destructor(void)

void VectorTest::test_destructor(void)
{
}


// void test_sum_operator(void) method

void VectorTest::test_sum_operator(void)
{
   message += "test_sum_operator\n";

   Vector<int> a, b, c, d;

   // Scalar

   a.set(1, 1);
   b =  a + 1;

   c.set(1, 2);
   
   assert_true(b == c, LOG);

   // Sum

   a.set(1, 1);
   b.set(1, 1);

   c = a + b;

   d.set(1, 2);

   assert_true(c == d, LOG);
}


// void test_rest_operator(void) method

void VectorTest::test_rest_operator(void)
{
   message += "test_rest_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a - 1.0;

   c.set(1, 0.0);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 1.0);
   b.set(1, 1.0);

   c = a - b;

   d.set(1, 0.0);

   assert_true(c == d, LOG);
}


// void test_multiplication_operator(void) method

void VectorTest::test_multiplication_operator(void)
{
   message += "test_multiplication_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a*2.0;

   c.set(1, 2.0);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 1.0);
   b.set(1, 1.0);

   c = a*b;

   d.set(1, 1.0);

   assert_true(c == d, LOG);

   // Matrix 

   Matrix<double> m(1, 1, 0.0);

   a.set(1, 0.0);

   Matrix<double> p = a*m;

   assert_true(p.get_rows_number() == 1, LOG);
   assert_true(p.get_columns_number() == 1, LOG);
   assert_true(p == 0.0, LOG);

   m.set(3, 2, 1.0);
   a.set(3, 1.0);

   p = a*m;

   assert_true(p.get_rows_number() == 3, LOG);
   assert_true(p.get_columns_number() == 2, LOG);
   assert_true(p == 1.0, LOG);
}


// void test_division_operator(void) method

void VectorTest::test_division_operator(void)
{
   message += "test_division_operator\n";

   Vector<double> a, b, c, d;

   // Scalar

   a.set(1, 1.0);
   b =  a/2.0;

   c.set(1, 0.5);
   
   assert_true(b == c, LOG);

   // Vector

   a.set(1, 2.0);
   b.set(1, 2.0);

   c = a/b;

   d.set(1, 1.0);

   assert_true(c == d, LOG);
}


// void test_sum_assignment_operator(void) method

void VectorTest::test_sum_assignment_operator(void)
{
   message += "test_sum_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 1);

   a += 1;

   assert_true(a == 2, LOG);

   // Vector

   a.set(2, 1);
   b.set(2, 1);

   a += b;

   assert_true(a == 2, LOG);
}


// void test_rest_assignment_operator(void) method

void VectorTest::test_rest_assignment_operator(void)
{
   message += "test_rest_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 1);

   a -= 1;

   assert_true(a == 0, LOG);

   // Vector

   a.set(2, 1);
   b.set(2, 1);

   a -= b;

   assert_true(a == 0, LOG);
}


// void test_multiplication_assignment_operator(void) method

void VectorTest::test_multiplication_assignment_operator(void)
{
   message += "test_multiplication_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 2);

   a *= 1;

   assert_true(a == 2, LOG);

   // Vector

   a.set(2, 2);
   b.set(2, 1);

   a *= b;

   assert_true(a == 2, LOG);
}


// void test_division_assignment_operator(void) method

void VectorTest::test_division_assignment_operator(void)
{
   message += "test_division_assignment_operator\n";

   Vector<int> a, b;

   // Scalar

   a.set(2, 2);

   a /= 2;

   assert_true(a == 1, LOG);

   // Vector

   a.set(2, 2);
   b.set(2, 2);

   a /= b;

   assert_true(a == 1, LOG);
}


// void test_equal_to_operator(void) method

void VectorTest::test_equal_to_operator(void)
{
   message += "test_equal_to_operator\n";

   Vector<int> a(2);
   a[0] = 0;
   a[1] = 1;

   Vector<int> b(2);
   b[0] = 0;
   b[1] = 1;

   Vector<int> c(2, -1);

   assert_true(a == b, LOG);
   assert_true(c == -1, LOG);
}


// void test_not_equal_to_operator(void) method

void VectorTest::test_not_equal_to_operator(void)
{
   message += "test_not_equal_to_operator\n";

   Vector<double> a(2, -1.0);
   Vector<double> b(2, 1.0);

   assert_true(a != b, LOG);
   assert_true(a != 0.0, LOG);
   assert_true(b != 0.0, LOG);
}


// void test_greater_than_operator(void) method

void VectorTest::test_greater_than_operator(void)
{
   message += "test_greater_than_operator\n";

   Vector<int> a(2);   
   a[0] = 1;
   a[1] = 2;

   Vector<int> b(2);
   b[0] = 0;
   b[1] = 1;

   assert_true(a > b, LOG);

   assert_true(a > 0, LOG);
   assert_false(a > 1, LOG);

   assert_true(b > -1, LOG);
   assert_false(b > 0, LOG);
}


// void test_less_than_operator(void) method

void VectorTest::test_less_than_operator(void)
{
   message += "test_less_than_operator\n";

   Vector<double> a(2);   
   a[0] = 0.0;
   a[1] = 1.0;

   Vector<double> b(2);
   b[0] = 1.0;
   b[1] = 2.0;

   assert_true(a < b, LOG);

   assert_true(a < 2.0, LOG);
   assert_false(a < 1.0, LOG);

   assert_true(b < 3.0, LOG);
   assert_false(b < 1.0, LOG);
}


// void test_greater_than_or_equal_to_operator(void) method

void VectorTest::test_greater_than_or_equal_to_operator(void)
{
   message += "test_greater_than_or_equal_to_operator\n";

   Vector<int> a(2);   
   a[0] = 1;
   a[1] = 2;

   Vector<int> b(2);
   b[0] = 1;
   b[1] = 1;

   assert_true(a >= b, LOG);

   assert_true(a >= 1, LOG);
   assert_false(a >= 2, LOG);

   assert_true(b >= 1, LOG);
   assert_false(b >= 2, LOG);
}


// void test_less_than_or_equal_to_operator(void) method

void VectorTest::test_less_than_or_equal_to_operator(void)
{
   message += "test_less_than_or_equal_to_operator\n";

   Vector<double> a(2);   
   a[0] = 1.0;
   a[1] = 1.0;

   Vector<double> b(2);
   b[0] = 1.0;
   b[1] = 2.0;

   assert_true(a <= b, LOG);

   assert_true(a <= 1.0, LOG);
   assert_false(a <= 0.0, LOG);

   assert_true(b <= 2.0, LOG);
   assert_false(b <= 1.0, LOG);
}


// void test_output_operator(void) method

void VectorTest::test_output_operator(void)
{
   message += "test_output_operator\n";

   Vector<int> v;
   Vector< Vector<double> > w;
   Vector< Matrix<bool> > x;

   // Test

   // Test

   w.set(2);
   w[0].set(2, 0.0);
   w[1].set(2, 1.0);

   // Test

   x.set(2);
   x[0].set(2, 3, false);
   x[1].set(3, 4, true);

}


// void test_get_size(void) method

void VectorTest::test_get_size(void)
{
   message += "test_get_size\n";

   Vector<int> v; 

   assert_true(v.size() == 0, LOG);

   v.set(1);

   assert_true(v.size() == 1, LOG);

   v.set(0);

   assert_true(v.size() == 0, LOG);
}


// void test_get_display(void) method

void VectorTest::test_get_display(void)
{
   message += "test_get_display\n";
}


// void test_set(void) method

void VectorTest::test_set(void)
{
   message += "test_set\n";

   Vector<int> v(3, 0);

   // Default 

   v.set();

   assert_true(v.size() == 0, LOG);

   // Size 

   v.set(1);

   assert_true(v.size() == 1, LOG);

   // Size initialization

   v.set(1, 0);

   assert_true(v.size() == 1, LOG);
   assert_true(v == 0, LOG);

   // File 

   v.save("../data/opennn_tests/vector.dat");
   v.set("../data/opennn_tests/vector.dat");

   assert_true(v.size() == 1, LOG);
   assert_true(v == 0, LOG);

   // Sequential

   v.set(10, 5, 50);

   assert_true(v.size() == 9, LOG);
   assert_true(v[0] == 10, LOG);
   assert_true(v[8] == 50, LOG);

   v.set(9, -1, 1);

   assert_true(v.size() == 9, LOG);
   assert_true(v[0] == 9, LOG);
   assert_true(v[8] == 1, LOG);

   // Copy

   v.set(1, 0);
   v.set(v);

   assert_true(v.size() == 1, LOG);
   assert_true(v == 0, LOG);
}


// void test_set_size(void) method

void VectorTest::test_set_size(void)
{
   message += "test_set_size\n";
}


// void test_set_display(void) method

void VectorTest::test_set_display(void)
{
   message += "test_set_display\n";
}


// void test_resize(void) method

void VectorTest::test_resize(void)
{
   message += "test_resize\n";

   Vector<int> a(1, 0);

   // Decrease size

   a.resize(2);

   assert_true(a.size() == 2, LOG);

   // Increase size

   a.resize(0);

   assert_true(a.size() == 0, LOG);
}


// void test_initialize(void) method

void VectorTest::test_initialize(void)
{
   message += "test_initialize\n";

   Vector<int> v(2);

   v.initialize(0);

   Vector<int> w(2, 0);
   
   assert_true(v == w, LOG);
}


// void test_initialize_sequential(void) method

void VectorTest::test_initialize_sequential(void)
{
   message += "test_initialize_sequential\n";

   Vector<double> v(2);

   v.initialize_sequential();

   Vector<double> w(2);
   w[0] = 0.0;
   w[1] = 1.0;
   
   assert_true(v == w, LOG);
}


// void test_initialize_uniform(void) method

void VectorTest::test_initialize_uniform(void)
{
   message += "test_initialize_uniform\n";

   Vector<double> v(3);

   v.initialize_uniform();

   assert_true(v >= -1.0, LOG);
   assert_true(v <=  1.0, LOG);
  
   v.initialize_uniform(0.0, 2.0);
   
   assert_true(v >= 0.0, LOG);
   assert_true(v <= 2.0, LOG);
}


// void test_initialize_normal(void) method

void VectorTest::test_initialize_normal(void)
{
   message += "test_initialize_normal\n";

   Vector<double> v(2);

   v.initialize_normal();

   v.initialize_normal(0.0, 0.0);

   assert_true(v == 0.0, LOG);
}


// void test_calculate_sum(void) method

void VectorTest::test_calculate_sum(void)
{
   message += "test_calculate_sum\n";

   Vector<int> v;

   assert_true(v.calculate_sum() == 0, LOG);

   v.set(2);
   v.initialize(1);

   assert_true(v.calculate_sum() == 2, LOG);
}


// void test_calculate_product(void) method

void VectorTest::test_calculate_product(void)
{
   message += "test_calculate_product\n";

   Vector<double> v;

   assert_true(v.calculate_product() == 1.0, LOG);

   v.set(2);
   v[0] = 0.5;
   v[1] = 1.5;

   assert_true(v.calculate_product() == 0.75, LOG);
}


// void test_calculate_mean(void) method

void VectorTest::test_calculate_mean(void)
{
   message += "test_calculate_mean\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_mean() == 1.0, LOG);

   v.set(2);
   v[0] = -1.0;
   v[1] =  1.0;

   assert_true(v.calculate_mean() == 0.0, LOG);
}


// void test_calculate_standard_deviation(void) method

void VectorTest::test_calculate_standard_deviation(void)
{
   message += "test_calculate_standard_deviation\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_standard_deviation() == 0.0, LOG);

   v.set(2);
   v[0] = -1.0;
   v[1] =  1.0;

   assert_true(v.calculate_standard_deviation() == 1.0, LOG);
}

   
// void test_calculate_mean_standard_deviation(void) method

void VectorTest::test_calculate_mean_standard_deviation(void)
{
   message += "test_calculate_mean_standard_deviation\n";

   Vector<double> v(2);
   v[0] = -1.0;
   v[1] =  1.0;

   Vector<double> mean_standard_deviation = v.calculate_mean_standard_deviation();

   assert_true(mean_standard_deviation[0] == 0.0, LOG);
   assert_true(mean_standard_deviation[1] == 1.0, LOG);
}


// void test_calculate_minimum(void) method

void VectorTest::test_calculate_minimum(void)
{
   message += "test_calculate_minimum\n";
   
   Vector<int> v(1, 1);

   assert_true(v.calculate_minimum() == 1, LOG);

   v.set(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   assert_true(v.calculate_minimum() == -1, LOG);
}


// void test_calculate_maximum(void) method

void VectorTest::test_calculate_maximum(void)
{
   message += "test_calculate_maximum\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_maximum() == 1.0, LOG);

   v.set(3);
   v[0] = -1.0;
   v[1] =  0.0;
   v[2] =  1.0;

   assert_true(v.calculate_maximum() == 1.0, LOG);
}


// void test_calculate_minimum_maximum(void) method

void VectorTest::test_calculate_minimum_maximum(void)
{
   message += "test_calculate_minimum_maximum\n";
   
   Vector<int> v(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   Vector<int> minimum_maximum = v.calculate_minimum_maximum();

   assert_true(minimum_maximum[0] == -1, LOG);
   assert_true(minimum_maximum[1] == 1, LOG);
}


// void test_calculate_histogram(void)

void VectorTest::test_calculate_histogram(void)
{
   message += "test_calculate_histogram\n";

   Vector<double> v;

   Vector< Vector<double> > histogram;

   // Test

   v.set(0.0, 1.0, 9.0);

   histogram = v.calculate_histogram(10); 

   assert_true(histogram[0].size() == 10, LOG);
   assert_true(histogram[0] == 1.0, LOG);
                                        
   assert_true(histogram[1].size() == 10, LOG);
   assert_true(fabs(histogram[1][0] - 0.45) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][1] - 1.35) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][2] - 2.25) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][3] - 3.15) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][4] - 4.05) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][5] - 4.95) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][6] - 5.85) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][7] - 6.75) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][8] - 7.65) < 1.0e-12, LOG);
   assert_true(fabs(histogram[1][9] - 8.55) < 1.0e-12, LOG);
}


// void test_calculate_minimal_index(void) method

void VectorTest::test_calculate_minimal_index(void)
{
   message += "test_calculate_minimal_index\n";
   
   Vector<double> v(1, 1.0);

   assert_true(v.calculate_minimal_index() == 0, LOG);

   v.set(3);
   v[0] =  1.0;
   v[1] =  0.0;
   v[2] = -1.0;

   assert_true(v.calculate_minimal_index() == 2, LOG);
}


// void test_calculate_maximal_index(void) method

void VectorTest::test_calculate_maximal_index(void)
{
   message += "test_calculate_maximal_index\n";
   
   Vector<int> v(1);

   assert_true(v.calculate_maximal_index() == 0, LOG);

   v.set(3);
   v[0] = -1;
   v[1] =  0;
   v[2] =  1;

   assert_true(v.calculate_maximal_index() == 2, LOG);
}


// void test_calculate_minimal_maximal_index(void) method

void VectorTest::test_calculate_minimal_maximal_index(void)
{
   message += "test_calculate_minimal_maximal_index\n";
   
   Vector<int> v(0, 1, 1);

   Vector<unsigned int> minimal_maximal_index = v.calculate_minimal_maximal_index();

   assert_true(minimal_maximal_index[0] == 0, LOG);
   assert_true(minimal_maximal_index[1] == 1, LOG);
}


// void test_calculate_cumulative_index(void)

void VectorTest::test_calculate_cumulative_index(void)
{
   message += "test_calculate_cumulative_index\n";

   Vector<double> v;
   double value;
   unsigned int index;

   // Test

   v.set(0.0, 1.0, 1.0); 
   value = 0.0;
   index = v.calculate_cumulative_index(value);

   assert_true(index == 0, LOG);

   // Test

   v.set(0.0, 1.0, 1.0); 
   value = 0.5;
   index = v.calculate_cumulative_index(value);

   assert_true(index == 1, LOG);

   // Test

   v.set(0.0, 1.0, 1.0); 
   value = 1.0;
   index = v.calculate_cumulative_index(value);

   assert_true(index == 1, LOG);
}


// void test_calculate_closest_index(void)

void VectorTest::test_calculate_closest_index(void)
{
   message += "test_calculate_closest_index\n";
}


// void test_calculate_sum_squared_error(void) method

void VectorTest::test_calculate_sum_squared_error(void)
{
   message += "test_calculate_sum_squared_error\n";
}


// void test_calculate_mean_squared_error(void) method

void VectorTest::test_calculate_mean_squared_error(void)
{
   message += "test_calculate_mean_squared_error\n";
}


// void test_calculate_root_mean_squared_error(void) method

void VectorTest::test_calculate_root_mean_squared_error(void)
{
   message += "test_calculate_root_mean_squared_error\n";
}


// void test_calculate_norm(void) method

void VectorTest::test_calculate_norm(void)
{
   message += "test_calculate_norm\n";

   Vector<double> v;

   assert_true(v.calculate_norm() == 0.0, LOG);

   v.set(2);
   v.initialize(1);

   assert_true(v.calculate_norm() == sqrt(2.0), LOG);
}


// void test_apply_absolute_value(void) method

void VectorTest::test_apply_absolute_value(void)
{
   message += "test_apply_absolute_value\n";
}


// void test_calculate_lower_bounded(void) method

void VectorTest::test_calculate_lower_bounded(void)
{
   message += "test_calculate_lower_bounded\n";

   Vector<double> v(1, -1.0);
   Vector<double> lower_bound(1, 0.0);

   assert_true(v.calculate_lower_bounded(lower_bound) == 0.0, LOG); 
}


// void test_calculate_upper_bounded(void) method

void VectorTest::test_calculate_upper_bounded(void)
{
   message += "test_calculate_upper_bounded\n";
}


// void test_calculate_lower_upper_bounded(void) method

void VectorTest::test_calculate_lower_upper_bounded(void)
{
   message += "test_calculate_lower_upper_bounded\n";
}


// void test_dot_vector(void) method

void VectorTest::test_dot_vector(void)
{
   message += "test_dot_vector\n";

   Vector<double> a(2, 0.0);
   Vector<double> b(2, 0.0);

   double c = a.dot(b);

   assert_true(c == 0.0, LOG);
}


// void test_dot_matrix(void) method

void VectorTest::test_dot_matrix(void)
{
   message += "test_dot_matrix\n";

   Vector<double> a(2, 0.0);
   Matrix<double> b(2, 2, 0.0);

   Vector<double> c = a.dot(b);

   assert_true(c == 0.0, LOG);
}


// void test_tuck_in(void) method

void VectorTest::test_tuck_in(void)
{
   message += "test_tuck_in\n";

   Vector<int> a(4, 0);
   Vector<int> b(2, 1);

   a.tuck_in(1, b);

   Vector<int> c(4);
   c[0] = 0;
   c[1] = 1;
   c[2] = 1;
   c[3] = 0;

   assert_true(a == c, LOG);
}


// void test_take_out(void) method

void VectorTest::test_take_out(void)
{
   message += "test_take_out\n";

   Vector<int> a(4);
   a[0] = 0;
   a[1] = 1;
   a[2] = 1;
   a[3] = 0;

   Vector<int> b = a.take_out(1, 2);

   Vector<int> c(2, 1);

   assert_true(b == c, LOG);
}


// void test_get_assembly(void) method

void VectorTest::test_get_assembly(void)
{
   message += "test_get_assembly\n";

   Vector<int> a;
   Vector<int> b;
   Vector<int> c; 
   Vector<int> d; 
	   
   c = a.get_assembly(b);

   assert_true(c.size() == 0, LOG);

   a.set(1, 0);
   b.set(0, 0),
   c = a.get_assembly(b);

   assert_true(c.size() == 1, LOG);

   a.set(0, 0);
   b.set(1, 0),
   c = a.get_assembly(b);

   assert_true(c.size() == 1, LOG);

   a.set(1, 0);
   b.set(1, 1);
  
   c = a.get_assembly(b);

   d.resize(2);
   d[0] = 0;
   d[1] = 1;

   assert_true(c == d, LOG);
}


// void test_apply_lower_bound(void) method

void VectorTest::test_apply_lower_bound(void)
{
   message += "test_apply_lower_bound\n";
}


// void test_apply_upper_bound(void) method

void VectorTest::test_apply_upper_bound(void)
{
   message += "test_apply_upper_bound\n";
}


// void test_apply_lower_upper_bounds(void) method

void VectorTest::test_apply_lower_upper_bounds(void)
{
   message += "test_apply_lower_upper_bounds\n";
}


// void test_parse(void) method

void VectorTest::test_parse(void)
{
   message += "test_parse\n";

   Vector<int> v;

   std::string str;

   // Test 

   str = "1 2 3";

   v.parse(str);

   assert_true(v.size() == 3, LOG);   
   assert_true(v[0] == 1, LOG);   
   assert_true(v[1] == 2, LOG);   
   assert_true(v[2] == 3, LOG);   
}


// void test_load(void) method

void VectorTest::test_load(void)
{
   message += "test_load\n";

   Vector<int> v;
      
   // Test

   v.set(3, 1);

   v.save("../data/opennn_tests/vector.dat");
   v.load("../data/opennn_tests/vector.dat");

   assert_true(v.size() == 3, LOG);   
   assert_true(v == 1, LOG);   

   // Test

   v.set(2);
   v[0] = -1;
   v[1] = 1;

   v.save("../data/opennn_tests/vector.dat");
   v.load("../data/opennn_tests/vector.dat");

   assert_true(v.size() == 2, LOG);   
   assert_true(v[0] == -1, LOG);   
   assert_true(v[1] == 1, LOG);   
}


// void test_save(void) method

void VectorTest::test_save(void)
{
   message += "test_save\n";

   Vector<int> v(2, 0);
   Vector<int> w(v);

   v.save("../data/opennn_tests/vector.dat");

   v.load("../data/opennn_tests/vector.dat");   

   assert_true(v == w, LOG);   
}


// void run_test_case(void) method

void VectorTest::run_test_case(void)
{
   message += "Running vector test case...\n";

   // Constructor and destructor methods

   test_constructor();
   test_destructor();

   // Arithmetic operators

   test_sum_operator();
   test_rest_operator();
   test_multiplication_operator();
   test_division_operator();

   // Operation and assignment operators

   test_sum_assignment_operator();
   test_rest_assignment_operator();
   test_multiplication_assignment_operator();
   test_division_assignment_operator();

   // Equality and relational operators

   test_equal_to_operator();
   test_not_equal_to_operator();

   test_greater_than_operator();
   test_greater_than_or_equal_to_operator();

   test_less_than_operator();
   test_less_than_or_equal_to_operator();

   // Output operator

   test_output_operator();

   // Get methods

   test_get_display();

   // Set methods

   test_set();
   test_set_size();
   test_set_display();

   // Resize methods

   test_resize();

   test_tuck_in();
   test_take_out();
   
   test_get_assembly();

   // Initialization methods

   test_initialize();
   test_initialize_sequential();
   test_initialize_uniform();
   test_initialize_normal();

   // Mathematical methods

   test_dot_vector();
   test_dot_matrix();

   test_calculate_sum();
   test_calculate_product();

   test_calculate_mean();
   test_calculate_standard_deviation();

   test_calculate_mean_standard_deviation();

   test_calculate_minimum();
   test_calculate_maximum();

   test_calculate_minimum_maximum();  

   test_calculate_histogram();  

   test_calculate_minimal_index();
   test_calculate_maximal_index();

   test_calculate_minimal_maximal_index();

   test_calculate_cumulative_index();
   test_calculate_closest_index();

   test_calculate_norm();

   test_calculate_sum_squared_error();
   test_calculate_mean_squared_error();
   test_calculate_root_mean_squared_error();

   test_apply_absolute_value();

   test_calculate_lower_bounded();
   test_calculate_upper_bounded();

   test_calculate_lower_upper_bounded();

   test_apply_lower_bound();
   test_apply_upper_bound();
   test_apply_lower_upper_bounds();

   // Parsing methods

   test_parse();

   // Serialization methods

   test_save();

   test_load();

   message += "End vector test case\n";

}


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
