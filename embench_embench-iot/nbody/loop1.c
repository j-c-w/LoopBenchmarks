#define PI 3.14159
#define SOLAR_MASS ( 4 * PI * PI )
struct body
{
  double x[3], fill, v[3], mass;
};

void loop(struct body *bodies, unsigned int nbodies) {
	int i, k;
  for (i = 0; i < nbodies; ++i)
    for (k = 0; k < 3; ++k)
      bodies[0].v[k] -= bodies[i].v[k] * bodies[i].mass / SOLAR_MASS;
}
