int
benchmark_body (int rpt, double **a, double *b)
{
  int  k;

  for (k = 0; k < rpt; k++)
    {
      int      i, j, nmax = 20, n = 5;
      long int /* eps, */ w;

      /* eps = 1.0e-6; */

      /* Init loop */
      for(i = 0; i <= n; i++)
	{
	  w = 0.0;              /* data to fill in cells */
	  for(j = 0; j <= n; j++)
	    {
	      a[i][j] = (i + 1) + (j + 1);
	      if(i == j)            /* only once per loop pass */
		a[i][j] *= 2.0;
	      w += a[i][j];
	    }
	  b[i] = w;
	}
    }

  return 0;
}
