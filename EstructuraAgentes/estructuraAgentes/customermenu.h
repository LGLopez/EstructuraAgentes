#ifndef CUSTOMERMENU_H_INCLUDED
#define CUSTOMERMENU_H_INCLUDED

#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>

#include"customerlist.h"
#include"listexception.h"

class CustomerMenu{
private:
    void keyToContinue();
public:
    CustomerMenu(CustomerList&);

    void mainMenu(CustomerList&);

    void addCustomer(CustomerList&);
    void deleteCustomer(CustomerList&);
    void modifyCustomer(CustomerList&);
    void showList(CustomerList&);

    void exit();
};


#endif // CUSTOMERMENU_H_INCLUDED
