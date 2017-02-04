// Can put out fires completely.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_ANARCHY_FIREDEPARTMENT_H
#define JOUEUR_ANARCHY_FIREDEPARTMENT_H

#include "anarchy.h"
#include "building.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// Can put out fires completely.
/// </summary>
class Anarchy::FireDepartment : public Anarchy::Building
{
    friend Anarchy::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        FireDepartment() {};
        ~FireDepartment() {};

    public:
        /// <summary>
        /// The amount of fire removed from a building when bribed to extinguish a building.
        /// </summary>
        int fireExtinguished;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Bribes this FireDepartment to extinguish the some of the fire in a building.
        /// </summary>
        /// <param name="building">The Building you want to extinguish.</param>
        /// <returns>True if the bribe worked, false otherwise.</returns>
        bool extinguish(Anarchy::Building* building);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
