*This activity has been created as part of the 42 curriculum by omajarad, yal-sale.*

# push_swap

## Description

**push_swap** sorts a list of unique integers using two stacks, `a` and `b`, and a limited set of operations. The program does not sort the numbers directly: it prints, on the standard output, a sequence of operations (one per line) that, when applied to stack `a`, leaves it sorted in ascending order with the smallest number on top. The goal is to discover algorithmic complexity in a concrete way: the cost of an algorithm is measured in the **number of push_swap operations generated**, not in CPU time.

The operations available are:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both (first element becomes last) |
| `rra` / `rrb` / `rrr` | reverse rotate `a` / `b` / both (last element becomes first) |

The binary embeds **four strategies**, selectable at runtime:

| Selector | Strategy | Complexity (in operations) |
|----------|----------|----------------------------|
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sort (≈ √n chunks) | O(n√n) |
| `--complex` | LSD radix sort on ranks | O(n log n) |
| `--adaptive` *(default)* | Chooses one of the three above from the measured **disorder** | depends on the regime |

### Contributions

- **yal-sale**: the stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) and the three sorting algorithms: simple, medium and complex.
- **omajarad**: the parser (argument validation, error handling), the disorder computation, the benchmark mode (`--bench`) and the adaptive algorithm.

Both learners reviewed the whole project and can explain any part of the code.

## Instructions

### Compilation

The `Makefile` builds the project as a **static library** (`push_swap.a`) with `cc -Wall -Wextra -Werror`. It provides the rules `all`, `clean`, `fclean`, `re` and does not relink.

```sh
make                                                    # builds push_swap.a
cc -Wall -Wextra -Werror main.c push_swap.a -o push_swap   # links the executable
```

### Execution

```sh
./push_swap [strategy selector] [--bench] <integers...>
```

- The first integer is the **top** of stack `a`.
- Operations are printed on **stdout**, separated by `\n`.
- If no argument is given, nothing is displayed.
- On any error (non-integer argument, integer outside the `int` range, duplicate value, invalid flag usage), `Error\n` is printed on **stderr**.

### Usage of the flags

- The program accepts **at most 2 flags**: one strategy selector (`--simple`, `--medium`, `--complex` or `--adaptive`) and/or the benchmark flag `--bench`.
- The flags **must be placed before the integers**. A flag in any other position (for example after or between the integers) is treated as an argument that is not an integer, and produces `Error`.
- Two strategy selectors at the same time (for example `--simple --medium`) are an error.
- If no selector is given, `--adaptive` is used.

### Benchmark mode

With `--bench`, the following is printed on **stderr** after sorting (the operations remain on stdout):

- the computed disorder (as a percentage with two decimals);
- the name of the strategy used and its complexity class;
- the total number of operations;
- the count of each operation type.

### Examples

```sh
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
$> ./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt(n))
[bench] total_ops: 17
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 3 rr: 0 rra: 0 rrb: 2 rrr: 0
$> ./push_swap --adaptive 0 one 2 3
Error
$> ./push_swap 3 2 3
Error
$> ./push_swap 3 2 1 --simple
Error
```

## Algorithms

### Disorder metric

The disorder is a number between 0 (sorted) and 1 (reverse sorted). It is computed **before any move** by counting, over all pairs `(i, j)` with `i < j`, the pairs where `a[i] > a[j]` (the "mistakes"), divided by the total number of pairs `n(n-1)/2`. This costs O(n²) comparisons and O(n) temporary memory, but **generates no push_swap operation**, so it does not count in the operation model.

### Simple: selection sort, O(n²)

*Principle.* Repeatedly find the minimum of stack `a`, bring it to the top using the shortest rotation (`ra` if it is in the upper half, `rra` otherwise), and push it to `b` with `pb`. When `a` is empty, push everything back with `pa`. Since each element is pushed in increasing order onto `b`, the largest ends at the bottom and the smallest on top after the final `pa`s, so `a` ends up sorted. If the minimum is the second element, a single `sa` is used instead of a rotation.

*Why this one.* It is the simplest baseline, it is easy to prove correct, and it requires no preprocessing.

*Complexity (operations).* For each of the n elements: at most ⌊n/2⌋ rotations + 1 `pb`. Then n `pa`. Total ≤ n²/2 + 2n = **O(n²)**. *Space:* O(1) auxiliary beyond the two stacks (which together hold n nodes).

### Medium: chunk-based sort, O(n√n)

