all:
	cc -c userpath.c heap.c kd.c ./alphabet/alpha.c kdmain.c
	cc userpath.o heap.o kd.o ./alphabet/alpha.o kdmain.o -lm
run:
	./a.out
