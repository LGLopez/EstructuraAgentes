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

void AgentList::sortByName(AgentNode*, AgentNode*) {

    }

void AgentList::sortBySpeciality(AgentNode*, AgentNode*) {

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
    pos->getNext()->setNext(pos->getPrev());

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
        result += aux->getData().toString(addList) + "\n";

        aux = aux->getNext();
        }

    return result;
    }

void AgentList::sortByName() {

    }

void AgentList::sortBySpeciality() {

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

void AgentList::writeToDisk(const std::string&) {

    }

void AgentList::readFromDisk(const std::string&) {

    }

AgentList& AgentList::operator=(const AgentList& l) {
    deleteAll();

    copyAll(l);

    return *this;
    }
