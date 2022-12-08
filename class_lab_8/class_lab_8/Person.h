#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Person :
    public Object
{
protected:
    string name;
    int age;
public:
    Person();
    Person(string, int);
    Person(Person&);

    virtual ~Person();

    void set_name(string n) { name = n; }
    void set_age(int a) { age = a; }

    string get_name() { return name; }
    int get_age() { return age; }

    Person& operator= (const Person&);

    void show();
    void input();

    virtual int HandleEvent(TEvent& e);
};

