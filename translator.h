#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <array>
#include <cstring>

using trMap = std::unordered_map<int /*LANG*/, std::string>;
using stringMap = std::unordered_map <int /*STRING_ID*/, trMap>;

enum LANG
{
    ENGLISH = 0,
    SPANISH,
    GERMAN,
    FRENCH
};

enum STRING_TYPE
{
    DEMO_TICKET = 0,
    CASHOUT_TICKET,
    HANDPAY_TICKET
};

static const stringMap strMap =
{
    {STRING_TYPE::DEMO_TICKET, {{LANG::ENGLISH,"demo_eng"}, {LANG::SPANISH,"demo_spa"}, {LANG::GERMAN,"demo_ger"},{LANG::FRENCH,"demo_fr"}}},
    {STRING_TYPE::CASHOUT_TICKET, {{LANG::ENGLISH,"cash_eng"}, {LANG::SPANISH,"cash_spa"}, {LANG::GERMAN,"cash_ger"},{LANG::FRENCH,"cash_fr"}}},
};

enum CHARSET_ID
{
    UPPERCASE = 0,
    LOWERCASE
};


//TODO map<charset_id, array>
static const std::array<char, 6> chs_words_uppercase = {'A','B','C','D','E','-'};
static const std::array<char, 6> chs_words_lowercase = {'a','b','c','d','e','_'};

template<int StrType, int Lang>
class translator
{
public:
    translator()
    {
        auto it  = strMap.find(StrType);
        if(it != strMap.end())
        {
            map_ = strMap.at(StrType);
        }
        else
        {
            throw std::runtime_error ("cant create object");
            delete this;
        }
    }
    ~translator() {}
    std::string GetString() const
    {
        auto it = map_.find(Lang);
        if(it != map_.end())
        {
            return it->second;
        }
        else return map_.at(0);
    }
    std::string GetDecodedString(int charset_id)
    {
        std::string raw_str = std::move(GetString());
        if(charset_id == CHARSET_ID::LOWERCASE)
        {
        }
        else if(charset_id == CHARSET_ID::UPPERCASE)
        {
            for(size_t i = 0; i<raw_str.size(); ++i)
                for(size_t j = 0; j<chs_words_uppercase.size();++j)
                {
                    //lol
                    #warning("replaced arrays!");
                    if((raw_str[i] - '0') == (chs_words_lowercase[j] - '0'))
                    {
                        raw_str[i] = chs_words_uppercase[j];
                    }
                }
        }
        return raw_str;

    }

    void print() const
    {
        for(const auto & item: map_)
            std::cout<<item.first<<": "<<item.second<<std::endl;
    }

protected:
    trMap map_;
};




#endif // TRANSLATOR_H
