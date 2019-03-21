#include "customernode.h"

CustomerNode::CustomerNode() : next(nullptr) {}

CustomerNode::CustomerNode(const Customer& aCustomerData) : customerData(aCustomerData), next(nullptr) {}

Customer& CustomerNode::getCustomerData() {
    return customerData;
    }

CustomerNode* CustomerNode::getNext() {
    return next;
    }

void CustomerNode::setCustomerData(const Customer& aCustomerData) {
    customerData = aCustomerData;
    }

void CustomerNode::setNext(CustomerNode* aNext) {
    next = aNext;
    }
