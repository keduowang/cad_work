#ifndef SOLID_MODELING_H
#define SOLID_MODELING_H
#include <stdlib.h>
#include <vector>
class Vertex;
class HalfEdge;
class Edge;
class Loop;
class Face;
class Solid;

class Point;
class Curve;
class Surface;

/* Topological class: Vertex */
class Vertex
{
public:
    Vertex(): vPoint(nullptr), nxtVertex(nullptr), prevVertex(nullptr){}
    Point* vPoint;
    Vertex* nxtVertex;
    Vertex* prevVertex;
};

/* Topological class: HalfEdge */
class HalfEdge
{
public:
    HalfEdge(): heVertex(nullptr), heLoop(nullptr), heEdge(nullptr), prevHalfEdge(nullptr), nxtHalfEdge(nullptr){}
    Vertex* heVertex;
    Loop* heLoop;
    Edge* heEdge; /* Map HalfEdge to Edge */
    HalfEdge* prevHalfEdge;
    HalfEdge* nxtHalfEdge;
};


/* Topological class: Edge */
class Edge
{
public:
    Edge(): eHalfEdge1(nullptr), eHalfEdge2(nullptr), prevEdge(nullptr){}
    HalfEdge* eHalfEdge1;
    HalfEdge* eHalfEdge2;
    Edge* prevEdge;
    Edge* nxtEdge;
};


/* Topological class: Loop */
class Loop
{
public:
    Loop(): lHalfEdge(nullptr), lFace(nullptr), prevLoop(nullptr), nxtLoop(nullptr){}
    HalfEdge* lHalfEdge;
    Face* lFace;
    Loop* prevLoop;
    Loop* nxtLoop;

};

/* Topological class: Face */
class Face
{
public:
    Face(): fSolid(nullptr), fLoops(nullptr), prevFace(nullptr), nxtFace(nullptr){}
    Solid* fSolid;
    Loop* fLoops;
    Face* prevFace;
    Face* nxtFace;
};


/* Topological class: Solid */
class Solid
{
public:
    Solid(): sFaces(nullptr), sEdges(nullptr), prevSolid(nullptr), nxtSolid(nullptr){}
    Face* sFaces;
    Edge* sEdges;
    Solid* prevSolid;
    Solid* nxtSolid;
};


/*
 *
*/

/* Geometry class: Point */
class Point
{
public:
    double pos[3];
};

/*Geometry class: Curve*/
class  Curve
{

};

/*Geometry class: Surface*/
class Surface
{

};

class CAD_Model
{
    std::vector<Solid> SolidList;
    std::
};


#endif // SOLID_MODELING_H