*Principle.* Each element is first replaced by its **rank** (0 to n-1) in a field of the node, so the algorithm works on a permutation. The ranks are split into chunks of size `c = 1.5·⌊√n⌋`.
1. **Phase 1:** scan `a`. If the top element belongs to the current chunk (rank < `chunk_max`), push it to `b` with `pb`; if it belongs to the lower half of the chunk it is also rotated to the bottom of `b` with `rb`. Otherwise rotate `a` with `ra`. When a chunk is fully pushed, `chunk_max` grows by `c`.
2. **Phase 2:** while `b` is not empty, find the maximum of `b`, bring it to the top using the shortest rotation (`rb` or `rrb`), and push it to `a` with `pa`. Since the maximum is always pushed first, `a` ends sorted.

*Why this one.* It gives a very good operation count (roughly 700 for 100 numbers and 6300 for 500 numbers on random input) with a simple structure, and it matches the O(n√n) class required by the subject.

*Complexity (operations).*
- Phase 1: there are about n/c = O(√n) chunks, and while filling a chunk, `a` is rotated at most once around (≤ n `ra`). So ≤ (n/c)·n = O(n√n) `ra`, plus n `pb` and at most n `rb`.
- Phase 2: after phase 1, `b` is organised by chunks (larger chunks closer to the top, the lower half of each chunk pushed down). The next maximum is therefore always within O(c) = O(√n) positions of an end of `b`, so each element costs O(√n) rotations plus one `pa`. Total O(n√n).
- Overall: **O(n√n)** operations (this is an upper-bound argument, supported by measurements).

*Space:* O(1) auxiliary beyond the stacks (the ranks are stored in the nodes).

### Complex: LSD radix sort, O(n log n)

*Principle.* After replacing each value by its rank (0 to n-1), the sort processes the bits of the rank from the least significant to the most significant. For each bit: look at the top of `a`; if the bit is 0, push it to `b` (`pb`), otherwise rotate `a` (`ra`). After n steps, push everything from `b` back to `a` (`pa`). Because each pass is **stable**, after the last bit the stack is sorted.

*Why this one.* Its number of operations is deterministic and bounded whatever the input order, which makes it the safe choice for strongly disordered input, and it is short to implement correctly.

*Complexity (operations).* The number of passes is ⌈log₂ n⌉ (the number of bits of n-1). Each pass costs n operations (`pb` or `ra`) plus at most n `pa`, so at most 2n per pass. Total ≤ 2n⌈log₂ n⌉ = **O(n log n)**. *Space:* O(1) auxiliary beyond the stacks.

### Adaptive (default): thresholds and rationale

The adaptive strategy measures the disorder `d` and selects the technique:

| Regime | Disorder | Technique | Operation complexity |
|--------|----------|-----------|----------------------|
| Low | `d < 0.2` | Selection sort | O(n²) |
| Medium | `0.2 ≤ d < 0.5` | Chunk-based sort | O(n√n) |
| High | `d ≥ 0.5` | LSD radix sort | O(n log n) |

*Rationale for the thresholds.* The thresholds 0.2 and 0.5 are the ones required by the subject (section 6.3.3). They are also meaningful: a uniformly random permutation has an expected disorder of 0.5, so `d ≥ 0.5` means "random or worse", where only a method with a guaranteed O(n log n) bound is safe; `d < 0.2` means that fewer than a fifth of the pairs are inverted, where the quadratic baseline is acceptable; the band in between uses the intermediate method.

*Complexity argument.* The disorder is computed once (no operation generated), then exactly one of the three algorithms above runs on the whole input. The number of operations is therefore bounded, in each regime, by the bound of the selected algorithm (≤ n²/2 + 2n, O(n√n) and ≤ 2n⌈log₂ n⌉ respectively). Auxiliary space: O(1) for the sorting itself, plus O(n) temporary memory for the disorder computation, which is freed before sorting. If the stack is already sorted (disorder 0), no operation is generated.

*Known limitation.* In the low regime, selection sort does not exploit the existing order beyond the trivial cases; the O(n²) bound holds but it is not optimal for nearly sorted input.

### Measured performance (random inputs)

| Input | Result |
|-------|--------|
| 100 numbers, default (adaptive) | about 850 to 950 operations on average, always under 1100 |
| 500 numbers, default (adaptive) | about 6700 operations on average, always under 6800 |

These values are inside the "good" bracket of the subject (< 1500 and < 8000) and fall under the pass limits (< 2000 and < 12000).

## Resources

### References

- Donald E. Knuth, *The Art of Computer Programming, Volume 3: Sorting and Searching*.
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting algorithm (overview)](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)), the basis of the disorder metric.
- The push_swap subject (42 curriculum).

### Use of AI

- AI was used **for learning during the project**: understanding algorithmic complexity, sorting techniques and how to reason about operation counts. All generated explanations were checked and tested by us before being used.
- AI was also used to review the code against the subject and to suggest fixes for bugs found during testing (error handling, parser checks, benchmark output).
- **This README file was written by AI**, from the information and the code provided by the authors.
