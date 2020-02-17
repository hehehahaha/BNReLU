#include "Convolution_layer.h"

datatype_kernel W_Conv[OUT_CH_NUM_Conv][IN_CH_NUM_Conv][Conv_MAP_SIZE][Conv_MAP_SIZE];
//datatype_kernel B_Conv[OUT_CH_NUM_Conv];

void Convolution_layer(datatype_Conv_Input ImgIn[IN_CH_NUM_Conv][IN_HEIGHT_Conv][IN_WIDTH_Conv], datatype_Convolution_layer ImgOut[OUT_CH_NUM_Conv][OUT_HEIGHT_Conv][OUT_WIDTH_Conv],datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE],datatype_control ctrl)
{
	if(ctrl==0)
	{
		ForWard_Convolution(ImgIn,ImgOut,W_Conv);
	}
	else if(ctrl==1)
	{
		Convolution_layer_Set_WB(WB_IN);
	}
}

void Convolution_layer_Set_WB(datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE])  //ËØªÂÖ•Âç∑ÁßØÊùÉÂ?º„?ÅÂÅèÁΩ?
{
	int _addr=0;
	int *addr=&_addr;
	for(int i=0; i<OUT_CH_NUM_Conv; i++)
		for(int t=0; t<IN_CH_NUM_Conv; t++)
			for(int j=0; j<Conv_MAP_SIZE; j++)
				for(int k=0; k<Conv_MAP_SIZE; k++){
					W_Conv[i][t][j][k]=WB_IN[(*addr)++];
					//printf("input_image_sum = %d\n",W_Conv[i][t][j][k]);
					}
	//for(int i=0;i<OUT_CH_NUM_Conv;i++)
		//B_Conv[i]=WB_IN[(*addr)++];
}


void ForWard_Convolution(datatype_Conv_Input ImgIn[IN_CH_NUM_Conv][IN_HEIGHT_Conv][IN_WIDTH_Conv], datatype_Convolution_layer ImgOut[OUT_CH_NUM_Conv][OUT_HEIGHT_Conv][OUT_WIDTH_Conv], datatype_kernel weight[OUT_CH_NUM_Conv][IN_CH_NUM_Conv][Conv_MAP_SIZE][Conv_MAP_SIZE])
{
//#pragma HLS array_partition variable = ImgIn complete dim = 1
//#pragma HLS array_partition variable = ImgOut complete dim = 1
//#pragma HLS array_partition variable = weight complete dim = 1
//#pragma HLS array_partition variable = weight complete dim = 2

	Row:
	for(int r=0; r<OUT_HEIGHT_Conv; r++)
	{
		Column:
		for(int c=0; c<OUT_WIDTH_Conv; c++)
		{
			Kernel_Row:
			for(int kr=0; kr<Conv_MAP_SIZE; kr++)
			{
				Kernel_Column:
				for(int kc=0; kc<Conv_MAP_SIZE; kc++)
				{
					Output_Channel:
					for(int cho=0; cho<OUT_CH_NUM_Conv; cho++)
					{
						Input_Channel:
						for(int chi=0; chi<IN_CH_NUM_Conv; chi++)
						{
							//ImgOut[cho][r][c] = ImgIn[chi][r+kr][c+kc];
							ImgOut[cho][r][c] += ImgIn[chi][r+kr][c+kc] * weight[cho][chi][kr][kc];
						}
					}
				}
			}
		}
	}
	/*
	Kernel_Row:
	for(int kr=0; kr<Conv_MAP_SIZE; kr++)
	{
		Kernel_Column:
		for(int kc=0; kc<Conv_MAP_SIZE; kc++)
		{
			Row:
			for(int r=0; r<OUT_HEIGHT_Conv; r++)
			{
#pragma HLS PIPELINE
				Column:
				for(int c=0; c<OUT_WIDTH_Conv; c++)
				{
					Output_Channel:
					for(int cho=0; cho<OUT_CH_NUM_Conv; cho++)
					{
						Input_Channel:
						for(int chi=0; chi<IN_CH_NUM_Conv; chi++)
						{
							ImgOut[cho][r][c] += ImgIn[chi][r+kr][c+kc] * weight[cho][chi][kr][kc];
						}
					}
				}
			}
		}
	}*/
}
