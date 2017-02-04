// A player in this game. Every AI controls one player.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_ANARCHY_PLAYER_H
#define JOUEUR_ANARCHY_PLAYER_H

#include "anarchy.h"
#include "gameObject.h"
#include "../../joueur/basePlayer.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Anarchy::Player : public Anarchy::GameObject, public Joueur::BasePlayer
{
    friend Anarchy::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Player() {};
        ~Player() {};

    public:
        /// <summary>
        /// How many bribes this player has remaining to use during their turn. Each action a Building does costs 1 bribe. Any unused bribes are lost at the end of the player's turn.
        /// </summary>
        int bribesRemaining;

        /// <summary>
        /// All the buildings owned by this player.
        /// </summary>
        std::vector<Anarchy::Building*> buildings;

        /// <summary>
        /// What type of client this is, e.g. 'Python', 'JavaScript', or some other language. For potential data mining purposes.
        /// </summary>
        std::string clientType;

        /// <summary>
        /// All the FireDepartments owned by this player.
        /// </summary>
        std::vector<Anarchy::FireDepartment*> fireDepartments;

        /// <summary>
        /// The Warehouse that serves as this player's headquarters and has extra health. If this gets destroyed they lose.
        /// </summary>
        Anarchy::Warehouse* headquarters;

        /// <summary>
        /// The name of the player.
        /// </summary>
        std::string name;

        /// <summary>
        /// This player's opponent in the game.
        /// </summary>
        Anarchy::Player* opponent;

        /// <summary>
        /// All the PoliceDepartments owned by this player.
        /// </summary>
        std::vector<Anarchy::PoliceDepartment*> policeDepartments;

        /// <summary>
        /// The amount of time (in ns) remaining for this AI to send commands.
        /// </summary>
        double timeRemaining;

        /// <summary>
        /// All the warehouses owned by this player. Includes the Headquarters.
        /// </summary>
        std::vector<Anarchy::Warehouse*> warehouses;

        /// <summary>
        /// All the WeatherStations owned by this player.
        /// </summary>
        std::vector<Anarchy::WeatherStation*> weatherStations;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
