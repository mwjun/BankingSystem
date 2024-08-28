#ifndef CPERSONINFO_H
#define CPERSONINFO_H

#include <string>

class CPersonInfo
{
private:
    std::string firstName;
    std::string lastName;
    int age;
    double checkingAccount;
    double savingsAccount;

public:
    CPersonInfo() : firstName(""), lastName(""), age(0), checkingAccount(0.0), savingsAccount(0.0) { }
    CPersonInfo(std::string fName, std::string lName, int a, double checking, double savings) :
        firstName(fName), lastName(lName), age(a), checkingAccount(checking), savingsAccount(savings) { }

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    double getCheckingAccount() const { return checkingAccount; }
    double getSavingsAccount() const { return savingsAccount; }

    bool operator<(const CPersonInfo& rhs) const { return age < rhs.age; }
    bool operator>(const CPersonInfo& rhs) const { return age > rhs.age; }
    bool operator==(const CPersonInfo& rhs) const { return age == rhs.age; }

    friend std::ostream& operator<<(std::ostream& os, const CPersonInfo& person);
};

std::ostream& operator<<(std::ostream& os, const CPersonInfo& person)
{
    os << person.firstName << " " << person.lastName << " Age: " << person.age
       << " Checking: " << person.checkingAccount << " Savings: " << person.savingsAccount;
    return os;
}

#endif