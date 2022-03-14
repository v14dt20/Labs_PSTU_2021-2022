#include <iostream>
#include "List.h"

using namespace std;

//конструктор
List::List()
{
    Head = NULL;
    size_list = 0;
}

//деструктор
List::~List()
{
    delAll();
}

//добавить элемент в конец
void List::push_back(double mes)
{
    elem* el = new elem;//создаём узел, информационное поле которого будет пришедшие данные, а указатель на след элемент NULL
    el->data = mes;
    el->pNext = NULL;

    if (Head == NULL)//если список пустой, то созданный узел становится первым
        Head = el;
    else//иначе 
    {
        elem* current = Head;//создаём указатель, который указывает на узел в данный момент
        while (current->pNext != NULL)//идём до конца списка (узел последний, если ссылка на след узел равна NULL)
            current = current->pNext;//передвигаем указатель на след элемент
        current->pNext = el;//добавляем в конец созданный узел
    }
    size_list++;//увеличиваем счётчик элементов
}

//удалить элемент с конца
void List::pop_back()
{
    if (Head == NULL)//если список пустой, то удалять нечего
        cout << "List is empty!\n"; 
    else if (Head->pNext == NULL)//если список из одного элемента, то первый становится NULL
    {
        Head = NULL;
        size_list--;//уменьшаем счётчик
    }
    else//иначе
    {
        elem* current = Head;//указатель на нынешний узел
        elem* prev = current;//указатель на прошлый узел
        while (current->pNext != NULL)//пока не конец списка
        {
            prev = current;//предыдущий = нынешнему
            current = current->pNext;//нынешний = следующему
        }
        size_list--;//уменьшаем счётчик 
        current = NULL;//удаляем нынешний узел
        prev->pNext = NULL;//ссылка на этот узел равна NULL
    }
}

//удалить весь список
void List::delAll()
{
    elem* current = Head;//указатель на нынешний узел
    if (current == NULL) return;//если список пустой ничего не делаем
    do
    {
        elem* prev = current;//указатель на прошлый узел
        current = current->pNext;//нынешний передвигаем на следующий
        delete prev;//удаляем предыдущий
    } while (current != NULL);//так делаем, пока нынешний не равен NULL
    size_list = 0;//счётчик 0
    Head = NULL;//1 узел NULL
}


//печать списка
void List::print()
{
    if (Head == NULL)//если список пустой
        cout << "List is empty!";
    else//иначе
    {
        elem* current = Head;//ссылка на нынешний элемент
        cout << "Your list: ";
        while (current != NULL)//пока этот узел не равен NULL
        {
            cout << current->data << " ";//выводим его информационное поле
            current = current->pNext;//переходим к след узлу
        }
    }
    cout << "\n";
    size();
    cout << "\n";
}

//вывод размера
void List::size()
{
    cout << "Size: " << size_list << "\n";
}

//добавить элемент
void List::push(int n, double mes)
{
    elem* current = Head;//указатель на нынешний узел
    if (n > size_list + 1)//если пришедший индекс больше размера + 1, то выводим сообщение об ошибке и выходим из ф-ии
    {
        cout << "Error!\n";
        return;
    }

    if (n == 1)//если пришёл индекс 1, т.е начало списка
    {
        elem* new_el = new elem;//создаём новый узел
        new_el->data = mes;
        new_el->pNext = Head;//указатель на след = Head
        Head = new_el;//теперь первый элемент вновь созданный
        size_list++;//увеличиваем размер
    }
    else if (n == size_list + 1)//если индекс равен размер списка + 1, то просто добавляем элемент в конец
        push_back(mes);
    else//в иных случаях:
    {
        int count = 1;//счётчик 
        elem* current = Head;//нынешний узел
        elem* prev = current;//предыдущий
        while (count != n)//пока не дошли до узла с заданным номером
        {
            prev = current;//предыдущий равен нынешнему
            current = current->pNext;//нынешний передвигаем вперёд
            count++;//счётчик увеличиваем
        }
        elem* new_el = new elem;//создаём новый узел
        new_el->data = mes;
        new_el->pNext = current;//новый узел указывает на нынешний
        prev->pNext = new_el;//предыдущий указывает на вновь созданный элемент
        size_list++;//увеличиваем размер
    }
}