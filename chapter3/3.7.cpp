#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

enum ANIMAL_TYPE {
  DOG,
  CAT
};

struct AnimalInfo {
  int id;
  ANIMAL_TYPE type;
  AnimalInfo(ANIMAL_TYPE _type): type(_type) {
    id = -1;
  }
};

class AnimalQueue {
  int count;
  list<AnimalInfo> dogs;
  list<AnimalInfo> cats;
  public:
    AnimalQueue() {
      count = 0;
    };

    void enqueue(AnimalInfo animal) {
      count++;
      animal.id = count;
      if (animal.type == DOG) {
        dogs.push_back(animal);
      } else {
        cats.push_back(animal);
      }
    }

    AnimalInfo dequeueAny() {
      if (dogs.empty() && cats.empty()) { throw; }
      if (!dogs.empty() && cats.empty()) { return dequeueDog(); }
      if (!cats.empty() && dogs.empty()) { return dequeueCat(); }
      AnimalInfo dog = dogs.front();
      AnimalInfo cat = cats.front();
      if (dog.id < cat.id) {
        return dequeueDog();
      } else {
        return dequeueCat();
      }
    }

    AnimalInfo dequeueDog() {
      if (dogs.empty()) { throw; }
      AnimalInfo dog = dogs.front();
      dogs.pop_front();
      return dog;
    }

    AnimalInfo dequeueCat() {
      if (cats.empty()) { throw; }
      AnimalInfo cat = cats.front();
      cats.pop_front();
      return cat;
    }
};

int main()
{
  srand(time(0));
  const int MAX_N = 100;
  AnimalQueue animals;
  int limit = rand() % MAX_N;
  ANIMAL_TYPE first_type;
  for (int i = 0; i < limit; ++i) {
    ANIMAL_TYPE type = (ANIMAL_TYPE)(rand() % 2);
    if (i == 0) { first_type = type; }
    animals.enqueue(AnimalInfo(type));
  }
  // assure it has both types
  animals.enqueue(AnimalInfo(DOG));
  animals.enqueue(AnimalInfo(CAT));
  assert(animals.dequeueAny().type == first_type);
  assert(animals.dequeueDog().type == DOG);
  assert(animals.dequeueCat().type == CAT);
}
