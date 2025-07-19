#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline void pyth_triples(int limit)
{
  for (long a = 1; a <= limit; a++) {
    for (long b = a; b <= limit; b++) {
      long c2 = (a * a) + (b * b);
      long c = (long) sqrt(c2); 
      
      if (c * c == c2 && c <= limit) {
        printf("(%ld, %ld, %ld)\n", a, b, c);
      }
    }
  }
}

inline void pyth_triples_filtered(int limit)
{
  for (long a = 1; a <= limit; a++) {
    for (long b = a; b <= limit; b++) {
      long c2 = (a * a) + (b * b);
      long c = (long) sqrt(c2); 
      
      if (c * c == c2 && c <= limit && b == c - 1) {
        printf("(%ld, %ld, %ld)\n", a, b, c);
      }
    }
  }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        puts("Usage: pythree <limit> <mode>");
        puts("Modes:\n 0 = all triples\n 1 = filtered (c = b + 1)");
        puts("Examples for modes:\n 0 - any pythagorean triples\n 1 - (5, 12, 13)");
        return 1;
    }

    int limit = atoi(argv[1]);
    int mode = atoi(argv[2]);

    if (limit <= 0) {
        puts("Limit must be positive");
        return 2;
    }

    puts("Pythagorean triples: a^2 + b^2 = c^2");
    puts("(a, b, c)\n");
    switch (mode) {
      case 0:
        puts("Mode: all triples");
        pyth_triples(limit);
        break;
      case 1:
        puts("Mode: filtered triples");
        pyth_triples_filtered(limit);
        break;
      default:
        puts("Invalid mode. Use 0, 1 or 2");
        return 3;
    }

    return 0;
}
