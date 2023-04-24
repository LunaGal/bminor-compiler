# 
#
LEX = flex
BSN = bison
CC = clang
CFLAGS = -Wall -O
LFLAGS = 
RM = rm -f
LDFLAGS = -ll

parser_driver: parser.o parser_driver.o scanner.o ast_helpers.o
	$(CC) $(LDFLAGS) -o $@ $^

ast_helpers.o: ast_helpers.c
	$(CC) $(CFLAGS) -o $@ -c $^

parser_driver.o: parser_driver.c
	$(CC) $(CFLAGS) -o $@ -c $^

scanner_driver: scanner.o scanner_driver.o
	$(CC) $(LDFLAGS) -o $@ $^

scanner: scanner.o
	$(CC) $(LDFLAGS) -o $@ $^

scanner_driver.o: scanner_driver.c parser.tab.h
	$(CC) $(CFLAGS) -o $@ -c scanner_driver.c

scanner.o: scanner.c
	$(CC) $(CFLAGS) -o $@ -c $^

scanner.c: scanner.l parser.tab.h
	$(LEX) $(LFLAGS) -o $@ scanner.l

parser.o: parser.tab.c 
	$(CC) $(CFLAGS) -o $@ -c $^

parser.tab.c: parser.y
	$(BSN) -d parser.y

parser.tab.h: parser.tab.c
	@test -f $@ || rm -f parser.tab.c
	@test -f $@ || $(MAKE) $(AM_MAKEFLAGS) data.c

clean:
	$(RM) *.o scanner.c scanner parser.tab.h parser.tab.c