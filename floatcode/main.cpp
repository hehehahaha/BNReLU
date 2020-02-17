#include "CNN.h"
#include "rdMNIST.h"
#include <stdlib.h>

using namespace std;

#define Parameter_Length (IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE)
#define Parameter_Length1 (OUT_CH_NUM_BN)

bool loadModelFile(const char* name, datatype_kernel WB_IN[Parameter_Length]);
bool loadModelFile1(const char* name, datatype_kernel BN_IN[Parameter_Length1]);

datatype_kernel WB_IN[IN_CH_NUM_Conv*OUT_CH_NUM_Conv*Conv_MAP_SIZE*Conv_MAP_SIZE];
datatype_kernel BN_IN[OUT_CH_NUM_BN];

datatype_Input_layer ImgIn[1][28][28];

datatype_Max_Pool ImgBN[OUT_CH_NUM_BN][OUT_HEIGHT_BN][OUT_WIDTH_BN];
int label[1];

int main(void)
{
	FILE *fp;
	char str[20];

	loadModelFile("E:\\123.txt",WB_IN);
	loadModelFile1("E:\\12.txt",BN_IN);
	CNN(NULL,NULL,WB_IN,BN_IN,1);//load_para

	for(int i=0;i<1;i++)
	{
		rdMNISTs28_test<datatype_Input_layer>(i,i+1,(datatype_Input_layer (*)[28][28]) ImgIn, (int *)label);
		CNN(ImgIn,ImgBN,NULL,NULL,0);
	}
}
float temp;

bool loadModelFile(const char* name, datatype_kernel WB_IN[Parameter_Length])
{
	FILE* fp = fopen(name,"r");
	if (fp == NULL) {
		printf( "Load Model Error!" );
		}
	for (int i=0;i<Parameter_Length;++i)
	{
		fscanf(fp,"%f",&temp);
		WB_IN[i]=temp;
		printf ("input_image_sum = %f\n",WB_IN[i]);
	}
	fclose(fp);
}

bool loadModelFile1(const char* name, datatype_kernel BN_IN[Parameter_Length1])
{
	FILE* fp = fopen(name, "rb");
	if (fp == NULL) {
		std::cout << "Load Model Error!" << std::endl;
		return false;
	}
	fread(BN_IN, sizeof(datatype_kernel) * Parameter_Length1, 1, fp);

	fflush(fp);
	fclose(fp);
	std::cout << "Load Success!" << std::endl;
	return true;
}
