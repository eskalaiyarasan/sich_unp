
.PHONY: debug release all clean

CC=gcc
AR=ar
INC=../include
CFLAGS= -Wall -I$(INC)
LIB_inc= -lunpwrap -lpthread
EXE=server
OUT=../output


all: debug release

debug: 
	@mkdir -p $(OUT)/debug
	$(CC) -c -g  *.c  $(CFLAGS) -L$(OUT)/lib/static   $(LIB_inc) -o $(OUT)/debug/$(EXE)
 	
release: 
	@mkdir -p $(OUT)/release
	$(CC) -c  *.c  $(CFLAGS) -L$(OUT)/lib/dynamic  $(LIB_inc) -o $(OUT)/release/$(EXE)


clean:
	rm -f *.o *.a *.so
	rm -f $(OUT)/debug/$(EXE)
	rm -f $(OUT)/release/$(EXE)

