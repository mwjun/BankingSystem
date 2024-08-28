#include <iostream>
#include <fstream>
#include "CBST.h"
#include "CPersonInfo.h"

int main()
{
    CBST<CPersonInfo> personTree;

    std::ifstream inputFile("PersonBankInfo.txt");
    if (!inputFile)
    {
        std::cerr << "Unable to open file PersonBankInfo.txt";
        return 1;
    }

    std::string firstName, lastName;
    int age;
    double checking, savings;

    while (inputFile >> firstName >> lastName >> age >> checking >> savings)
    {
        CPersonInfo person(firstName, lastName, age, checking, savings);
        personTree.add(person);
    }

    inputFile.close();

    // Example of using the tree (e.g., finding, inserting, etc.)
    // personTree.contains(somePerson);
    // personTree.remove(somePerson);

    return 0;
}