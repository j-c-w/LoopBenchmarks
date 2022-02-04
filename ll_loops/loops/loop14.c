void loop (int loop, int n, double *vx, double *xx, long *ix, double * xi, double *ex1, double *dex1, double *dex, int *ir, double *rx, double *rh, double flx, double *ex, long *grd) {
	int l, k;
	// TODO -- should these be broken up into separate loops?
    for ( l=1 ; l<=loop ; l++ ) {
        for ( k=0 ; k<n ; k++ ) {
            vx[k] = 0.0;
            xx[k] = 0.0;
            ix[k] = (long) grd[k];
            xi[k] = (double) ix[k];
            ex1[k] = ex[ ix[k] - 1 ];
            dex1[k] = dex[ ix[k] - 1 ];
        }
        for ( k=0 ; k<n ; k++ ) {
            vx[k] = vx[k] + ex1[k] + ( xx[k] - xi[k] )*dex1[k];
            xx[k] = xx[k] + vx[k]  + flx;
            ir[k] = xx[k];
            rx[k] = xx[k] - ir[k];
            ir[k] = ( ir[k] & 2048-1 ) + 1;
            xx[k] = rx[k] + ir[k];
        }
        for ( k=0 ; k<n ; k++ ) {
            rh[ ir[k]-1 ] += 1.0 - rx[k];
            rh[ ir[k]   ] += rx[k];
        }
    }
}
