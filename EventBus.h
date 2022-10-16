#ifndef H_EVENT_BUS
#define H_EVENT_BUS

#include <_types/_uint32_t.h>
#include <functional>
#include <map>

typedef uint32_t EventBusUID;

template<typename EventData_T>
class EventBus {
  private:
    EventBusUID event_bus_unique_id = 0;
    std::map<EventBusUID, std::function<void(EventData_T*)>> subscribers; 
  
  public:
    void broadcast(EventData_T* e) {
      for (auto& sub : subscribers) {
        auto callback = sub.second;
        callback(e);
      }
    }

    void publish(EventData_T* e) {
      broadcast(e);
    }

    EventBusUID subscribe(std::function<void(EventData_T*)> callback) {
      event_bus_unique_id++;
      subscribers[event_bus_unique_id] = callback;
      return event_bus_unique_id;
    }

    void unsubscribe(uint32_t id) {
      auto loc = subscribers.find(id);
      if (loc == subscribers.end()) return;
      subscribers.erase(loc);
    } 
};

#endif
