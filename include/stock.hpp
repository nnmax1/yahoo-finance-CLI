#ifndef STOCK_HPP
#define STOCK_HPP

#include <string>

class Stock {
    public:
    Stock() {}
    void setSymbol(std::string str) ;
    std::string getSymbol();
    void setExchange(std::string str) ;
    std::string getExchange() ;
    void setMarket(std::string str) ;
    std::string getMarket() ;
    void setShortName(std::string str) ;
    std::string getShortName() ;
    void setTradeable(bool b);
    bool isTradeable();
    void setFiftyDayAvg(double d);
    double getFiftyDayAvg() ;
    void setYearHigh(double d);
    double getYearHigh() ;
    void setYearLow(double d);
    double getYearLow() ;
    void setRegularMarketChange(double r) ;
    double getRegularMarketChange();
   void setRegularMarketPrice(double r) ;
    double getRegularMarketPrice() ;
   void setRegularMarketPreviousClose(double r) ;
    double getRegularMarketPreviousClose() ;
    void setTwoHundredDayAverage(double r) ;
    double getTwoHundredDayAverage() ;
    private: 
    std::string symbol="", exchange,market="", shortName="";
    bool tradeable=false;
    double fiftyDayAvg=0.0, yearLow=0.0, yearHigh=0.0;
    double regularMarketChange, regularMarketPrice,regularMarketPreviousClose;
    double twoHundredDayAverage;
};

#endif