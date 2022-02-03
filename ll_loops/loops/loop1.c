void loop(int loop, int n, doublt *x, double q, double *y, double r, double *z, double t) {
	int l, k;
	for ( l=1 ; l<=loop ; l++ ) {
        for ( k=0 ; k<n ; k++ ) {
            x[k] = q + y[k]*( r*z[k+10] + t*z[k+11] );
        }
    }
}
