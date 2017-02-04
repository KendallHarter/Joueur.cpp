// This is a class that manages the Checkers Game and its GameObjects. Competitors should never have to care about this class's existance.
// DO NOT MODIFY THIS FILE


#include "gameManager.h"
#include "ai.h"
// The Game Objects
#include "checker.h"
#include "gameObject.h"
#include "player.h"

Checkers::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->checkersGame = new Checkers::Game();
    this->checkersAI = new Checkers::AI();

    this->setup(this->checkersGame, this->checkersAI);
}

// @overrides
Joueur::BaseGameObject* Checkers::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "Checker")
    {
        return new Checkers::Checker();
    }
    else if (gameObjectName == "GameObject")
    {
        return new Checkers::GameObject();
    }
    else if (gameObjectName == "Player")
    {
        return new Checkers::Player();
    }

    throw new std::runtime_error(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void Checkers::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->checkersAI->player = (Checkers::Player*)(this->getGameObject(playerID));
    this->checkersAI->game = this->checkersGame;
}

// @overrides
boost::property_tree::ptree* Checkers::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);

    if (order == "gotCaptured")
    {
        this->checkersAI->runTurn(
            unserializeGameObject(ptrees[0])
        );
    }
    if (order == "runTurn")
    {
        auto returned = this->checkersAI->runTurn(
        );

        return this->serialize(returned);
    }

    delete ptrees;
    return nullptr;
}
