#pragma once
#include <iostream>

class Exam
{
private:
    std::string FIO;
    std::string discipline;
    int mark;
public:
    Exam();//конструктор без параметров
    Exam(std::string, std::string, int);//конструктор с параметрами
    Exam(const Exam&);//конструктор копирования

    ~Exam();//деструктор

    //селекторы
    void get_FIO();
    void get_discipline();
    void get_mark();

    //модификаторы
    void set_FIO(std::string);
    void set_discipline(std::string);
    void set_mark(int);

    void print();//вывод содержимого
};