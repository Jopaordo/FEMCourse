//
//  CompElementTemplate.h
//  FemCourse
//
//  Created by Philippe Devloo on 24/04/18.
//

#ifndef CompElementTemplate_h
#define CompElementTemplate_h

#include "CompElement.h"
#include "IntRule.h"
#include "Topology1d.h"
#include "TopologyQuad.h"
#include "TopologyTriangle.h"
#include "TopologyTetrahedron.h"
#include "Shape1d.h"
#include "ShapeQuad.h"
#include "ShapeTetrahedron.h"
#include "ShapeTriangle.h"
#include "DOF.h"

template<class Shape>
class CompElementTemplate : public CompElement
{
    
    // Vector with degrees of freedom indices
    std::vector<int64_t> dofindexes;
    
    // Integration rule object
    typename Shape::LocIntRule intrule;

public:
    
    // Default constructor of CompElementTemplate
    CompElementTemplate();
    
    // Constructor of CompElementTemplate
    CompElementTemplate(int64_t ind, CompMesh *cmesh, GeoElement *geo);
    
    // Copy constructor of CompElementTemplate
    CompElementTemplate(const CompElementTemplate &);
    
    // Operator of copy
    CompElementTemplate &operator=(const CompElementTemplate &);
    
    // Destructor of CompElementTemplate
    virtual ~CompElementTemplate();
    
    // Method for creating a copy of the element
    virtual CompElement *Clone() const;
    
    // Return the number of shape functions
    virtual int NShapeFunctions() const;
    
    // Compute shape functions set at point x
    virtual void ShapeFunctions(const VecDouble &intpoint, VecDouble &phi, Matrix &dphi) const;
    
    // Return the number of degree of freedom
    virtual int NDOF() const;
    
    // Return the number of shape functions stored in the DOF data structure
    virtual int NShapeFunctions(int doflocindex);
    
    // Use the Shape template class to compute the number of shape functions
    virtual int ComputeNShapeFunctions(int doflocindex, int order);
    

    
    // Return space dimension
    virtual int Dimension() const;
};
#endif /* CompElementTemplate_h */
