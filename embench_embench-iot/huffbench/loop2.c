#include<stdlib.h>

#define bits32 unsigned long

void loop(char * optr, unsigned long *code, unsigned char *clen, bits32 *heap2) {
	int j;
  for (j = 0; j < 256; ++j)
    {
      (*optr) = (char) j;
      ++optr;

      // if code exists for this byte
      if (code[j] | clen[j])
	{
	  // begin at first code bit
	  int k = 0;
	  size_t mask = 1 << (clen[j] - 1);

	  // find proper node, using bits in
	  // code as path.
	  for (int i = 0; i < clen[j]; ++i)
	    {
	      k = k * 2 + 1;	// right link

	      if (code[j] & mask)
		++k;		// go left

	      mask >>= 1;	// next bit
	    }

	  heap2[j] = k;		// store link in heap2
	}
    }
}
