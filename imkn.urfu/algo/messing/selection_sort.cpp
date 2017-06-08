#include <iostream>
using namespace std;

struct element {
  int value;
  int index;
};

void sort(int array[], int size){
  for (int i = 0; i < size - 1; i++) {
    element min = { array[i], i };
    for (int j = i+1; j < size; j++) {
      if (array[j] < min.value) {
        min = { array[j], j };
      }
    }
    array[min.index] = array[i];
    array[i] = min.value;
  }
}

void print(int array[], int size){
  for (int i = 0; i < size; i++) cout << array[i] << ", ";
  cout << endl;
}

int main() {
  int sorted [5] = { 1, 2, 3, 4, 5 };
  int reversed [5] = { 5, 4, 3, 2, 1 };
  int messed [5] = { 4, 3, 1, 2, 5 };

  sort(sorted, 5);
  sort(reversed, 5);
  sort(messed, 5);

  print(sorted, 5);
  print(reversed, 5);
  print(messed, 5);

  return 0;
}
