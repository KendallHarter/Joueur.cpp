// A basic building. It does nothing besides burn down. Other Buildings inherit from this class.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_ANARCHY_BUILDING_H
#define JOUEUR_ANARCHY_BUILDING_H

#include "anarchy.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A basic building. It does nothing besides burn down. Other Buildings inherit from this class.
/// </summary>
class Anarchy::Building : public Anarchy::GameObject
{
    friend Anarchy::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Building() {};
        ~Building() {};

    public:
        /// <summary>
        /// When true this building has already been bribed this turn and cannot be bribed again this turn.
        /// </summary>
        bool bribed;

        /// <summary>
        /// The Building directly to the east of this building, or nullptr if not present.
        /// </summary>
        Anarchy::Building* buildingEast;

        /// <summary>
        /// The Building directly to the north of this building, or nullptr if not present.
        /// </summary>
        Anarchy::Building* buildingNorth;

        /// <summary>
        /// The Building directly to the south of this building, or nullptr if not present.
        /// </summary>
        Anarchy::Building* buildingSouth;

        /// <summary>
        /// The Building directly to the west of this building, or nullptr if not present.
        /// </summary>
        Anarchy::Building* buildingWest;

        /// <summary>
        /// How much fire is currently burning the building, and thus how much damage it will take at the end of its owner's turn. 0 means no fire.
        /// </summary>
        int fire;

        /// <summary>
        /// How much health this building currently has. When this reaches 0 the Building has been burned down.
        /// </summary>
        int health;

        /// <summary>
        /// True if this is the Headquarters of the owning player, false otherwise. Burning this down wins the game for the other Player.
        /// </summary>
        bool isHeadquarters;

        /// <summary>
        /// The player that owns this building. If it burns down (health reaches 0) that player gets an additional bribe(s).
        /// </summary>
        Anarchy::Player* owner;

        /// <summary>
        /// The location of the Building along the x-axis.
        /// </summary>
        int x;

        /// <summary>
        /// The location of the Building along the y-axis.
        /// </summary>
        int y;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
