#include "customerlist.h"


void CustomerList::copyAll(const CustomerList& aList) {
    CustomerNode* newNode;
    CustomerNode* lastNode(nullptr);
    CustomerNode* aux(aList.anchor);

    while(aux!= nullptr){
        newNode = new CustomerNode(aux->getCustomerData());

        if(newNode == nullptr){
            throw ListException("Memoria no disponible, copyAll");
            }
        if(lastNode==nullptr){
            anchor = newNode;
            }
        else{
            lastNode->setNext(newNode);
            }
        lastNode = newNode;
        aux = aux->getNext();
        }
    }

bool CustomerList::isValidPos(CustomerNode* p) {
    CustomerNode* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

CustomerList::CustomerList() : anchor(nullptr) {}

CustomerList::CustomerList(const CustomerList& aCustomerList)  {
    copyAll(aCustomerList);
    }

CustomerList::~CustomerList() {
    deleteAll();
    }

bool CustomerList::isEmpty() {
    return anchor == nullptr;
    }

void CustomerList::insertData(CustomerNode* p, const Customer& e) {
    if(p != nullptr and !isValidPos(p)){
        throw ListException("La posicion no es valida, insertData");
        }
    CustomerNode* temporary(new CustomerNode(e));

    if(temporary == nullptr){
        throw ListException("Memoria no disponible, tratando de insetar un cliente");
        }

    if(p == nullptr){
        temporary->setNext(anchor);
        anchor = temporary;
        }
    else{
        temporary->setNext(p->getNext());
        p->setNext(temporary);
        }

    }

void CustomerList::insertOrdered(const Customer& e) {
    CustomerNode* temporary(anchor);
    CustomerNode* previous(nullptr);

    while(temporary!=nullptr and e >= temporary->getCustomerData()){
        previous = temporary;
        temporary = temporary->getNext();
        }
    insertData(previous,e);
    }

void CustomerList::deleteData(CustomerNode* aDeleteData) {
    if(!isValidPos(aDeleteData)){
        throw ListException("La posicion no es valida, deleteData");
        }
    if(aDeleteData == anchor){
        anchor = aDeleteData->getNext();
        }
    else{
        getPrevPos(aDeleteData)->setNext(aDeleteData->getNext());
        }
    delete aDeleteData;
    }

CustomerNode* CustomerList::getFistPos() const {
    return anchor;
    }

CustomerNode* CustomerList::getLastPos() const {
    CustomerNode* aux(anchor);

    while(aux != nullptr){
        aux = aux->getNext();
        }
    return aux;
    }

CustomerNode* CustomerList::getPrevPos(CustomerNode* aGetPrev) const {
    CustomerNode* aux(anchor);

    while(aux != nullptr and aux->getNext() != aGetPrev){
        aux = aux->getNext();
        }
    return aux;
    }

CustomerNode* CustomerList::getNextPos(CustomerNode* aGetNext) const {
    return aGetNext->getNext();
    }

CustomerNode* CustomerList::findData(const Customer& aFindData) const {
    CustomerNode* aux(anchor);

    while(aux != nullptr){
        if(aux->getCustomerData() == aFindData){
            return aux;
            }
        aux = aux->getNext();
        }
    throw ListException("No existe ese dato, findData");
    }

Customer& CustomerList::retrieve(CustomerNode* aCustomerNode) {
    return aCustomerNode->getCustomerData();
    }

std::string CustomerList::toString() const {
    CustomerNode* temporary(anchor);

    std::string result;

    while(temporary!=nullptr){
        result += temporary->getCustomerData().toString() + "\n";
        temporary = temporary->getNext();
        }
    return result;
    }

void CustomerList::deleteAll() {
    CustomerNode* aux;

    while(anchor!=nullptr){
        aux = anchor;

        anchor = aux->getNext();

        delete aux;
        }

    }

void CustomerList::writeToDisk(const std::string&) {

    }

void CustomerList::readFromDisk(const std::string&) {

    }

CustomerList& CustomerList::operator=(const CustomerList& p) {
    copyAll(p);

    return *this;
    }
