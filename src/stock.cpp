    
#include "stock.hpp"
    void Stock::setSymbol(std::string str) {
        symbol = str;
    }
    std::string Stock::getSymbol() {
        return symbol ;
    }
    void Stock::setExchange(std::string str) {
        exchange = str;
    }
    std::string Stock::getExchange() {
        return exchange ;
    }
    void Stock::setMarket(std::string str) {
        market = str;
    }
    std::string Stock::getMarket() {
        return market ;
    }
    void Stock::setShortName(std::string str) {
        shortName = str;
    }
    std::string Stock::getShortName() {
        return shortName ;
    }

    void Stock::setTradeable(bool b) {
        tradeable = b;
    }
    bool Stock::isTradeable() {
        return tradeable;
    }
    void Stock::setFiftyDayAvg(double d){
    fiftyDayAvg = d;
    }
    double Stock::getFiftyDayAvg() {
        return fiftyDayAvg;
    }
    void Stock::setYearHigh(double d){
        yearHigh = d;
    }
    double Stock::getYearHigh() {
        return yearHigh;
    }
    void Stock::setYearLow(double d){
        yearLow = d;
    }
    double Stock::getYearLow() {
        return yearLow;
    }
    void Stock::setRegularMarketChange(double r) {
            regularMarketChange = r;
    } 
    double Stock::getRegularMarketChange() {
        return  regularMarketChange;
    } 
   void Stock::setRegularMarketPrice(double r) {
        regularMarketPrice = r;
    }
    double Stock::getRegularMarketPrice() {
        return regularMarketPrice;
    }
   void Stock::setRegularMarketPreviousClose(double r) {
        regularMarketPreviousClose = r;
    }
    double Stock::getRegularMarketPreviousClose() {
        return regularMarketPreviousClose;
    }
    void Stock::setTwoHundredDayAverage(double r) {
        twoHundredDayAverage = r;
    }
    double Stock::getTwoHundredDayAverage() {
        return twoHundredDayAverage;
    }