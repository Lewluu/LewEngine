#pragma once
#include <iostream>
#include <string>

class Test {
    public:
        Test(/* args */);
        ~Test();
        void setValues(std::string strval, int int8val);
        void callValues();
    
    private:
        std::string m_str_value;
        int m_int_value;
};