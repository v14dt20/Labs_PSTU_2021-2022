#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class Abiturient :
    public Person
{
protected:
    int points;
    string speciality;
public:
    Abiturient();
    Abiturient(string, int, int, string);
    Abiturient(Abiturient&);

    ~Abiturient();

    void set_points(int p) { points = p; };
    void set_speciality(string s) { speciality = s; };

    int get_points() { return points; };
    string get_speciality() { return speciality; };

    Abiturient& operator=(const Abiturient&);

    void show();
    void input();
};

