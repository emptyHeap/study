#include <iostream>
using namespace std;

#define MALE false
#define FEMALE true

// структура Человек
struct Person
{
    string name;
    int age;
    bool gender;
};


// удобство использования структур
// вместо 3х параметров передается 1
void print(Person p)
{
    if (p.gender == FEMALE)
        cout << "Girl ";
    else
        cout << "Boy ";
    cout << p.name << ", " << p.age << " years old\n";
}


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
    print(boy);
    print(girl);
    
    return 0;
}