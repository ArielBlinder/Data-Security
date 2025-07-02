# Data Security Algorithms

C implementations of cryptographic number theory algorithms.

## Programs

**Carmichael Number** - Check if a number is a Carmichael number

**Carmichael Number over** - Find next Carmichael number after input

**Prime Count** - Count primes in a range

**PrimeNumberNext** - Find next prime after input

**PrimitiveRoot** - Find primitive roots modulo a prime

## Building

```bash
# Build all programs
make

# Build specific program
make carmichael
make prime_count

# Clean up
make clean
```

## Running

```bash
cd "Program Directory"
./program_name
```

## Examples

```bash
# Check if 561 is Carmichael
cd "Carmichael Number"
./carmichael
# Input: 561
# Output: 561 is a Carmichael number.

# Count primes 1-100
cd "Prime Count"
./prime_count
# Input: 1 100
# Output: Number of prime numbers between 1 and 100: 25

# Find primitive root in Z_7 greater than 2
cd "PrimitiveRoot"
./primitive_root
# Input: p=7, X=2
# Output: The first primitive root of Z_7 that is greater than 2 is: 3
```

## License

MIT License
