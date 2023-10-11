// University of La Laguna
// School of Engineering and Technology
// Bachelor's Degree in Computer Engineering
// Computability and Algorithmics
// 2nd Year
// Practice 2: The Sieve of Eratosthenes
// Reference:
// https://github.com/fsande/CyA-P02-Eratosthenes/blob/master/Eratosthenes.md
// Author: Antonella Sofía García Álvarez
// Institutional email: alu0101227610@ull.edu.es
// Current file: Main principal .cc

#include <iostream>
#include <stdlib.h>
#include <vector>

void Write(std::ostream &os, std::vector<std::vector<int>> &Primes) {
  os << "Prime Numbers:" << std::endl;
  for(unsigned i=0; i < Primes.size(); i++) {
    os << Primes.at(i).at(0);

    if(Primes.at(i).at(1) == 1) {
      os << "  ";
    } 
    else {
      os << "  ";
    }
  }

  std::cout << std::endl;
}


// Explanation of what the algorithm does
void Clean(std::vector<std::vector<int>> &Primes) {
  for(std::vector<std::vector<int>>::iterator it = Primes.begin(); it != Primes.end(); std::advance(it,1)) {
    if(it->at(1) == 0) {
      Primes.erase(it);
      std::advance(it,-1);
    }
  }
}

void Remove(std::vector<std::vector<int>> &Primes, unsigned pos) {
  for(unsigned i = pos; i <= Primes.size(); i = i + pos) {
    if(i == pos) continue;
    Primes.at(i - 1).at(1) = 0;
  }
}

void Sieve(std::vector<std::vector<int>> &Primes) {
  Primes.at(0).at(1) = 0;

  for(unsigned i = 1; i < Primes.size(); i++) {               // here, you can call 'i' as 'current_number'
    if(Primes.at(i).at(1) == 1) {
      Remove(Primes, i + 1);
    }
  }
}

int main(int argc, char* argv[]) {
  int Size = -1;

  std::vector<std::vector<int>> Primes;
  if(argc > 1) {
    Size = std::atoi(argv[1]);
  }
  if(Size < 0) {
    return 1;
  }
  for(int i = 1; i <= Size; i++) {
    std::vector<int> PrimeVector;
    PrimeVector.push_back(i);
    PrimeVector.push_back(1);
    Primes.push_back(PrimeVector);
  }
  Sieve(Primes);
  Clean(Primes);
  Write(std::cout, Primes);
}
