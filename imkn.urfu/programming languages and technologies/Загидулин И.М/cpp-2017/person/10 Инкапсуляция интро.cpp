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



struct Student : Person
{
    int kurs;
    // добавим Студенту возможность получать оценки по предметам
    int marks[SUBJECTS];
    
    Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
        : Person(Name, Age, Gender), kurs(Kurs)
    {
        // заполним нулями массив оценок
        for (int i = 0; i < SUBJECTS; i++)
            marks[i] = 0;
    }

    void print()
    {
        cout << "I am student " << name << ", " << kurs << " kurs\n";
    }

    // вычисление среднего балла
    double avgMark()
    {
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
            return 0;
        return sum / cnt;
    }

    void setMark(Subject s, int value)
    {
        if (value > 5 || value < 1)
            throw logic_error("Value must be from 1 to 5");
        marks[s] = value;
    }
};


int main() 
{
    // вызовы конструкторов
    Student tom("Tom", 20, MALE, 2), lena("Lena", 21, FEMALE, 3);

    cout << tom.avgMark() << endl;
    
    tom.setMark(LITERATURE, 4);
    tom.setMark(MATHS, 3);
    tom.setMark(PHYSICS, 4);
    tom.setMark(MUSIC, 5);
    tom.setMark(HISTORY, 5);
    cout << tom.avgMark() << endl;

    // но можно обойти наложенные ограничения
    tom.marks[BIOLOGY] = 1000;
    cout << tom.avgMark() << endl;

    return 0;
}