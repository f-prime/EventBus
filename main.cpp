#include <iostream>
#include "EventBus.h"

struct EventData {
  int age;

  EventData(int age): age(age) {}
};

int main() {
  EventBus<EventData> eb;

  auto ageChangeEvent = [](EventData* x) { 
    if (x->age != 30) return;
    std::cout << "Is 30 years old!" << std::endl; 
  };

  eb.subscribe(ageChangeEvent);

  for (auto age = 0; age < 100; age++) {
    auto ed = EventData(age);
    eb.publish(&ed);
  }
}
