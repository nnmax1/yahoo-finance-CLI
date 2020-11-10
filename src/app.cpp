
#include "app.hpp"
#include "quotes.hpp"
#include "marketItem.hpp"
#include "insidertrades.hpp"
#include <chrono> 
#include <thread> 
#include <iostream>
#include <mutex>
std::mutex globalMutex;


void App::topGainers() {
    //continuously gather data every  2 minutes
        MarketItem topgainers(key, "https://yahoo-finance15.p.rapidapi.com/api/yahoo/ga/topgainers?start=0");
        topgainers.setType("topgainers");
        try {
            topgainers.exportToCSV();
            std::cout<<"Saved market/top-gainers data at "+ topgainers.getDate()+"\n";
        }catch(std::string * except) {
            std::cout<<*except<<"\n";
        }
        topgainers.refresh();

}


void App::mutualFunds( ) {
    //continuously gather data every 2 min
        MarketItem mutualFunds(key, "https://yahoo-finance15.p.rapidapi.com/api/yahoo/mu/topmutualfunds?start=0");
        mutualFunds.setType("mutualFunds");
        try {
            mutualFunds.exportToCSV();
            std::cout<<"Saved market/mutual-funds data at "+ mutualFunds.getDate()+"\n";
        }catch(std::string * except) {
            std::cout<<*except<<"\n";
        }
        mutualFunds.refresh();
}
void App::etfs( ) {
        MarketItem etfs(key, "https://yahoo-finance15.p.rapidapi.com/api/yahoo/et/topetfs?start=0");
        etfs.setType("etfs");
        try {
            etfs.exportToCSV();
            std::cout<<"Saved market/etf data at "+ etfs.getDate()+"\n";
        }catch(std::string * except) {
            std::cout<<*except<<"\n";
        }
        etfs.refresh();
}

void App::insiderTrades() {
        InsiderTrades insidertrades(key);
        try {
            insidertrades.exportToCSV();
            std::cout<<"Saved insider-trades data at "+ insidertrades.getDate()+"\n";
        }catch(std::string * except) {
            std::cout<<*except<<"\n";
        }
        insidertrades.refresh();
}
    void App::marketQuotes(std::vector<std::string> t) {
        Quotes quotes(key, t);
        try {
        quotes.exportQuotes();
        }catch(std::string * exc) {
            std::cout<<*exc<<"\n";
        }
        std::cout<<"Data saved to quotes_"+quotes.getDate()+".csv\n";
    }
    void App::operator()(std::string k, std::string choice, std::vector<std::string> t)  {
        key = k;
        bool run = true;
        while(run){
            std::cout<<"Fetching data from yahoo-finance15 API......\n";
            globalMutex.lock();
            if(choice == "--quotes") {
                marketQuotes(t);
            }
            if(choice == "--top-gainers"){
                topGainers() ;
            }else if(choice == "--etfs"){
                etfs();
            }else if(choice == "--mutual-funds"){
                mutualFunds();
            }else if(choice == "--insider-trades"){
                insiderTrades();
            }
            globalMutex.unlock();
            std::this_thread::sleep_for(std::chrono::minutes(5));
        }
    } 