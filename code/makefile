CC = gcc
CFLAGS = -w -g
INCLUDES = -lm
CMOCKA = -l cmocka

all: kaprekarDemo kaprekarTest kaprekarTestCmocka

kaprekarDemo: kaprekar_utils.o kaprekar_demo.c
	$(CC) $(CFLAGS) kaprekar_demo.c kaprekar_utils.o $(INCLUDES) -o kaprekarDemo

kaprekarTest: kaprekar_utils.o kaprekar_test.c
	$(CC) $(CFLAGS) kaprekar_test.c kaprekar_utils.o $(INCLUDES) -o kaprekarTest

kaprekarTestCmocka: kaprekar_utils.o kaprekar_test_cmocka.c
	$(CC) $(CFLAGS) kaprekar_test_cmocka.c kaprekar_utils.o $(INCLUDES) -o kaprekarTestCmocka $(CMOCKA)

kaprekarUtils.o: kaprekar_utils.c kaprekar_utils.h
	$(CC) $(CFLAGS) kaprekar_utils.c -c -o kaprekarUtils.o

clean:
	rm -f *.o *~ kaprekarDemo kaprekarTest kaprekarTestCmocka
