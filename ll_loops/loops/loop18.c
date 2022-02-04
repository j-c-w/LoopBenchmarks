void loop(int loop, int n, double **px, double **vy, double **cx) {
	int l, k, i;
	int j;
    for ( l=1 ; l<=loop ; l++ ) {
        for ( k=0 ; k<25 ; k++ ) {
            for ( i=0 ; i<25 ; i++ ) {
#pragma nohazard
                for ( j=0 ; j<n ; j++ ) {
                    px[j][i] += vy[k][i] * cx[j][k];
                }
            }
        }
    }
}
