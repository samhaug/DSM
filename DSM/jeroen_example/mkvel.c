//
// make a velocity model as part of the
// input file for tish.f (SH) and tipsv.f (PSV)
//
// for lower mantle
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

main( argc, argv )
int   argc;
char *argv[];
{

char velmodel[20];
char ss[80];

FILE *fp, *f_sv, *f_sh;

int i=0;
int nlines;

float Qm = 312.;   // Qmu of the lower mantle
float Qk = 57823.; // Qkappa of the lower mantle
float rho0, rho1, vph0, vph1, vsh0, vsh1;

float rad[100];	// radius
float rho[100];	// rho
float vph[100];	// P velocity
float vsh[100];	// S velocity

if (argc != 4) {
   fprintf(stderr,"Usage: mkvel VELMODEL out_PSV out_SH\n");
   exit(-1);
}

if ( (fp = fopen(argv[1],"r" )) == NULL) {
   fprintf(stderr,"%s cannot be opened ...\n", argv[1]);
   exit(-1);
}
if ( (f_sv = fopen(argv[2],"w" )) == NULL) {
   fprintf(stderr,"%s cannot be opened ...\n", argv[2]);
   exit(-1);
}
if ( (f_sh = fopen(argv[3],"w" )) == NULL) {
   fprintf(stderr,"%s cannot be opened ...\n", argv[3]);
   exit(-1);
}

while (fgets(ss,80,fp) != NULL) {
  sscanf(ss,"%f %f %f %f", &rad[i], &rho[i], &vph[i], &vsh[i]);
  i = i+1;
}
nlines = i-1;
//fprintf(stdout,"N= %d\n", nlines);

for (i=0; i<nlines; i++) {
  if ( linearize(rad[i],rho[i],rad[i+1],rho[i+1],&rho1,&rho0) )
     fprintf(f_sv,"%9.1f  %7.1f  %9.4f %8.4f %8.4f %8.4f\n",rad[i],rad[i+1],rho0,rho1,0.,0.);
     fprintf(f_sh,"%9.1f  %7.1f  %9.4f %8.4f %8.4f %8.4f\n",rad[i],rad[i+1],rho0,rho1,0.,0.);
  if ( linearize(rad[i],vph[i],rad[i+1],vph[i+1],&vph1,&vph0) )
     fprintf(f_sv,"%29.4f %8.4f %8.4f %8.4f\n",                             vph0,vph1,0.,0.);
     fprintf(f_sv,"%29.4f %8.4f %8.4f %8.4f\n",                             vph0,vph1,0.,0.);
  if ( linearize(rad[i],vsh[i],rad[i+1],vsh[i+1],&vsh1,&vsh0) )
     fprintf(f_sv,"%29.4f %8.4f %8.4f %8.4f\n",                             vsh0,vsh1,0.,0.);
     fprintf(f_sv,"%29.4f %8.4f %8.4f %8.4f\n",                             vsh0,vsh1,0.,0.);
     fprintf(f_sv,"%29.4f %8.4f %8.4f %8.4f  %5.1f  %7.1f\n",               1.,0.,0.,0.,Qm,Qk);
     fprintf(f_sh,"%29.4f %8.4f %8.4f %8.4f\n",                             vsh0,vsh1,0.,0.);
     fprintf(f_sh,"%29.4f %8.4f %8.4f %8.4f  %5.1f\n",                      vsh0,vsh1,0.,0.,Qm);
}

}

// find the line y=ax+b for between (R1,z1) and (R2,z2)

int linearize(R1,z1,R2,z2,a,b)
float R1,z1,R2,z2, *a, *b;
{

float Ra = 6371.;
float dR = 6371.;
float slope=0, interc=0;
*a = 0.;
*b = 0.;

dR = R2-R1;

if ( (fabsf(dR)) < 0.000001) {
   if ( (fabs(z2-z1) < 0.000001) ) {
     fprintf(stderr,"In linearize().... (R1,z1) == (R2,z2)\n");
     return(0);
   } else {
     fprintf(stderr,"In linearize().... R1 (%f) == R2 (%f)\n", R1,R2);
     return(0);
   }
}

//fprintf(stdout,"in linearize R1,R2,z1,z2= %f %f %f %f\n", R1,z1,R2,z2);
slope  = (z2 - z1)  *Ra/dR;
interc =  z2 - slope*R2/Ra;

*a = slope;
*b = interc;

return(1);
}
