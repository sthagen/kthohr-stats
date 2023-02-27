/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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
    print_begin("pf");

    // parameters

    double a_par = 10.0;
    double b_par = 12.0;

    //

    std::vector<double> inp_vals = { 1.0,        2.0,        3.0 };
    std::vector<double> exp_vals = { 0.5074083,  0.8724921,  0.962352 };

    //
    // scalar tests

    STATS_TEST_EXPECTED_VAL(pf,inp_vals[0],exp_vals[0],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(pf,inp_vals[1],exp_vals[1],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(pf,inp_vals[2],exp_vals[2],false,a_par,b_par);
    STATS_TEST_EXPECTED_VAL(pf,inp_vals[1],exp_vals[1],true,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(pf,TEST_NAN,TEST_NAN,false,a_par,b_par);                                // NaN inputs
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,TEST_NAN,b_par);
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,a_par,TEST_NAN);

    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,0,3);                                               // bad parameter value cases (a or b <= 0)
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,4,0);
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,3,-1);
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,-1,4);
    STATS_TEST_EXPECTED_VAL(pf,2,TEST_NAN,false,-1,-1);

    STATS_TEST_EXPECTED_VAL(pf,0,0,false,1,3);                                                      // x <= 0
    STATS_TEST_EXPECTED_VAL(pf,-1,0,false,2,2);
    STATS_TEST_EXPECTED_VAL(pf,TEST_NEGINF,0,false,a_par,b_par);

    STATS_TEST_EXPECTED_VAL(pf,2,1,false,TEST_POSINF,TEST_POSINF);                                  // a == +Inf and b == +Inf
    STATS_TEST_EXPECTED_VAL(pf,1,0.5,false,TEST_POSINF,TEST_POSINF);
    STATS_TEST_EXPECTED_VAL(pf,0.5,0,false,TEST_POSINF,TEST_POSINF);

    STATS_TEST_EXPECTED_VAL(pf,2,0.6822703,false,TEST_POSINF,3);                                    // a == +Inf

    STATS_TEST_EXPECTED_VAL(pf,2,0.8646647,false,2,TEST_POSINF);                                    // b == +Inf
 
    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_MAT(pf,inp_vals,exp_vals,std::vector<double>,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(pf,inp_vals,exp_vals,std::vector<double>,true,a_par,b_par);
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

    STATS_TEST_EXPECTED_MAT(pf,inp_mat,exp_mat,mat_obj,false,a_par,b_par);
    STATS_TEST_EXPECTED_MAT(pf,inp_mat,exp_mat,mat_obj,true,a_par,b_par);
#endif

    // 

    print_final("pf");

    return 0;
}
