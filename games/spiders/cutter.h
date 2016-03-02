// Generated by Creer at 04:24PM on March 02, 2016 UTC, git hash: '0cc14891fb0c7c6bec65a23a8e2497e80f8827c1'
// A Spiderling that can cut existing Webs.

#ifndef JOUEUR_SPIDERS_CUTTER_H
#define JOUEUR_SPIDERS_CUTTER_H

#include "spiders.h"
#include "spiderling.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Spiderling that can cut existing Webs.
/// </summary>
class Spiders::Cutter : public Spiders::Spiderling
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Cutter() {};
        ~Cutter() {};

    public:
        /// <summary>
        /// The Web that this Cutter is trying to cut. Null if not cutting.
        /// </summary>
        Spiders::Nest* cuttingWeb;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Cuts a web, destroying it, and any Spiderlings on it.
        /// </summary>
        /// <param name="web">The web you want to Cut. Must be connected to the Nest this Cutter is currently on.</param>
        /// <returns>True if the cut was successfully started, false otherwise.</returns>
        bool cut(Spiders::Web* web);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
