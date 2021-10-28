#include "Employee.h"


// default constructor
Employee::Employee() {
    id_employee = 0;
    job_position = "" ;
    yearly_salary = 0 ;
}

// constructor member initializer lists
Employee::Employee(int id, std::string position, int wage)
    : id_employee{ id }, job_position{ position }, yearly_salary{ wage } {};


// getters
int Employee::get_id_employee() {return id_employee;}
std::string Employee::get_job_position() { return job_position; }
int Employee::get_yearly_salary() { return yearly_salary; }

// setters
void Employee::set_id_employee(int id) {id_employee = id;}
void Employee::set_job_position(std::string position) { job_position = position; }
void Employee::set_yearly_salary(int pay) { yearly_salary = pay; }

void Employee::show_details()
{
    std::cout << "Employee name: " << get_name() << std::endl;
    std::cout << "Employee id: " << id_employee  << std::endl;
    std::cout << "Employee job title: " << job_position << std::endl;
}
