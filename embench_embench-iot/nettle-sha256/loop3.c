#include<stdint.h>

#define ROTL32(n,x) (((x)<<(n)) | ((x)>>((-(n)&31))))

#define SHA256_DATA_LENGTH 16

#define DEBUG(i)

#define Choice(x,y,z)   ( (z) ^ ( (x) & ( (y) ^ (z) ) ) )
#define Majority(x,y,z) ( ((x) & (y)) ^ ((z) & ((x) ^ (y))) )

#define S0(x) (ROTL32(30,(x)) ^ ROTL32(19,(x)) ^ ROTL32(10,(x)))
#define S1(x) (ROTL32(26,(x)) ^ ROTL32(21,(x)) ^ ROTL32(7,(x)))

#define s0(x) (ROTL32(25,(x)) ^ ROTL32(14,(x)) ^ ((x) >> 3))
#define s1(x) (ROTL32(15,(x)) ^ ROTL32(13,(x)) ^ ((x) >> 10))

#define EXPAND(W,i) \
( W[(i) & 15 ] += (s1(W[((i)-2) & 15]) + W[((i)-7) & 15] + s0(W[((i)-15) & 15])) )

/* It's crucial that DATA is only used once, as that argument will
 * have side effects. */
#define ROUND(a,b,c,d,e,f,g,h,k,data) do {      \
    h += S1(e) + Choice(e,f,g) + k + data;      \
    d += h;                                     \
    h += S0(a) + Majority(a,b,c);               \
  } while (0)

void loop2(uint32_t *state, const uint32_t *k) {
	uint32_t data[SHA256_DATA_LENGTH];
  uint32_t A, B, C, D, E, F, G, H;	/* Local vars */
  unsigned i;
  /* Set up first buffer and local data buffer */
  A = state[0];
  B = state[1];
  C = state[2];
  D = state[3];
  E = state[4];
  F = state[5];
  G = state[6];
  H = state[7];

  /* Heavy mangling */
  /* First 16 subrounds that act on the original data */

  // TODO -- should this be un-unrolled since a compiler
  // could probably do that?
  for (; i < 64; i += 16, k += 16)
    {
      ROUND (A, B, C, D, E, F, G, H, k[0], EXPAND (data, 0));
      ROUND (H, A, B, C, D, E, F, G, k[1], EXPAND (data, 1));
      ROUND (G, H, A, B, C, D, E, F, k[2], EXPAND (data, 2));
      ROUND (F, G, H, A, B, C, D, E, k[3], EXPAND (data, 3));
      ROUND (E, F, G, H, A, B, C, D, k[4], EXPAND (data, 4));
      ROUND (D, E, F, G, H, A, B, C, k[5], EXPAND (data, 5));
      ROUND (C, D, E, F, G, H, A, B, k[6], EXPAND (data, 6));
      ROUND (B, C, D, E, F, G, H, A, k[7], EXPAND (data, 7));
      ROUND (A, B, C, D, E, F, G, H, k[8], EXPAND (data, 8));
      ROUND (H, A, B, C, D, E, F, G, k[9], EXPAND (data, 9));
      ROUND (G, H, A, B, C, D, E, F, k[10], EXPAND (data, 10));
      ROUND (F, G, H, A, B, C, D, E, k[11], EXPAND (data, 11));
      ROUND (E, F, G, H, A, B, C, D, k[12], EXPAND (data, 12));
      ROUND (D, E, F, G, H, A, B, C, k[13], EXPAND (data, 13));
      ROUND (C, D, E, F, G, H, A, B, k[14], EXPAND (data, 14));
      ROUND (B, C, D, E, F, G, H, A, k[15], EXPAND (data, 15));
    }
}
