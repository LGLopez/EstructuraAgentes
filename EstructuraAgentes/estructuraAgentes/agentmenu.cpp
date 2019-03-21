#include"agentmenu.h"

void AgentMenu::keyToContinue() {
    std::cout << "Presione una tecla para continuar.";
    getchar();
    }

void AgentMenu::mainMenu(AgentList& aAgentList) {
    unsigned int option;

    do {
        system("cls");

        std::cout << "\t\tMenu de Agentes" << std::endl << std::endl;

        std::cout << "1. Agregar Agentes" << std::endl;
        std::cout << "2. Eliminar Agentes" << std::endl;
        std::cout << "3. Modifiar Agentes" << std::endl;
        std::cout << "4. Mostrar Agentes" << std::endl;
        std::cout << "5. Ordenar Agentes" << std::endl;
        std::cout << "6. Leer del disco" << std::endl;
        std::cout << "7. Escribir al disco" << std::endl;
        std::cout << "8. Salir" << std::endl << std::endl;

        std::cout << "Elija la opcion deseada: " << std::endl;
        std::cin >> option;
        std::cin.ignore();

        switch(option) {
            case 1:
                addAgent(aAgentList);
                break;
            case 2:
                deleteAgent(aAgentList);
                break;
            case 3:
                modifyAgent(aAgentList);
                break;
            case 4:
                showList(aAgentList);
                break;
            case 5:
                sortList(aAgentList);
                break;
            case 6:
                readFromDisk(aAgentList);
                break;
            case 7:
                writeToDisk(aAgentList);
                break;
            case 8:
                exit();
                break;


            default:
                std::cout << "La opcion elegida no es valida, intente de nuevo";
                std::cin >> option;
                std::cin.ignore();
            }
        }
    while(option!=8);
    }

void AgentMenu::addAgent(AgentList& aAgentList) {
    Name myName;
    Agent myAgent;
    Time myTime;
    GeneralSchedule mySchedule;
    AgentNode* position;
    std::string myString;
    unsigned int myInt;

    system("cls");

    std::cout << "\t\tAgregar Agente" << std::endl;

    std::cout << "Ingrese el numero de el empleado: " << std::endl;
    std::cin >> myInt;
    std::cin.ignore();

    myAgent.setEmployeeNumber(myInt);

    position = aAgentList.findData(myAgent);

    if(position != nullptr) {
        std::cout << "Ese codigo de empleado ya esta usado." << std::endl;

        keyToContinue();
        return;
        }

    std::cout << "Ingrese el apellido de el Agente: " << std::endl;
    getline(std::cin, myString);
    myName.setLastName(myString);

    std::cout << "Ingrese el nombre de el agente: " << std::endl;
    getline(std::cin, myString);
    myName.setFirstName(myString);

    myAgent.setName(myName);

    std::cout << "Ingrese la hora de entrada de el agente (HH:MM) : " << std::endl;
    getline(std::cin,myString, ':');
    myTime.setHours(atoi(myString.c_str()));
    getline(std::cin, myString);
    myTime.setMinutes(atoi(myString.c_str()));

    mySchedule.setStartTime(myTime);

    std::cout << "Ingrese la hora de salida (HH:MM) : " << std::endl;
    getline(std::cin,myString, ':');
    myTime.setHours(atoi(myString.c_str()));
    getline(std::cin, myString);
    myTime.setMinutes(atoi(myString.c_str()));

    mySchedule.setEndTime(myTime);

    myAgent.setSchedule(mySchedule);

    std::cout << "Ingrese el numero de extension de el empleado: " << std::endl;
    std::cin >> myInt;
    std::cin.ignore();

    myAgent.setExtensionNumber(myInt);

    std::cout << "Ingrese el numero de horas trabajadas: " << std::endl;
    std::cin >> myInt;
    std::cin.ignore();

    myAgent.setWorkedHours(myInt);

    std::cout << "Ingrese la especialidad de el agente: " << std::endl;
    getline(std::cin, myString);

    myAgent.setSpeciality(myString);

    do {
        std::cout << "Desea agregar clientes para el agente [1=si,0=no]: " << std::endl;
        std::cin >> myInt;
        std::cin.ignore();
        }
    while(myInt!=1 and myInt!=0);

    if(myInt == 1) {
        new CustomerMenu(myAgent.getCustomerList());
        }

    try {
        aAgentList.insertData(aAgentList.getLastPos(), myAgent);
        }
    catch(ListException ex) {
        std::cout << "Fallo al intentar insertar el agente." << std::endl;
        std::cout << ex.what() << std::endl;
        std::cout << "Volviendo al menu..." << std::endl;
        keyToContinue();
        return;
        }
    std::cout << "El agente se ha insertado exitosamente." << std::endl;
    keyToContinue();
    }

void AgentMenu::deleteAgent(AgentList& aAgentList) {
    std::string myString;
    AgentNode* posToDelete;
    Agent agentToDelete;
    Name nameToDelete;
    unsigned int option;
    bool correctPosition = false;

    while(!correctPosition){
        system("cls");

        std::cout << "Desea ver la lista de Agentes [1=si,0=no]: " << std::endl;
        std::cin >> option;
        std::cin.ignore();
        if(option)
            showList(aAgentList);

        std::cout << "Ingrese el nombre del agente que desea eliminar (apellido,nombre): ";
        getline(std::cin, myString,',');
        nameToDelete.setLastName(myString);
        getline(std::cin, myString);
        nameToDelete.setFirstName(myString);

        agentToDelete.setName(nameToDelete);

        posToDelete = aAgentList.findData(agentToDelete);


        if(posToDelete == nullptr){
            std::cout << "El agente que ingreso no existe." << std::endl;
            correctPosition = true;
            keyToContinue();
            }
        else{
            aAgentList.deleteData(posToDelete);
            std::cout << "El agente ha sido eliminado." << std::endl;
            correctPosition = true;
            keyToContinue();
            }
        }
    }

void AgentMenu::modifyAgent(AgentList&) {

    }

void AgentMenu::showList(AgentList& aAgentList) {
    unsigned int option;

    system("cls");

    std::cout << "\t\tLista de agentes" << std::endl << std::endl;

    do {
        std::cout << "Desea que los agentes se muestren con sus clientes [1=si,0=no]: " << std::endl;
        std::cin >> option;
        std::cin.ignore();

        }while(option!= 1 and option!=0);
    std::cout << std::endl << std::endl;

    std::cout << aAgentList.toString(option==1);

    std::cout << std::endl << std::endl;

    keyToContinue();
    }

void AgentMenu::sortList(AgentList&) {

    }

void AgentMenu::writeToDisk(AgentList&) {

    }

void AgentMenu::readFromDisk(AgentList&) {

    }

void AgentMenu::exit() {
    return;
    }

AgentMenu::AgentMenu(AgentList& aAgentList) {
    mainMenu(aAgentList);
    }

