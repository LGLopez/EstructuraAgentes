#ifndef AGENTMENU_H_INCLUDED
#define AGENTMENU_H_INCLUDED

#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>

#include "time.h"
#include "customerlist.h"
#include "agentlist.h"
#include "name.h"
#include "generalschedule.h"
#include "listexception.h"
#include "customermenu.h"


class AgentMenu{
private:
    void keyToContinue();

    void mainMenu(AgentList&);

    void addAgent(AgentList&);
    void deleteAgent(AgentList&);
    void modifyAgent(AgentList&);
    void showList(AgentList&);
    void searchAgent(AgentList&);

    void sortList(AgentList&);

    void writeToDisk(AgentList&);
    void readFromDisk(AgentList&);

    void exit();
public:
    AgentMenu(AgentList&);
};

#endif // AGENTMENU_H_INCLUDED
