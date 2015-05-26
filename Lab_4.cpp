/// Отключение warning-оповещений
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>

/// Используем стандартное пространство имен
using namespace std;

/** \class Unit - класс описания и методов поля
*/
class Unit {
    ///- Список узлов
    list<Unit> units;
    ///- Количество узлов
    int numOfUnits;

 public:
    ///- Конструктор по-умолчанию
    Unit();
    ///- Конструктор с параметром
    Unit(int);
    ///- Деструктор
    ~Unit();
    ///- Метод, добавляющий в список новый узел
    void Add(const Unit&);
    ///- Метод поиска узла
    Unit& Find(int);
    ///- Метод, возвращающий количество узлов
    int  GetNumOfUnits();
    ///- Метод вывода дерева в прямом порядке
    void PrintDirect();
    ///- Метод вывода дерева в обратном порядке
    void PrintReverse();
    ///- Метод вывода дерева в симметричном порядке
    void PrintSymmetrical();
};

///- Глобальная переменная для указателя на искомый элемент списка
Unit* unit;

/**
Реализация методов
*/

Unit::Unit() {
}

Unit::~Unit() {
}

void Unit::PrintDirect() {
    if (numOfUnits)
        cout << numOfUnits << " ";
    for (std::list<Unit>::iterator iter = units.begin(); iter != units.end(); ++iter)
        (&(iter)._Ptr->_Myval)->PrintDirect();
}

void Unit::PrintReverse() {
    for (std::list<Unit>::iterator iter = units.begin(); iter != units.end(); ++iter)
        (&(iter)._Ptr->_Myval)->PrintReverse();
    if (numOfUnits)
        cout << numOfUnits << " ";
}

void Unit::PrintSymmetrical() {
    bool flag = true;
    if (units.size() == 0) {
        if (numOfUnits != 0)
            cout << numOfUnits << " ";
    }
    for (std::list<Unit>::iterator iter = units.begin(); iter != units.end(); ++iter) {
        (&(iter)._Ptr->_Myval)->PrintSymmetrical();
        if (flag) {
            if (numOfUnits)
                cout << numOfUnits << " ";
            flag = false;
        }
    }
}

Unit::Unit(int numOfUnits) {
    this->numOfUnits = numOfUnits;
}

int Unit::GetNumOfUnits() {
    return numOfUnits;
}

Unit& Unit::Find(int num) {
    for (std::list<Unit>::iterator iter = units.begin(); iter != units.end(); ++iter) {
        if ((&(iter)._Ptr->_Myval)->GetNumOfUnits() == num)
            unit = &(iter)._Ptr->_Myval;
        else
            (&(iter)._Ptr->_Myval)->Find(num);
    }
    return (*unit);
}

void Unit::Add(const Unit& unit) {
    units.push_back(unit);
}


/**\return {0} - выход из функции
*/
/// Функция main() − точка входа в программу
int main() {
    ///> Алгоритм функции
    ///- Инициализируем переменные
    int N, newUnit, numOfUnits;
    N = newUnit = numOfUnits = 0;
    Unit* baseUnit = new Unit(numOfUnits);
    ///- Считывание количества узлов
    cout << "N: ";
    cin >> N;
    ///- Считывание индексов N-го количества узлов
    for (int i = 0; i < N; ++i) {
        cin >> newUnit;
        if (newUnit) {
            ++numOfUnits;
            baseUnit->Find(newUnit).Add(*(new Unit(numOfUnits)));
        } else {
            ++numOfUnits;
            baseUnit->Add(*(new Unit(numOfUnits)));
        }
    }
    ///- Вывод дерева на экран в трех различных порядках
    baseUnit->PrintDirect();
    cout << endl;
    baseUnit->PrintReverse();
    cout << endl;
    baseUnit->PrintSymmetrical();
    cout << endl;

    system("pause");
    return 0;
}

