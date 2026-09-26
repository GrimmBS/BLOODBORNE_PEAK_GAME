#ifndef FLIGHTPASSENGER_H
#define FLIGHTPASSENGER_H

#include <string>
using namespace std;

class FlightPassenger {
private:
    string name;
    string flightNumber;
    string seatNumber;

    double* baggageWeights;
    int baggageCount;

    void copyFrom(const FlightPassenger& other);

public:
    FlightPassenger();
    FlightPassenger(const string& name,
                     const string& flightNumber,
                     const string& seatNumber,
                     const double* weights,
                     int count);

    FlightPassenger(const FlightPassenger& other);

    ~FlightPassenger();

    string getName() const;
    string getFlightNumber() const;
    string getSeatNumber() const;
    int getBaggageCount() const;
    double getBaggageWeight(int index) const;
    double getTotalBaggageWeight() const;

    void setName(const string& newName);
    void setFlightNumber(const string& newFlightNumber);
    void setSeatNumber(const string& newSeatNumber);
    void setBaggageWeights(const double* weights, int count);

    FlightPassenger& operator=(const FlightPassenger& other);
    bool operator==(const FlightPassenger& other) const;

    void print() const;
};

#endif
