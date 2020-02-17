#include "Relu_layer.h"

void Relu_layer(datatype_Relu_Input ImgIn[OUT_CH_NUM_Relu][OUT_HEIGHT_Relu][OUT_WIDTH_Relu],datatype_Relu ImgOut[OUT_CH_NUM_Relu][OUT_HEIGHT_Relu][OUT_WIDTH_Relu])
{
	for(int i=0;i<OUT_CH_NUM_Relu;i++)
		for(int j=0;j<OUT_HEIGHT_Relu;j++)
			Relu_layer_label6:for(int k=0;k<OUT_WIDTH_Relu;k++)
				ImgOut[i][j][k]=(ImgIn[i][j][k] > 0) ? ImgIn[i][j][k] : ((float)0.0);  //Relu功能

}
