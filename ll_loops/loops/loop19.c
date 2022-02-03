#include<math.h>

void loop(int loop, int n, double *u, double *y, double *w, double *v, double *x) {
	doule expmax = 20.0;
    u[n-1] = 0.99*expmax*v[n-1];
    for ( l=1 ; l<=loop ; l++ ) {
        for ( k=0 ; k<n ; k++ ) {
            y[k] = u[k] / v[k];
            w[k] = x[k] / ( exp( y[k] ) -1.0 );
        }
    }
}
