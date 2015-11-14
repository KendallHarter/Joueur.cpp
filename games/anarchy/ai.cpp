// Generated by Creer at 08:40PM on November 07, 2015 UTC, git hash: '1b69e788060071d644dd7b8745dca107577844e1'
// This is where you build your AI for the Checkers game.

#include "ai.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here for your AI.
// <<-- /Creer-Merge: includes -->>



/// <summary>
/// This returns your AI's name to the game server. Just replace the string.
/// </summary>
/// <returns>string of you AI's name.</returns>
std::string Anarchy::AI::getName()
{
    // <<-- Creer-Merge: get-name -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    return "Anarchy C++ Player"; // REPLACE THIS WITH YOUR TEAM NAME!
    // <<-- /Creer-Merge: get-name -->>
}

/// <summary>
/// This is automatically called when the game first starts, once the Game object and all GameObjects have been initialized, but before any players do anything.
/// </summary>
void Anarchy::AI::start()
{
    // <<-- Creer-Merge: start -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // This is a good place to initialize any variables you add to your AI, or start tracking game objects.
    // <<-- /Creer-Merge: start -->>
}

/// <summary>
/// This is automatically called every time the game (or anything in it) updates.
/// </summary>
void Anarchy::AI::gameUpdated()
{
    // <<-- Creer-Merge: game-updated -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // If a function you call triggers an update this will be called before that function returns.
    // <<-- /Creer-Merge: game-updated -->>
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if your player won, false otherwise</param>
/// <param name="reason">a string explaining why you won or lost</param>
void Anarchy::AI::ended(bool won, std::string reason)
{
    // <<-- Creer-Merge: ended -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can do any cleanup of you AI here, or do custom logging. After this function returns the application will close.
    // <<-- /Creer-Merge: ended -->>
}

#include <iostream>

/// <summary>
/// This is called every time the AI is asked to respond with a command during their turn
/// </summary>
/// <returns>represents if you want to end your turn. true means end the turn, false means to keep your turn going and re-call runTurn()</returns>
bool Anarchy::AI::runTurn()
{
    // <<-- Creer-Merge: runTurn -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // Get my first warehouse
    auto warehouse = player->warehouses[0];
    if(canBribe(warehouse))
    {
        //ignite the first enemy building unless it's a headquarters
        auto building = player->otherPlayer->buildings[0];
        if(!building->isHeadquarters)
        {
            warehouse->ignite(building);
        }
    }
    // Get my first fire department
    auto fireDepartment = player->fireDepartments[0];
    if(canBribe(fireDepartment))
    {
        //extinguish the first building unless it's headquarters
        auto toExtinguish = player->buildings[0];
        if(!toExtinguish->isHeadquarters)
        {
            fireDepartment->extinguish(toExtinguish);
        }
    }
    // Get my first police department
    auto policeDepartment = player->policeDepartments[0];
    if(canBribe(policeDepartment))
    {
        // Get the first enemy warehouse
        auto toRaid = player->otherPlayer->warehouses[0];
        // Make sure it is alive to be raided
        if(toRaid->health > 0)
        {
            // Raid the first enemy warehouse
            policeDepartment->raid(player->otherPlayer->warehouses[0]);
        }
    }
    // Get my first weather station
    auto weatherStation1 = player->weatherStations[0];
    if(canBribe(weatherStation1))
    {
        // Make sure the intensity isn't at max
        if(game->nextForecast->intensity < game->maxForecastIntensity)
        {
            weatherStation1->intensify();
        }
        else
        {
            // Otherwise decrease the intensity
            weatherStation1->intensify(true);
        }
    }
    // Get my second weather station
    auto weatherStation2 = player->weatherStations[1];
    if(canBribe(weatherStation2))
    {
        // Rotate clockwise
        weatherStation2->rotate();
    }
    return true;
    // <<-- /Creer-Merge: runTurn -->>
}

// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional methods here for your AI to call
bool Anarchy::AI::canBribe(const Building* toTest) const
{
    //make sure it has health, hasn't been bribed, and you are the owner
    return (toTest->health > 0 &&
            !toTest->bribed &&
            toTest->owner == player);
}
// <<-- /Creer-Merge: methods -->>
