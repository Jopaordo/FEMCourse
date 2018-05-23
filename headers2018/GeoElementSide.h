//
//  GeoElementSide.h
//  FemSC
//
//  Created by Philippe Devloo on 16/04/18.
//

#include "GeoElement.h"

#ifndef GeoElementSide_h
#define GeoElementSide_h

class GeoElement;

class GeoElementSide
{
    //cambie a publico estas variables
//    // Associated element
//    GeoElement *fElement;
//
//
//
//    // Associated side
//    int fSide;
    
     // Associated neighbour //MODIFUQUE
    std::vector<GeoElementSide > neighboursSide;

    
public:

        // Associated element
        GeoElement *fElement;
    
    
    
        // Associated side
        int fSide;

    // Default Constructor of GeoElementSide
    GeoElementSide();
    
    // Constructor of GeoElementSide
    GeoElementSide(GeoElement *element, int side) : fElement(element), fSide(side)
    {

    }
    
    // Copy constructor of GeoElementSide
    GeoElementSide(const GeoElementSide &copy);
    
    // Operator of copy 
    GeoElementSide &operator=(const GeoElementSide &copy);
    
    // Return the associated element
    GeoElement *Element() const
    {
        return fElement;
    }

    // Return the associated side
    int Side() const
    {
        return fSide;
    }

    // Return neighbour element of a given side
    GeoElementSide Neighbour() const;
    
    void SetNeighbour( GeoElementSide &neighbour);
    
};
#endif /* GeoElementSide_h */
