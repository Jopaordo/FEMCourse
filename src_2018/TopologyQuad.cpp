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
#include "IntRuleQuad.h"
#include "tpanic.h"


typedef IntRuleQuad LocIntRule;

const int nSides = 9;

const int nCorners = 4;

/// Number of nodes associated with a side
int TopologyQuad::NSideNodes(int side){
    int u=0;
    if (side<=3){
        return 1;
        u=1;
    }
    if (side>=4 && side<8){
        return 2;
        u=1;
    }
    if (side==8){
        u=1;
        return 4;
    }
    if (u==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
}

/// local node index of a node associated with a side
int TopologyQuad::SideNodeIndex(int side, int node){
    int u=0;
    int resto=0;
    if(side<4 && node==0){
        return side;
        u=1;
    }
    if(side>3 && side<7 && node<2){
        resto=(side%4)+node;
        return resto;
        u=1;
    }
    if(side==7 && node<2){
        resto=3-(node*3);
        return resto;
        u=1;
    }
    if(side==8){
        return node;
        u=1;
    }
    if (u==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
}

/// return the enumerated element type
ElementType TopologyQuad::Type(){
    return ElementType(1);
}
