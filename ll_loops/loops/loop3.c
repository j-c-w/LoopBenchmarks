void (int loop, int n, double *z, double *x) {
	double q;
	int l, k;
    for ( l=1 ; l<=loop ; l++ ) {
        q = 0.0;
        for ( k=0 ; k<n ; k++ ) {
            q += z[k]*x[k];
        }
    }
}
