    //
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.

#include "ShapeQuad.h"
#include "IntRuleTriangle.h"
#include "ShapeTriangle.h"
#include "tpanic.h"
#include "Topology1d.h"

/// Number of nodes associated with a side
 int Topology1d::NSideNodes(int side){
   
     if (side<= 1){
         return 1;
     }
     else{
         return 2;
     }
     
}

/// local node index of a node associated with a side
int Topology1d::SideNodeIndex(int side, int node){
    if(side <2 && node == 0) {
        return side;
    }
    if(side == 2 && node <2){
        return node;
    }
    if (side>2){
        std::cout<<"The maximun number of sides on a 2D element is 2";
        DebugStop();
        
    }
    if (side<2 && node!=0){
        std::cout<<"The number of sides on a point is 0";
        DebugStop();
        
    }
   
}

/// return the enumerated element type
ElementType Topology1d::Type(){
    return ElementType(1);
}
