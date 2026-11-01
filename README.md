# Fall in Love With DSA

Code for the book **Fall in Love With DSA — Data Structures & Algorithms** by **Vamsi Bhavani**.

Every example in the book is here as a file you can open, run and change. The example numbers are the same as in the book: *Example 9.6* in the book is `example-09-06-…` in this repository.

## What is inside

```
cpp/                      every C++ example from the book, by chapter
  01-what-is-dsa/
  02-complexity-analysis/
  ...
  26-how-to-approach-any-dsa-problem/
EXAMPLES.md               a clickable list of all examples
```

There are three kinds of files:

- **Complete programs** — exactly as printed in the book.
- **Functions with a small test** — the book shows only the function. Here, the same code is followed by a short `main()` (and sometimes a few helper functions, clearly marked) so that you can run it. The part copied from the book is marked `---- code from the book ----`.
- **Fragments** — a few short pieces of code in the book that are not complete programs (for example, a template or a two-line loop). They are marked as fragments at the top.

Every runnable file has been compiled and checked: its output matches the `Output` printed in the book.

## How to run an example

You need a C++ compiler that supports C++17 (g++ 7+ or clang++ 5+).

```bash
git clone https://github.com/panda-sai/fall-in-love-with-dsa.git
cd fall-in-love-with-dsa/cpp/09-linked-lists
g++ -std=c++17 example-09-06-reverse-a-linked-list.cpp -o reverse
./reverse
```

On Windows, you can use the same commands in MinGW or WSL, or simply open the file in any IDE (VS Code, CLion, Code::Blocks, Dev-C++) and run it.

## How to use this repository while reading

1. **Read the idea in the book first,** and dry run the example on paper.
2. **Then run it here,** and compare with your dry run.
3. **Change it.** Use a different input, break it on purpose, add a print statement inside the loop. Seeing what changes is how the idea becomes yours.
4. **Try the exercises yourself before looking at any solution.**

## Coming soon

- Java and Python versions of every example, with the same example numbers.
- Solutions to all 282 end-of-chapter exercises (the book does not print them, so that you try first).

Watch this repository (the **Watch** button at the top) to be notified when they are added.

## About the author

Vamsi Bhavani teaches programming and DSA in Telugu on YouTube at [youtube.com/@VamsiBhavani](https://www.youtube.com/@VamsiBhavani). The free *DSA Sprint* course on the channel follows the same topics as Part I to Part III of this book.

If you find a mistake in the code or the book, please open an issue.
