Main: main.c
	gcc -g -O -c src/main.c -fPIC -DPIC -o obj/main.o
	
	gcc -g -O -c src/user_maintainance.c -fPIC -DPIC -o obj/user_maintainance.o
	
	gcc -o bin/Main obj/main.o obj/user_maintainance.o

	./bin/Main
