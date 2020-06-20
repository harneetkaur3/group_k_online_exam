Main: src/main.c

	gcc -g -O -c src/main.c -fPIC -DPIC -o obj/main.o
	
	gcc -g -O -c src/user_maintainance.c -fPIC -DPIC -o obj/user_maintainance.o
	
	gcc -g -O -c src/validation.c -fPIC -DPIC -o obj/validation.o
	
	gcc -g -O -c src/student.c -fPIC -DPIC -o obj/student.o
	
	gcc -g -O -c src/professor.c -fPIC -DPIC -o obj/professor.o
	
	gcc -o bin/Main obj/main.o obj/user_maintainance.o obj/validation.o obj/student.o obj/professor.o

	./bin/Main
