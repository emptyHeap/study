#include <iostream>
using namespace std;

#define MALE false
#define FEMALE true

// в С++ структура и класс - почти одно и то же
struct Person
{
    // поля класса
    string name;
    int age;
    bool gender;
    
    // В С++ появилась возможность объединять данные 
    // и фунции для работы с этими данными в одну структуру - объект.
    // Теперь параметров у фунции нет 
    // (они и не нужны - все данные доступны из структуры)
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
    Person girl, boy;
    
    girl.name = "Tanya";
    girl.age = 19;
    girl.gender = FEMALE;
    
    boy.name = "Dima";
    boy.age = 20;
    boy.gender = MALE;

    // Теперь формат вызова фунции изменился
    // Кстати, фунции, описанные внутри объектов, называются МЕТОДАМИ.
    boy.print();
    girl.print();
    
    return 0;
}