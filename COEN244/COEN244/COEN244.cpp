// COEN244.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Driver.h"

Driver driver;
int main()
{
    int input;
    Vertex v1(1, " ");
    Vertex* v2 = new Vertex(9, "ENCS282");

    Vertex* vStart1 = new Vertex(5, "ENGR233");
    Vertex* vEnd1 = new Vertex(3, "COEN311");
    Edge* e1 = new Edge(2, vStart1, vEnd1);

    Vertex* vStart2 = new Vertex(0, "ENGR213");
    Vertex* vEnd2 = new Vertex(3, "COEN212");
    Edge* e2 = new Edge(10, vStart2, vEnd2);
    do
    {
        std::cout << " 1. Add vertex(vertices)\n 2. Search terminator/ending vertex\n 3. Add value to vertex\n 4. Search value" << std::endl;
        std::cout << " 5. Add edge(s)\n 6. Search if edge exists" << std::endl;
        std::cout << " 7. Convert graph\n 8. Display graph \n 9. Exit" << std::endl;

        std::cin >> input;

        switch (input)//Evaluation of one variable
        {
        case 1: 
            driver.addVertices(v2);
            break;
        case 2: 
            break;
        case 3: 
            driver.addValue("COEN244", v1);
            break;
        case 4: 
            driver.searchValueExists("ENCS282");
            break;
        case 5: 
            driver.addEdges(e);
            break;
        case 6: 
            driver.searchEdgeExists(e);
            break;
        case 7: 
            break;
        case 8: 
            break;
            break;
        default:
            break;
        }
    } while (input != 9);
}