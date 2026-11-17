

#include "../include/Fertilizer.h"

Fertilizer::Fertilizer(string id, string name, string company) {
    fertilizerID = id;
    fertilizerName = name;
    manufacturer = company;
}

string Fertilizer::getID() const {
    return fertilizerID;
}

string Fertilizer::getName() const {
    return fertilizerName;
}

string Fertilizer::getManufacturer() const {
    return manufacturer;
 }
