tests: linked_list.o library.o main.o
	gcc -o tests main.o linked_list.o library.o

linked_list.o: linked_list.c linked_list.h library.h
	gcc -c linked_list.c

library.o: library.c linked_list.h
	gcc -c library.c

main.o: main.c linked_list.h
	gcc -c main.c

clean:
	rm *.o
	rm tests

run: tests
	./tests
