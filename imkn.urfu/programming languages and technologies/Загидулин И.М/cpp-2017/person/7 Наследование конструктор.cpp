#include <iostream>
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
    
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
};


// наследование
struct Student : Person
{
    // добавилось новое поле (пока не используется)
    int kurs;
    
    // поля Возраст, Имя и Пол присутствуют у Студента
    // Они унаследованы от Человека
    // Давайте опишем конструктор для класса Студент,
    // который будет инициализировать все поля
    Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
        : Person(Name, Age, Gender), // вызов конструктора родительского класса
        kurs(Kurs)
    {}
};


int main() 
{

    Person girl("Tanya", 19, FEMALE), boy("Dima", 20, MALE);
    boy.print();
    girl.print();

    Student vasya;
    vasya.print();
    
    return 0;
}