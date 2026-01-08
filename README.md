*This project has been created as part of the 42 curriculum by so-ait-l.*

# push_swap

## Description

**push_swap** is an algorithmic sorting project that focuses on efficiency and problem-solving
under strict constraints. The goal is to sort a list of integers using two stacks and a
limited set of allowed operations, while minimizing the total number of moves.

The program works with:
- **Stack A**, which initially contains all the unsorted numbers
- **Stack B**, which starts empty and is used as auxiliary storage

Only predefined operations such as swapping, pushing, rotating, and reverse rotating
are allowed. The main challenge is to design an optimized algorithm that sorts the stack
correctly using as few operations as possible.

This repository includes:
- **push_swap**: generates the operations required to sort the stack
- **checker** (bonus): validates whether a given sequence of operations correctly sorts
  the stack

---

## Instructions

### Compilation

To compile the mandatory program:
```bash
make
