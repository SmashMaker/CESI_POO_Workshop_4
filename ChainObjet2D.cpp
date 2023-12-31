//
// Created by paull on 21/11/2023.
//

#include "ChainObjet2D.h"

// Check if head is leading to the tail
void ChainObjet2D::checkIfAllGood() {
    Objet2D* supposed_tail = processTail();
    if(this->tail != supposed_tail) {
        std::cout << "Error: Head is not leading to the tail" << std::endl << std::endl;
    } else {std::cout << "All good Sir !" << std::endl << std::endl;}
}

Objet2D* ChainObjet2D::processTail() {
    Objet2D* current_obj = this->getHead();

    // Go all the way through the chain
    while (current_obj->getSuivant() != nullptr && current_obj->getSuivant() != current_obj){
        current_obj = current_obj->getSuivant();
    }

    return current_obj;
}


// Construct
ChainObjet2D::ChainObjet2D(void) {
    this->head = nullptr;
    this->tail = nullptr;
}

ChainObjet2D::ChainObjet2D(Objet2D *head) {
    this->head = head;
    this->tail = processTail();
}

ChainObjet2D::ChainObjet2D(Objet2D *head, Objet2D *tail) {
    this->head = head;
    this->tail = tail;
    checkIfAllGood();
}


// Setters & Getters
void ChainObjet2D::setHead(Objet2D *obj) {
    this->head = obj;
    this->tail = processTail();
}

void ChainObjet2D::setTail(Objet2D *obj) {
    this->tail = obj;
    checkIfAllGood();
}

Objet2D *ChainObjet2D::getHead() {
    return this->head;
}

Objet2D *ChainObjet2D::getTail() {
    return this->tail;
}


// Methods
Objet2D *ChainObjet2D::getFromIndex(int index, bool error_if_out_of_range) {
    Objet2D* current_obj = this->getHead();

    // Go through the chain
    for(int i = 0; i < index; i++) {
        current_obj = current_obj->getSuivant();

        if(current_obj == nullptr) {
            if (error_if_out_of_range) {
                std::cout << "Error: Index out of range" << std::endl;
                return nullptr;
            } else {return current_obj;}
        }
    }
    return current_obj;
}

void ChainObjet2D::addAtIndex(Objet2D *new_obj, int index) {
    Objet2D* current_obj = this->getFromIndex(index, true);
    if(current_obj == nullptr) {
        this->addAtTail(new_obj);
    } else {
        new_obj->setSuivant(current_obj->getSuivant());
        current_obj->setSuivant(new_obj);
    }
}

void ChainObjet2D::addAtHead(Objet2D *new_obj) {
    new_obj->setSuivant(this->getHead());
    this->setHead(new_obj);
}

void ChainObjet2D::addAtTail(Objet2D *new_obj) {
    Objet2D *old_tail = this->getTail();
    old_tail->setSuivant(new_obj);
    this->setTail(new_obj);
}

void ChainObjet2D::removeFromIndex(int index) {

}

void ChainObjet2D::removeHead() {
    Objet2D* second_head = this->getHead()->getSuivant();
    this->setHead(second_head);
}

void ChainObjet2D::removeTail() {
    Objet2D* current_obj1 = this->getHead()->getSuivant();
    Objet2D* current_obj2 = this->getHead();

    if(current_obj1 == nullptr) { // Si il n'y a qu'un seul élément
        this->setHead(nullptr);
        this->setTail(nullptr);
    } else { // Si il y a plus d'un élément
        while(current_obj1->getSuivant() != nullptr) {
            current_obj1 = current_obj1->getSuivant();
            current_obj2 = current_obj2->getSuivant();
        }
        current_obj2->setSuivant(nullptr);
        this->setTail(current_obj2);
    }
}

void ChainObjet2D::deleteFromIndex(int index) {

}

void ChainObjet2D::deleteHead() {

}

void ChainObjet2D::deleteTail() {

}

void ChainObjet2D::printChain() {
    std::cout << "Printing chain" << std::endl;
    Objet2D* current_obj = this->getHead();
    while(current_obj != nullptr) {
        std::cout << current_obj->afficheInfo() << std::endl;
        current_obj = current_obj->getSuivant();
    }
    std::cout << std::endl;
}

