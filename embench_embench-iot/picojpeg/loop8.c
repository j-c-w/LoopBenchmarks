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
loop (uint8 srcOfs, uint8 dstOfs)
{
  // Cr - affects R and G
  uint8 x, y;
  int16 *pSrc = gCoeffBuf + srcOfs;
  uint8 *pDstR = gMCUBufR + dstOfs;
  uint8 *pDstG = gMCUBufG + dstOfs;
  for (y = 0; y < 4; y++)
    {
      for (x = 0; x < 8; x++)
	{
	  uint8 cr = (uint8) * pSrc++;
	  int16 crR, crG;

	  crR = (cr + ((cr * 103U) >> 8U)) - 179;
	  pDstR[0] = addAndClamp (pDstR[0], crR);
	  pDstR[8] = addAndClamp (pDstR[8], crR);

	  crG = ((cr * 183U) >> 8U) - 91;
	  pDstG[0] = subAndClamp (pDstG[0], crG);
	  pDstG[8] = subAndClamp (pDstG[8], crG);

	  ++pDstR;
	  ++pDstG;
	}

      pDstR = pDstR - 8 + 16;
      pDstG = pDstG - 8 + 16;
    }
}
