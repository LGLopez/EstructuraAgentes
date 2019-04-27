#include"agentmenu.h"

void AgentMenu::keyToContinue() {
    std::cout << "Presione una tecla para continuar.";
    getchar();
    }

void AgentMenu::mainMenu(AgentList& aAgentList) {
    unsigned int option,delAll;

    do {
        system("cls");

        std::cout << "\t\tMenu de Agentes" << std::endl << std::endl;

        std::cout << "1. Agregar Agentes" << std::endl;
        std::cout << "2. Eliminar Agentes" << std::endl;
        std::cout << "3. Modifiar Agentes" << std::endl;
        std::cout << "4. Mostrar Agentes" << std::endl;
        std::cout << "5. buscar" << std::endl;
        std::cout << "6. Ordenar Agentes" << std::endl;
        std::cout << "7. Leer del disco" << std::endl;
        std::cout << "8. Escribir al disco" << std::endl;
        std::cout << "9. Eliminar todos los agentes" << std::endl;
        std::cout << "10. Salir" << std::endl << std::endl;

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
                searchAgent(aAgentList);
                break;
            case 6:
                sortList(aAgentList);
                break;
            case 7:
                readFromDisk(aAgentList);
                break;
            case 8:
                writeToDisk(aAgentList);
                break;
            case 9:
                do {
                    std::cout << "Esta seguro de que desea eliminar a todos los agentes [1=si,0=no]:" << std::endl;
                    std::cin >> delAll;
                    std::cin.ignore();
                    if(delAll==1) {
                        aAgentList.deleteAll();
                        std::cout << "Todos los agentes fueron eliminados." << std::endl;
                        }
                    if(delAll==0) {
                        std::cout << "Operacion cancelada." << std::endl;
                        }
                    }
                while(delAll!=1 and delAll!=0);
                keyToContinue();
                break;
            case 10:
                exit();
                break;

            default:
                std::cout << "La opcion elegida no es valida, intente de nuevo";
                keyToContinue();
            }
        }
    while(option!=10);
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

//    do {
//        std::cout << "Desea agregar clientes para el agente [1=si,0=no]: " << std::endl;
//        std::cin >> myInt;
//        std::cin.ignore();
//        }
//    while(myInt!=1 and myInt!=0);

//    if(myInt == 1) {
    new CustomerMenu(myAgent.getCustomerList());
//        }

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

    while(!correctPosition) {
        system("cls");

        std::cout << "Desea ver la lista de Agentes [1=si,0=no]: " << std::endl;
        std::cin >> option;
        std::cin.ignore();
        system("cls");
        if(option)
            showList(aAgentList);

        std::cout << "Ingrese el nombre del agente que desea eliminar (apellido,nombre): ";
        getline(std::cin, myString,',');
        nameToDelete.setLastName(myString);
        getline(std::cin, myString);
        nameToDelete.setFirstName(myString);

        agentToDelete.setName(nameToDelete);

        posToDelete = aAgentList.findData(agentToDelete);

        std::cout << "Esta seguro que desea eliminar este agente [0=no,1=si]:" << std::endl;
        std::cin >> option;
        std::cin.ignore();
        if(option == 1) {
            if(posToDelete == nullptr) {
                std::cout << "El agente que ingreso no existe." << std::endl;
                correctPosition = true;
                keyToContinue();
                }
            else {
                aAgentList.deleteData(posToDelete);
                std::cout << "El agente ha sido eliminado." << std::endl;
                correctPosition = true;
                keyToContinue();
                }
            }
        correctPosition = true;
        }
    }

