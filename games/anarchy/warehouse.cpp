// A typical abandoned warehouse... that anarchists hang out in and can be bribed to burn down Buildings.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "warehouse.h"
#include "gameManager.h"

#include "building.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::Warehouse::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::Building::deltaUpdateField(fieldName, delta);

    if (fieldName == "exposure")
    {
        this->exposure = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "fireAdded")
    {
        this->fireAdded = this->gameManager->unserializeInt(delta);
    }
}



int Anarchy::Warehouse::ignite(Anarchy::Building* building)
{
    boost::property_tree::ptree args;
    args.put_child("building", *this->gameManager->serialize(static_cast<BaseGameObject*>(building)));

    auto returned = this->gameManager->runOnServer(*this, "ignite", args);
    return this->gameManager->unserializeInt(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Warehouse then you can code them here.
// <<-- /Creer-Merge: methods -->>
