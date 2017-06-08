#include <iostream>
using namespace std;

#define MALE false
#define FEMALE true

struct Person
{
    string name;
    int age;
    bool gender;
    
    
    // Существует другая форма записи конструктора
    // есть возможность задать значения по-умолчанию
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


int main() 
{
    // вызов конструктора девочки
    Person girl("Tanya", 19, FEMALE);
    // вызов конструктора мальчика
    Person boy("Dima", 20, MALE), 
        boy2,           // вызов конструктора по-умолчанию (без параметров)
        girl2("Sasha"); // задано только имя, остальные поля - по-умолчанию

    boy.print();
    girl.print();
    boy2.print();
    girl2.print();
    
    return 0;
}