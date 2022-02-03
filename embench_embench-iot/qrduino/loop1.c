unsigned char g0log[256], g0exp[256];

static void
gentables ()
{
#define GFPOLY (0x11d)
  unsigned char i, j;
  g0log[0] = 255;
  g0exp[255] = 0;
  j = 1;
  for (i = 0; i < 255; i++)
    {
      g0log[j] = i;
      g0exp[i] = j;
      j <<= 1;
      if (j & 256)
	j ^= GFPOLY;
      j &= 255;
    }
}
