#include "MaxPool_layer.h"

#define Max(A,B) ((A>B)?A:B)

void MaxPool_layer(datatype_MaxPool_Input ImgIn[OUT_CH_NUM_MaxP][OUT_HEIGHT_MaxP*2][OUT_WIDTH_MaxP*2],datatype_Max_Pool ImgOut[OUT_CH_NUM_MaxP][OUT_HEIGHT_MaxP][OUT_WIDTH_MaxP])
{
	for(int i=0;i<OUT_CH_NUM_MaxP;i++)
		for(int j=0;j<OUT_HEIGHT_MaxP;j++)
			for(int k=0;k<OUT_WIDTH_MaxP;k++)
				ImgOut[i][j][k]=Max( Max( ImgIn[i][2*j][2*k], ImgIn[i][2*j][2*k+1]) , Max( ImgIn[i][2*j+1][2*k], ImgIn[i][2*j+1][2*k+1]) );
}

