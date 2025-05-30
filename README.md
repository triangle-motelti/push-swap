# Push Swap - Efficient Stack Sorting Algorithm


## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Operations](#operations)
5. [Sorting Algorithms](#sorting-algorithms)
6. [Error Handling](#error-handling)
7. [Project Structure](#project-structure)


## Introduction
**Push Swap** is an efficient sorting algorithm project that sorts a stack of integers using two stacks (A and B) with a limited set of operations. The goal is to sort stack A in ascending order (smallest number at the top) using the fewest operations possible.

## Installation
1. Clone the repository:
```bash
git clone https://github.com/<your-username>/push_swap.git
cd push_swap
```

2. Compile the program:
```bash
make
```
This will create two executables: `push_swap` (the sorting algorithm) and `checker` (program to verify results).

## Usage
```bash
./push_swap [list of integers]
```

### Example
```bash
./push_swap 3 1 4 2 5
```
This will output a sequence of operations to sort the numbers.

To validate the result:
```bash
./push_swap 3 1 4 2 5 | ./checker 3 1 4 2 5
```
Output: `OK` (if sorted correctly) or `KO` (if errors exist)

## Operations
Push Swap uses these 11 operations to manipulate stacks:

| Operation | Description |
|-----------|-------------|
| `sa`      | Swap first two elements of stack A |
| `sb`      | Swap first two elements of stack B |
| `ss`      | `sa` and `sb` simultaneously |
| `pa`      | Push top element from B to A |
| `pb`      | Push top element from A to B |
| `ra`      | Rotate stack A (shift all up) |
| `rb`      | Rotate stack B (shift all up) |
| `rr`      | `ra` and `rb` simultaneously |
| `rra`     | Reverse rotate stack A (shift all down) |
| `rrb`     | Reverse rotate stack B (shift all down) |
| `rrr`     | `rra` and `rrb` simultaneously |

## Sorting Algorithms

### 1. Sorting 3 Elements (`sort_3`)
- **Strategy**: Handle all permutations with minimal operations
- **Operations**: Uses combinations of `sa`, `ra`, and `rra`
- **Example**:
  - Input: [3, 1, 2] → `sa` → [1, 3, 2] → `ra` → [3, 2, 1] → `sa` → [2, 1, 3]
  - Final: [1, 2, 3]

### 2. Sorting 4 Elements (`sort_4`)
- **Strategy**: Reduce to 3-element problem
- **Steps**:
  1. Find and push smallest element to stack B
  2. Sort remaining 3 elements in stack A
  3. Push element back from B to A
- **Example**:
  - Input: [4, 2, 3, 1] → `pb` → A=[4, 2, 3], B=[1]
  - Sort A: [2, 3, 4]
  - `pa` → Final: [1, 2, 3, 4]

### 3. Sorting 5 Elements (`sort_5`)
- **Strategy**: Extend 4-element solution
- **Steps**:
  1. Push smallest element to stack B
  2. Sort remaining 4 elements in stack A
  3. Push element back from B to A
- **Example**:
  - Input: [5, 2, 4, 1, 3] → `pb` → A=[5, 2, 4, 3], B=[1]
  - Sort A: [2, 3, 4, 5]
  - `pa` → Final: [1, 2, 3, 4, 5]

### 4. Sorting Large Stacks (`hossni_sorting`)
- **Strategy**: Chunk-based sorting for efficiency
- **Key Features**:
  - Dynamically calculates chunk size (20 for ≤100 elements, 33 for >100)
  - Assigns indexes based on sorted position
- **Process**:
  1. **Push to Stack B in chunks**:
     - Push elements within current chunk range to stack B
     - Rotate (rb) if in next chunk
     - Optimize rotations based on position
  2. **Push Back to Stack A**:
     - Find maximum in stack B
     - Rotate to top with minimal operations
     - Push to stack A with `pa`
- **Complexity**: O(n log n) average case

## Error Handling
Push Swap validates input and handles errors gracefully:
- Checks for duplicate numbers
- Validates all inputs are integers
- Ensures numbers are within integer range
- On error: Prints `Error` to stderr and exits

```bash
./push_swap 1 2 3 3        # Error: duplicate number
./push_swap 1 2 "three"    # Error: non-numeric value
./push_swap 1 99999999999  # Error: integer overflow
```

## Project Structure
```
push_swap/
├── Makefile           # Compilation rules
├── push_swap          # Main executable
├── checker            # Validation program
├── includes/          # Header files
├── srcs/              # Source code
│   ├── sort_small.c   # Sorting for 3-5 elements
│   ├── sort_large.c   # Chunk-based sorting
│   ├── operations.c   # Stack operations
│   ├── utils.c        # Helper functions
│   └── error_handling.c # Input validation
└── libft/             # Custom library
    ├── ft_atoi.c
    ├── ft_isdigit.c
    └── ...
```

