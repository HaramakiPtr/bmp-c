#include <stdio.h>
#include <stdlib.h>
#include "bmph/bmph.h"

int main(void)
{
	FILE* fp;
	int size = 1;
	printf("Please enter the size:");
	scanf("%d",&size);
	while((size % 4) != 0)
	{
		size ++;
	}
	int pixSize = (size*size)*3;
	char* header = getHeaderInfo(size);
	char* image = (char*)malloc(pixSize);
	
	int i;
	for(i=0;i<pixSize;i+=3)
	{
		image[i+0] = 173;
		image[i+1] = 236;
		image[i+2] = 128;
	}
	
	if((fp = fopen("bluebox.bmp","wb")) == NULL)
	{
		exit(1);
	}
	
	fwrite(header,54,1,fp);
	fwrite(image,pixSize,1,fp);
	
	free(header);
	free(image);
	fclose(fp);
	return 0;
}