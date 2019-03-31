#include <stdlib.h>

#ifndef __BMP_H__
#define __BMP_H__

char* getHeaderInfo(int size)
{
  char* header = (char*)calloc(sizeof(char),54);

  header[0] = 'B';
  header[1] = 'M';

  int* di;
  di = (int*)(header + 2);
  *di = (size * size)*3 + 54;
  di = (int*)(header + 10);
  *di = 54;
  di = (int*)(header + 14);
  *di = 40;
  di = (int*)(header + 18);
  *di = size;
  di = (int*)(header + 22);
  *di = size;

  short* ds;
  ds = (short*)(header + 26);
  *ds = 1;
  ds = (short*)(header + 28);
  *ds = 24;

  return header;
}

#endif
