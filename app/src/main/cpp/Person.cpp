//
// Created by komine on 2022/4/16.
//

#include "Person.h"

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}
