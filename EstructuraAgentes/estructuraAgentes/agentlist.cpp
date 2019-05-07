#include"agentlist.h"

void AgentList::copyAll(const AgentList& aList) {
    AgentNode* auxiliar(aList.header->getNext());
    AgentNode* newNode;

    while(auxiliar!=aList.header){
        try{
            if((newNode = new AgentNode(auxiliar->getData()))==nullptr){
                throw ListException("Memoria no disponible, copyAll");
                }
            }catch(nodeException ex){
                std::string msg("Error durante la creacion de nodo,copyAll");
                msg += ex.what();

                throw ListException(msg);
                }
        auxiliar->setPrev(header->getPrev());
        auxiliar->setNext(header);

        header->getPrev()->setNext(auxiliar);
        header->setPrev(auxiliar);

        }
    }

bool AgentList::isValidPos(AgentNode* position) const {
    AgentNode* aux(header->getNext());

    while(aux != header){
        if(aux == position){
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

void AgentList::sortByName(AgentNode* leftEdge, AgentNode* rightEdge) {
    if(leftEdge == rightEdge){
        return;
        }

    if(leftEdge->getNext() == rightEdge){
        if(leftEdge->getData().getName() > rightEdge->getData().getName()){
            ptrSwapper(leftEdge,rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while(i != j){
        while(i != j and i->getData().getName() <= rightEdge->getData().getName()){
            i = i->getNext();
            }
        while(i != j and j->getData().getName() >= rightEdge->getData().getName()){
            j = j->getPrev();
            }

        if(i != j){
            ptrSwapper(i,j);
            }
        }

    if(i != rightEdge){
        ptrSwapper(i,rightEdge);
        }
    if(i != leftEdge){
        sortByName(leftEdge,i->getPrev());
        }
    if(i != rightEdge){
        sortByName(i->getNext(), rightEdge);
        }
    }

void AgentList::sortBySpeciality(AgentNode* leftEdge, AgentNode* rightEdge) {
    if(leftEdge == rightEdge){
        return;
        }

    if(leftEdge->getNext() == rightEdge){
        if(leftEdge->getData().getSpeciality() > rightEdge->getData().getSpeciality()){
            ptrSwapper(leftEdge,rightEdge);
            }
        return;
        }

    AgentNode* i(leftEdge);
    AgentNode* j(rightEdge);

    while(i != j){
        while(i != j and i->getData().getSpeciality() <= rightEdge->getData().getSpeciality()){
            i = i->getNext();
            }
        while(i != j and j->getData().getSpeciality() >= rightEdge->getData().getSpeciality()){
            j = j->getPrev();
            }

        if(i != j){
            ptrSwapper(i,j);
            }
        }

    if(i != rightEdge){
        ptrSwapper(i,rightEdge);
        }
    if(i != leftEdge){
        sortBySpeciality(leftEdge,i->getPrev());
        }
    if(i != rightEdge){
        sortBySpeciality(i->getNext(), rightEdge);
        }
    }

void AgentList::ptrSwapper(AgentNode* a, AgentNode* b){
    Agent* auxiliar(a->getDataPtr());

    a->setDataPtr(b->getDataPtr());
    b->setDataPtr(auxiliar);
    }


AgentList::AgentList() : header(new AgentNode) {

    if(header == nullptr){
        throw ListException("La memoria no esta disponible, inicializando la lista");
        }

    header->setNext(header);
    header->setPrev(header);

    }

AgentList::AgentList(const AgentList& l) {
    copyAll(l);
    }

AgentList::~AgentList() {
    deleteAll();

    delete header;
    }

bool AgentList::isEmpty() const {
    return header->getNext() == header;
    }

void AgentList::insertData(AgentNode* p, const Agent& e) {

    if(p!=nullptr and !isValidPos(p)){
        throw ListException("Posicion invalida al insertar");
        }

    if(p == nullptr){
        p = header;
        }

    AgentNode* aux;

    try{
    aux = (new AgentNode(e));
        }catch (nodeException ex){
        std::string msg("Error durante la incializacion del nodo");
        msg += ex.what();

        throw ListException(msg);
        }

    if(aux == nullptr){
        throw ListException("Memoria no disponible al insertar");
        }

    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);

    }

void AgentList::deleteData(AgentNode* pos) {
    if(!isValidPos(pos)){
        throw ListException("Posicion invalida, deleteData");
        }
    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());

    delete pos;
    }

AgentNode* AgentList::getFirstPos() const {
    if(isEmpty()){
        return nullptr;
        }
    return header->getNext();
    }

AgentNode* AgentList::getLastPos() const {
    if(isEmpty()){
        return nullptr;
        }
    return header->getPrev();
    }

AgentNode* AgentList::getPrevPos(AgentNode* pos) const {
    if(pos == header->getPrev() or !isValidPos(pos)){
        return nullptr;
        }
    return pos->getPrev();
    }

AgentNode* AgentList::getNextPos(AgentNode* pos) const {
    if(pos == header->getNext() or !isValidPos(pos)){
        return nullptr;
        }
    return pos->getNext();
    }

AgentNode* AgentList::findData(const Agent& aFindData) const {
    AgentNode* auxiliar(header->getNext());

    while(auxiliar != header){
        if(auxiliar->getData() == aFindData){
            return auxiliar;
            }
        auxiliar = auxiliar->getNext();
        }
    return nullptr;
    }

Agent& AgentList::retrieve(AgentNode* pos) {
    if(!isValidPos(pos)){
        throw ListException("Posicion invalida, retrieve");
        }
    return pos->getData();
    }

std::string AgentList::toString(const bool& addList) const {
    std::string result;

    AgentNode* aux(header->getNext());
    while(aux != header){
        result += "*********************************************\n\t\tAgente\n";
        result += aux->getData().toString(addList) + "\n";

        aux = aux->getNext();
        }

    return result;
    }

void AgentList::sortByName() {
    sortByName(header->getNext(), header->getPrev());
    }

void AgentList::sortBySpeciality() {
    sortBySpeciality(header->getNext(), header->getPrev());
    }

void AgentList::deleteAll() {
    AgentNode* auxiliar;

    while(header->getNext()!= header){
        auxiliar = header->getNext();

        header->setNext(auxiliar->getNext());

        delete auxiliar;
        }

    header->setPrev(header);
    }

void AgentList::writeToDisk(const std::string& fileName) {
    std::ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()){
        std::string msg;
        msg = "El archivo ";
        msg+= fileName;
        msg+= " No se pudo abrir para escritura";

        throw ListException(msg);
        }

    system("del *.customer");

    AgentNode* aux(header->getNext());

    while(aux != header){
        myFile << aux->getData() << std::endl;

        try{
            aux->getData().getCustomerList().writeToDisk(std::to_string(aux->getData().getEmployeeNumber()) + ".customer");
            }
        catch(ListException ex){
            std::string msg;
            msg = "Error al intentar escribir clientes\n";
            msg+= "Error reportado: ";
            msg+= ex.what();

            myFile.close();

            throw ListException(msg);
            }
        aux = aux->getNext();
        }
    myFile.close();
    }

void AgentList::readFromDisk(const std::string& fileName) {
    std::ifstream myFile;

    Agent myAgent;
    AgentNode* newNode;

    myFile.open(fileName);

    if(!myFile.is_open()){
        std::string msg;

        msg = "El archivo ";
        msg+= fileName;
        msg+= " no se pudo abrir para lectura";

        throw ListException(msg);
        }

    deleteAll();

    try{
        while(myFile >> myAgent){
            myAgent.getCustomerList().readFromDisk(std::to_string(myAgent.getEmployeeNumber()) + ".customer");

            newNode = new AgentNode(myAgent);

            newNode->setPrev(header->getPrev());
            newNode->setNext(header);

            header->getPrev()->setNext(newNode);
            header->setPrev(newNode);
            }
        }
    catch(nodeException ex){
        std::string msg("Error durante la lectura del archivo ");
        msg+= fileName;
        msg+= ", error: ";
        msg+= ex.what();

        myFile.close();

        throw ListException(msg);
        }
    catch(ListException ex){
        std::string msg("Error durante la lectura del archivo ");
        msg+= fileName;
        msg+= ", error: ";
        msg+= ex.what();

        myFile.close();

        throw ListException(msg);
        }
    myFile.close();
    }

AgentList& AgentList::operator=(const AgentList& l) {
    deleteAll();

    copyAll(l);

    return *this;
    }
