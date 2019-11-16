CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: testme

testme: testme.c
	echo "testme.c results: " >> testme.out
	gcc -o testme -g testme.c $(CFLAGS)
	./testme >> testme.out
	
withgcov:
	gcov testme.c -f -b -c >> testme.out


clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out