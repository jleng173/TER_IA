#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"

struct TEXTURE_STRUCT
{
  int width, height, bpp;
  unsigned char *data;
};

class ppm{
    public:
        TEXTURE_STRUCT * readPpm (char *ppmFileName);
        void writePpm (char *filename, unsigned char *data);
        unsigned char * rgb2rgba(TEXTURE_STRUCT * texture);
};
