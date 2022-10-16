#ifndef H_EVENT_BUS
#define H_EVENT_BUS

#include <_types/_uint32_t.h>
#include <functional>
#include <map>

typedef uint32_t EventBusUID;

template<typename... CallbackParams>
class EventBus {
  private:
    EventBusUID event_bus_unique_id = 0;
    std::map<EventBusUID, std::function<void(CallbackParams...)>> subscribers; 
  
  public:
    void broadcast(CallbackParams... args) {
      for (auto& sub : subscribers) {
        auto callback = sub.second;
        callback(args...);
      }
    }

    void publish(CallbackParams... e) {
      broadcast(e...);
    }

    EventBusUID subscribe(std::function<void(CallbackParams...)> callback) {
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
