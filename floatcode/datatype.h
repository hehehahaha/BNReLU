#ifndef __DATATYPE_H
#define	__DATATYPE_H

#include <stdio.h>
#include <iostream>

#include <ap_fixed.h>
#include <ap_int.h>
#include <cmath>
//#include <HLS_math.h>
/*
typedef ap_uint<1> datatype_control;
typedef ap_int<1> datatype_kernel;
//typedef int<1> datatype_kernel;
typedef ap_ufixed<16,2,SC_RND,SC_SAT> datatype_Input_layer;
typedef ap_fixed<16,1,SC_RND,SC_SAT> datatype_Convolution_layer;
typedef ap_fixed<16,1,SC_RND,SC_SAT> datatype_Max_Pool;
typedef ap_fixed<16,1,SC_RND,SC_SAT> datatype_Relu;
typedef datatype_Relu datatype_Reshape;
typedef ap_fixed<32,5,SC_RND,SC_SAT> datatype_Fully_Connected;
typedef ap_fixed<16,2,SC_RND,SC_SAT> datatype_Softplus;
*/
typedef ap_uint<1> datatype_control;
typedef float datatype_kernel;
//typedef int<1> datatype_kernel;
typedef float datatype_Input_layer;
typedef float datatype_Convolution_layer;
typedef float datatype_Max_Pool;
typedef float datatype_BN;
typedef float datatype_Relu;


#endif
