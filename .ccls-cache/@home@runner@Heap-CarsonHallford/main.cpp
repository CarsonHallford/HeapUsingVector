// I obtained help via StackOverflow : 
// https://stackoverflow.com/questions/5227976/what-is-the-use-of-the-heap-data-structure
// wiki:http://en.wikipedia.org/wiki/Heap_%28data_structure%29
// I wrote the code in VS Studio 19' for debugging uses
// Carson Hallford
// Peer reviewed by: Kevin Fogle

#include <algorithm>
#include <iostream>
#include <vector>

#include "heap.h"

class Heap {
 public:
  void insert(int data) {
    int parent = 0;

    // O(1)
    heap.push_back(data);
    // O(1)
    current = heap.size() - 1;
    // O(1)
    parent = (current - 1) / 2;

    if (heap.size() > 1) {
      // O(n^2)
      while (heap.at(parent) < heap.at(current)) {
        if (heap.at(current) > heap.at(parent)) {
          std::swap(heap.at(parent), heap.at(current));
          current = parent;
          // O(1)
          parent = (parent - 1) / 2;
        }
      }
    }
  }

  void remove_max() {
    // O(1)
    if (heap.empty()) return;

    std::swap(heap.at(0), heap.at(heap.size() - 1));
    heap.pop_back();

    size_t parent = 0;
    do {
      // O(1)
      size_t child = 2 * parent + 1;
      if (child < heap.size()) {
        size_t rchild = 2 * (parent + 1);
        if (rchild < heap.size() && heap[rchild] > heap[child]) child = rchild;
        if (heap[child] > heap[parent]) {
          std::swap(heap[child], heap[parent]);
          parent = child;
        } else {
          break;
        }
      } else {
        break;
      }

    } while (true); //O(n^2)
  }

  int max() { return heap.at(0); } //O(n)

  bool empty() { return heap.empty(); } //O(1)

 private:
  std::vector<int> heap;
  int current = 0;
};

int main() {
  // TODO: implement!
  Heap myHeap;
  std::string command;
  int data;

  do {
    // O(1)
    std::cin >> command;

    if (command == "add") {
      // O(1)
      std::cin >> data;
      // O(n)
      myHeap.insert(data);
    } else if (command == "run") {
      // O(1)
      std::cout << myHeap.max() << std::endl;
      // O(n)
      myHeap.remove_max();
    } else if (command == "exit") {
      while (!myHeap.empty()) {
        // O(1)
        std::cout << myHeap.max() << std::endl;
        // O(n)
        myHeap.remove_max();
      }
    }
  } while (command != "exit");
  return 0;
}