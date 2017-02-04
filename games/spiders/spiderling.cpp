// A Spider spawned by the BroodMother.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "spiderling.h"
#include "gameManager.h"

#include "web.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Spiderling::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::Spider::deltaUpdateField(fieldName, delta);

    if (fieldName == "busy")
    {
        this->busy = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "movingOnWeb")
    {
        this->movingOnWeb = (Spiders::Web*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "movingToNest")
    {
        this->movingToNest = (Spiders::Nest*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "numberOfCoworkers")
    {
        this->numberOfCoworkers = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "workRemaining")
    {
        this->workRemaining = this->gameManager->unserializeDouble(delta);
    }
}



bool Spiders::Spiderling::attack(Spiders::Spiderling* spiderling)
{
    boost::property_tree::ptree args;
    args.put_child("spiderling", *this->gameManager->serialize(static_cast<BaseGameObject*>(spiderling)));

    auto returned = this->gameManager->runOnServer(*this, "attack", args);
    return this->gameManager->unserializeBool(*returned);
}

bool Spiders::Spiderling::move(Spiders::Web* web)
{
    boost::property_tree::ptree args;
    args.put_child("web", *this->gameManager->serialize(static_cast<BaseGameObject*>(web)));

    auto returned = this->gameManager->runOnServer(*this, "move", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Spiderling then you can code them here.
// <<-- /Creer-Merge: methods -->>
