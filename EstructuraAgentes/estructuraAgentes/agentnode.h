#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED

#include<exception>
#include<string>

#include"agent.h"

class nodeException : public std::exception {
    private:
        std::string msg;

    public:
        explicit nodeException(const char* message) { }

        explicit nodeException(const std::string& message) : msg(message) { }

        virtual ~nodeException() throw() {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

class AgentNode {
    private:
        Agent* dataPtr;
        AgentNode* prev;
        AgentNode* next;

    public:
        AgentNode();
        AgentNode(const Agent&);

        ~AgentNode();

        Agent* getDataPtr() const;
        Agent& getData();
        AgentNode* getPrev() const;
        AgentNode* getNext() const;

        void setDataPtr(Agent*);
        void setData(const Agent&);
        void setPrev(AgentNode*);
        void setNext(AgentNode*);
    };

#endif // AGENTNODE_H_INCLUDED
