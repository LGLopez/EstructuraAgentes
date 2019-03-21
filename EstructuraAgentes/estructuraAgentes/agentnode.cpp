#include"agentnode.h"

AgentNode::AgentNode() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

AgentNode::AgentNode(const Agent& aAgent) : dataPtr(new Agent(aAgent)), prev(nullptr), next(nullptr){
    if(dataPtr == nullptr){
        throw nodeException("Memoria no disponible durante la construccion de el nodo");
        }
    }

AgentNode::~AgentNode() {
    delete dataPtr;
    }

Agent* AgentNode::getDataPtr() const {
    return dataPtr;
    }

Agent& AgentNode::getData() {
    return *dataPtr;
    }

AgentNode* AgentNode::getPrev() const {
    return prev;
    }

AgentNode* AgentNode::getNext() const {
    return next;
    }

void AgentNode::setDataPtr(Agent* aDataPtr) {
    dataPtr = aDataPtr;
    }

void AgentNode::setData(const Agent& aData) {
    if(dataPtr == nullptr){
        if((dataPtr=new Agent(aData)) == nullptr){
            throw nodeException("Memoria no disponible, setData");
            }
        }
    else{
        *dataPtr = aData;
        }
    }

void AgentNode::setPrev(AgentNode* aPrev) {
    prev = aPrev;
    }

void AgentNode::setNext(AgentNode* aNext) {
    next = aNext;
    }

