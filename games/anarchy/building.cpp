// A basic building. It does nothing besides burn down. Other Buildings inherit from this class.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "building.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::Building::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "bribed")
    {
        this->bribed = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "buildingEast")
    {
        this->buildingEast = (Anarchy::Building*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "buildingNorth")
    {
        this->buildingNorth = (Anarchy::Building*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "buildingSouth")
    {
        this->buildingSouth = (Anarchy::Building*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "buildingWest")
    {
        this->buildingWest = (Anarchy::Building*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "fire")
    {
        this->fire = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "health")
    {
        this->health = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "isHeadquarters")
    {
        this->isHeadquarters = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Anarchy::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "x")
    {
        this->x = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "y")
    {
        this->y = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Building then you can code them here.
// <<-- /Creer-Merge: methods -->>
