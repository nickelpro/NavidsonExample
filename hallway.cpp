#include "labyrinth.hpp"
#include "minotaur.hpp"

#include "iostream"

void descend() {
  minotaur mini {};
  std::cout << "The minotaur says: " << mini.say() << std::endl;
}
