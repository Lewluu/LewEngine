#include "Test.h"

Test::Test(){
    std::cout << "Test class created!\n";
}

void Test::setValues(std::string strval, int int8val){
    m_str_value = strval;
    m_int_value = int8val;
}

void Test::callValues(){
    std::cout<< "Test string value is: " << m_str_value << "\n";
    std::cout<< "Test int value value is: " << m_int_value << "\n";
}

Test::~Test(){
    std::cout << "Test class destructed!\n";
}