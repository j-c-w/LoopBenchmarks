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
loop (uint8* gMCUBufG, uint8* gMCUBufB, int16 *gCoeffBuf, uint8 dstOfs)
{
  uint8 i;
  uint8 *pDstG = gMCUBufG + dstOfs;
  uint8 *pDstB = gMCUBufB + dstOfs;
  int16 *pSrc = gCoeffBuf;

  for (i = 64; i > 0; i--)
    {
      uint8 cb = (uint8) * pSrc++;
      int16 cbG, cbB;

      cbG = ((cb * 88U) >> 8U) - 44U;
      *pDstG = subAndClamp (pDstG[0], cbG);
      pDstG++;

      cbB = (cb + ((cb * 198U) >> 8U)) - 227U;
      *pDstB = addAndClamp (pDstB[0], cbB);
      pDstB++;
    }
}
