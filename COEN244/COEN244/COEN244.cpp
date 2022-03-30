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
}