# Algorithmic Efficiency Comparison

Compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 comparison_algorithms.c -o comparison_algorithms`

Note: the two results differ (naive: 625025000, single-pass: 25000) because the naive version re-counts every even element once per outer iteration; the source logic was left unmodified.
Array size: 50000. Naive = nested loop (O(n^2)), single-pass = one loop (O(n)).

## Raw results (seconds)

| Run | Naive algorithm | Single-pass algorithm |
|-----|-----------------|-----------------------|
| 1 | 2.767784 | 0.000106 |
| 2 | 2.758813 | 0.000106 |
| 3 | 2.758293 | 0.000106 |
| 4 | 2.757620 | 0.000106 |
| 5 | 2.774124 | 0.000106 |

## Averages

- Naive algorithm: 2.763327 seconds
- Single-pass algorithm: 0.000106 seconds

## Relative difference

The naive algorithm is ~26069 times slower than the single-pass algorithm (2.763327 / 0.000106).
