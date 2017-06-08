#include <iostream>
#include <string>
using namespace std;


struct Person
{
    string name;
    int age;
    bool gender;
    
    Person(string Name = "NoName", int Age = 0, bool Gender = false)
        : name(Name), age(Age), gender(Gender) // здесь происходит инициализация полей
    {}

    // этот метод не будет переопределен
    void eat()
    {
        cout << name << ": I'm eating\n";
    }
    
    void print()
    {
        if (gender == true)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
};


struct Student : Person
{
    int kurs;
    
    Student(string Name = "NoName", int Age = 0, bool Gender = false, int Kurs = 1)
        : Person(Name, Age, Gender), // вызов конструктора родительского класса
        kurs(Kurs)
    {}

    // переопределим поведение метода print в классе-наследнике
    void print()
    {
        cout << "I am student " << name << ", " << kurs << " kurs\n";
    }
};


int main() 
{

    Person girl("Tanya", 19, true), boy("Dima", 20, false);
    Student vasya("Vasiliy");
    
    boy.print();    // Person
    boy.eat();
    girl.print();   // Person
    girl.eat();
    vasya.print();  // Student
    vasya.eat();
    
    return 0;
}