#include <string>
#include <istream>
#include <map>
#include <vector>

using namespace std;

class Student {
  public:
    Student(string _surname, string _name)
      : surname(_surname)
      , name(_name)
    { }
    int compare(const Student& other) const {
      int res = surname.compare(other.surname);
      if (res != 0) return res;

      res = name.compare(other.name);
      return res;
    }

    bool operator> (const Student& other) const {
      return compare(other) > 0;
    }
    bool operator< (const Student& other) const {
      return compare(other) < 0;
    }

    string name;
    string surname;
};

class Subject {
  public:
    string name;
};

bool debtsComp(
    pair<Student, vector<Subject> >& first,
    pair<Student, vector<Subject> >& second) {
  return first.second.size() < second.second.size();
}

class DebtsList : map<Student, vector<Subject> > {
  public:
    DebtsList(istream inputStream) {
      string studentName, studentSurname, subjectName;
      inputStream >> studentSurname >> studentName >> subjectName;
      Student readedStudent = Student(studentSurname, studentName);

      vector<Subject> *studentDebts;
      iterator sit = find(readedStudent);
      if (sit == end()) {
        vector<Subject> debts = vector<Subject>();
        insert(pair<Student, vector<Subject> >(readedStudent, debts));
        studentDebts = &debts;
      } else {
        studentDebts = &(sit->second);
      }

      totalDebts = countDebts();
    }

    vector < pair <Student, vector<Subject> > > studentsWithDebts(int debtsAmount) {
      vector< pair <Student, vector<Subject> > > result;
      for (pair <Student, vector<Subject> > studentWithDebts: this) {
        if (studentWithDebts.second.size() == debtsAmount) {
          result.push_back(studentWithDebts);
        }
      }
      return result;
    }

    vector < pair <Student, vector<Subject> >* > sortedByDebts() {
      vector < pair <Student, vector<Subject> >* > result;
      for (pair <Student, vector<Subject> > studentWithDebts : this) {
        result.push_back(&studentWithDebts);
      }
      result.sort(debtsComp);
      return result;
    }

  private:
    int totalDebts = 0;
    int countDebts() {
      int result = 0;
      for (pair <Student, vector<Subject> > studentWithDebts: this) {
        result += studentWithDebts.size();
      }
      return result;
    }
};

int main() {
}
