#include <iostream>
#include "EventBus.h"

int main() {
  EventBus<int, int> eb;

  auto ageChangeEvent = [](int age, int size) { 
    if (age != 30) return;
    std::cout << "Is 30 years old!" << std::endl; 
  };

  eb.subscribe(ageChangeEvent);

  for (auto age = 0; age < 100; age++) {
    eb.publish(age, 6);
  }
}
