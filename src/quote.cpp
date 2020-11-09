#include "quote.hpp"
#include <iostream>
#include <iomanip>

#include "jsonxx.hpp"
#include "JSONFetcher.hpp"
using namespace jsonxx ;

    Quote::Quote(std::string a, std::string s) {
        apiKey = a;
        symbol = s;
        refresh();
    }
    void Quote::refresh() {
        jsonStr = "";
        JSONFetcher fetcher;
        fetcher.setUrl("https://yahoo-finance15.p.rapidapi.com/api/yahoo/qu/quote/"+symbol);
        fetcher.setApiKey("x-rapidapi-key: "+apiKey);
        fetcher.setHost( "x-rapidapi-host: yahoo-finance15.p.rapidapi.com");
        jsonStr = fetcher.getJSON();
        storeData();
    }
    void Quote::show() {
        std::cout<<currentQuote.longName<<"\n";
        std::cout<<"ASK: "<<currentQuote.ask<<"  |  BID: "<<currentQuote.bid<<"\n";
        std::cout<<"ASK SIZE: "<<currentQuote.askSize<<"  |  BID SIZE: "<<currentQuote.bidSize<<"\n";
        std::cout<<"EXCHANGE: "<<currentQuote.exchange<<"\n";
        std::cout<<"BOOK VALUE: "<<currentQuote.bookValue<<"\n";
        std::cout<<"MARKET CAP: "<<currentQuote.marketCap<<"\n";
        std::cout<<"TRAILING PE: "<<currentQuote.trailingPE<<"\n";
        std::cout<<"FORWARD PE: "<<currentQuote.forwardPE<<"\n";
        std::cout<<"REG. MARKET PRICE: "<<currentQuote.regMarketPrice<<"\n";
        std::cout<<"REG. MARKET VOLUME: "<<currentQuote.regMarketVolume<<"\n";
        std::cout<<"REG. MARKET HIGH: "<<currentQuote.regMarketHigh<<"\n";
        std::cout<<"REG. MARKET LOW: "<<currentQuote.regMarketLow<<"\n";
        std::cout<<"REG. MARKET CHANGE: "<<currentQuote.regMarketChange<<"\n";
        std::cout<<"REG. MARKET OPEN: "<<currentQuote.regMarketOpen<<"\n";
        std::cout<<"REG. MARKET PREV. CLOSE: "<<currentQuote.regMarketPreviousClose<<"\n";
        std::cout<<"50 DAY AVG.: "<<currentQuote.fiftyDayAvg<<"\n";
        std::cout<<"50 DAY AVG. CHANGE: "<<currentQuote.fiftyDayAvgChange<<"\n";
        std::cout<<"200 DAY AVG.: "<<currentQuote.twoHundredDayAvg<<"\n";
        std::cout<<"200 DAY AVG. CHANGE: "<<currentQuote.twoHundredDayAvgChange<<"\n";
        std::cout<<"1 YEAR HIGH: "<<currentQuote.yearHigh<<"  |  1 YEAR LOW: "<<currentQuote.yearLow<<"\n";
    }
    QuoteType Quote::getCurrentQuote() {
        return currentQuote;
    }
   void  Quote::storeData() {
        Array jsonxxObj;
        jsonxxObj.parse(jsonStr);
        std::string tempName= jsonxxObj.get<Object>(0).get<String>("longName");  
        removeComma(tempName);
        currentQuote.longName = tempName;
        currentQuote.exchange = jsonxxObj.get<Object>(0).get<String>("exchange");  
        currentQuote.ask = jsonxxObj.get<Object>(0).get<Number>("ask");
        currentQuote.bid = jsonxxObj.get<Object>(0).get<Number>("bid");    
        currentQuote.askSize = jsonxxObj.get<Object>(0).get<Number>("askSize");  
        currentQuote.bidSize = jsonxxObj.get<Object>(0).get<Number>("bidSize");  
        currentQuote.averageDailyVolume10Day =jsonxxObj.get<Object>(0).get<Number>("averageDailyVolume10Day");
        currentQuote.bookValue = jsonxxObj.get<Object>(0).get<Number>("bookValue");  
        currentQuote.yearHigh = jsonxxObj.get<Object>(0).get<Number>("fiftyTwoWeekHigh");  
        currentQuote.yearLow = jsonxxObj.get<Object>(0).get<Number>("fiftyTwoWeekLow");  
        currentQuote.fiftyDayAvg = jsonxxObj.get<Object>(0).get<Number>("fiftyDayAverage");  
        currentQuote.fiftyDayAvgChange =  jsonxxObj.get<Object>(0).get<Number>("fiftyDayAverageChange");  
        currentQuote.twoHundredDayAvg = jsonxxObj.get<Object>(0).get<Number>("twoHundredDayAverage");  
        currentQuote.twoHundredDayAvgChange  =  jsonxxObj.get<Object>(0).get<Number>("twoHundredDayAverageChange");  
        currentQuote.trailingPE =  jsonxxObj.get<Object>(0).get<Number>("trailingPE");  
        currentQuote.forwardPE =  jsonxxObj.get<Object>(0).get<Number>("forwardPE");  
        currentQuote.regMarketChange =  jsonxxObj.get<Object>(0).get<Number>("regularMarketChange");  
        currentQuote.regMarketPrice =  jsonxxObj.get<Object>(0).get<Number>("regularMarketPrice");  
        currentQuote.regMarketHigh = jsonxxObj.get<Object>(0).get<Number>("regularMarketDayHigh");  
        currentQuote.regMarketLow = jsonxxObj.get<Object>(0).get<Number>("regularMarketDayLow");  
        currentQuote.regMarketOpen = jsonxxObj.get<Object>(0).get<Number>("regularMarketOpen");  
        currentQuote.regMarketVolume = jsonxxObj.get<Object>(0).get<Number>("regularMarketVolume");  
        currentQuote.regMarketPreviousClose = jsonxxObj.get<Object>(0).get<Number>("regularMarketPreviousClose");  
    }
    void Quote::removeComma(std::string &str) {
        for(int i=0;i< str.length();i++) {
            if(str.at(i) == ',') {
                str.at(i) = ' ';
            }
        }
    }