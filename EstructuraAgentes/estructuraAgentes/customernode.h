#ifndef CUSTOMERNODE_H_INCLUDED
#define CUSTOMERNODE_H_INCLUDED

#include"customer.h"

class CustomerNode{
private:
    Customer customerData;
    CustomerNode* next;

public:
    CustomerNode();
    CustomerNode(const Customer&);

    Customer& getCustomerData();
    CustomerNode* getNext();

    void setCustomerData(const Customer&);
    void setNext(CustomerNode*);

};


#endif // CUSTOMERNODE_H_INCLUDED
