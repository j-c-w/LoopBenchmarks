#include<math.h>

#define PI 3.1415926

// TODO -- Inline.
void
SolveCubic (double a, double b, double c, double d, int *solutions, double *x)
{
  long double a1 = (long double) (b / a);
  long double a2 = (long double) (c / a);
  long double a3 = (long double) (d / a);
  long double Q = (a1 * a1 - 3.0L * a2) / 9.0L;
  long double R = (2.0L * a1 * a1 * a1 - 9.0L * a1 * a2 + 27.0L * a3) / 54.0L;
  double R2_Q3 = (double) (R * R - Q * Q * Q);

  double theta;

  if (R2_Q3 <= 0)
    {
      *solutions = 3;
      theta = acos (((double) R) / sqrt ((double) (Q * Q * Q)));
      x[0] = -2.0 * sqrt ((double) Q) * cos (theta / 3.0) - a1 / 3.0;
      x[1] =
	-2.0 * sqrt ((double) Q) * cos ((theta + 2.0 * PI) / 3.0) - a1 / 3.0;
      x[2] =
	-2.0 * sqrt ((double) Q) * cos ((theta + 4.0 * PI) / 3.0) - a1 / 3.0;
    }
  else
    {
      *solutions = 1;
      x[0] = pow (sqrt (R2_Q3) + fabs ((double) R), 1 / 3.0);
      x[0] += ((double) Q) / x[0];
      x[0] *= (R < 0.0L) ? 1 : -1;
      x[0] -= (double) (a1 / 3.0L);
    }
}

// output_pos is a [48] array.
int loop(double a1, double *output_pos) {
	int solutions;
	for(double b1=10;b1>8;b1--) {
	  for(double c1=5;c1<6;c1+=0.5) {
            for(double d1=-1;d1>-3;d1--) {
	      SolveCubic(a1, b1, c1, d1, &solutions, output_pos);
            }
	  }
	}

	return solutions;
}
