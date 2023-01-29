#include <iostream>
#include <queue>
#include <utility>

template <typename T>
class UpdatablePriorityQueue {
  std::vector<T> heap;
  std::vector<int> pos;

 public:
  UpdatablePriorityQueue(std::vector<T> v) {
    heap = v;
    pos.resize(heap.size());
    for (int i = 0; i < heap.size(); i++) {
      pos[i] = i;
    }
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
      siftDown(i);
    }
  }

  void siftDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap.size() && heap[left] < heap[smallest]) {
      smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
      smallest = right;
    }
    if (smallest != i) {
      std::swap(heap[i], heap[smallest]);
      std::swap(pos[heap[i]], pos[heap[smallest]]);
      siftDown(smallest);
    }
  }

  void siftUp(int i) {
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
      std::swap(heap[i], heap[(i - 1) / 2]);
      std::swap(pos[heap[i]], pos[heap[(i - 1) / 2]]);
      i = (i - 1) / 2;
    }
  }

  void update(int i, T value) {
    heap[pos[i]] = value;
    siftUp(pos[i]);
    siftDown(pos[i]);
  }

  void insert(T value) {
    heap.push_back(value);
    pos.push_back(heap.size() - 1);
    siftUp(heap.size() - 1);
  }

  T extractMin() {
    T result = heap[0];
    std::swap(heap[0], heap[heap.size() - 1]);
    std::swap(pos[heap[0]], pos[heap[heap.size() - 1]]);
    heap.pop_back();
    pos.pop_back();
    siftDown(0);
    return result;
  }

  void print() {
    for (int i = 0; i < heap.size(); i++) {
      std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
  }
};