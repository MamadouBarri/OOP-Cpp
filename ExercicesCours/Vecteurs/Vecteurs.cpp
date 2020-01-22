// Vecteurs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


void modifier(std::vector<int> v) {
    v[3] = 1234;
    std::cout << v[3] << std::endl;
}


int main()
{
    std::vector<int> unTableau;

    for (int i = 1; i < 10; i++)
        unTableau.push_back(i);

    modifier(unTableau);


}
