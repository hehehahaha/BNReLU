#include "CNN.h"

datatype_Convolution_layer ImgConv[OUT_CH_NUM_Conv][OUT_HEIGHT_Conv][OUT_WIDTH_Conv];
datatype_Max_Pool ImgMaxP[OUT_CH_NUM_MaxP][OUT_HEIGHT_MaxP][OUT_WIDTH_MaxP];


void CNN(datatype_Input_layer ImgIn[1][28][28],
		datatype_Max_Pool ImgBN[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
		datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE],
		datatype_kernel BN_IN[OUT_CH_NUM_BN],
		datatype_control ctrl)
{	
	if(ctrl==0)
	{
		Convolution_layer(ImgIn,ImgConv,NULL,0);
		MaxPool_layer(ImgConv,ImgMaxP);
		BatchNormalization_layer(ImgMaxP,ImgBN,NULL,0);
	}
	else if(ctrl==1)
	{
		Convolution_layer(NULL,NULL,WB_IN,1);
		BatchNormalization_layer(NULL,NULL,BN_IN,1);
	}
}
