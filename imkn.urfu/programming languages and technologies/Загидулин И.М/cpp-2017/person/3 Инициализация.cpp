#include <iostream>
using namespace std;

#define MALE false
#define FEMALE true

struct Person
{
    string name;
    int age;
    bool gender;
    
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
    
    // давайте, для инициализации полей объектов 
    // будем также использовать фунцию (метод)
    void init(string Name, int Age, bool Gender)
    {
        name = Name;
        age = Age;
        gender = Gender;
    }
};


int main() 
{
    Person girl, boy;
    
    // использование нашей структуры Person упростилось
    girl.init("Tanya", 19, FEMALE);
    boy.init("Dima", 20, MALE);

    boy.print();
    girl.print();
    
    return 0;
}