#include "Log.h"

Log::Log(){
    std::cout << "Log class created!\n";
}

void Log::setFormat(FORMAT format){
    switch(format){
        case L:
            m_format = "- LEW ENGINE";
            break;
        case LT:
            m_format = "- LEW ENGINE - TIME";
            break;
        case LDT:
            m_format = "- LEW ENGINE - DATE - TIME";
            break;
        case LTD:
            m_format = "- LEW ENGINE - TIME - DATE";
            break;
        default:
            m_format = "- LEW ENGINE - TIME";
            break;
    }
}

void Log::Info(std::string info){
    std::cout << "[::: INFO " << m_format << " :::] " << info << "\n";
}

Log::~Log(){
    std::cout << "Log class destructed!\n";
}