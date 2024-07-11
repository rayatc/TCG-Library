# TCG Library Documentation

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Basic Usage](#basic-usage)
4. [Classes and Functions](#classes-and-functions)
   - [Ordered Set](#ordered-set)
   - [Random Function](#random-function)
   - [Random Vector (rvector)](#random-vector-rvector)
   - [Permutation](#permutation)
   - [Unique Vector](#unique-vector)
   - [Random String (rstring)](#random-string-rstring)
   - [Random Matrix (rmatrix)](#random-matrix-rmatrix)
   - [Graph Generators](#graph-generators)
     - [Tree](#tree)
     - [Binary Tree](#binary-tree)
     - [Graph](#graph)
   - [Random Points](#random-points)
5. [Examples](#examples)
6. [Best Practices](#best-practices)
7. [Troubleshooting](#troubleshooting)

## Introduction

The TCG Library is a comprehensive C++ toolkit designed to generate various types of random data structures and values. It's particularly useful for competitive programming, algorithm testing, and generating test cases various problems.

This library provides efficient and easy-to-use classes and functions for generating:

- Random values of different types
- Random vectors and unique vectors
- Random permutations
- Random strings
- Random matrices
- Random graphs, trees, and binary trees
- Random 2D points

## Installation

To use this library, include the `generator.h` header file in your C++ project:

```cpp
#include "generator.h"
```

Ensure that you have C++17 or later, as some features rely on C++17 functionality.

## Basic Usage

Here's a quick example of how to use some of the basic features:

```cpp
#include "generator.h"
#include <iostream>

int main() {
    // Generate a random integer between 1 and 100
    int rand_int = random(1, 100);
    std::cout << "Random integer: " << rand_int << std::endl;

    // Generate a random vector of 10 integers between 1 and 100
    rvector<int> rand_vec(10, 1, 100);
    std::cout << "Random vector: ";
    rand_vec.print();

    // Generate a random permutation of integers from 1 to 5
    permutation perm(5);
    std::cout << "Random permutation: ";
    perm.print();

    return 0;
}
```

## Classes and Functions

### Ordered Set

```cpp
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
```

This is a policy-based data structure that provides an ordered set with additional operations like finding the k-th element or the number of elements less than a given value.

### Random Function

```cpp
template <typename T>
T random(T l, T r);
```

Generates a random value of type T in the range [l, r].

- Supports integral types, floating-point types, and characters.
- For floating-point types, it generates a value in the continuous range [l, r].
- For integral types and characters, it generates a value in the discrete range [l, r].

### Random Vector (rvector)

```cpp
template <typename T>
class rvector : public vector<T>;
```

A vector filled with random elements.

Constructor 1: `rvector(size_t length, T l, T r)`

- Creates a vector of `length` elements, each randomly chosen in the range [l, r].

Constructor 2: `rvector(size_t length, const vector<T> &a)`

- Creates a vector of `length` elements, each randomly chosen from the given vector `a`.

Method: `void print() const`

- Prints the elements of the vector.

### Permutation

```cpp
class permutation : public vector<int>;
```

Generates a random permutation of integers.

Constructor: `permutation(int n, int start = 1)`

- Creates a permutation of `n` integers starting from `start`.

Method: `void print() const`

- Prints the permutation.

### Unique Vector

```cpp
template <typename T>
class unique_vector : public vector<T>;
```

A vector filled with unique random elements.

Constructor: `unique_vector(size_t n, T l, T r)`

- Creates a vector of `n` unique elements, each in the range [l, r].

Method: `void print() const`

- Prints the elements of the vector.

### Random String (rstring)

```cpp
class rstring : public string;
```

Generates a random string.

Constructor 1: `rstring(size_t length, char l, char r)`

- Creates a string of `length` characters, each randomly chosen in the range [l, r].

Constructor 2: `rstring(size_t length, const string &s)`

- Creates a string of `length` characters, each randomly chosen from the given string `s`.

Method: `void print() const`

- Prints the string.

### Random Matrix (rmatrix)

```cpp
template <typename T>
class rmatrix : public vector<vector<T>>;
```

Generates a random 2D matrix.

Constructor 1: `rmatrix(size_t r, size_t c, T l, T h)`

- Creates an r × c matrix with elements randomly chosen in the range [l, h].

Constructor 2: `rmatrix(size_t r, size_t c, const vector<T> &values)`

- Creates an r × c matrix with elements randomly chosen from the given vector `values`.

Constructor 3: `rmatrix(size_t r, size_t c, const string &s)` (only for char type)

- Creates an r × c character matrix with elements randomly chosen from the given string `s`.

Method: `void print(const string &separator = " ") const`

- Prints the matrix, using the specified separator between elements.

### Graph Generators

#### Tree

```cpp
template <typename WeightType = long long>
class Tree : public GraphBase<WeightType>;
```

Generates a random tree.

Constructor 1: `Tree(int n)`

- Creates an unweighted tree with `n` vertices.

Constructor 2: `Tree(int n, T l, T r)`

- Creates a weighted tree with `n` vertices and edge weights in the range [l, r].

#### Binary Tree

```cpp
template <typename WeightType = long long>
class BinaryTree : public GraphBase<WeightType>;
```

Generates a random binary tree.

Constructor 1: `BinaryTree(int n)`

- Creates an unweighted binary tree with `n` nodes.

Constructor 2: `BinaryTree(int n, T l, T r)`

- Creates a weighted binary tree with `n` nodes and edge weights in the range [l, r].

#### Graph

```cpp
template <typename WeightType = long long>
class Graph : public GraphBase<WeightType>;
```

Generates a random graph.

Constructor 1: `Graph(int n, int m)`

- Creates an unweighted graph with `n` vertices and `m` edges.

Constructor 2: `Graph(int n, int m, T l, T r)`

- Creates a weighted graph with `n` vertices, `m` edges, and edge weights in the range [l, r].

All graph classes have a `print()` method to output the edges (and weights for weighted graphs).

### Random Points

```cpp
class points : public vector<pair<int, int>>;
```

Generates random 2D points.

Constructor 1: `points(int n, int l, int r)`

- Creates `n` points with both x and y coordinates in the range [l, r].

Constructor 2: `points(int n, int lx, int rx, int ly, int ry)`

- Creates `n` points with x coordinates in the range [lx, rx] and y coordinates in the range [ly, ry].

Method: `void print() const`

- Prints the points.

## Examples

Here are some examples demonstrating how to use various classes:

```cpp
#include "generator.h"
#include <iostream>

int main() {
    // Generate a random string of 10 lowercase letters
    rstring rand_str(10, 'a', 'z');
    std::cout << "Random string: ";
    rand_str.print();

    // Generate a 3x3 matrix of integers between 1 and 100
    rmatrix<int> rand_matrix(3, 3, 1, 100);
    std::cout << "Random matrix:\n";
    rand_matrix.print();

    // Generate a random tree with 5 vertices
    Tree<> rand_tree(5);
    std::cout << "Random tree edges:\n";
    rand_tree.print();

    // Generate 5 random points in the 2D plane with coordinates between -10 and 10
    points rand_points(5, -10, 10);
    std::cout << "Random points:\n";
    rand_points.print();

    return 0;
}
```

## Best Practices

1. Seed the random number generator only once at the beginning of your program to ensure reproducibility.
2. When generating large amounts of data, consider using move semantics to improve performance.
3. For graph generation, ensure that the number of edges (m) does not exceed the maximum possible edges for n vertices to avoid infinite loops.
4. When using weighted graphs, choose an appropriate range for weights based on your specific problem requirements.

## Troubleshooting

- If you encounter compilation errors, make sure you're using C++17 or later.
- For any "ambiguous overload" errors, explicitly specify the type when calling the `random()` function.
- If generating unique elements takes too long, ensure that the range is large enough compared to the number of elements requested.

For more detailed information on each class and function, refer to the inline documentation in the `generator.h` file.
