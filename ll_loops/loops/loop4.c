void loop (int loop, int n, double *x, double *y) {
    int m = ( 1001-7 )/2;
	int l, k, lw, j;
	double temp;
    for ( l=1 ; l<=loop ; l++ ) {
        for ( k=6 ; k<1001 ; k=k+m ) {
            lw = k - 6;
            temp = x[k-1];
#pragma nohazard
            for ( j=4 ; j<n ; j=j+5 ) {
                temp -= x[lw]*y[j];
                lw++;
            }
            x[k-1] = y[4]*temp;
        }
    }
}
