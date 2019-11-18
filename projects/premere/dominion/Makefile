CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: randomtestresults

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c rngs.c
	echo "randomtestcard1.c results: " >> randomtestresults.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov dominion.c -f -b -c >> randomtestresults.out

	echo "randomtestcard2.c results: " >> randomtestresults.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov dominion.c -f -b -c >> randomtestresults.out

	echo "randomtestcard3.c results: " >> randomtestresults.out
	gcc -o randomtestcard3 -g randomtestcard3.c dominion.c rngs.c $(CFLAGS)
	# ./randomtestcard3 >> randomtestresults.out
	gcov dominion.c -f -b -c >> randomtestresults.out

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