void AgentMenu::modifyAgent(AgentList& aAgentList) {
    Agent agentToModify;
    Name nameToModify;
    GeneralSchedule scheduleToModify;
    Time timeToModify;
    AgentNode* nodeToModify;
    std::string myStr;
    unsigned int opt,optModify,intToModify;

    system("cls");

    std::cout << "\t\tModificar empleado" << std::endl << std::endl;
    std::cout << "Ingrese el nombre del agente a modificar (apellido,nombre): " << std::endl;
    getline(std::cin, myStr, ',');
    nameToModify.setLastName(myStr);
    getline(std::cin, myStr);
    nameToModify.setFirstName(myStr);

    agentToModify.setName(nameToModify);

    nodeToModify = aAgentList.findData(agentToModify);

    system("cls");

    if(nodeToModify == nullptr) {
        std::cout << "El empleado no existe." << std::endl;
        return;
        }

    do {
        system("cls");
        std::cout << "\t\tModificar empleado" << std::endl << std::endl;
        std::cout << aAgentList.retrieve(nodeToModify).toString(false) << std::endl << std::endl;
        std::cout << "1. Modificar Empleado" << std::endl;
        std::cout << "2. Modificar lista de empleado" << std::endl;
        std::cout << "3. Volver al menu" << std::endl;
        std::cin >> opt;
        std::cin.ignore();

        switch(opt) {
            case 1:
                do {
                    system("cls");

                    std::cout << "\t\tModificar empleado" << std::endl << std::endl;

                    std::cout << aAgentList.retrieve(nodeToModify).toString(false) << std::endl;

                    std::cout << "1.Nombre" << std::endl;
                    std::cout << "2.Horario" << std::endl;
                    std::cout << "3.Numero de empleado" << std::endl;
                    std::cout << "4.Numero de extension" << std::endl;
                    std::cout << "5.Horas trabajadas" << std::endl;
                    std::cout << "6.Especialidad" << std::endl;
                    std::cout << "7.Volver al menu anterior" << std::endl;
                    std::cin >> optModify;
                    std::cin.ignore();

                    switch(optModify) {
                        case 1:
                            std::cout << "Ingrese la correccion del nombre (apellido,nombre):" << std::endl;
                            getline(std::cin, myStr,',');
                            nameToModify.setLastName(myStr);
                            getline(std::cin, myStr);
                            nameToModify.setFirstName(myStr);

                            aAgentList.retrieve(nodeToModify).setName(nameToModify);

                            break;
                        case 2:
                            std::cout << "Ingrese el nuevo hora de entrada (HH:MM):" << std::endl;
                            getline(std::cin,myStr, ':');
                            timeToModify.setHours(atoi(myStr.c_str()));
                            getline(std::cin, myStr);
                            timeToModify.setMinutes(atoi(myStr.c_str()));

                            scheduleToModify.setStartTime(timeToModify);

                            std::cout << "Ingrese el nuevo hora de salida (HH:MM):" << std::endl;
                            getline(std::cin,myStr, ':');
                            timeToModify.setHours(atoi(myStr.c_str()));
                            getline(std::cin, myStr);
                            timeToModify.setMinutes(atoi(myStr.c_str()));

                            scheduleToModify.setEndTime(timeToModify);

                            aAgentList.retrieve(nodeToModify).setSchedule(scheduleToModify);

                            break;
                        case 3:
                            std::cout << "Ingrese el nuevo numero de empleado:" << std::endl;
                            std::cin >> intToModify;

                            aAgentList.retrieve(nodeToModify).setEmployeeNumber(intToModify);

                            break;
                        case 4:
                            std::cout << "Ingrese el nuevo numero de extension:" << std::endl;
                            std::cin >> intToModify;
                            aAgentList.retrieve(nodeToModify).setExtensionNumber(intToModify);

                            break;
                        case 5:
                            std::cout << "Ingrese el nuevo valor de horas trabajadas:" << std::endl;
                            std::cin >> intToModify;
                            aAgentList.retrieve(nodeToModify).setWorkedHours(intToModify);

                            break;
                        case 6:
                            std::cout << "Ingrese la nueva especialidad: " << std::endl;
                            getline(std::cin, myStr);
                            aAgentList.retrieve(nodeToModify).setSpeciality(myStr);

                            break;
                        case 7:
                            std::cout << "Saliendo..." << std::endl;

                            break;
                        default:
                            system("cls");
                            std::cout << "La opcion que eligio no es correcta, ingrese una nueva opcion:"<<std::endl;
                            keyToContinue();
                        }
                    }
                while(optModify != 7);
                break;

            case 2:
                new CustomerMenu(aAgentList.retrieve(nodeToModify).getCustomerList());
                break;

            case 3:
                std::cout << "Saliendo..."<< std::endl;
                break;
            default:
                system("cls");
                std::cout << "La opcion que ingreso no es correcta, intente de nuevo:"<< std::endl;
                keyToContinue();
            }
        }
    while(opt != 3);
    }

