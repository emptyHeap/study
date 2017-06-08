#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfect(int number) {

  if (number == 1) return false;

  int sum = 1;
  for (int i = 2; i < sqrt(number); i++) {
    if (number % i == 0) {
      sum += i + number / i;
    }
  }

  return sum == number;
}

int main() {
  vector<int> arr;
  int input;

  cout << "enter array of positive numbers, on finish enter 0\n";
  while(true) {
    cin >> input;
    if (input != 0) {
      arr.push_back(input);
    } else {
      break;
    }
  }

  int max_i = 0;
  int min_i = 0;
  int max = arr[max_i];
  int min = arr[min_i];

  for (int i = 1; i < arr.size(); i++) {
    int value = arr[i];

    if (value > max) {
      max = value;
      max_i = i;
    } else if (value == max) {
      max_i = i;
    } else if (value < min) {
      min = value;
      min_i = i;
    }
  }

  int left = std::min(max_i, min_i);
  int right = std::max(max_i, min_i);
  long unsigned int sum = 0;
  for (int i = left; i <= right; i++) {
    // cout << arr[i] << " - checked\n";
    if (isPerfect(arr[i])) {
      sum += arr[i];
    }
  }

  cout << "sum: " << sum << endl;
}
