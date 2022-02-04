typedef unsigned char uint8;
typedef unsigned short uint16;
typedef signed char int8;
typedef signed short int16;

static uint8
addAndClamp (uint8 a, int16 b)
{
  b = a + b;

  if ((uint16) b > 255U)
    {
      if (b < 0)
	return 0;
      else if (b > 255)
	return 255;
    }

  return (uint8) b;
}

uint8
subAndClamp (uint8 a, int16 b)
{
  b = a - b;

  if ((uint16) b > 255U)
    {
      if (b < 0)
	return 0;
      else if (b > 255)
	return 255;
    }

  return (uint8) b;
}

static void
loop (int16* gCoeffBuf, uint8* gMCUBufR, uint8* gMCUBufG, int16*pSRC, uint8 dstOfs)
{
  uint8 i;
  uint8 *pDstR = gMCUBufR + dstOfs;
  uint8 *pDstG = gMCUBufG + dstOfs;
  int16 *pSrc = gCoeffBuf;

  for (i = 64; i > 0; i--)
    {
      uint8 cr = (uint8) * pSrc++;
      int16 crR, crG;

      crR = (cr + ((cr * 103U) >> 8U)) - 179;
      *pDstR = addAndClamp (pDstR[0], crR);
      pDstR++;

      crG = ((cr * 183U) >> 8U) - 91;
      *pDstG = subAndClamp (pDstG[0], crG);
      pDstG++;
    }
}
