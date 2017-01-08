#include <iostream>
#include <vector>

using namespace std;

int main() {
  char symbol;
  string str;
  vector<int> founded;

  cout << "searching for symbol: ";
  cin >> symbol;

  cout << "in string: ";
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == symbol) {
      founded.push_back(i);
    }
  }

  cout << "\n" << founded.size() << " symbols founded\non positions: ";
  for (int position : founded) {
    cout << position << " ";
  }
  cout << "\n";
}
