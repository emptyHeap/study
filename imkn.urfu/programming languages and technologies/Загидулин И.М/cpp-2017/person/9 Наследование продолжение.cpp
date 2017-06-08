#include <iostream>
#include <stdexcept>

using namespace std;

#define MALE false
#define FEMALE true

struct Person
{
    string name;
    int age;
    bool gender;
    
    Person(string Name = "NoName", int Age = 0, bool Gender = MALE)
        : name(Name), age(Age), gender(Gender) // здесь происходит инициализация полей
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

    // добавим метод, создающий новых людей
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
    
    Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
        : Person(Name, Age, Gender), kurs(Kurs)
    {}

    void print()
    {
        cout << "I am student " << name << ", " << kurs << " kurs\n";
    }
};


int main() 
{
    // вызовы конструкторов
    Person girl("Tanya", 19, FEMALE), boy("Dima", 20, MALE);
    

    boy.eat();
    lena.eat();

    // метод возвращает объект класса Person
    Person kid = boy.createPerson(lena);
    // метод прекрасно работает и для класса Student
    // возращается все равно Человек (он ведь не обязательно должен быть Студентом)
    Student vasya("Vasiliy"), lena("Lena", 21, FEMALE);
    Person kid2 = lena.createPerson(boy);
    
    // даем детям имена и устанавливаем пол
    kid.name = "Vseslav";
    kid2.name = "Olga";
    kid2.gender = FEMALE;

    kid.print();
    kid2.print();

    return 0;
}