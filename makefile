# 
#
LEX = flex
CC = clang
CFLAGS = -Wall -O
LFLAGS = 
RM = rm -f
LDFLAGS = -ll
scanner_driver: scanner.o 

scanner: scanner.o
	$(CC) $(LDFLAGS) -o $@ $^

scanner.o: scanner.c
	$(CC) $(CFLAGS) -o $@ -c $^

scanner.c: scanner.l
	$(LEX) $(LFLAGS) -o $@ $^

clean:
	$(RM) *.o scanner.c scanner