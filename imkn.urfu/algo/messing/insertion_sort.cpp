#include <iostream>
using namespace std;

struct element {
  int value;
  int index;
};

void sort(int array[], int size){
  for (int i = 1; i < size; i++){
    int value = array[i];
    int j = i - 1;
    while (j >=0 && array[j] > value) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = value;
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
