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

    do
    {
        std::cout << " 1. Add vertex(vertices)\n 2. Search terminator/ending vertex\n 3. Add value to vertex\n 4. Search value" << std::endl;
        std::cout << " 5. Add edge(s)\n 6. Search if specifc edge exists" << std::endl;
        std::cout << " 7. Convert graph\n 8. Display graph \n 9. Exit" << std::endl;

        std::cin >> input;

        switch (input)//Evaluation of one variable
        {
        case 1: 
            break;
        case 2: 
            break;
        case 3: 
            break;
        case 4: 
            break;
        case 5: 
            break;
        case 6: 
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