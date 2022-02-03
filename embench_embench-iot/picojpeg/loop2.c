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

// Does this need to be convereted into a traditioanl loop?
void
loop (const uint8 * pBits, HuffTable * pHuffTable)
{
  uint8 i = 0;
  uint8 j = 0;

  uint16 code = 0;

  for (;;)
    {
      uint8 num = pBits[i];

      if (!num)
	{
	  pHuffTable->mMinCode[i] = 0x0000;
	  pHuffTable->mMaxCode[i] = 0xFFFF;
	  pHuffTable->mValPtr[i] = 0;
	}
      else
	{
	  pHuffTable->mMinCode[i] = code;
	  pHuffTable->mMaxCode[i] = code + num - 1;
	  pHuffTable->mValPtr[i] = j;

	  j = (uint8) (j + num);

	  code = (uint16) (code + num);
	}

      code <<= 1;

      i++;
      if (i > 15)
	break;
    }
}
