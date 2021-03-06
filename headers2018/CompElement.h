//
//  CompElement.h
//  FemCourse
//
//  Created by Philippe Devloo on 24/04/18.
//

#ifndef CompElement_h
#define CompElement_h

#include "DataTypes.h"
#include "IntRule.h"
#include "IntPointData.h"

class CompMesh;
class GeoElement;
class MathStatement;

class CompElement
{
    
    // Computational mesh to which the element belongs
    CompMesh *compmesh = 0;
    
    // Element index into mesh element vector
    int64_t index = -1;
    
    // Geometrical element associated
    GeoElement *geoel = 0;
    
    // Integration rule object
    IntRule *intrule = 0;
    
    // Material object associated
    MathStatement *mat = 0;
    
public:
    
    // Default constructor of CompElement
    CompElement();
    
    // Constructor of CompElement
    CompElement(int64_t ind, CompMesh *cmesh, GeoElement *geo);
    
    // Copy constructor of CompElement
    CompElement(const CompElement &copy);
    
    // Operator of copy
    CompElement &operator=(const CompElement &);
    
    // Destructor of CompElement
    virtual ~CompElement();
    
    // Method for creating a copy of the element
    virtual CompElement *Clone() const;
    
    // Return the material object associated with the element
    MathStatement *GetStatement() const;
    
    // Set the material object associated with the element
    void SetStatement(MathStatement *statement);
    
    // Return integration rule established
    IntRule *GetIntRule() const;
    
    // Set integration rule established
    void SetIntRule(IntRule *intrule);
    
    // Return element index
    int64_t GetIndex() const
    {
        return index;
    }
    
    // Set element index
    void SetIndex(int64_t ind);
    
    // Return the geometric element associated
    GeoElement *GetGeoElement() const;
    
    // Set the geometric element associated
    void SetGeoElement(GeoElement *element);
    
    // Return a pointer to the element computational mesh
    CompMesh *GetCompMesh() const;
    
    // Set a pointer to the element computational mesh
    void SetCompMesh(CompMesh *mesh);
    
    // Initialize integration points data object
    void InitializeIntPointData(IntPointData &data) const;
    
    // Compute and fill integration points data object
    void ComputeRequiredData(IntPointData &data, VecDouble &intpoint) const;
    
    // Compute the element stifness matrix and force vector
    virtual void CalcStiff(Matrix &ek, Matrix &ef) const;
    
    // Mandatory methods
    
    // Return the number of shape functions
    virtual int
    NShapeFunctions() const = 0;
    
    // Compute shape functions set at point x
    virtual void ShapeFunctions(const VecDouble &intpoint, VecDouble &phi, Matrix &dphi) const = 0;

    // Return the number of degree of freedom
    virtual int NDOF() const = 0;
    
    // Return the number of shape functions stored in the DOF data structure
    virtual int NShapeFunctions(int doflocindex) = 0;
    
    // Use the Shape template class to compute the number of shape functions
    virtual int ComputeNShapeFunctions(int doflocindex, int order) = 0;
    
    
    // Return the dimension of the element
    virtual int Dimension() const = 0;
};
#endif /* CompElement_h */
