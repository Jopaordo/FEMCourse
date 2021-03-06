//
//  Topology1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//

#ifndef Topology1d_h
#define Topology1d_h

#include "DataTypes.h"
#include "IntRule1d.h"

class Topology1d
{
public:
    
    // Type definition for integration rule 1D
    typedef IntRule1d LocIntRule;
    
    // Number of sides associated with 1D elements
    const static int nSides = 3;

    // Number of corner nodes associated with 1D elements
    const static int nCorners = 2;
    
    // Number of nodes associated with a side
    static int NSideNodes(int side);
    
    // Local node index of a node associated with a side
    static int SideNodeIndex(int side, int node);
    
    // Return the enumerated element type
    static ElementType Type();
};

#endif /* Topology1d_h */
