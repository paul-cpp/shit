#include <iostream>
#include "translator.h"
using namespace std;

int main() try
{
    translator<STRING_TYPE::CASHOUT_TICKET, LANG::GERMAN> tr;
    tr.print();
    std::cout<<tr.GetString()<<std::endl;
    std::cout<< tr.GetDecodedString(CHARSET_ID::UPPERCASE) << std::endl;
    return 0;
}
catch(std::exception& e)
{
    std::cout<< e.what() << std::endl;
}

