#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Matrix {
  private:
    int *data;
    int maxValue;
  public:
    int size;

    Matrix(){
      size = 0;
    }

    Matrix(istream& input){
      input >> size;
      data = new int[size*size];
      int readed[size*size];
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          input >> data[i*size + j];
        }
      }
      maxValue = this->maxElement();
    }

    bool isSuperTriangular(){
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
          if (data[i*size + j] != 0) return false;
        }
      }
      return true;
    }

    int maxElement(){
      int max = data[0];
      for (int i = 1; i < size*size; i++){
        if (data[i] > max) max = data[i];
      }
      return max;
    }

    bool operator<(Matrix const &b) {
      return maxValue < b.maxValue;
    }

    string toString() {
      stringstream result;
      result << "maximum value: " << maxValue << "\n";
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          result << data[i*size + j] << " ";
        }
        result << "\n";
      }
      return result.str();
    }
};

int main() {
  cout << "enter matrix array. First matrix size, then elements line by line or just separated, finish with 0 instead of matrix size\n";

  vector<Matrix> data;
  while (true) {
   Matrix another = Matrix(cin);
   if (another.size == 0) {
     break;
   } else {
     data.push_back(another);
   }
  };

  vector<Matrix> triangularMatrixes;
  for (Matrix matrix : data) {
    if (matrix.isSuperTriangular()) triangularMatrixes.push_back(matrix);
  }

  if (triangularMatrixes.size() == 0) {
    cout << "no super triangular matrixes founded\n";
  }

  sort(triangularMatrixes.begin(), triangularMatrixes.end());

  for (Matrix triangularMatrix : triangularMatrixes) {
    cout << triangularMatrix.toString();
  }
}
