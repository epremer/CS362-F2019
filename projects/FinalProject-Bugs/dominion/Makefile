CFLAGS= -Wall -fpic -coverage -lm -std=c99

unittest1: unittest_1.c dominion.o rngs.o 
	gcc -o unittest1 -g  unittest_1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest_2.c dominion.o rngs.o 
	gcc -o unittest2 -g  unittest_2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest_3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest_3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest_4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest_4.c dominion.o rngs.o $(CFLAGS)

unittest5: unittest_5.c dominion.o rngs.o
	gcc -o unittest5 -g  unittest_5.c dominion.o rngs.o $(CFLAGS)

unittest6: unittest_6.c dominion.o rngs.o
	gcc -o unittest6 -g  unittest_6.c dominion.o rngs.o $(CFLAGS)

unittest7: unittest_7.c dominion.o rngs.o
	gcc -o unittest7 -g  unittest_7.c dominion.o rngs.o $(CFLAGS)

unittest8: unittest_8.c dominion.o rngs.o
	gcc -o unittest8 -g  unittest_8.c dominion.o rngs.o $(CFLAGS)

unittest9: unittest_9.c dominion.o rngs.o
	gcc -o unittest9 -g  unittest_9.c dominion.o rngs.o $(CFLAGS)

unittest10: unittest_10.c dominion.o rngs.o
	gcc -o unittest10 -g  unittest_10.c dominion.o rngs.o $(CFLAGS)

unittest11: unittest_11.c dominion.o rngs.o
	gcc -o unittest11 -g  unittest_11.c dominion.o rngs.o $(CFLAGS)

unittests: unittest1 unittest2 unittest3 unittest4 unittest5 unittest6 unittest7 unittest8 unittest9 unittest10 unittest11

unittestresults: unittests
	./unittest1 &> unittestresult.out
	./unittest2 &> unittestresult.out
	./unittest3 &> unittestresult.out
	./unittest4 &> unittestresult.out
	./unittest5 &> unittestresult.out
	./unittest6 &> unittestresult.out
	./unittest7 &> unittestresult.out
	./unittest8 &> unittestresult.out
	./unittest9 &> unittestresult.out
	./unittest10 &> unittestresult.out
	./unittest11 &> unittestresult.out
	gcov dominion.c -b -f >> unittestresult.out
	
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
