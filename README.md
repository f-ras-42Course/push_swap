# Push_swap

## Overview

The Push_swap project is a classic algorithm project where the goal is to sort a stack of integers using a limited set of instructions. The project consists of two parts:

1. **Mandatory part**: Write a program called `push_swap` that takes a stack of integers as input and outputs the shortest possible sequence of instructions to sort the stack in ascending order.

2. **Bonus part**: Write a program called `checker` that takes a stack of integers and a sequence of instructions as input, and verifies whether the instructions correctly sort the stack.

## Requirements

- The project must be written in C and comply with the Norm (42 coding style).
- No memory leaks are allowed.
- The `push_swap` program must sort the stack with the lowest possible number of operations.
- The `checker` program must correctly verify whether the instructions sort the stack.
- The project must include a Makefile with the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Instructions

The programs can perform the following instructions:

- `sa` (swap a): Swap the first two elements at the top of stack a.
- `sb` (swap b): Swap the first two elements at the top of stack b.
- `ss`: `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time.

## Benchmarks

To validate the project, the programs must sort the following stacks with a minimal number of operations:

- For minimal validation (80% grade), `push_swap` must sort 100 random numbers in fewer than 700 operations.
- For maximum validation (100% grade), `push_swap` must sort 500 random numbers in fewer than 5500 operations.

## My Approach

In my implementation of `push_swap`, I focused on optimizing the sorting algorithm to minimize the number of operations. I analyzed the structure of the stack and made decisions based on the relative positions of the elements.

One key decision I made was to use a combination of different sorting algorithms, such as insertion sort and radix sort, depending on the size and distribution of the stack. This allowed me to adapt the sorting strategy to specific input, leading to more efficient sorting.

Additionally, I implemented a series of helper functions to manipulate stacks and perform common operations, such as finding minimum and maximum elements, checking if a stack is sorted, and more. These functions made my code more modular and easier to maintain.

For the `checker` program, I focused on implementing robust error handling to detect invalid inputs and instructions. I also optimized parsing for input stacks and instructions to ensure efficient processing.

Overall, I aimed to write clean, well-structured code that adheres to Norm and is easy to understand and maintain. Comprehensive comments were included to explain my decisions and functionality.

## Usage

To use the `push_swap` and `checker` programs, follow these steps:

1. Compile using provided Makefile:

    ```bash
    make
    ```

2. Run `push_swap` with integers as arguments:

    ```bash
    ./push_swap 3 1 2 4 5
    ```

3. Run `checker` with integers and sorting instructions:

    ```bash
    ./push_swap 3 1 2 4 5 | ./checker 3 1 2 4 5
    ```

If sorted correctly, `checker` outputs "OK". Otherwise, it outputs "KO".
