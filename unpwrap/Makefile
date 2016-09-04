
.PHONY: static dynamic all clean

CC=gcc
AR=ar
INC=../include
CFLAGS= -Wall -I$(INC)
OUT=../output/lib

all: static dynamic

static: 
	@mkdir -p $(OUT)/static
	$(CC) -c -fPIC *.c  $(CFLAGS)
	$(AR) -cvq $(OUT)/static/libunpwrap.a *.o
 	
dynamic: 
	@mkdir -p $(OUT)/dynamic
	$(CC) -c -fPIC  *.c  $(CFLAGS)
	$(CC) -shared -o $(OUT)/dynamic/libunwrap.so *.o

clean:
	rm -f *.o *.a *.so
	rm -f $(OUT)/static/libunpwrap.a 
	rm -f $(OUT)/dynamic/libunpwrap.so
