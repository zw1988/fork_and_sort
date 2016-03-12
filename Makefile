CCFLAG = -g -std=c99 -Wall -Werror

all : multiprocess merge_sort heap_sort quick_sort runprogram

util.o : util.h util.c
	cc -c $(CCFLAG) util.c

sortobj = merge_sort.o heap_sort.o quick_sort.o
$(sortobj) : %.o : %.c util.h
	cc -c $(CCFLAG)  $<

sortexc = merge_sort heap_sort quick_sort
$(sortexc) : % : %.o util.o
	cc  util.o $<  -o $@

multiprocess :  multiprocess.c util.h
	cc $(CCFLAG) multiprocess.c -o multiprocess 

runprogram:
	./multiprocess

clean:
	rm *.o  *.data
