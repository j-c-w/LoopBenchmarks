void loop(double *x, double *y, int loop, int n) {
	int l, k;
    for ( l=1 ; l<=loop ; l++ ) {
        x[0] = y[0];
        for ( k=1 ; k<n ; k++ ) {
            x[k] = x[k-1] + y[k];
        }
    }
}
