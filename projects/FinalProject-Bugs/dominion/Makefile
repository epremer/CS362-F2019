CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: unittestresults

unittestresults: unittest_lizz.c unittest_helen.c unittest_rob.c dominion.c rngs.c
	echo "unittest_lizz.c results: " >> unittestresults.out
	gcc -o unittest_lizz -g unittest_lizz.c dominion.c rngs.c $(CFLAGS)
	./unittest_lizz >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest_helen.c results: " >> unittestresults.out
	gcc -o unittest_helen -g unittest_helen.c dominion.c rngs.c $(CFLAGS)
	./unittest_helen >> unittestresults.out
	gcov dominion.c -f -b -c >> unittestresults.out

	echo "unittest_rob.c results: " >> unittestresults.out
	gcc -o unittest_rob -g unittest_rob.c dominion.c rngs.c $(CFLAGS)
	./unittest_rob >> unittestresults.out
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
