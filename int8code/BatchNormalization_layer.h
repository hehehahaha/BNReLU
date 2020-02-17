#ifndef _BatchNormalization_layer
#define _BatchNormalization_layer

#include "datatype.h"

typedef datatype_Max_Pool datatype_BN_Input;

#define OUT_CH_NUM_BN 32
#define OUT_HEIGHT_BN 13
#define OUT_WIDTH_BN 13

void BatchNormalization_layer(datatype_BN_Input ImgIn[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],datatype_BN ImgOut[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN], datatype_kernel BN_IN[OUT_CH_NUM_BN], datatype_control ctrl);
void BatchNormalization_layer_Set_BN(datatype_kernel BN_IN[OUT_CH_NUM_BN]);
void BatchNormalization(datatype_BN_Input ImgIn[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],datatype_BN ImgOut[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN], datatype_kernel beta[OUT_CH_NUM_BN]);
#endif
