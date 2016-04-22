//
// turns the polynominal expression of PREM
// density and velocity into a layered form
//
// lower mantle only, so only isotropic velocities
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

main( argc, argv )
int   argc;
char *argv[];

{

FILE *fp;
char ss[80];


// prem.poly:
//  - Radius(km) -     --- Density (g/cm^3)---
//                     ---   Vpv     (km/s) ---
//                     ---   Vph     (km/s) ---
//                     ---   Vsv     (km/s) ---
//                     ---   Vsh     (km/s) ---
//
// 3480.0   3630.0     7.9565  -6.4761   5.5283  -3.0807
//                    15.3891  -5.3181   5.5242  -2.5514
//                    15.3891  -5.3181   5.5242  -2.5514
//                     6.9254   1.4672  -2.0834   0.9783
//                     6.9254   1.4672  -2.0834   0.9783
//                     1.0000   0.0000   0.0000   0.0000   312.0   57823.0
// 3630.0   5600.0     7.9565  -6.4761   5.5283  -3.0807
//                    24.9520 -40.4673  51.4832 -26.6419
//                    24.9520 -40.4673  51.4832 -26.6419
//                    11.1671 -13.7818  17.4575  -9.2777
//                    11.1671 -13.7818  17.4575  -9.2777
//                     1.0000   0.0000   0.0000   0.0000   312.0   57823.0

int i,j,nl;

float a = 6371.;
float r, v, rad;
float rho, vpv, vph, vsv, vsh;
float r1[2];	// radius1
float r2[2];	// radius2
float rho0[2], rho1[2], rho2[2], rho3[2];
float vpv0[2], vpv1[2], vpv2[2], vpv3[2];
float vph0[2], vph1[2], vph2[2], vph3[2];
float vsv0[2], vsv1[2], vsv2[2], vsv3[2];
float vsh0[2], vsh1[2], vsh2[2], vsh3[2];

r1[0]  = 3480.; r2[0] = 3630.;
rho0[0]=   7.9565; rho1[0]=  -6.4761; rho2[0]=   5.5283; rho3[0]=  -3.0807;
vpv0[0]=  15.3891; vpv1[0]=  -5.3181; vpv2[0]=   5.5242; vpv3[0]=  -2.5514;
vph0[0]=  15.3891; vph1[0]=  -5.3181; vph2[0]=   5.5242; vph3[0]=  -2.5514;
vsv0[0]=   6.9254; vsv1[0]=   1.4672; vsv2[0]=  -2.0834; vsv3[0]=   0.9783;
vsh0[0]=   6.9254; vsh1[0]=   1.4672; vsh2[0]=  -2.0834; vsh3[0]=   0.9783;

r1[1]  = 3630.; r2[1] = 5600.;
rho0[1]=   7.9565; rho1[1]=  -6.4761; rho2[1]=   5.5283; rho3[1]=  -3.0807;
vpv0[1]=  24.9520; vpv1[1]= -40.4673; vpv2[1]=  51.4832; vpv3[1]= -26.6419;
vph0[1]=  24.9520; vph1[1]= -40.4673; vph2[1]=  51.4832; vph3[1]= -26.6419;
vsv0[1]=  11.1671; vsv1[1]= -13.7818; vsv2[1]=  17.4575; vsv3[1]=  -9.2777;
vsh0[1]=  11.1671; vsh1[1]= -13.7818; vsh2[1]=  17.4575; vsh3[1]=  -9.2777;

nl = 2;

for (i=3480;i<3640; i=i+20) {
  rad = i*1.;
  r   = rad/a;
  // find the layer for this radius
  for(j=0;j<nl;j++) {
    if ( rad>= r1[j] && rad<=r2[j]) {
      break;
    }
  }
  rho = rho0[j] + rho1[j]*r + rho2[j]*r*r + rho3[j]*r*r*r; 
  vph = vph0[j] + vph1[j]*r + vph2[j]*r*r + vph3[j]*r*r*r; 
  vpv = vpv0[j] + vpv1[j]*r + vpv2[j]*r*r + vpv3[j]*r*r*r; 
  vsv = vsv0[j] + vsv1[j]*r + vsv2[j]*r*r + vsv3[j]*r*r*r; 
  vsh = vsh0[j] + vsh1[j]*r + vsh2[j]*r*r + vsh3[j]*r*r*r; 
  fprintf(stdout,"%f %f %f %f\n",  rad, rho, vpv, vsv);
}
for (i=3640;i<5440; i=i+100) {
  rad = i*1.;
  r   = rad/a;
  // find the layer for this radius
  for(j=0;j<nl;j++) {
    if ( rad>= r1[j] && rad<=r2[j]) {
      break;
    }
  }
  rho = rho0[j] + rho1[j]*r + rho2[j]*r*r + rho3[j]*r*r*r; 
  vph = vph0[j] + vph1[j]*r + vph2[j]*r*r + vph3[j]*r*r*r; 
  vpv = vpv0[j] + vpv1[j]*r + vpv2[j]*r*r + vpv3[j]*r*r*r; 
  vsv = vsv0[j] + vsv1[j]*r + vsv2[j]*r*r + vsv3[j]*r*r*r; 
  vsh = vsh0[j] + vsh1[j]*r + vsh2[j]*r*r + vsh3[j]*r*r*r; 
  fprintf(stdout,"%f %f %f %f\n",  rad, rho, vpv, vsv);
}
rad = 5600.;
r   = rad/a;
// find the layer for this radius
for(j=0;j<nl;j++) {
  if ( rad>= r1[j] && rad<=r2[j]) {
    break;
  }
}
rho = rho0[j] + rho1[j]*r + rho2[j]*r*r + rho3[j]*r*r*r; 
vph = vph0[j] + vph1[j]*r + vph2[j]*r*r + vph3[j]*r*r*r; 
vpv = vpv0[j] + vpv1[j]*r + vpv2[j]*r*r + vpv3[j]*r*r*r; 
vsv = vsv0[j] + vsv1[j]*r + vsv2[j]*r*r + vsv3[j]*r*r*r; 
vsh = vsh0[j] + vsh1[j]*r + vsh2[j]*r*r + vsh3[j]*r*r*r; 
fprintf(stdout,"%f %f %f %f\n",  rad, rho, vpv, vsv);

}
