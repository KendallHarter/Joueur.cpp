// There's an infestation of enemy spiders challenging your queen broodmother spider! Protect her and attack the other broodmother in this turn based, node based, game.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "game.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Game::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGame::deltaUpdateField(fieldName, delta);

    if (fieldName == "currentPlayer")
    {
        this->currentPlayer = (Spiders::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "currentTurn")
    {
        this->currentTurn = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "cutSpeed")
    {
        this->cutSpeed = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "eggsScalar")
    {
        this->eggsScalar = this->gameManager->unserializeDouble(delta);
    }
    else if (fieldName == "initialWebStrength")
    {
        this->initialWebStrength = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "maxTurns")
    {
        this->maxTurns = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "movementSpeed")
    {
        this->movementSpeed = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "nests")
    {
        this->nests = this->gameManager->unserializeVectorOfGameObjects<Spiders::Nest*>(delta, &this->nests);
    }
    else if (fieldName == "players")
    {
        this->players = this->gameManager->unserializeVectorOfGameObjects<Spiders::Player*>(delta, &this->players);
    }
    else if (fieldName == "session")
    {
        this->session = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "spitSpeed")
    {
        this->spitSpeed = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "weavePower")
    {
        this->weavePower = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "weaveSpeed")
    {
        this->weaveSpeed = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "webs")
    {
        this->webs = this->gameManager->unserializeVectorOfGameObjects<Spiders::Web*>(delta, &this->webs);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Game then you can code them here.
// <<-- /Creer-Merge: methods -->>
