// A Spider in the game. The most basic unit.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SPIDERS_SPIDER_H
#define JOUEUR_SPIDERS_SPIDER_H

#include "spiders.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Spider in the game. The most basic unit.
/// </summary>
class Spiders::Spider : public Spiders::GameObject
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Spider() {};
        ~Spider() {};

    public:
        /// <summary>
        /// If this Spider is dead and has been removed from the game.
        /// </summary>
        bool isDead;

        /// <summary>
        /// The Nest that this Spider is currently on. nullptr when moving on a Web.
        /// </summary>
        Spiders::Nest* nest;

        /// <summary>
        /// The Player that owns this Spider, and can command it.
        /// </summary>
        Spiders::Player* owner;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
