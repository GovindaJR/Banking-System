#include "User.h"
#include<iostream>

// getters
std::string User::get_name() { return name; }
std::string User::get_email() { return email; }
std::string User::get_password() { return password; }

// setters
void User::set_name(std::string person_name) { name = person_name; }
void User::set_email(std::string person_email) { email = person_email; }
void User::set_password(std::string person_password) { password = person_password; }

