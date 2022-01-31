long int
loop (short b[], const short k[], long int n, long int f)
{
  long int i;

  f -= b[n - 1] * k[n - 1];
  for (i = n - 2; i >= 0; i--)
    {
      f -= b[i] * k[i];
      b[i + 1] = b[i] + ((k[i] * (f >> 16)) >> 16);
    }
  b[0] = f >> 16;
  return f;
}
