int
loop (int row_a, int col_a, int row_b, int col_b)
{
  int i, j, k, row_c, col_c;
  float w;

  row_c = row_a;
  col_c = col_b;

  if (row_c < 1 || row_b < 1 || col_c < 1 || col_a != row_b)
    return (999);

  for (i = 0; i < row_c; i++)
    {
      for (j = 0; j < col_c; j++)
	{
	  w = 0.0;
	  for (k = 0; k < row_b; k++)
	    w += a[i][k] * b[k][j];
	  c[i][j] = w;
	}
    }

  return (0);
}
