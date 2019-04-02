#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>

#include"listexception.h"
#include"customernode.h"
#include"customer.h"

class CustomerList{
private:
    CustomerNode* anchor;

    void copyAll(const CustomerList&);

    bool isValidPos(CustomerNode*);

public:
    CustomerList();
    CustomerList(const CustomerList&);

    ~CustomerList();

    bool isEmpty();

    void insertData(CustomerNode*, const Customer&);
    void insertOrdered(const Customer&);
    void deleteData(CustomerNode*);

    CustomerNode* getFistPos() const;
    CustomerNode* getLastPos() const;
    CustomerNode* getPrevPos(CustomerNode*) const;
    CustomerNode* getNextPos(CustomerNode*) const;

    CustomerNode* findData(const Customer&) const;

    Customer& retrieve(CustomerNode*);

    std::string toString() const;

    void deleteAll();

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

    CustomerList& operator = (const CustomerList&);

    friend std::istream& operator >> (std::istream&, CustomerList&);
    friend std::ostream& operator << (std::ostream&, CustomerList&);
};







#endif // CUSTOMERLIST_H_INCLUDED
