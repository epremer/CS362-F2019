CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: unittestresults

unittestresults: unittest_9.c unittest_10.c unittest_11.c dominion.c rngs.c
	echo "unittest_9.c results: " >> unittestresults.out
	gcc -o unittest_9 -g unittest_9.c dominion.c rngs.c $(CFLAGS)
	./unittest_9 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out


	echo "unittest_10.c results: " >> unittestresults.out
	gcc -o unittest_10 -g unittest_10.c dominion.c rngs.c $(CFLAGS)
	./unittest_10 >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest_11.c results: " >> unittestresults.out
	gcc -o unittest_11 -g unittest_11.c dominion.c rngs.c $(CFLAGS)
	./unittest_11 >> unittestresults.out
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
