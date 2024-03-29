#include <iostream>
#include <cstring>
#include "person.pb.h"   
#include "address_book.pb.h"
#include "date_pkg.pb.h"

void set_person(PERSON::Person& per,const char* name, const char* email, int ID, int date, int month, int year)
{
    my::date::module::Date birthday;
    birthday.set_year(year);
    birthday.set_month(month);
    birthday.set_day(date);


    per.set_name(name);
    per.set_id(ID);
    per.set_email(email);
    per.mutable_birthday()->CopyFrom(birthday);  // Set the birthday
}

void print_person(PERSON::Person& per)
{
    // if(per.has_name())
    // {
    //     std::cout << " Name: " << *per.mutable_name() << std::endl;
    // }
    // else
    // {
    //     std::cout << "Name is not defined" << std::endl;
    // }
    // if(per.has_email())
    // {
    //     std::cout << " Email: " << *per.mutable_email() << std::endl;
    // }
    // if(per.has_id())
    // {
    //     std::cout << " ID: " << per.id() << std::endl;
    // }

    std::cout << per.DebugString() << std::endl;

}

int main(int argc, char** v)
{
    PERSON::Person person01, person02, person03, person04;

    //my.date.module::Date d1;
    set_person(person01, "person01", "person01@xyz.com", 01, 1, 2, 1993);
    set_person(person02, "person02", "person02@xyz.com", 02, 4, 5, 1995);

    print_person(person01);
    print_person(person02);

    // ADDRESS_BOOK::AddressBook address_book;
    // address_book.add_people()->CopyFrom(person01);
    // address_book.add_people()->CopyFrom(person02);
    





    return EXIT_SUCCESS;
}