/*################################################################################
  ##
  ##   Copyright (C) 2011-2022 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
    print_begin("pinvgamma");

    // parameters

    double shape_par = 3.0;
    double rate_par = 2.0;

    //

    std::vector<double> inp_vals = { 0.7,        1.01,       2.5,      };
    std::vector<double> exp_vals = { 0.4559447,  0.6820361,  0.9525774 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[0],exp_vals[0],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[1],exp_vals[1],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[2],exp_vals[2],false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,inp_vals[1],exp_vals[1],true,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0.3,0.03803761,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,3.5,0.9796131,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,7.5,0.9974089,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,10.0,0.9988515,false,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NAN,TEST_NAN,false,shape_par,rate_par);                      // NaN inputs
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NAN,rate_par);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,shape_par,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NAN,TEST_NAN,false,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,-1,2);                                           // shape < 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,TEST_NEGINF,2);

    STATS_TEST_EXPECTED_VAL(pinvgamma,2,1,false,1,0);                                                   // scale <= 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,4,-1);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,3,TEST_NEGINF);

    STATS_TEST_EXPECTED_VAL(pinvgamma,-1,0.0,false,shape_par,rate_par);                                 // x < 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_NEGINF,0.0,false,shape_par,rate_par);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0,0,false,0,2);                                                   // shape == 0
    STATS_TEST_EXPECTED_VAL(pinvgamma,1,0,false,0,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,1,1,false,0,0);

    STATS_TEST_EXPECTED_VAL(pinvgamma,0,0,false,0.5,3);                                                 // x == 0

    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_POSINF,TEST_NAN,false,TEST_POSINF,TEST_POSINF);              // x == +Inf or shape == +Inf or scale == +Inf
    STATS_TEST_EXPECTED_VAL(pinvgamma,TEST_POSINF,1,false,2,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,1,false,TEST_POSINF,2);
    STATS_TEST_EXPECTED_VAL(pinvgamma,2,TEST_NAN,false,2,TEST_POSINF);
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_vals,exp_vals,std::vector<double>,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_vals,exp_vals,std::vector<double>,true,shape_par,rate_par);
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj inp_mat(2,3);
    inp_mat(0,0) = inp_vals[0];
    inp_mat(1,0) = inp_vals[2];
    inp_mat(0,1) = inp_vals[1];
    inp_mat(1,1) = inp_vals[0];
    inp_mat(0,2) = inp_vals[2];
    inp_mat(1,2) = inp_vals[1];

    mat_obj exp_mat(2,3);
    exp_mat(0,0) = exp_vals[0];
    exp_mat(1,0) = exp_vals[2];
    exp_mat(0,1) = exp_vals[1];
    exp_mat(1,1) = exp_vals[0];
    exp_mat(0,2) = exp_vals[2];
    exp_mat(1,2) = exp_vals[1];

    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_mat,exp_mat,mat_obj,false,shape_par,rate_par);
    STATS_TEST_EXPECTED_MAT(pinvgamma,inp_mat,exp_mat,mat_obj,true,shape_par,rate_par);
#endif

    // 

    print_final("pinvgamma");

    return 0;
}
