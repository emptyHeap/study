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
};


int main() 
{

    Person girl("Tanya", 19, FEMALE), boy("Dima", 20, MALE);
    boy.print();
    girl.print();


    Student vasya;
    vasya.print(); // метод унаследовался от Person    
    return 0;
}