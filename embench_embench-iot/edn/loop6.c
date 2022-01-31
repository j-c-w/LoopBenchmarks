void
loop (const short *coefs, const short *input, long int *optr, long int *state)
{
  long int x;
  long int t;
  long int n;

  x = input[0];
  for (n = 0; n < 50; n++)
    {
      t = x + ((coefs[2] * state[0] + coefs[3] * state[1]) >> 15);
      x = t + ((coefs[0] * state[0] + coefs[1] * state[1]) >> 15);
      state[1] = state[0];
      state[0] = t;
      coefs += 4;		/* point to next filter coefs  */
      state += 2;		/* point to next filter states */
    }
  *optr++ = x;
}
