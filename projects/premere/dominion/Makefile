CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: unittestresults

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c rngs.c
	echo "unittest1.c results: " >> unittestresults.out
	gcc -o unittest1 -g unittest1.c dominion.c rngs.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest2.c results: " >> unittestresults.out
	gcc -o unittest2 -g unittest2.c dominion.c rngs.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest3.c results: " >> unittestresults.out
	gcc -o unittest3 -g unittest3.c dominion.c rngs.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest4.c results: " >> unittestresults.out
	gcc -o unittest4 -g unittest4.c dominion.c rngs.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out
 
	echo "unittest5.c results: " >> unittestresults.out
	gcc -o unittest5 -g unittest5.c dominion.c rngs.c $(CFLAGS)
	./unittest5 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out
	
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
