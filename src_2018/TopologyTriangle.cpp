//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//

//
//  Topology1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//


#include "DataTypes.h"
#include "IntRule1d.h"
#include "Topology1d.h"
#include "TopologyQuad.h"
#include "TopologyTriangle.h"
#include "IntRuleQuad.h"
#include "tpanic.h"

typedef IntRuleTriangle LocIntRule;

const int nSides = 7;

const int nCorners = 3;

/// Number of nodes associated with a side
int TopologyTriangle::NSideNodes(int side){
    int u=0;
    if (side<=2){
        return 1;
        u=1;
    }
    if (side>=3 && side<6){
        return 2;
        u=1;
    }
    if (side==6){
        return 3;
        u=1;
    }
    if (u==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
}

/// local node index of a node associated with a side
int TopologyTriangle::SideNodeIndex(int side, int node){
    int u=0;
    int resto=0;
    if(side<3 && node==0){
        return side;
        u=1;
    }
    if(side>2 && side<5 && node<2){
        resto=(side%3)+node;
        return resto;
        u=1;
    }
    if(side==5 && node<2){
        resto=2-(node*2);
        return resto;
        u=1;
    }
    if(side==6){
        return node;
        u=1;
    }
    if (u==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
}

/// return the enumerated element type
ElementType TopologyTriangle::Type(){
    return ElementType(1);
}
