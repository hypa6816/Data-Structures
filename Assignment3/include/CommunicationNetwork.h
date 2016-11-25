#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string name;
    std::string message;
    City *next;

    City(){}; // default constructor

    City(std::string initName, City *initNext, std::string initMessage)
    {
        name = initName;
        next = initNext;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(std::string, std::string);
        void buildNetwork();
        void transmitMsg(char *); //this is like a string
        void printNetwork();
    protected:
    private:
        City *head = new City;
        City *tail = new City;
};

#endif // COMMUNICATIONNETWORK_H
