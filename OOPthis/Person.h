#ifndef PERSON_H
#define PERSON_H
#include "Date.h"

class Person {
private:
    int id;
    char* familiya;
    char* imya;
    char* otchestvo;
    Date dataRozhdeniya;
    
    static int count;

public:
    Person(int id, const char* fam, const char* im, 
           const char* otch, int d, int m, int y);
    Person();
    Person(const Person& other);
    ~Person();
    
    static int getCount();
    
    void print();
    
    int getId();
    const char* getFamiliya();
    const char* getImya();
    const char* getOtchestvo();
    Date getDataRozhdeniya();
    
    void setId(int newId);
    void setFamiliya(const char* newFam);
    void setImya(const char* newIm);
    void setOtchestvo(const char* newOtch);
    void setDataRozhdeniya(int d, int m, int y);
};

#endif