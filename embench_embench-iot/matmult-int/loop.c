#define UPPERLIMIT 20
#define ZERO 0
typedef long matrix[UPPERLIMIT][UPPERLIMIT];

void
loop (matrix A, matrix B, matrix Res)
{
  register int Outer, Inner, Index;

  for (Outer = 0; Outer < UPPERLIMIT; Outer++)
    for (Inner = 0; Inner < UPPERLIMIT; Inner++)
      {
	Res[Outer][Inner] = ZERO;
	for (Index = 0; Index < UPPERLIMIT; Index++)
	  Res[Outer][Inner] += A[Outer][Index] * B[Index][Inner];
      }
}
