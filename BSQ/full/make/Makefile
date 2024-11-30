bsq: main.o solver.o fileops.o gridops.o validation.o bools.o
	gcc -Wall -Wextra -Werror -o bsq main.o solver.o fileops.o gridops.o validation.o bools.o

main.o: main.c bsq.h
	gcc -Wall -Wextra -Werror -c main.c

solver.o: solver.c bsq.h
	gcc -Wall -Wextra -Werror -c solver.c

fileops.o: fileops.c bsq.h
	gcc -Wall -Wextra -Werror -c fileops.c

gridops.o: gridops.c bsq.h
	gcc -Wall -Wextra -Werror -c gridops.c

validation.o: validation.c bsq.h
	gcc -Wall -Wextra -Werror -c validation.c

bools.o: bools.c bsq.h
	gcc -Wall -Wextra -Werror -c bools.c

clean:
	rm -f *.o

fclean: clean
	rm -f bsq
