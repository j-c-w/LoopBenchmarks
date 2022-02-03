void loop (int loop, int n, double *x, double *z, double *y) {
	int l, i;
    for ( l=1 ; l<=loop ; l++ ) {
        for ( i=1 ; i<n ; i++ ) {
			// Is this CGRA acceleratable?  May be that dependency is too much?
            x[i] = z[i]*( y[i] - x[i-1] );
        }
    }
}
