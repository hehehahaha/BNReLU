#ifndef __Convolution_layer_H
#define	__Convolution_layer_H

#include "datatype.h"
#include <cstring>

typedef datatype_Input_layer datatype_Conv_Input;

#define	Conv_MAP_SIZE 3
#define IN_CH_NUM_Conv 1
#define IN_HEIGHT_Conv 28
#define IN_WIDTH_Conv 28

#define OUT_CH_NUM_Conv 32
#define OUT_HEIGHT_Conv (IN_HEIGHT_Conv-Conv_MAP_SIZE+1)
#define OUT_WIDTH_Conv (IN_WIDTH_Conv-Conv_MAP_SIZE+1)

void Convolution_layer(datatype_Conv_Input ImgIn[IN_CH_NUM_Conv][IN_HEIGHT_Conv][IN_WIDTH_Conv],datatype_Convolution_layer ImgOut[OUT_CH_NUM_Conv][OUT_HEIGHT_Conv][OUT_WIDTH_Conv],datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE],datatype_control ctrl);
void Convolution_layer_Set_WB(datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE]);
void ForWard_Convolution(datatype_Conv_Input ImgIn[IN_CH_NUM_Conv][IN_HEIGHT_Conv][IN_WIDTH_Conv], datatype_Convolution_layer ImgOut[OUT_CH_NUM_Conv][OUT_HEIGHT_Conv][OUT_WIDTH_Conv], datatype_kernel weight[OUT_CH_NUM_Conv][IN_CH_NUM_Conv][Conv_MAP_SIZE][Conv_MAP_SIZE]);

#endif
