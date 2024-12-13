#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>

class Person {
public:
    std::string name = "";
    int ss = 1;
};

class Education : public Person {
public:
    int attainment = 0;
    std::string institution = "";
};

class Service : public Education {
public:
    int personnel_number = 0;
    std::string department = "";
};

class PersonRecord : public Service {
public:
    std::shared_ptr<PersonRecord> supervisor = nullptr;
};

std::shared_ptr<PersonRecord> entry(const std::string& name, int ss, int attainment, const std::string& institution,
                                    int personnel_number, const std::string& department, std::shared_ptr<PersonRecord> supervisor);

#endif // PERSON_H