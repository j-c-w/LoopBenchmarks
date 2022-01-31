typedef uint64_t uint64;
typedef int64_t int64;

uint64 loop (uint64 x, uint64 y, uint64 z)
{

  /* Divides (x || y) by z, for 64-bit integers x, y,
     and z, giving the remainder (modulus) as the result.
     Must have x < z (to get a 64-bit result). This is
     checked for. */

  int64 i, t;

  for (i = 1; i <= 64; i++)
    {				// Do 64 times.
      t = (int64) x >> 63;	// All 1's if x(63) = 1.
      x = (x << 1) | (y >> 63);	// Shift x || y left
      y = y << 1;		// one bit.
      if ((x | t) >= z)
	{
	  x = x - z;
	  y = y + 1;
	}
    }
  return x;			// Quotient is y.
}
