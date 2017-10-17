org_test: linked_list.o organizer.o
	gcc -o org_test linked_list.o organizer.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

organizer.o: organizer.c linked_list.h
	gcc -c organizer.c

clean:
	rm lists
	rm *~
	rm *.o

run: all
	./lists
