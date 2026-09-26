#include "FlightPassenger.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void FlightPassenger::copyFrom(const FlightPassenger& other) {
    this->name = other.name;
    this->flightNumber = other.flightNumber;
    this->seatNumber = other.seatNumber;
    this->baggageCount = other.baggageCount;

    if (other.baggageWeights != nullptr && other.baggageCount > 0) {
        this->baggageWeights = new double[this->baggageCount];
        for (int i = 0; i < this->baggageCount; i++) {
            this->baggageWeights[i] = other.baggageWeights[i];
        }
    } else {
        this->baggageWeights = nullptr;
    }
}

FlightPassenger::FlightPassenger()
    : name(""), flightNumber(""), seatNumber(""), baggageWeights(nullptr), baggageCount(0) {
    cout << "[Конструктор] Үнсіз келісім бойынша объект жасалды." << endl;
}

FlightPassenger::FlightPassenger(const string& name,
                                  const string& flightNumber,
                                  const string& seatNumber,
                                  const double* weights,
                                  int count) {
    this->name = name;
    this->flightNumber = flightNumber;
    this->seatNumber = seatNumber;
    this->baggageCount = (count > 0) ? count : 0;

    if (weights != nullptr && this->baggageCount > 0) {
        this->baggageWeights = new double[this->baggageCount];
        for (int i = 0; i < this->baggageCount; i++) {
            this->baggageWeights[i] = weights[i];
        }
    } else {
        this->baggageWeights = nullptr;
    }

    cout << "[Конструктор] \"" << this->name << "\" жолаушысы үшін объект жасалды." << endl;
}

FlightPassenger::FlightPassenger(const FlightPassenger& other) {
    copyFrom(other);
    cout << "[Көшірме конструктор] \"" << this->name << "\" жолаушысының көшірмесі жасалды." << endl;
}

FlightPassenger::~FlightPassenger() {
    if (baggageWeights != nullptr) {
        delete[] baggageWeights;
        baggageWeights = nullptr;
    }
    cout << "[Деструктор] \"" << name << "\" жолаушысының объектісі жойылды." << endl;
}

string FlightPassenger::getName() const {
    return this->name;
}

string FlightPassenger::getFlightNumber() const {
    return this->flightNumber;
}

string FlightPassenger::getSeatNumber() const {
    return this->seatNumber;
}

int FlightPassenger::getBaggageCount() const {
    return this->baggageCount;
}

double FlightPassenger::getBaggageWeight(int index) const {
    if (index < 0 || index >= baggageCount) {
        throw out_of_range("Индекс жүк массивінің шегінен тыс.");
    }
    return baggageWeights[index];
}

double FlightPassenger::getTotalBaggageWeight() const {
    double total = 0.0;
    for (int i = 0; i < baggageCount; i++) {
        total += baggageWeights[i];
    }
    return total;
}

void FlightPassenger::setName(const string& newName) {
    this->name = newName;
}

void FlightPassenger::setFlightNumber(const string& newFlightNumber) {
    this->flightNumber = newFlightNumber;
}

void FlightPassenger::setSeatNumber(const string& newSeatNumber) {
    this->seatNumber = newSeatNumber;
}

void FlightPassenger::setBaggageWeights(const double* weights, int count) {
    if (this->baggageWeights != nullptr) {
        delete[] this->baggageWeights;
        this->baggageWeights = nullptr;
    }

    this->baggageCount = (count > 0) ? count : 0;

    if (weights != nullptr && this->baggageCount > 0) {
        this->baggageWeights = new double[this->baggageCount];
        for (int i = 0; i < this->baggageCount; i++) {
            this->baggageWeights[i] = weights[i];
        }
    }
}

FlightPassenger& FlightPassenger::operator=(const FlightPassenger& other) {
    if (this == &other) {
        return *this;
    }

    if (this->baggageWeights != nullptr) {
        delete[] this->baggageWeights;
        this->baggageWeights = nullptr;
    }

    copyFrom(other);

    cout << "[operator=] \"" << other.name << "\" мәліметтері көшірілді." << endl;
    return *this;
}

bool FlightPassenger::operator==(const FlightPassenger& other) const {
    return (this->name == other.name) && (this->flightNumber == other.flightNumber);
}

void FlightPassenger::print() const {
    cout << "----- Жолаушы туралы ақпарат -----" << endl;
    cout << "Аты: " << name << endl;
    cout << "Рейс нөмірі: " << flightNumber << endl;
    cout << "Орын нөмірі: " << seatNumber << endl;
    cout << "Жүк саны: " << baggageCount << endl;
    for (int i = 0; i < baggageCount; i++) {
        cout << "  Жүк " << (i + 1) << ": " << baggageWeights[i] << " кг" << endl;
    }
    cout << "Жалпы салмақ: " << getTotalBaggageWeight() << " кг" << endl;
    cout << "-----------------------------------" << endl;
}

