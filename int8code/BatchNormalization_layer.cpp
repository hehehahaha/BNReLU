#include "BatchNormalization_layer.h"
#include "hls_math.h"

datatype_kernel beta[OUT_CH_NUM_BN];
datatype_kernel gamma[OUT_CH_NUM_BN];
datatype_kernel mean[OUT_CH_NUM_BN];
datatype_kernel variance[OUT_CH_NUM_BN];

void BatchNormalization_layer(datatype_BN_Input ImgIn[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
							  datatype_BN ImgOut[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
							  datatype_kernel BN_IN[OUT_CH_NUM_BN],
							  datatype_control ctrl)
{
	if(ctrl==0)
	{
		BatchNormalization(ImgIn, ImgOut, beta);
	}
	else if(ctrl==1)
	{
		BatchNormalization_layer_Set_BN(BN_IN);
	}
}

void BatchNormalization_layer_Set_BN(datatype_kernel BN_IN[OUT_CH_NUM_BN]) //读入BN层的均�?��?�方差�?�beta、gamma
{
	int _addr=0;
	int *addr=&_addr;
	for(int i=0; i<OUT_CH_NUM_BN; i++)
		{beta[i]=BN_IN[(*addr)++];}
	for(int i=0;i<OUT_CH_NUM_BN;i++)
		{gamma[i]=BN_IN[(*addr)++];}
	for(int i=0;i<0;i++)
		{variance[i]=BN_IN[(*addr)++];}
	//variance[0]=BN_IN[*addr];
}

void BatchNormalization(datatype_BN_Input ImgIn[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
						datatype_BN ImgOut[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN],
						datatype_kernel beta[OUT_CH_NUM_BN])
{
	ddd:for(int i=0;i<OUT_CH_NUM_BN;i++)
		for(int j=0;j<OUT_HEIGHT_BN;j++)
			BN_layer_label:for(int k=0;k<OUT_WIDTH_BN;k++)
				//ImgOut[i][j][k]=gamma[i]*((ImgIn[i][j][k]-mean[i])/(ap_fixed<16,2,SC_RND,SC_SAT>)sqrt(float((variance[i]+((ap_fixed<16,2,SC_RND,SC_SAT>)0.1)))))+beta[i];//计算BN公式
				//ImgOut[i][j][k]=beta[i]*(ImgIn[i][j][k])+gamma[i];
				ImgOut[i][j][k]=(ImgIn[i][j][k] > beta[i]) ? (datatype_BN)(ImgIn[i][j][k]-beta[i]) : ((datatype_BN)0.0);
}
