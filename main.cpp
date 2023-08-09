#include <iostream>
#include "EventList.h"

void InputEvents(std::string &name, std::string &description, float &price, int &durationInMinutes, int &year, unsigned &month, unsigned &day, int &hourOfBegin, int &minuteOfBegin){
    std::cout << "Inserisci il nome dell'evento" << std::endl;
    std::cin >> name;
    std::cout << "Inserisci la descrizione dell'evento" << std::endl;
    std::cin >> description;
    std::cout << "Inserisci il prezzo dell'evento" << std::endl;
    std::cin >> price;
    std::cout << "Inserisci la durata in minuti dell'evento" << std::endl;
    std::cin >> durationInMinutes;
    std::cout << "Inserisci l'anno dell'evento" << std::endl;
    std::cin >> year;
    std::cout << "Inserisci il mese dell'evento" << std::endl;
    std::cin >> month;
    std::cout << "Inserisci il giorno dell'evento" << std::endl;
    std::cin >> day;
    std::cout << "Inserisci l'ora di inzio dell'evento" << std::endl;
    std::cin >> hourOfBegin;
    std::cout << "Inserisci il minuto di inzio dell'evento" << std::endl;
    std::cin >> minuteOfBegin;
}

int main() {
    EventList eventList;
    eventList.readfile();

    int choice;

    do {
        std::cout << "Benvenuto nel programma di gestione eventi" << std::endl;
        std::cout << "Se vuoi aggiungere un evento, premi 1" << std::endl;
        std::cout << "Se vuoi rimuovere un evento, premi 2" << std::endl;
        std::cout << "Se vuoi modificare un evento, premi 3" << std::endl;
        std::cout << "Se vuoi stampare la lista degli eventi, premi 4" << std::endl;
        std::cout << "Se vuoi stampare la lista degli eventi dal file, premi 5" << std::endl;
        std::cout << "Se vuoi cercare un evento nella lista, premi 6" << std::endl;
        std::cout << "Se vuoi cercare un evento sulla base del nome e sapere le altre informazioni riguardanti l'evento premi 7" << std::endl;
        std::cout << "Se vuoi cercare un evento sulla base della data e sapere le altre informazioni riguardanti l'evento premi 8" << std::endl;
        std::cout << "Se vuoi cercare un evento sulla base dell'orario di inzio e sapere le altre informazioni riguardanti l'evento premi 9" << std::endl;
        std::cout << "Se vuoi cercare un evento sulla base della data e dell'orario di inizio e sapere le altre informazioni riguardanti l'evento premi 10" << std::endl;
        std::cout << "Se vuoi uscire, premi 0" << std::endl;
        std::cin >> choice;
        if (choice < 0 or choice > 10)
            std::cout << "Scelta non valida" << std::endl;
        else if (choice == 1) {
            std::string name, description;
            float price;
            int year, durationInMinutes, hourOfBegin, minuteOfBegin;
            unsigned month, day;
            InputEvents(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            Event event(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            eventList.addEvent(event);
            std::cout<<"L'evento e' stato aggiunto correttamente"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 2) {
            std::string name, description;
            float price;
            int year, durationInMinutes, hourOfBegin, minuteOfBegin;
            unsigned month, day;
            InputEvents(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            Event event(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            bool flag = eventList.removeEvent(event);
            if (flag)
                std::cout<<"L'evento e' stato rimosso correttamente"<<std::endl;
            else
                std::cout<<"L'evento da rimuovere non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 3) {
            std::string name, description;
            float price;
            int year, durationInMinutes, hourOfBegin, minuteOfBegin;
            unsigned month, day;
            std::cout<<"Inserisci i dati dell'evento da modificare"<<std::endl;
            InputEvents(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            Event oldEvent(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            std::cout<<"Inserisci i dati dell'evento nuovo"<<std::endl;
            InputEvents(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            Event newEvent(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            bool flag = eventList.modifyEvent(oldEvent, newEvent);
            if (flag)
                std::cout<<"L'evento e' stato modificato correttamente"<<std::endl;
            else
                std::cout<<"L'evento da modificare non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 4) {
            eventList.print();
            std::cout<<std::endl;
        }
        else if (choice == 5) {
            EventList::printfromfile();
            std::cout<<std::endl;
        }
        else if (choice == 6) {
            std::string name, description;
            float price;
            int year, durationInMinutes, hourOfBegin, minuteOfBegin;
            unsigned month, day;
            InputEvents(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            Event event(name, description, price, durationInMinutes, year, month, day, hourOfBegin, minuteOfBegin);
            bool flag = eventList.searchEvent(event);
            if (flag)
                std::cout<<"L'evento cercato e' presente nella lista"<<std::endl;
            else
                std::cout<<"L'evento cercato non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 7) {
            std::string name;
            std::cout<<"Inserisci il nome dell'evento da cercare"<<std::endl;
            std::cin>>name;
            bool flag = eventList.searchByName(name);
            if (!flag)
                std::cout<<"L'evento cercato non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 8) {
            int year;
            unsigned month, day;
            std::cout<<"Inserisci l'anno dell'evento da cercare"<<std::endl;
            std::cin>>year;
            std::cout<<"Inserisci il mese dell'evento da cercare"<<std::endl;
            std::cin>>month;
            std::cout<<"Inserisci il giorno dell'evento da cercare"<<std::endl;
            std::cin>>day;
            bool flag = eventList.searchByDate(year, month, day);
            if (!flag)
                std::cout<<"L'evento cercato non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 9) {
            int hourOfBegin, minuteOfBegin;
            std::cout<<"Inserisci l'ora di inizio dell'evento da cercare"<<std::endl;
            std::cin>>hourOfBegin;
            std::cout<<"Inserisci il minuto di inizio dell'evento da cercare"<<std::endl;
            std::cin>>minuteOfBegin;
            bool flag = eventList.searchByTime(hourOfBegin, minuteOfBegin);
            if (!flag)
                std::cout<<"L'evento cercato non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
        else if (choice == 10) {
            int year, hourOfBegin, minuteOfBegin;
            unsigned month, day;
            std::cout<<"Inserisci l'anno dell'evento da cercare"<<std::endl;
            std::cin>>year;
            std::cout<<"Inserisci il mese dell'evento da cercare"<<std::endl;
            std::cin>>month;
            std::cout<<"Inserisci il giorno dell'evento da cercare"<<std::endl;
            std::cin>>day;
            std::cout<<"Inserisci l'ora di inizio dell'evento da cercare"<<std::endl;
            std::cin>>hourOfBegin;
            std::cout<<"Inserisci il minuto di inizio dell'evento da cercare"<<std::endl;
            std::cin>>minuteOfBegin;
            bool flag = eventList.searchByDateAndTime(year, month, day, hourOfBegin, minuteOfBegin);
            if (!flag)
                std::cout<<"L'evento cercato non e' presente nella lista"<<std::endl;
            std::cout<<std::endl;
        }
    } while (choice != 0);

    std::cout<<"Sei uscito dal programma"<<std::endl;
    return 0;
}
