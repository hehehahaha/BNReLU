#ifndef __CNN_5_H
#define	__CNN_5_H

#include <iostream>
#include "datatype.h"

#include "Convolution_layer.h"
#include "MaxPool_layer.h"
#include "BatchNormalization_layer.h"

void CNN(datatype_Input_layer ImgIn[1][28][28],
		 datatype_Max_Pool ImgBN[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
		 datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE],
		 datatype_kernel BN_IN[OUT_CH_NUM_BN],
		 datatype_control ctrl);
#endif 
