tests: linked_list.o music_library.o main.o
	gcc -o tests main.o linked_list.o music_library.o

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

music_library.o: music_library.c linked_list.h music_library.h
	gcc -c music_library.c

main.o: main.c linked_list.h music_library.h
	gcc -c main.c

clean:
	rm *.o
	rm tests

run: tests
	./tests
