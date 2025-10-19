#pragma once
#include <iostream>
#include <string>

enum FORMAT{
    L,
    LT,
    LDT,
    LTD
};

class Log{
    public:
        Log();
        ~Log();
        void setFormat(FORMAT format);
        void Info(std::string info);
    private:
        std::string m_format;
};