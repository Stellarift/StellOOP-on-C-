#include "Var.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Var::Var() : type(VAR_INT) {
    intValue = 0;
}

Var::Var(int value) : type(VAR_INT) {
    intValue = value;
}

Var::Var(double value) : type(VAR_DOUBLE) {
    doubleValue = value;
}

Var::Var(const char* value) : type(VAR_STRING) {
    stringValue = new String(value);
}

Var::Var(const Var& other) : type(other.type) {
    switch (type) {
        case VAR_INT: intValue = other.intValue; break;
        case VAR_DOUBLE: doubleValue = other.doubleValue; break;
        case VAR_STRING: stringValue = new String(*other.stringValue); break;
    }
}

Var::~Var() {
    if (type == VAR_STRING) {
        delete stringValue;
    }
}

Var& Var::operator=(const Var& other) {
    if (this == &other) return *this;
    
    if (type == VAR_STRING) {
        delete stringValue;
    }
    
    type = other.type;
    switch (type) {
        case VAR_INT: intValue = other.intValue; break;
        case VAR_DOUBLE: doubleValue = other.doubleValue; break;
        case VAR_STRING: stringValue = new String(*other.stringValue); break;
    }
    
    return *this;
}

Var Var::operator+(const Var& other) const {
    if (type == VAR_INT && other.type == VAR_INT) {
        return Var(intValue + other.intValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_DOUBLE) {
        return Var(doubleValue + other.doubleValue);
    }
    else if (type == VAR_STRING && other.type == VAR_STRING) {
        return Var((*stringValue + *other.stringValue).c_str());
    }
    else if (type == VAR_INT && other.type == VAR_DOUBLE) {
        return Var(intValue + other.doubleValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_INT) {
        return Var(doubleValue + other.intValue);
    }
    else if (type == VAR_STRING) {
        if (other.type == VAR_INT) {
            char buffer[32];
            sprintf(buffer, "%d", other.intValue);
            return Var((*stringValue + String(buffer)).c_str());
        } else if (other.type == VAR_DOUBLE) {
            char buffer[32];
            sprintf(buffer, "%g", other.doubleValue);
            return Var((*stringValue + String(buffer)).c_str());
        }
    }
    else if (other.type == VAR_STRING) {
        if (type == VAR_INT) {
            char buffer[32];
            sprintf(buffer, "%d", intValue);
            return Var((String(buffer) + *other.stringValue).c_str());
        } else if (type == VAR_DOUBLE) {
            char buffer[32];
            sprintf(buffer, "%g", doubleValue);
            return Var((String(buffer) + *other.stringValue).c_str());
        }
    }
    
    return Var(0);
}

Var Var::operator-(const Var& other) const {
    if (type == VAR_INT && other.type == VAR_INT) {
        return Var(intValue - other.intValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_DOUBLE) {
        return Var(doubleValue - other.doubleValue);
    }
    else if (type == VAR_INT && other.type == VAR_DOUBLE) {
        return Var(intValue - other.doubleValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_INT) {
        return Var(doubleValue - other.intValue);
    }
    return Var(0);
}

Var Var::operator*(const Var& other) const {
    if (type == VAR_INT && other.type == VAR_INT) {
        return Var(intValue * other.intValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_DOUBLE) {
        return Var(doubleValue * other.doubleValue);
    }
    else if (type == VAR_INT && other.type == VAR_DOUBLE) {
        return Var(intValue * other.doubleValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_INT) {
        return Var(doubleValue * other.intValue);
    }
    else if (type == VAR_STRING && other.type == VAR_INT) {
        String result;
        for (int i = 0; i < other.intValue; i++) {
            result = String(result.c_str()) + *stringValue;
        }
        return Var(result.c_str());
    }
    return Var(0);
}

Var Var::operator/(const Var& other) const {
    if (other.type == VAR_INT && other.intValue == 0) return Var(0);
    if (other.type == VAR_DOUBLE && other.doubleValue == 0) return Var(0);
    
    if (type == VAR_INT && other.type == VAR_INT) {
        return Var(intValue / other.intValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_DOUBLE) {
        return Var(doubleValue / other.doubleValue);
    }
    else if (type == VAR_INT && other.type == VAR_DOUBLE) {
        return Var(intValue / other.doubleValue);
    }
    else if (type == VAR_DOUBLE && other.type == VAR_INT) {
        return Var(doubleValue / other.intValue);
    }
    return Var(0);
}

Var& Var::operator+=(const Var& other) {
    *this = *this + other;
    return *this;
}

Var& Var::operator-=(const Var& other) {
    *this = *this - other;
    return *this;
}

Var& Var::operator*=(const Var& other) {
    *this = *this * other;
    return *this;
}

Var& Var::operator/=(const Var& other) {
    *this = *this / other;
    return *this;
}

bool Var::operator==(const Var& other) const {
    if (type != other.type) return false;
    
    switch (type) {
        case VAR_INT: return intValue == other.intValue;
        case VAR_DOUBLE: return doubleValue == other.doubleValue;
        case VAR_STRING: return *stringValue == *other.stringValue;
    }
    return false;
}

bool Var::operator!=(const Var& other) const {
    return !(*this == other);
}

bool Var::operator<(const Var& other) const {
    if (type == VAR_INT && other.type == VAR_INT) {
        return intValue < other.intValue;
    }
    else if (type == VAR_DOUBLE && other.type == VAR_DOUBLE) {
        return doubleValue < other.doubleValue;
    }
    else if (type == VAR_STRING && other.type == VAR_STRING) {
        return *stringValue < *other.stringValue;
    }
    else if (type == VAR_INT && other.type == VAR_DOUBLE) {
        return intValue < other.doubleValue;
    }
    else if (type == VAR_DOUBLE && other.type == VAR_INT) {
        return doubleValue < other.intValue;
    }
    return false;
}

bool Var::operator>(const Var& other) const {
    return other < *this;
}

bool Var::operator<=(const Var& other) const {
    return !(*this > other);
}

bool Var::operator>=(const Var& other) const {
    return !(*this < other);
}

void Var::print() const {
    switch (type) {
        case VAR_INT: cout << intValue; break;
        case VAR_DOUBLE: cout << doubleValue; break;
        case VAR_STRING: stringValue->output(); break;
    }
}

VarType Var::getType() const { return type; }