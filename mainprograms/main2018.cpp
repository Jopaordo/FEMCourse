

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
#include "Shape1d.h"
#include "DataTypes.h"
#include "GeoMesh.h"
#include "ReadGmsh.h"
#include "VTKGeoMesh.h"
#include "CompElementTemplate.h"
#include "GeoElement.h"
#include "CompElement.h"
#include "CompMesh.h"
#include "GeomQuad.h"
#include "GeoMesh.h"
#include "GeoElementTemplate.h"
#include "Poisson.h"
#include "CompElementTemplate.h"
#include "Shape1d.h"
#include "Geom1d.h"

using std::cout;
using std::endl;
using std::cin;

int main ()
{

    
    ReadGmsh read;
    
    GeoMesh geomesh;
    
    read.Read(geomesh, "jorg.msh");
    CompElementTemplate<ShapeQuad> jos;
    geomesh.Print(cout);

    return 0;
    
}
