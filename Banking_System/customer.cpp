#include "customer.h"


// default constructor
Customer::Customer()
{
    id_number = 0;
}

// constructor member initializer lists

// getters
int Customer::get_id_number() {return id_number;}
// setters


void Customer::show_details()
{
    std::cout << "Customer name: " << get_name() << std::endl;
    std::cout << "Customer id: " << get_id_number()  << std::endl;
    // should show balance as well
}
