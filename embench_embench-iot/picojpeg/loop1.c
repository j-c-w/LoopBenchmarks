typedef unsigned char uint8;
typedef unsigned short uint16;
typedef signed char int8;
typedef signed short int16;

typedef struct HuffTableT
{
  uint16 mMinCode[16];
  uint16 mMaxCode[16];
  uint8 mValPtr[16];
} HuffTable;

//------------------------------------------------------------------------------
static uint8
getBit (void)
{
  uint8 ret = 0;
  if (gBitBuf & 0x8000)
    ret = 1;

  if (!gBitsLeft)
    {
      gBitBuf |= getOctet (1);

      gBitsLeft += 8;
    }

  gBitsLeft--;
  gBitBuf <<= 1;

  return ret;
}

// Unclear whether this loop is runnable on a typical CGRA.
void
loop (const HuffTable * pHuffTable, const uint8 * pHuffVal)
{
  uint8 i = 0;
  uint8 j;
  uint16 code = getBit ();

  // This func only reads a bit at a time, which on modern CPU's is not terribly efficient.
  // But on microcontrollers without strong integer shifting support this seems like a
  // more reasonable approach.
  for (;;)
    {
      uint16 maxCode;

      if (i == 16)
	return 0;

      maxCode = pHuffTable->mMaxCode[i];
      if ((code <= maxCode) && (maxCode != 0xFFFF))
	break;

      i++;
      code <<= 1;
      code |= getBit ();
    }

  j = pHuffTable->mValPtr[i];
  j = (uint8) (j + (code - pHuffTable->mMinCode[i]));
}
