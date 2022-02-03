void loop(int loop, int n, double *x, double *u, double r, double *z, double *y) {
	int l, k;
    for ( l=1 ; l<=loop ; l++ ) {
#pragma nohazard
        for ( k=0 ; k<n ; k++ ) {
            x[k] = u[k] + r*( z[k] + r*y[k] ) +
                   t*( u[k+3] + r*( u[k+2] + r*u[k+1] ) +
                      t*( u[k+6] + r*( u[k+5] + r*u[k+4] ) ) );
        }
    }
}
