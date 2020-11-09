#ifndef QUOTE_HPP
#define QUOTE_HPP


#include <string>
//class to get market/quote 


struct QuoteType {
    std::string longName,exchange;
    double ask, bid, askSize, bidSize, averageDailyVolume10Day;
    double bookValue, yearHigh, yearLow, fiftyDayAvg, twoHundredDayAvg;
    double forwardPE, trailingPE, marketCap, fiftyDayAvgChange, twoHundredDayAvgChange;
    double regMarketPrice, regMarketHigh, regMarketLow, regMarketChange, regMarketVolume;
    double regMarketOpen,regMarketPreviousClose;
};

// A single Quote

class Quote{
    public:
    //constructor
    Quote(std::string, std::string);
    //send another GET Request to API
    void refresh() ;
    //print insider trades data  to console
    void show() ;
    //returns a QuoteType 
    QuoteType getCurrentQuote();
    private:
    QuoteType currentQuote;
    std::string jsonStr, apiKey, symbol;
    //store data in vector 
    void storeData() ;
    void removeComma(std::string &);


};

#endif