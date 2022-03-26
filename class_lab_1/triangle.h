class Triangle
{
private:
    int first;
    int second;
public:
    Triangle();//конструктор без параметров
    Triangle(int, int);//конструктор с параметрами

    ~Triangle();//деструктор

    //селекторы
    void get_first();
    void get_second();

    //модификаторы
    void set_first(int);
    void set_second(int);

    void hipotenuse();//вычисление гипотенузы
};