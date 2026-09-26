#include <iostream>
#include "FlightPassenger.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cout << "=== 1. Параметрлі конструктор арқылы объект жасау ===" << endl;
    double weights1[] = {23.5, 18.2};
    FlightPassenger p1("Askar Serikov", "KC901", "12A", weights1, 2);
    p1.print();

    cout << "\n=== 2. Көшірме конструктор (deep copy) ===" << endl;
    FlightPassenger p2(p1);
    p2.setName("Askar Serikov (copy)");
    cout << "p1 аты: " << p1.getName() << endl;
    cout << "p2 аты: " << p2.getName() << endl;

    cout << "\n=== 3. Меншіктеу операторы (=) ===" << endl;
    double weights3[] = {10.0, 5.5, 7.8};
    FlightPassenger p3("Aigerim Bolatova", "KC205", "7C", weights3, 3);
    p3.print();

    FlightPassenger p4;
    p4 = p3;
    cout << "\nМеншіктеуден кейінгі p4:" << endl;
    p4.print();

    cout << "\n=== 4. Салыстыру операторы (==) ===" << endl;
    FlightPassenger p5("Aigerim Bolatova", "KC205", "9D", nullptr, 0);
    if (p3 == p5) {
        cout << "p3 мен p5 бірдей жолаушы деп танылды (аты мен рейс нөмірі сәйкес)." << endl;
    } else {
        cout << "p3 мен p5 әр түрлі жолаушылар." << endl;
    }

    if (p1 == p3) {
        cout << "p1 мен p3 бірдей." << endl;
    } else {
        cout << "p1 мен p3 әр түрлі жолаушылар." << endl;
    }

    cout << "\n=== 5. Тұрақты объект және const әдістерді шақыру ===" << endl;
    const FlightPassenger constPassenger("Nurlan Amirov", "KC330", "3B", weights1, 2);
    cout << "Аты: " << constPassenger.getName() << endl;
    cout << "Рейс нөмірі: " << constPassenger.getFlightNumber() << endl;
    cout << "Жалпы салмағы: " << constPassenger.getTotalBaggageWeight() << " кг" << endl;

    cout << "\n=== Бағдарлама соңы, деструкторлар шақырылады ===" << endl;
    return 0;
}
