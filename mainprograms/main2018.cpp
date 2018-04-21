

#include <iostream>
#include <math.h>
#include "IntRule.h"
#include "IntRule1d.h"
#include "IntRuleQuad.h"
#include "IntRuleTetrahedron.h"
#include "IntRuleTriangle.h"
#include "Shape1d.h"
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
    Shape1d Jorge;
    VecDouble xi(1);
    xi[0]=0.8;
    VecInt ord(3);
    ord[0]=1;
    ord[1]=1;
    ord[2]=4;
    VecDouble phi;
    Matrix dphi;
    Jorge.Shape(xi, ord, phi, dphi);
    std::cout<<phi[0]<<"\n";
    std::cout<<phi[1]<<"\n";
    std::cout<<phi[2]<<"\n";
    std::cout<<phi[3]<<"\n";
    std::cout<<phi[4]<<"\n";
    std::cout<<phi[5]<<"\n";
    
    return 0;
}

