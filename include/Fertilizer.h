

#ifndef FERTILIZER_H
#define FERTILIZER_H

#include <string>
using namespace std;

class Fertilizer {
private:
    string fertilizerID;
    string fertilizerName;
    string manufacturer;

public:
    Fertilizer(string id, string name, string company);

    string getID() const;
    string getName() const;
    string getManufacturer() const;
};

#endif
