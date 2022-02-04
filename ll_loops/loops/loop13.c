void loop(int loop, int n, int **p, int *y, int *z, int *e, int *f, double **h, double **c, double **b) {
	int l, ip, i1, j1, i2, j2;
    for ( l=1 ; l<=loop ; l++ ) {
        for ( ip=0 ; ip<n ; ip++ ) {
            i1 = p[ip][0];
            j1 = p[ip][1];
            i1 &= 64-1;
            j1 &= 64-1;
            p[ip][2] += b[j1][i1];
            p[ip][3] += c[j1][i1];
            p[ip][0] += p[ip][2];
            p[ip][1] += p[ip][3];
            i2 = p[ip][0];
            j2 = p[ip][1];
            i2 = ( i2 & 64-1 ) - 1 ;
            j2 = ( j2 & 64-1 ) - 1 ;
            p[ip][0] += y[i2+32];
            p[ip][1] += z[j2+32];
            i2 += e[i2+32];
            j2 += f[j2+32];
            h[j2][i2] += 1.0;
        }
    }

}
