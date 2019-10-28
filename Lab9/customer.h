#ifndef CUSTOMER_H

#define CUSTOMER_H

#include <iostream>

using std::string;

class Customer

{

private:
    int year, mileage, arrivalPosition;

    string name;

    int priority, serial;

public:
    Customer()
    {
        year = -1;
        mileage = -1;
        arrivalPosition = -1;
        name = "";
        priority = -1;
        serial = -1;
    } // Constructor

    ~Customer(){}; // Destructor

    // Setters and getters

    void setYear(int y) { years = y; }

    void setMileage(int m) { mileage = m; }

    void setArrivalPosition(int ap) { arrivalPosition = ap; }

    void setName(string n) { name = n; }

    void setPriority(int p) { priority = p; }

    void setSerial(int s) { serial = s; }

    int getYear() const { return year; }

    int getMileage() const { return mileage; }

    int getArrivalPosition() const { return arrivalPosition; }

    string getName() const { return name; }

    int calculatePriority(int mileage, int year, int arrivalPosition)

    {

        priority = (mileage / 1000 + year - arrivalPosition);

        setPriority(priority);

        return priority;
    }

    int calculateSerialNo(int priority, int arrivalPosition)

    {

        serial = (priority * 100 + (100 - arrivalPosition));

        setSerial(serial);

        return serial;
    }

    int getPriority() const { return priority; }

    int getSerial() const { return serial; }

    friend bool operator<(const Customer &c1, const Customer &c2)

    {

        if (c1.serialNo < c2.serialNo)
            return true;

        return false;
    }

    friend bool operator>(const Customer &c1, const Customer &c2)

    {

        if (c1.serialNo > c2.serialNo)
            return true;

        return false;
    }

    friend bool operator==(const Customer &c1, const Customer &c2)

    {

        if (c1.serialNo == c2.serialNo)
            return true;

        return false;
    }
};

#endif
