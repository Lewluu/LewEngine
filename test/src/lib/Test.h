#pragma once
#include <string>

class Test {
    public:
        Test(/* args */);
        ~Test();
        void setValues(std::string strval, int8_t int8vl);
        void callValues();
    
    private:
        std::string _str_value;
        int8_t _int8_value;
};

Test::Test(/* args */)
{
}

Test::~Test()
{
}