void AgentMenu::showList(AgentList& aAgentList) {
    unsigned int option;

    system("cls");

    if(!aAgentList.isEmpty()) {
        std::cout << "\t\tLista de agentes" << std::endl << std::endl;

        do {
            std::cout << "Desea que los agentes se muestren con sus clientes [1=si,0=no]: " << std::endl;
            std::cin >> option;
            std::cin.ignore();

            }
        while(option!= 1 and option!=0);
        system("cls");
        std::cout << std::endl << std::endl;

        std::cout << aAgentList.toString(option==1);

        std::cout << std::endl << std::endl;
        }
    else {
        std::cout << "No hay agentes en la lista" << std::endl << std::endl;
        }
    keyToContinue();
    }

void AgentMenu::searchAgent(AgentList& aAgentList) {
    Agent agentToFind;
    Name nameToFind;
    std::string myStr;

    system("cls");

    std::cout << "\t\tBuscar empleado" << std::endl << std::endl;
    std::cout << "Ingrese el nombre del agente que desea buscar (apellido,nombre): " << std::endl;
    getline(std::cin, myStr, ',');
    nameToFind.setLastName(myStr);
    getline(std::cin, myStr);
    nameToFind.setFirstName(myStr);

    agentToFind.setName(nameToFind);

    std::cout << aAgentList.retrieve(aAgentList.findData(agentToFind)).toString(true) << std::endl;
    keyToContinue();
    }

void AgentMenu::sortList(AgentList& aAgentList) {
    system("cls");
    unsigned int opt;

    std::cout << "Seleccione como desea ordenar a los agentes:" << std::endl;
    std::cout << "1. Ordenar por nombre" << std::endl;
    std::cout << "2. Ordenar por Especialidad" << std::endl;
    std::cout << "3. Salir sin ordenar" << std::endl;
    std::cin >> opt;
    std::cin.ignore();

    switch(opt) {
        case 1:
            std::cout << "Ordenando..." << std::endl;
            aAgentList.sortByName();
            std::cout << "Agentes ordenados." << std::endl;
            keyToContinue();

            break;
        case 2:
            std::cout << "Ordenando..." << std::endl;
            aAgentList.sortBySpeciality();
            std::cout << "Agentes ordenados por especialidad." << std::endl;
            keyToContinue();

            break;
        case 3:
            std::cout << "Saliendo"<<std::endl;
            break;
        default:
            std::cout << "La opcion no es correcta.";
        }
    }

void AgentMenu::writeToDisk(AgentList& aAgentList) {
    system("cls");

    std::cout << "Escribiendo al disco..." << std::endl;

    try {
        aAgentList.writeToDisk("List.agent");
        }
    catch(ListException ex) {
        std::cout << "Algo malo sucedio al tratar de escribir al disco" << std::endl;
        std::cout << "El sistem dice: " << ex.what() << std::endl << std::endl;

        std::cout << "Tratando seguir con la ejecucion del programa..." << std::endl << std::endl;

        keyToContinue();

        return;
        }
    std::cout << "Archivo guardado con exito"<< std::endl << std::endl;

    keyToContinue();
    }

void AgentMenu::readFromDisk(AgentList& aAgentList) {
    system("cls");

    std::cout << "Leyendo del disco..." << std::endl;

    try {
        aAgentList.readFromDisk("List.agent");
        }
    catch(ListException ex){
        std::cout << "No se pudo leer el archivo" << std::endl;
        std::cout << "El sistema reporta: " << ex.what() << std::endl;
        keyToContinue();
        return;
        }
    std::cout << "El archivo fue cargado a la lista exitosamente." << std::endl;
    keyToContinue();
    }

void AgentMenu::exit() {
    return;
    }

AgentMenu::AgentMenu(AgentList& aAgentList) {
    mainMenu(aAgentList);
    }

