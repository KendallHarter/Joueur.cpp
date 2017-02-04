// The weather effect that will be applied at the end of a turn, which causes fires to spread.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "forecast.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::Forecast::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "controllingPlayer")
    {
        this->controllingPlayer = (Anarchy::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "direction")
    {
        this->direction = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "intensity")
    {
        this->intensity = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Forecast then you can code them here.
// <<-- /Creer-Merge: methods -->>
