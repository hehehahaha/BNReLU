#ifndef __MaxPool_layer
#define __MaxPool_layer

#include "datatype.h"

typedef datatype_Convolution_layer datatype_MaxPool_Input;

#define OUT_CH_NUM_MaxP 32
#define OUT_HEIGHT_MaxP 13
#define OUT_WIDTH_MaxP 13

void MaxPool_layer(datatype_MaxPool_Input ImgIn[OUT_CH_NUM_MaxP][OUT_HEIGHT_MaxP*2][OUT_WIDTH_MaxP*2],datatype_Max_Pool ImgOut[OUT_CH_NUM_MaxP][OUT_HEIGHT_MaxP][OUT_WIDTH_MaxP]);

#endif
