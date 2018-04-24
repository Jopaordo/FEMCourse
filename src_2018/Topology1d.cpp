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
#include "tpanic.h"

    
    typedef IntRule1d LocIntRule;
    
    const int nSides = 3;
    
    const int nCorners = 2;
    
    /// Number of nodes associated with a side
int Topology1d::NSideNodes(int side){
     int v=0;
    if (side==0){
        v=1;
        return 1;
    }
    if (side==1){
        return 1;
        v=1;
    }
    if (side==2){
        v=1;
        return 2;
    }
    if (v==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
}


int Topology1d::SideNodeIndex(int side, int node){
       int v=0;
    if ((side >=0  && side<2) && node==0){
        v=1;
        return side;
    }
    if (side==2 && (node >=0 && node<2)){
        v=1;
        return node;
    }
 
    if (v==0) {
        std::cout<<"Incorrect Parameters"<<"\n";
        DebugStop();
    }
        
        
        
        
}
    
    /// return the enumerated element type

ElementType Topology1d::Type(){
    return ElementType(1);
}
