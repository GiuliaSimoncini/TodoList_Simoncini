#include <iostream>
#include "EventList.h"

void InputEvents(std::string &name, std::string &description, float &price, float &duration, float &date, float &time){
    std::cout << "Inserisci il nome dell'evento" << std::endl;
    std::cin >> name;
    std::cout << "Inserisci la descrizione dell'evento" << std::endl;
    std::cin >> description;
    std::cout << "Inserisci il prezzo dell'evento" << std::endl;
    std::cin >> price;
    std::cout << "Inserisci la durata dell'evento" << std::endl;
    std::cin >> duration;
    std::cout << "Inserisci la data dell'evento" << std::endl;
    std::cin >> date;
    std::cout << "Inserisci l'ora dell'evento" << std::endl;
    std::cin >> time;
}

int main() {
    EventList eventList;
    eventList.readfileandsave();

    int choice;

    do {
        std::cout << "Benvenuto nel programma di gestione eventi" << std::endl;
        std::cout << "Se vuoi aggiungere un evento, premi 1" << std::endl;
        std::cout << "Se vuoi rimuovere un evento, premi 2" << std::endl;
        std::cout << "Se vuoi modificare un evento, premi 3" << std::endl;
        std::cout << "Se vuoi stampare la lista degli eventi, premi 4" << std::endl;
        std::cout << "Se vuoi stampare la lista degli eventi dal file, premi 5" << std::endl;
        std::cout << "Se vuoi uscire, premi 0" << std::endl;
        std::cin >> choice;
        if (choice < 0 or choice > 5)
            std::cout << "Scelta non valida" << std::endl;
        else if (choice == 1) {
            std::string name, description;
            float date, time, price, duration;
            InputEvents(name, description, price, duration, date, time);
            Event event(name, description, price, duration, date, time);
            eventList.addEvent(event);
        }
        else if (choice == 2) {
            std::string name, description;
            float date, time, price, duration;
            InputEvents(name, description, price, duration, date, time);
            Event event(name, description, price, duration, date, time);
            eventList.removeEvent(event);
        }
        else if (choice == 3) {
            std::string name, description;
            float date, time, price, duration;
            std::cout<<"Inserisci i dati dell'evento da modificare"<<std::endl;
            InputEvents(name, description, price, duration, date, time);
            Event oldEvent(name, description, price, duration, date, time);
            std::cout<<"Inserisci i dati dell'evento nuovo"<<std::endl;
            InputEvents(name, description, price, duration, date, time);
            Event newEvent(name, description, price, duration, date, time);
            eventList.modifyEvent(oldEvent, newEvent);
        }
        else if (choice == 4) {
            eventList.print();
        }
        else if (choice == 5) {
            EventList::printfromfile();
        }
    } while (choice != 0);

    std::cout<<"Sei uscito dal programma"<<std::endl;

    return 0;
}
