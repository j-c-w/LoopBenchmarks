
#include<math.h>
struct body
{
  double x[3], fill, v[3], mass;
};

double
loop (struct body *bodies, unsigned int nbodies)
{
  double dx[3], distance, e = 0.0;
  unsigned int i, j, k;

  for (i = 0; i < nbodies; ++i)
    {
      e += bodies[i].mass * (bodies[i].v[0] * bodies[i].v[0]
			     + bodies[i].v[1] * bodies[i].v[1]
			     + bodies[i].v[2] * bodies[i].v[2]) / 2.;

      for (j = i + 1; j < nbodies; ++j)
	{
	  for (k = 0; k < 3; ++k)
	    dx[k] = bodies[i].x[k] - bodies[j].x[k];

	  distance = sqrt (dx[0] * dx[0] + dx[1] * dx[1] + dx[2] * dx[2]);
	  e -= (bodies[i].mass * bodies[j].mass) / distance;
	}
    }
  return e;
}
