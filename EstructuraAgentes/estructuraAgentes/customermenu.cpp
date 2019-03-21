#include "customermenu.h"

void CustomerMenu::keyToContinue() {
    std::cout << "Presione cualquier tecla para continuar.";
    getchar();
    }

CustomerMenu::CustomerMenu(CustomerList& aCustomerList) {
    mainMenu(aCustomerList);
    }


void CustomerMenu::mainMenu(CustomerList& aCustomerList) {
    unsigned int opc;

    do {
        system("cls");

        std::cout << "Menu de Clientes" << std::endl << std::endl;

        std::cout << "1. Agregar cliente" << std::endl;
        std::cout << "2. Eliminar Cliente" << std::endl;
        std::cout << "3. Modificar Cliente" << std::endl;
        std::cout << "4. Mostrar Clientes" << std::endl;
        std::cout << "5. Salir" << std::endl;

        std::cout << "Elija la opcion deseada: " << std::endl;
        std::cin >> opc;
        std::cin.ignore();

        switch(opc) {
            case 1:
                addCustomer(aCustomerList);
                break;
            case 2:
                deleteCustomer(aCustomerList);
                break;
            case 3:
                modifyCustomer(aCustomerList);
                break;
            case 4:
                showList(aCustomerList);
                break;
            case 5:
                exit();
                break;
            default:
                std::cout << "La opcion elegida no es valida, intente de nuevo";
                std::cin >> opc;
                std::cin.ignore();
            }

        }
    while(opc!=5);

    }

void CustomerMenu::addCustomer(CustomerList& aCustomerList) {
    std::string myStr;
    Customer myCustomer;
    Name customerName;
    Time callTime;
    int callDuration;

    std::cout << "Ingrese el apellido del Cliente: " << std::endl;
    getline(std::cin, myStr);
    customerName.setLastName(myStr);

    std::cout << "Ingrese el nombre del cliente: " << std::endl;
    getline(std::cin, myStr);
    customerName.setFirstName(myStr);

    myCustomer.setName(customerName);

    std::cout << "Ingrse la hora de la llamada [HH:MM]: " << std::endl;
    getline(std::cin, myStr,':');
    callTime.setHours(atoi(myStr.c_str()));
    getline(std::cin, myStr);
    callTime.setMinutes(atoi(myStr.c_str()));

    myCustomer.setCallTime(callTime);

    std::cout << "Ingrese la duracion de la llamada (segundos): ";
    std::cin >> callDuration;
    myCustomer.setDuration(callDuration);
    std::cin.ignore();
    try {
        aCustomerList.insertOrdered(myCustomer);
        }
    catch(ListException ex) {
        std::cout << "Error al tratar de insertar el cliente" << std::endl;
        std::cout << ex.what() << std::endl;

        keyToContinue();
        }
    std::cout << "El cliente se ha añadido exitosamente." << std::endl;
    keyToContinue();
    }

void CustomerMenu::deleteCustomer(CustomerList& aCustomerList) {
    std::string myString;
    CustomerNode* position;
    Customer customerToDelete;
    Name nameToDelete;
    bool correctPosition=false;
    int option;

    while(!correctPosition){
        system("cls");
        std::cout << "Desea ver la lista de clientes agregados[1=si/0=no]: " << std::endl;
        std::cin >> option;
        std::cin.ignore();
        if(option)
            showList(aCustomerList);

        std::cout << "Ingrese el nombre del cliente que desea eliminar (apellido,nombre): ";
        getline(std::cin, myString,',');
        nameToDelete.setLastName(myString);
        getline(std::cin, myString);
        nameToDelete.setFirstName(myString);

        customerToDelete.setName(nameToDelete);

        position = aCustomerList.findData(customerToDelete);

        if(position == nullptr){
            std::cout << "El valor que ingreso es incorrecto, desea intentar de nuevo [1=si,0=no]: " << std::endl;
            correctPosition = true;
            keyToContinue();
            }
        else{
            aCustomerList.deleteData(position);
            std::cout << "Cliente eliminado" << std::endl;
            correctPosition = true;
            keyToContinue();
            }
        }
    }

void CustomerMenu::modifyCustomer(CustomerList& aCustomerList) {
    std::string myString;
    int option, newDuration=90;
    Customer customerToModify;
    CustomerNode* auxiliar;
    Name nameToModify;
    Time timeToModify;

    system("cls");
    std::cout << "Desea ver la lista de clientes agregados[1=si/0=no]: " << std::endl;
    std::cin >> option;
    std::cin.ignore();
    if(option)
        showList(aCustomerList);

    std::cout << "Ingrese el nombre del cliente que desea modificar (apellido,nombre): ";
    getline(std::cin, myString,',');
    nameToModify.setLastName(myString);
    getline(std::cin, myString);
    nameToModify.setFirstName(myString);

    customerToModify.setName(nameToModify);

    auxiliar = aCustomerList.findData(customerToModify);

    customerToModify = auxiliar->getCustomerData();

    std::cout << "Ingrese la nueva duracion de la llamada: ";
    std::cin >> newDuration;
    std::cin.ignore();

    customerToModify.setDuration(newDuration);

    auxiliar->setCustomerData(customerToModify);

    std::cout << "Duracion de la llamada modificada." << std::endl;

    keyToContinue();
    }

void CustomerMenu::showList(CustomerList& aCustomerList) {
    system("cls");
    if(aCustomerList.isEmpty()){
        std::cout << "No hay clientes agregados" << std::endl;
        }
    else{
        std::cout << "Listado de clientes" << std::endl << std::endl;
        }
    std::cout << aCustomerList.toString();
    keyToContinue();
    }

void CustomerMenu::exit() {
    return;
    }
