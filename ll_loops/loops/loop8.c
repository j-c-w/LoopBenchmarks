void loop(int loop, int n, double *du1, double *du2, double *du3, double ***u1, double ***u2, double ***u3, double a31, double a32, double a33, double a13, double a12, double a11, double a21, double a22, double a23, double sig) {
	int l, kx, ky;
	int nl1, nl2;
    for ( l=1 ; l<=loop ; l++ ) {
        nl1 = 0;
        nl2 = 1;
        for ( kx=1 ; kx<3 ; kx++ ){
#pragma nohazard
            for ( ky=1 ; ky<n ; ky++ ) {
               du1[ky] = u1[nl1][ky+1][kx] - u1[nl1][ky-1][kx];
               du2[ky] = u2[nl1][ky+1][kx] - u2[nl1][ky-1][kx];
               du3[ky] = u3[nl1][ky+1][kx] - u3[nl1][ky-1][kx];
               u1[nl2][ky][kx]=
                  u1[nl1][ky][kx]+a11*du1[ky]+a12*du2[ky]+a13*du3[ky] + sig*
                     (u1[nl1][ky][kx+1]-2.0*u1[nl1][ky][kx]+u1[nl1][ky][kx-1]);
               u2[nl2][ky][kx]=
                  u2[nl1][ky][kx]+a21*du1[ky]+a22*du2[ky]+a23*du3[ky] + sig*
                     (u2[nl1][ky][kx+1]-2.0*u2[nl1][ky][kx]+u2[nl1][ky][kx-1]);
               u3[nl2][ky][kx]=
                  u3[nl1][ky][kx]+a31*du1[ky]+a32*du2[ky]+a33*du3[ky] + sig*
                     (u3[nl1][ky][kx+1]-2.0*u3[nl1][ky][kx]+u3[nl1][ky][kx-1]);
            }
        }
    }

}
