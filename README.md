# Updatable-Priority-Queue

힙 기반의 업데이트 가능한 우선순위 큐의 구현입니다.  
내부에 기존 위치(인덱스)를 추적할 수 있는 배열이 존재합니다.

## Usage

- `insert(T value)` 
- `update(int index, T value)`
- `extractMin()`
- `print()`

## Example

```C++
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  UpdatablePriorityQueue<int> upq(v);
  upq.print();
  upq.update(3, 0);
  upq.print();
  upq.update(3, 10);
  upq.print();
  for (int i = 0; i < 9; i++) {
    std::cout << upq.extractMin() << " ";
  }
  return 0;
}
```

```
1 2 3 4 5 6 7 8 9
0 1 3 2 5 6 7 8 9
0 1 3 8 5 6 7 10 9
0 1 3 5 6 7 8 9 10
```
