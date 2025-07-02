CC = gcc
CFLAGS = -O2 -Wall

all: carmichael next_carmichael prime_count next_prime primitive_root

carmichael:
	cd "Carmichael Number" && $(CC) $(CFLAGS) -o carmichael main.c

next_carmichael:
	cd "Carmichael Number over" && $(CC) $(CFLAGS) -o next_carmichael main.c

prime_count:
	cd "Prime Count" && $(CC) $(CFLAGS) -o prime_count main.c

next_prime:
	cd "PrimeNumberNext" && $(CC) $(CFLAGS) -o next_prime main.c

primitive_root:
	cd "PrimitiveRoot" && $(CC) $(CFLAGS) -o primitive_root main.c

clean:
	find . -name "*.exe" -delete 2>/dev/null || true
	find . -name "carmichael" -delete 2>/dev/null || true
	find . -name "next_carmichael" -delete 2>/dev/null || true
	find . -name "prime_count" -delete 2>/dev/null || true
	find . -name "next_prime" -delete 2>/dev/null || true
	find . -name "primitive_root" -delete 2>/dev/null || true 