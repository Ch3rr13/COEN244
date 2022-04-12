// COEN244.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Driver.h"
int Vertex::UniqueID = 0;
Driver driver;
int main()
{
    Driver CourseSequence;
    std::cout << "|1| : Graph can be empty: " << std::endl;
    CourseSequence.display();
    

    //list of Vertices
    Vertex* COEN243 = new Vertex("COEN243");                                    // ID 1
    Vertex* COEN244 = new Vertex("COEN244");                                    // ID 2
    Vertex* ArrayOfVertex = new Vertex[5];  
    ArrayOfVertex[0].setValue("COEN212");                                      // ID 3
    ArrayOfVertex[1].setValue("COEN311");                                      // ID 4
    ArrayOfVertex[2].setValue("COEN313");                                      // ID 5
    ArrayOfVertex[3].setValue("ENGR213");                                      // ID 6
    ArrayOfVertex[4].setValue("ENGR233");                                      // ID 7

    //list of edges
    Edge* Cplusplus = new Edge("Prerequisite", *COEN243, *COEN244);
    Edge* COENedges = new Edge[3];
    COENedges[0].setWeight("Prerequisite");
    COENedges[0].setStartVertex(ArrayOfVertex[0]);
    COENedges[0].setEndVertex(ArrayOfVertex[1]);
    COENedges[1].setWeight("Prerequisite");
    COENedges[1].setStartVertex(ArrayOfVertex[1]);
    COENedges[1].setEndVertex(ArrayOfVertex[2]);
    COENedges[2].setWeight("Prerequisite");
    COENedges[2].setStartVertex(ArrayOfVertex[0]);
    COENedges[2].setEndVertex(ArrayOfVertex[2]);

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|2| : Graph is directed: " << std::endl;
    CourseSequence.addVertices(COEN243, 1);
    CourseSequence.addVertices(COEN244, 1);
    CourseSequence.addEdges(Cplusplus, 1);
    CourseSequence.display();

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|3| : Graph can add Vertices and edges: " << std::endl;
    if (CourseSequence.addVertices(ArrayOfVertex, 5)) {
        std::cout << "Vertices has been added" << std::endl;
    }
    if (CourseSequence.addEdges(COENedges, 3)) {
        std::cout << "Edges has been added" << std::endl;
    }
    CourseSequence.display();

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|4| : Vertex of graphs can have values or no values: " << std::endl;
    Vertex* Empty = new Vertex;                         
    Empty->setID(8);
    CourseSequence.addVertices(Empty, 1);
    CourseSequence.display();

    std::cout << "After adding a value to Vertex 8: " << std::endl;
    CourseSequence.addValue("any value", *Empty);
    CourseSequence.display();

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|5| : All possibles paths in the graph: " << std::endl;
    CourseSequence.displaypaths();

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|6| : All possibles paths From a Vertex: " << std::endl;
    CourseSequence.displaypathsfromVertex(ArrayOfVertex[0]);
    
    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|7| : Search for if edge exists in the graph: " << std::endl;
    if (CourseSequence.searchEdgeExists(Cplusplus)) {
        std::cout << "Edge exists " << std::endl;
    }
    else {
        std::cout << "Edge does not exists " << std::endl;
    }
    Edge* FakeEdge = new Edge("Corequisite", *COEN243, ArrayOfVertex[3]);
    //FakeEdge->setEndVertex(ArrayOfVertex[3]);
 
    if (CourseSequence.searchEdgeExists(FakeEdge)) {
        std::cout << "Edge exists " << std::endl;
    }
    else {
        std::cout << "Edge does not exists " << std::endl;
    }

    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "|8| : Search for if value exists in the graph:: " << std::endl;
    if (CourseSequence.searchValueExists("COEN311")) {
        std::cout << "Vertex with value COEN311 exists " << std::endl;
    }
    else {
        std::cout << "Vertex with value COEN311 does not exists " << std::endl;
    }
    if (CourseSequence.searchValueExists("COEN3110")) {
        std::cout << "Vertex with value COEN3110 Edge exists " << std::endl;
    }
    else {
        std::cout << "Vertex with value COEN3110 Edge does not exists " << std::endl;
    }
    std::cout << std::endl << "End result of Graph: " << std::endl;
    CourseSequence.display();
    std::cout << "--------------------- " << std::endl;

/*
    int input;
    Vertex* v1 = new Vertex(1, " ");
    Vertex* v2 = new Vertex(9, "ENCS282");

    Vertex* vStart1 = new Vertex(5, "ENGR233");
    Vertex* vEnd1 = new Vertex(3, "COEN311");
    Edge* e1 = new Edge(2, vStart1, vEnd1);

    Vertex* vStart2 = new Vertex(0, "ENGR213");
    Vertex* vEnd2 = new Vertex(3, "COEN212");
    Edge* e2 = new Edge(10, vStart2, vEnd2);
    driver.addVertices(v1, 1);
    driver.addVertices(vStart1, 1);
    driver.addVertices(vEnd1, 1);
    driver.addVertices(vStart2, 1);

    do
    {
        std::cout << " 1. Add vertex(vertices)\n 2. Search terminator/ending vertex\n 3. Add value to vertex\n 4. Search value" << std::endl;
        std::cout << " 5. Add edge(s)\n 6. Search if edge exists" << std::endl;
        std::cout << " 7. Convert graph\n 8. Display graph \n 9. Exit" << std::endl;

        std::cin >> input;

        switch (input)//Evaluation of one variable
        {
        case 1:
            if (driver.addVertices(v2, 1) == true)
            {
                std::cout << "Success! Vertex/Vertices added" << std::endl;
            }
            else
            {
                std::cout << "Sorry there was an error" << std::endl;
            }
            break;
        case 2:
            break;
        case 3:
            if (driver.addValue("COEN244", *v1) == true)
            {
                std::cout << "Success! Value added" << std::endl;
            }
            else
            {
                std::cout << "Sorry there was an error" << std::endl;
            }
            break;
        case 4:
            if (driver.searchValueExists("ENCS282") == true)
            {
                std::cout << "Value exists" << std::endl;
            }
            else
            {
                std::cout << "Sorry there was an error" << std::endl;
            }
            break;
        case 5:
            if (driver.addEdges(e1, 1) == true)
            {
                std::cout << "Success! Edge(s) added" << std::endl;
            }
            else
            {
                std::cout << "Sorry there was an error or Vertices do not exists" << std::endl;
            }
            break;
        case 6: 
            if (driver.searchEdgeExists(e2) == true)
            {
                std::cout << "Edge " << e2->getWeight() << " exists" << std::endl;
            }
            else
            {
                std::cout << "Sorry there was an error" << std::endl;
            }
            break;
        case 7: 
            break;
        case 8: 
            driver.display();
            break;
            break;
        default:
            break;
        }
    } while (input != 9);
    */  

    
    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "UNDIRECTED GRAPH TEST " << std::endl;
    std::cout << "--------------------- " << std::endl;

    //list of Vertices
    Vertex* SF = new Vertex("San Francisco");                                   
    Vertex* LA = new Vertex("Los Angeles");                                    
    Vertex* ArrayOfLocation = new Vertex[6];
    ArrayOfLocation[0].setValue("Denver");                                     
    ArrayOfLocation[1].setValue("Chicago");                                     
    ArrayOfLocation[2].setValue("New York");                                     
    ArrayOfLocation[3].setValue("Boston");                                     
    ArrayOfLocation[4].setValue("Atlanta");                                      
    ArrayOfLocation[5].setValue("Miami");   

    Edge* Distance = new Edge[8];

    Distance[0].setInfo("349", *SF, *LA);
    Distance[1].setInfo("834", *LA, ArrayOfLocation[0]);
    Distance[2].setInfo("957", ArrayOfLocation[0], *SF);
    Distance[3].setInfo("908", ArrayOfLocation[1], ArrayOfLocation[0]);
    Distance[4].setInfo("860", ArrayOfLocation[1], ArrayOfLocation[3]);
    Distance[5].setInfo("2534", *SF, ArrayOfLocation[2]);
    Distance[6].setInfo("2451", *LA, ArrayOfLocation[2]);
    Distance[7].setInfo("909", ArrayOfLocation[1], ArrayOfLocation[4]);

    UndirectedDriver Mileage;
    Mileage.addVertices(SF, 1);
    Mileage.addVertices(LA, 1);
    Mileage.addVertices(ArrayOfLocation, 6);
    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "Printing graph with only vertices added " << std::endl;
    Mileage.display();

    Mileage.addEdges(Distance, 8);
    std::cout << "--------------------- " << std::endl;
    std::cout << std::endl << "Printing graph with Edges added " << std::endl;
    Mileage.display();
    std::cout << std::endl << "Printing All paths " << std::endl;
    Mileage.displaypaths();
    std::cout << std::endl << "Printing All paths from San Francisco " << std::endl;
    Mileage.displaypathsfromVertex(*SF);


    return 0;
}