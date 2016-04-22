//
// calc -
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


//  3800.0000   3900.0000   10.3543   -5.3071   0.0000   0.0000

int i,j,nl;

float a = 6371.;
float r, v, rad;
float r1[50];	// radius1
float r2[50];	// radius2
float x0[50];
float x1[50];
float x2[50];
float x3[50];

if ( (fp = fopen(argv[1],"r")) == NULL )
  fprintf(stderr,"Error opening %s\n", argv[1]);
j=0;
while (fgets(ss,80,fp) != NULL) {
   sscanf(ss,"%f %f   %f %f %f %f",&r1[j],&r2[j], &x0[j],&x1[j],&x2[j],&x3[j]);
   j = j+1;
}
nl = j-1;

for (i=348;i<630; i++) {
  rad = i*10.;
  r   = rad/a;
  // find the layer for this radius
  for(j=0;j<nl;j++) {
    if ( rad>= r1[j] && rad<r2[j]) {
      break;
    }
  }
  v = x0[j] + x1[j]*r + x2[j]*r*r + x3[j]*r*r*r; 
  fprintf(stdout,"rad= %f j= %d v= %f\n", rad, j, v);
}

}
