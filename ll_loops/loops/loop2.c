void loop(int loop, int n, double *x, double *v) {
	int l, k, ii, i;
	int ipntp;
	int ipnt;
    for ( l=1 ; l<=loop ; l++ ) {
        ii = n;
        ipntp = 0;
        do {
            ipnt = ipntp;
            ipntp += ii;
            ii /= 2;
            i = ipntp - 1;
#pragma nohazard
            for ( k=ipnt+1 ; k<ipntp ; k=k+2 ) {
                i++;
                x[i] = x[k] - v[k  ]*x[k-1] - v[k+1]*x[k+1];
            }
        } while ( ii>0 );
    }
}
