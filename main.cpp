#include <iostream>
#include "src/EventBus.h"

struct EventData {
  int id;
};

int main() {
  EventData s1 = { 0 }; 
  EventBus<EventData> eb;

  std::function<void(EventData*)> cb = [](EventData* x) { 
    std::cout << x->id << std::endl; 
    x->id++;
  };
  
  auto id = eb.subscribe(cb);
  eb.publish(&s1);
  eb.publish(&s1);
  eb.flush();
  eb.unsubscribe(id);
  eb.publish(&s1);
  eb.flush();
  eb.publish(&s1);
  eb.flush();

}
