void loop(int loop, int n, double *x, double *y) {
	int l, k;
	for ( l=1 ; l<=loop ; l++ ) {
        for ( k=0 ; k<n ; k++ ) {
            x[k] = y[k+1] - y[k];
        }
    }
}
