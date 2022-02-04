void loop6(int loop, int n, double *w, double **b) {
	int l, k, i;
    for ( l=1 ; l<=loop ; l++ ) {
        for ( i=1 ; i<n ; i++ ) {
            for ( k=0 ; k<i ; k++ ) {
                w[i] += b[k][i] * w[(i-k)-1];
            }
        }
    }
}
