/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "MaintenanceValues.h"

#include "Playerbots.h"

bool CanMoveAroundValue::Calculate()
{
    if (bot->IsInCombat())
        return false;

    if (bot->GetTradeData())
        return false;

    if (botAI->HasStrategy("stay", BOT_STATE_NON_COMBAT))
        return false;

    if (!AI_VALUE(bool, "group ready"))
        return false;

    return true;
}

bool ShouldHomeBindValue::Calculate()
{
    return false;
    //return AI_VALUE2(float, "distance", "home bind") > 1000.0f;
}

bool ShouldRepairValue::Calculate()
{
    return false;
    //return AI_VALUE(uint8, "durability") < 80;
}

bool CanRepairValue::Calculate()
{
    return false;
    //return AI_VALUE(uint8, "durability") < 100 &&
    //    AI_VALUE(uint32, "repair cost") < AI_VALUE2(uint32, "free money for", (uint32)NeedMoneyFor::repair);
}

bool ShouldSellValue::Calculate()
{
    return false;
    //return AI_VALUE(uint8, "bag space") > 80;
}

bool CanSellValue::Calculate()
{
    return false;
    /*return (AI_VALUE2(uint32, "item count", "usage " + std::to_string(ITEM_USAGE_VENDOR)) +
        AI_VALUE2(uint32, "item count", "usage " + std::to_string(ITEM_USAGE_AH))) > 1;*/
}

bool CanFightEqualValue::Calculate()
{
    return AI_VALUE(uint8, "durability") > 20;
}

bool CanFightEliteValue::Calculate()
{
    return false;
    /*return bot->GetGroup() && AI_VALUE2(bool, "group and", "can fight equal") &&
        AI_VALUE2(bool, "group and", "following party") && !AI_VALUE2(bool, "group or", "should sell,can sell");*/
}

bool CanFightBossValue::Calculate()
{
    return false;
    //return bot->GetGroup() && bot->GetGroup()->GetMembersCount() > 3 &&
    //    AI_VALUE2(bool, "group and", "can fight equal") && AI_VALUE2(bool, "group and", "following party") &&
    //    !AI_VALUE2(bool, "group or", "should sell,can sell");
}
