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
    
    // с virtual будут вызываться методы подклассов
    virtual void print()
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
    // примеры работы с указателями
    int *pInt;
    double *pDouble;
    Person *pPerson;
    Student *pStudent;

    // все указатели - это просто адреса оперативной памяти
    cout << sizeof(pInt) << endl;
    cout << sizeof(pDouble) << endl;
    cout << sizeof(pPerson) << endl;
    cout << sizeof(pStudent) << endl;
    cout << endl;

    pInt     = new int(3);
    pDouble  = new double;
    // конструкторы
    pPerson  = new Person("Kirill", 12, 0);
    pStudent = new Student("Eugen", 22, 0, 4);

    cout << pInt << endl;
    cout << pDouble << endl;
    cout << pPerson << endl;
    cout << pStudent << endl;

    // на один участок памяти можно смотреть по-разному
    // *pInt = 256;
    char *arr = (char *) pInt;
    cout << (int) arr[0] << " " << (int) arr[1] << " " << (int) arr[2] << " " << (int) arr[3] << " " <<  endl;


    // как обращаться к полям и методам объекта через указатель 
    pPerson->print();
    pStudent->eat();
    pStudent->age = 23;


    // попробуем так
    Person* boy = pStudent;
    boy->print();

    // импользование указателей отрывает нам большие возможности
    // один и тот же код работает по разному
    boy = pPerson;
    boy->print();
    // один и тот же код работает по разному
    // полиморфизм — свойство языка программирования, позволяющее единообразно обрабатывать данные разных типов

    return 0;
}