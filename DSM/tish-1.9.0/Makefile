# makefile for tish

FC	= ifort
FC	= gfortran
FFLAGS	= -O3
OBJS	= calmat.f trialf.f others.f dclisb.f dclisb3.f tish.f
tish: $(OBJS)
	$(FC) $(FFLAGS) $(OBJS) -o tish_etude
clean:
	rm -f tish
