# makefile for spcsac

#- old
CC = /opt/intel/cc/9.0/bin/icc
CFLAGS = -L/usr/lib -g

#- Jeroen Ritsema
#- no debugging
CC = gcc
CFLAGS = -L/usr/lib
OBJS = spcsac.o

all:
	make spcsac

spcsac: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o spcsac;
.c.o: 
	$(CC) -c $(FFLAGS) $<

clean:
	rm -f $(OBJS) spcsac

