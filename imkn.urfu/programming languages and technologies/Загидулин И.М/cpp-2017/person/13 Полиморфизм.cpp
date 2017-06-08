#include <iostream>
#include <string>
#include <vector>
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

    // этот метод не будет перегружен
    void eat()
    {
        cout << name << ": I'm eating\n";
    }
    
    // virtual 
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
};


struct Student : Person
{
    int kurs;
    
    Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
        : Person(Name, Age, Gender), // вызов конструктора родительского класса
        kurs(Kurs)
    {}

    // переопределим поведение метода print в классе-наследнике
    // virtual 
    void print()
    {
        cout << "I am student " << name << ", " << kurs << " kurs\n";
    }
};


void travelByBus()
{
    vector<Person> bus;
    // заходят в автобус вечером
    bus.push_back(Person("Anna", 7, FEMALE));
    bus.push_back(Person("Bob", 27, MALE));
    bus.push_back(Person("Catrin", 16, FEMALE));
    bus.push_back(Student("Din", 18, MALE));
    bus.push_back(Student("Evelin", 20, FEMALE));
    bus.push_back(Person("Frank", 70, MALE));
    bus.push_back(Person("Grace", 45, FEMALE));
    bus.push_back(Student("Henry", 19, MALE));

    // кондуктор проверяет билеты
    // студенты платят половину стоимости (были такие времена)
    for (int i = 0; i < bus.size(); i++)
    {
        cout << "Conductor: Tickets, please\n";
        cout << "Passenger: ";
        // компилятор не знает, метод какого класса тут вызывать
        // до старта программы эта информация отсутствует
        bus[i].print();
    }
}

void travelByBusPointer()
{
    vector<Person*> bus;
    // заходят в автобус вечером
    bus.push_back(new Person("Anna", 7, FEMALE));
    bus.push_back(new Person("Bob", 27, MALE));
    bus.push_back(new Person("Catrin", 16, FEMALE));
    bus.push_back(new Student("Din", 18, MALE));
    bus.push_back(new Student("Evelin", 20, FEMALE));
    bus.push_back(new Person("Frank", 70, MALE));
    bus.push_back(new Person("Grace", 45, FEMALE));
    bus.push_back(new Student("Henry", 19, MALE));

    // кондуктор проверяет билеты
    // студенты платят половину стоимости (были такие времена)
    for (int i = 0; i < bus.size(); i++)
    {
        cout << "Conductor: Tickets, please\n";
        cout << "Passenger: ";
        // компилятор не знает, метод какого класса тут вызывать (Person или Student)
        // до старта программы эта информация отсутствует
        // поэтому нужный метод должен определяться во время работы программы
        // так называемое, "позднее связывание"
        bus[i]->print();
    }
}


// проверяем переопределение метода
void testOverload() 
{
    Person girl("Tanya", 19, true), boy("Dima", 20, false);
    boy.print();
    boy.eat();
    girl.print();
    girl.eat();

    Student vasya("Vasiliy");
    vasya.print();
    vasya.eat();
}


int main()
{
    testOverload();
}