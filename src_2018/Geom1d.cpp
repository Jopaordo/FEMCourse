//
//  Geom1d.h
//  FemSC
//
//  Created by Philippe Devloo on 03/04/18.
//


#include "Topology1d.h"
#include "Geom1d.h"
#include "GeoElementSide.h"

/// Constructor
Geom1d::Geom1d(){
    fNodeIndices.resize(2);
    fNodeIndices[0]=0;
    fNodeIndices[1]=1;
}

/// destructor
Geom1d::~Geom1d(){

}

/// copy constructor
Geom1d::Geom1d(const Geom1d &copy){
    fNodeIndices=copy.fNodeIndices;
    fNeighbours[0] =copy.fNeighbours[0];
    fNeighbours[1] =copy.fNeighbours[1];
    fNeighbours[2] =copy.fNeighbours[2];
}

/// operator=
Geom1d &Geom1d::operator=(const Geom1d &copy){
    fNodeIndices=copy.fNodeIndices;
    fNeighbours[0] =copy.fNeighbours[0];
    fNeighbours[1] =copy.fNeighbours[1];
    fNeighbours[2] =copy.fNeighbours[2];
}

/// Computes the shape functions associated with the geometric map
 void Geom1d::Shape(const VecDouble &xi, VecDouble &phi, Matrix &dphi){

     //funciones de forma lineares
     phi[0] = (1.0-xi[0])/2.;
     phi[1] = (1.0+xi[0])/2.;
     dphi(0,0) = -0.5;
     dphi(0,1) = 0.5;
}

/// Computes the value of x for a given point in parameter space as a function of corner coordinates
 void Geom1d::X(const VecDouble &xi, Matrix &NodeCo, VecDouble &x){
     double phi1 = (1- xi[0])/2;
     double phi2 = (1+ xi[0])/2;
     double map = NodeCo(0,0)*phi1 + NodeCo(1,0)*phi2;
     x[0]= map;
}

/// Computes the value of x and gradx for a given point in parameter space
 void Geom1d::GradX(const VecDouble &xi, Matrix &NodeCo, VecDouble &x, Matrix &gradx){
     
     //gradX linear
     double phi1 = (1- xi[0])/2;
     double phi2 = (1+ xi[0])/2;
     
     double dphi1 = -0.5;
     double dphi2 = 0.5;
     double map = NodeCo(0,0)*phi1 + NodeCo(1,0)*phi2;
     double dmap = NodeCo(0,0)*dphi1 + NodeCo(1,0)*dphi2;     
     x[0]= map;
     gradx(0,0)=dmap;
}

/// return the number of nodes of the template
int Geom1d::NumNodes(){
    return nCorners;
}

/// Set the node indices of the element
void Geom1d::SetNodes(const VecInt &nodes){
    fNodeIndices.resize(nSides-1);
    fNodeIndices=nodes;
}

/// Set the node indices of the element
void Geom1d::GetNodes(VecInt &nodes){
    nodes = fNodeIndices;
}

/// Return the index of a node
int Geom1d::NodeIndex(int node){
    return fNodeIndices[node];
}

/// Return the neighbour along side
GeoElementSide Geom1d::Neighbour(int side){
    return fNeighbours[side];
}

/// Initialize the neighbour data structure
void Geom1d::SetNeighbour(int side, GeoElementSide &neighbour){
    fNeighbours[side]= neighbour;
}

