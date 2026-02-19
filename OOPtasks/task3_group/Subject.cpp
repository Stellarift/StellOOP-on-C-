#include "Subject.h"
#include <cstring>
using namespace std;

Subject::Subject(const char* n) {
    strcpy(name, n);
}

const char* Subject::getName() { return name; }