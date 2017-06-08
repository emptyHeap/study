#include <iostream>
using namespace std;

#define MALE false
#define FEMALE true

struct Person
{
    string name;
    int age;
    bool gender;
    
    // существует специальный метод для инициализации полей класса - КОНСТРУКТОР
    // заметьте: не указан тип возвращаемого значения!
    Person(string Name, int Age, bool Gender)
    {
        init(Name, Age, Gender);
    }
    
	//override
    // можно описать конструктор по-умолчанию
    Person()
    {
        init("NoName", 0, MALE);
    }
    
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
    
    void init(string Name, int Age, bool Gender)
    {
        name = Name;
        age = Age;
        gender = Gender;
    }
};


int main() 
{	
    // вызов конструктора девочки
    Person girl("Tanya", 19, FEMALE);
    // вызов конструктора мальчика
    Person boy("Dima", 20, MALE), 
        boy2, girl2; // вызов конструктора по-умолчанию (без параметров)

    boy.print();
    girl.print();
    boy2.print();
    girl2.print();
    
    return 0;
}