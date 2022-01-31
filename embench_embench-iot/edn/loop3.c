#define N 100
#define ORDER 50

void
loop (const short array1[], const short coeff[], long int output[])
{
  long int i, j, sum;

  for (i = 0; i < N - ORDER; i++)
    {
      sum = 0;
      for (j = 0; j < ORDER; j++)
		{
		  sum += array1[i + j] * coeff[j];
		}
      output[i] = sum >> 15;
    }
}
