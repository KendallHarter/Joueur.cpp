// This is a class that manages the Spiders Game and its GameObjects. Competitors should never have to care about this class's existance.
// DO NOT MODIFY THIS FILE


#include "gameManager.h"
#include "ai.h"
// The Game Objects
#include "broodMother.h"
#include "cutter.h"
#include "gameObject.h"
#include "nest.h"
#include "player.h"
#include "spider.h"
#include "spiderling.h"
#include "spitter.h"
#include "weaver.h"
#include "web.h"

Spiders::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->spidersGame = new Spiders::Game();
    this->spidersAI = new Spiders::AI();

    this->setup(this->spidersGame, this->spidersAI);
}

// @overrides
Joueur::BaseGameObject* Spiders::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "BroodMother")
    {
        return new Spiders::BroodMother();
    }
    else if (gameObjectName == "Cutter")
    {
        return new Spiders::Cutter();
    }
    else if (gameObjectName == "GameObject")
    {
        return new Spiders::GameObject();
    }
    else if (gameObjectName == "Nest")
    {
        return new Spiders::Nest();
    }
    else if (gameObjectName == "Player")
    {
        return new Spiders::Player();
    }
    else if (gameObjectName == "Spider")
    {
        return new Spiders::Spider();
    }
    else if (gameObjectName == "Spiderling")
    {
        return new Spiders::Spiderling();
    }
    else if (gameObjectName == "Spitter")
    {
        return new Spiders::Spitter();
    }
    else if (gameObjectName == "Weaver")
    {
        return new Spiders::Weaver();
    }
    else if (gameObjectName == "Web")
    {
        return new Spiders::Web();
    }

    throw new std::runtime_error(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void Spiders::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->spidersAI->player = (Spiders::Player*)(this->getGameObject(playerID));
    this->spidersAI->game = this->spidersGame;
}

// @overrides
boost::property_tree::ptree* Spiders::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);

    if (order == "runTurn")
    {
        auto returned = this->spidersAI->runTurn(
        );

        return this->serialize(returned);
    }

    delete ptrees;
    return nullptr;
}
