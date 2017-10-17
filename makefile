all: linked_list.c linkedlist.h
	gcc -o lists linked_list.c

run: all
	./lists

clean:
	rm lists
	rm *~
	rm *.o
 
