#include <iostream>
#include <stdexcept>
using namespace std;

#define MALE false
#define FEMALE true

enum Subject 
{
    MATHS,
    MUSIC,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    LITERATURE,
    ENGLISH,
    HISTORY,
    SUBJECTS
};

struct Person
{
    string name;
    int age;
    bool gender;
    
    Person(string Name = "NoName", int Age = 0, bool Gender = MALE)
        : name(Name), age(Age), gender(Gender)
    {}

    void eat()
    {
        cout << name << ": I'm eating\n";
    }
    
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }

    Person createPerson(Person p)
    {
        if (gender ^ p.gender)
            return Person();
        else
            throw logic_error("Gender error!");
    }
};


// по-умолчанию в С++ применяется модификатор private
// при наследовании модификаторы доступа также меняются
class Student : public Person
{
private:
    int kurs;
    int marks[SUBJECTS];
    double avg_mark;
    
public:
    Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
        : Person(Name, Age, Gender), kurs(Kurs)
    {
        for (int i = 0; i < SUBJECTS; i++)
            marks[i] = 0;
        avg_mark = 0;
    }

    void print()
    {
        cout << "I am student " << name << ", " << kurs << " kurs\n";
    }

    double avgMark()
    {
        // оценки не обновлялись
        if (avg_mark >= 0)
            return avg_mark;

        // иначе пересчитываем
        double sum = 0;
        int cnt = 0;
        for (int i = 0; i < SUBJECTS; i++)
            // будем учитывать только ненулевые отметки
            if (marks[i] != 0)
            {
                sum += marks[i];
                cnt++;
            }
        if (cnt == 0) // избегаем деления на ноль
            avg_mark = 0;
        avg_mark = sum / cnt;
        return avg_mark;
    }

    void setMark(Subject s, int value);

    void setKurs(int k);
};


// довольно часто можно встретить такой способ описания методов
// в классе описаны лишь заголовки (сигнатуры)
// а реализация методов вынесена из класса
void Student::setMark(Subject s, int value)
{
    if (value > 5 || value < 1)
        throw logic_error("Value must be from 1 to 5");
    marks[s] = value;
    avg_mark = -1; // средний балл нужно обновить
}


void Student::setKurs(int k)
{
    if (k > 5 || k < 1)
        throw logic_error("Kurs must be from 1 to 5");
    kurs = k;
}


int main() 
{
    // вызовы конструкторов
    Student tom("Tom", 20, MALE, 2), lena("Lena", 21, FEMALE, 3);
    
    // без модификатора public Person эти строчки бы не скомпилировались
    tom.eat();
    tom.age = 22;
    tom.print();

    return 0;
}