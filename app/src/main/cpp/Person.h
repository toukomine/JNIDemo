//
// Created by komine on 2022/4/16.
//

#ifndef JNIDEMO_PERSON_H
#define JNIDEMO_PERSON_H

#include <jni.h>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name,int age);
    string getName();
    int getAge();
    void setName(string name);
    void setAge(int age);
};

#endif //JNIDEMO_PERSON_H
