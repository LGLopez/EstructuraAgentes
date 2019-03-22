#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED

#include<iostream>
#include<string>

#include"agent.h"
#include"agentnode.h"

class AgentList{
private:
    AgentNode* header;

    void copyAll(const AgentList&);

    bool isValidPos(AgentNode*) const;

    void sortByName(AgentNode*, AgentNode*);
    void sortBySpeciality(AgentNode*, AgentNode*);

    void ptrSwapper(AgentNode*, AgentNode*);
public:
    AgentList();
    AgentList(const AgentList&);

    ~AgentList();

    bool isEmpty() const;

    void insertData(AgentNode*, const Agent&);
    void deleteData(AgentNode*);

    AgentNode* getFirstPos() const;
    AgentNode* getLastPos() const;
    AgentNode* getPrevPos(AgentNode*) const;
    AgentNode* getNextPos(AgentNode*) const;

    AgentNode* findData(const Agent&) const;

    Agent& retrieve(AgentNode*);

    std::string toString(const bool&) const;

    void sortByName();
    void sortBySpeciality();

    void deleteAll();

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

    AgentList& operator = (const AgentList&);
};


#endif // AGENTLIST_H_INCLUDED
