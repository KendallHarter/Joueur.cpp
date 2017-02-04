// A player in this game. Every AI controls one player.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "player.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::Player::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Anarchy::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "bribesRemaining")
    {
        this->bribesRemaining = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "buildings")
    {
        this->buildings = this->gameManager->unserializeVectorOfGameObjects<Anarchy::Building*>(delta, &this->buildings);
    }
    else if (fieldName == "clientType")
    {
        this->clientType = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "fireDepartments")
    {
        this->fireDepartments = this->gameManager->unserializeVectorOfGameObjects<Anarchy::FireDepartment*>(delta, &this->fireDepartments);
    }
    else if (fieldName == "headquarters")
    {
        this->headquarters = (Anarchy::Warehouse*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "lost")
    {
        this->lost = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "name")
    {
        this->name = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "opponent")
    {
        this->opponent = (Anarchy::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "policeDepartments")
    {
        this->policeDepartments = this->gameManager->unserializeVectorOfGameObjects<Anarchy::PoliceDepartment*>(delta, &this->policeDepartments);
    }
    else if (fieldName == "reasonLost")
    {
        this->reasonLost = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "reasonWon")
    {
        this->reasonWon = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "timeRemaining")
    {
        this->timeRemaining = this->gameManager->unserializeDouble(delta);
    }
    else if (fieldName == "warehouses")
    {
        this->warehouses = this->gameManager->unserializeVectorOfGameObjects<Anarchy::Warehouse*>(delta, &this->warehouses);
    }
    else if (fieldName == "weatherStations")
    {
        this->weatherStations = this->gameManager->unserializeVectorOfGameObjects<Anarchy::WeatherStation*>(delta, &this->weatherStations);
    }
    else if (fieldName == "won")
    {
        this->won = this->gameManager->unserializeBool(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Player then you can code them here.
// <<-- /Creer-Merge: methods -->>
