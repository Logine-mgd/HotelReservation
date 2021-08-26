#ifndef GUEST_H
#define GUEST_H
#include "Hotel.h"
#include <string>

using namespace std;
class Guest
{
public:
    Guest();
private:
    string username;
    int ID;
//    Hotel* hotel;
public:
    void setID(int id)
    {
        Guest::ID = id;
    }
    int getID()
    {
        return    Guest::ID ;
    }
    void setName(string n)
    {
        Guest::username=n;
    }
    string getName()
    {
        return    Guest::username;
    }

    virtual int getTotalCost(int l, int m,int s,int D)=0;
};

#endif // GUEST_H
