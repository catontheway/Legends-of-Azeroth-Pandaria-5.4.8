#ifndef _PLAYERBOT_MANASAVELEVELVALUE_H
#define _PLAYERBOT_MANASAVELEVELVALUE_H

#include "Value.h"

class PlayerbotAI;

class ManaSaveLevelValue : public ManualSetValue<double>
{
public:
    ManaSaveLevelValue(PlayerbotAI* botAI) : ManualSetValue<double>(botAI, 1.0, "mana save level") {}

    std::string const Save()
    {
        std::ostringstream out;
        out << value;
        return out.str();
    }

    bool Load(std::string const text)
    {
        value = atof(text.c_str());
        return true;
    }
};

#endif
