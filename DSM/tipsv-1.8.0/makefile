# makefile .fr tipsv

FC	= ifort
FC	= gfortran
FFLAGS	= -O3
OBJS	= calmat.f trialf.f others.f rk3.f glu2.f dcsymbdl0.f dcsymbdl.f tipsv.f

tipsv: $(OBJS)
	$(FC) $(FFLAGS) $(OBJS)  -o tipsv

clean:
	rm -f tipsv
