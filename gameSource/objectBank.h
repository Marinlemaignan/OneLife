#ifndef OBJECT_BANK_INCLUDED
#define OBJECT_BANK_INCLUDED


#include "minorGems/game/doublePair.h"


typedef struct ObjectRecord {
        int id;
        
        char *description;

        // can it go into a container
        char containable;
        
        // can it not be picked up
        char permanent;


        // chance of occurrence naturally on map
        // value between 0 and 1 inclusive
        // Note that there's an overall chance-of-anything that is applied
        // first (controls density of map), so even if an object's value is
        // 1, it will not appear everywhere.
        // Furthermore, this value is a weight that is a fraction of the
        // total sum weight of all objects.
        float mapChance;
        
        int heatValue;
        
        // between 0 and 1, how much heat is transmitted
        float rValue;

        char person;
        
        int foodValue;
        
        // multiplier on walking speed when holding
        float speedMult;
        

        // if it is a container, how many slots?
        // 0 if not a container
        int numSlots;

        doublePair *slotPos;
        

        int numSprites;
        
        int *sprites;
        
        doublePair *spritePos;

        double *spriteRot;

        
    } ObjectRecord;





// loads from objects folder
void initObjectBank();


void freeObjectBank();


// useful during development when new object property added
void resaveAll();



ObjectRecord *getObject( int inID );


// return array destroyed by caller, NULL if none found
ObjectRecord **searchObjects( const char *inSearch, 
                              int inNumToSkip, 
                              int inNumToGet, 
                              int *outNumResults, int *outNumRemaining );


int addObject( const char *inDescription,
               char inContainable,
               char inPermanent,
               float inMapChance,
               int inHeatValue,
               float inRValue,
               char inPerson,
               int inFoodValue,
               float inSpeedMult,
               int inNumSlots, doublePair *inSlotPos,
               int inNumSprites, int *inSprites, 
               doublePair *inSpritePos,
               double *inSpriteRot,
               int inReplaceID = -1 );




// inAge -1 for no age modifier
void drawObject( ObjectRecord *inObject, doublePair inPos, 
                 char inFlipH, double inAge );


void drawObject( ObjectRecord *inObject, doublePair inPos,
                 char inFlipH,
                 double inAge,
                 int inNumContained, int *inContainedIDs );



void deleteObjectFromBank( int inID );


char isSpriteUsed( int inSpriteID );



int getNumContainerSlots( int inID );

char isContainable( int inID );



// -1 if no person object exists
int getRandomPersonObject();



#endif
