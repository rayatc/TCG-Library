#include "generator.h"
#include <iostream>

int main()
{
  // Generate random numbers of different types
  int randomInt = random(1, 100);
  float randomFloat = random(0.0f, 1.0f);
  char randomChar = random('a', 'z');
  cout << "Random integer: " << randomInt << "\n";
  cout << "Random float: " << randomFloat << "\n";
  cout << "Random char: " << randomChar << "\n\n";

  // Generate random elements from containers
  vector<string> fruits = {"apple", "banana", "orange", "grape", "kiwi"};
  string randomFruit = random(fruits);
  cout << "Random fruit: " << randomFruit << "\n";

  string vowels = "aeiou";
  char randomVowel = random(vowels);
  cout << "Random vowel: " << randomVowel << "\n\n";

  // Generate random vectors with different options
  rvector<int> randomIntVector(10, 1, 100);
  cout << "Random vector of integers:\n";
  randomIntVector.print();

  vector<char> possibleChars = {'A', 'B', 'C', 'D', 'E'};
  rvector<char> randomCharVector(5, possibleChars); // add multiple times to increase probability
  cout << "Random vector of selected characters:\n";
  randomCharVector.print();
  cout << "\n";

  // Generate permutations with different starting values
  permutation standardPerm(5);
  cout << "Standard permutation (1 to 5):\n";
  standardPerm.print();

  permutation zeroPerm(5, 0);
  cout << "Permutation starting from 0 (0 to 4):\n";
  zeroPerm.print();
  cout << "\n";

  // Generate unique vectors with different types
  unique_vector<int> uniqueInts(5, 1, 10);
  cout << "Unique integers:\n";
  uniqueInts.print();

  unique_vector<char> uniqueChars(3, 'X', 'Z');
  cout << "Unique characters:\n";
  uniqueChars.print();
  cout << "\n";

  // Generate random strings with different options
  rstring randomUppercase(8, 'A', 'Z');
  cout << "Random uppercase string: " << randomUppercase << "\n";

  rstring randomFromSet(10, "abcdefghijklmnopqrstuvwxyz0123456789");
  cout << "Random string from character set: " << randomFromSet << "\n\n";

  // Generate random matrices with different types and options
  rmatrix<int> intMatrix(3, 4, 1, 10);
  cout << "Random integer matrix:\n";
  intMatrix.print();
  cout << "\n";

  vector<char> matrixChars = {'X', 'O', '.'};
  rmatrix<char> charMatrix(10, 10, matrixChars);
  cout << "Random character matrix:\n";
  charMatrix.print();
  cout << "\n";

  rmatrix<float> floatMatrix(2, 2, 0.1f, 1.0f);
  cout << "Random float matrix:\n";
  floatMatrix.print();
  cout << "\n";

  // Generate different types of trees
  Tree<int> weightedTree(5, 1, 10);
  cout << "Weighted tree:\n";
  weightedTree.print();
  cout << "\n";

  Tree<> unweightedTree(4);
  cout << "Unweighted tree:\n";
  unweightedTree.print();
  cout << "\n";

  // Generate different types of binary trees
  BinaryTree<float> weightedBinaryTree(5, 0.1f, 1.0f);
  cout << "Weighted binary tree:\n";
  weightedBinaryTree.print();
  cout << "\n";

  BinaryTree<> unweightedBinaryTree(4);
  cout << "Unweighted binary tree:\n";
  unweightedBinaryTree.print();
  cout << "\n";

  // Generate different types of graphs
  Graph<int> weightedGraph(6, 10, 1, 100);
  cout << "Weighted graph:\n";
  weightedGraph.print();
  cout << "\n";

  Graph<> unweightedGraph(5, 7);
  cout << "Unweighted graph:\n";
  unweightedGraph.print();
  cout << "\n";

  // Generate random co-ordinates
  points a(5, 1, 10);
  cout << "Random co-ordinates:\n";
  a.print();
  cout << "\n";

  return 0;
}