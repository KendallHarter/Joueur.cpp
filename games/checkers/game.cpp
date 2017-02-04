// The simple version of American Checkers. An 8x8 board with 12 checkers on each side that must move diagonally to the opposing side until kinged.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "game.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Checkers::Game::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGame::deltaUpdateField(fieldName, delta);

    if (fieldName == "boardHeight")
    {
        this->boardHeight = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "boardWidth")
    {
        this->boardWidth = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "checkerMoved")
    {
        this->checkerMoved = (Checkers::Checker*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "checkerMovedJumped")
    {
        this->checkerMovedJumped = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "checkers")
    {
        this->checkers = this->gameManager->unserializeVectorOfGameObjects<Checkers::Checker*>(delta, &this->checkers);
    }
    else if (fieldName == "currentPlayer")
    {
        this->currentPlayer = (Checkers::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "currentTurn")
    {
        this->currentTurn = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "maxTurns")
    {
        this->maxTurns = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "players")
    {
        this->players = this->gameManager->unserializeVectorOfGameObjects<Checkers::Player*>(delta, &this->players);
    }
    else if (fieldName == "session")
    {
        this->session = this->gameManager->unserializeString(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Game then you can code them here.
// <<-- /Creer-Merge: methods -->>
