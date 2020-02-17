#ifndef __Tanh_layer
#define __Tanh_layer

#include "datatype.h"

typedef datatype_BN datatype_Relu_Input;

#define OUT_CH_NUM_Relu 32
#define OUT_HEIGHT_Relu 13
#define OUT_WIDTH_Relu 13

void Relu_layer(datatype_Relu_Input ImgIn[OUT_CH_NUM_Relu][OUT_HEIGHT_Relu][OUT_WIDTH_Relu],datatype_Relu ImgOut[OUT_CH_NUM_Relu][OUT_HEIGHT_Relu][OUT_WIDTH_Relu]);

#endif
