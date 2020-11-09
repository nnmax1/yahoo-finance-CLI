

#include "quotes.hpp"
#include <sstream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "quote.hpp"

    std::string Quotes::getDate() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%m-%d-%Y_%H-%M-%S");
        auto str = oss.str();
        return str;
    }
    //export market Quotes to CSV
    void Quotes::exportQuotes() {
        std::ofstream writer;
        writer.open("quotes_"+getDate()+".csv");
        if(writer.fail()) {
            throw new std::string("FileNotFoundException");
        }
        writer<<"Symbol, Long Name, Ask, Bid, Ask Size, Bid Size, Exchange, ";
        writer<<"Book Value, Market Cap, Trailing PE, Forward PE, ";
        writer<<"Reg. Market Price, Reg. Market High, Reg. Market Low, ";
        writer<<"Reg. Market Change, Reg. Market Volume, Reg. Market Open, ";
        writer<<"Reg. Market Previous Close, 50 Day Avg, 50 Day Avg Change, 200 Day Avg, ";
        writer<<"200 Day Avg Change, 1 Year High, 1 Year Low\n";
        for(int i=0;i<symbols.size();i++) {
            Quote *q = new Quote(apiKey, symbols[i]);
            QuoteType temp = q->getCurrentQuote();
            writer<<symbols[i]<<" , "<<temp.longName<<" , ";
            writer<<temp.ask<<" , "<<temp.bid<<" , ";
            writer<<temp.askSize<<" , "<<temp.bidSize<<" , ";
            writer<<temp.exchange<<" , "<<temp.bookValue <<" , ";
            writer<<temp.marketCap<<" , "<<temp.trailingPE<<" , ";
            writer<<temp.forwardPE<<" , "<<temp.regMarketPrice<<" , ";
            writer<<temp.regMarketHigh<<" , "<<temp.regMarketLow<<" , ";
            writer<< temp.regMarketChange<<" , "<<temp.regMarketVolume<<" , ";
            writer<<temp.regMarketOpen<<" , "<<temp.regMarketPreviousClose<< " , ";
            writer<<temp.fiftyDayAvg<<" , "<<temp.fiftyDayAvgChange<<" , ";
            writer<<temp.twoHundredDayAvg<<" , "<<temp.twoHundredDayAvgChange<<" , ";
            writer<<temp.yearHigh<<" , "<<temp.yearLow<<"\n";
            delete q;
        }
        writer.close();
    }