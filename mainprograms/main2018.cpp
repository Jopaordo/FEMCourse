

#include <iostream>
#include <math.h>
#include "IntRule.h"
#include "IntRule1d.h"
#include "IntRuleQuad.h"
#include "IntRuleTetrahedron.h"
#include "IntRuleTriangle.h"
#include "Topology1d.h"
#include "TopologyTriangle.h"
#include "TopologyQuad.h"
#include "TopologyTetrahedron.h"
#include "DataTypes.h"

using std::cout;
using std::endl;
using std::cin;

int main ()
{
    IntRule1d jorge(2);
    jorge.Print(cout);
    
    int p;
    VecDouble co(3);
    double weight;
    co[0]=0;
    
    double S=0;
    for(int i=0;i<=jorge.NPoints()-1;i++){
        jorge.Point(i, co,weight);
        S = S + weight * co[0] * co[0];
    }
    std::cout<<"Integral: "<<S<<"\n";

    
    return 0;
}

