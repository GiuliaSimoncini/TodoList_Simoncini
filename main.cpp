#include <iostream>
#include "EventList.h"

int main() {

    EventList eventList;
    Event event1("Concert", "Music", 20, 2, 2020, 21);
    Event event2("Theatre", "Drama", 15, 1.5, 2020, 20);
    Event event3("Cinema", "Film", 10, 2, 2020, 18);
    eventList.addEvent(event1);
    eventList.addEvent(event2);
    eventList.addEvent(event3);
    eventList.print();
    std::cout<<std::endl;
    eventList.removeEvent(event2);
    eventList.print();
    std::cout<<std::endl;
    eventList.modifyEvent(event1, event2);
    eventList.print();
    std::cout<<std::endl;
    eventList.printfromfile();

    return 0;
}
