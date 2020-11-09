#include "marketItem.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>

#include "jsonxx.hpp"
#include "JSONFetcher.hpp"
using namespace jsonxx ;

    MarketItem::MarketItem(std::string a, std::string u){
        apiKey = a;
        url = u;
        refresh();
    }
    void MarketItem::setType(std::string t) {
        type = t;
    }
    void MarketItem::refresh() {
        jsonStr = "";
        stocks.clear();
        JSONFetcher fetcher;
        fetcher.setUrl(url);
        fetcher.setApiKey("x-rapidapi-key: "+apiKey);
        fetcher.setHost( "x-rapidapi-host: yahoo-finance15.p.rapidapi.com");
        jsonStr = fetcher.getJSON();
        storeData();
    }
   void MarketItem::show() {
        std::cout<<type + "Data \n";
        std::cout<<"  -------------------\n";
        for(int j=0;j<count;j++) {
            std::cout<<"  "<<j+1<<".) ";
            std::cout<<stocks[j].getSymbol()<< ": "<<stocks[j].getShortName()<<"\n";
        }
    }
   void MarketItem::exportToCSV() {
        //export top gainers data to CSV
        std::ofstream writer;
        writer.open(type+"_"+getDate()+".csv");
        if(writer.fail()) {
            throw new std::string("FileNotFoundException");
        }
        writer<<"Symbol , Exchange , Short Name , Market , Tradeable, Regular Market Price , ";
        writer<<"Regular Market Change , Regular Market Previous Close , ";
        writer<<"50 Day Avg ,  200 Day Avg , 52 Week Low , 52 Week High \n";
       writer<<jsonStr<<"\n";
        for(int j=0;j<count;j++) {
           writer<<stocks[j].getSymbol()<< " , "<<stocks[j].getExchange()<<" , "<<stocks[j].getShortName()<<" , ";
           writer<<stocks[j].getMarket()<< " , "<<stocks[j].isTradeable()<<" , ";
           writer<<stocks[j].getRegularMarketPrice()<<" , "<<stocks[j].getRegularMarketChange()<<" , ";
           writer<<stocks[j].getRegularMarketPreviousClose()<<" , ";
           writer<<stocks[j].getFiftyDayAvg()<<" , "<<stocks[j].getTwoHundredDayAverage()<<" , ";
           writer<<stocks[j].getYearLow()<< " , "<<stocks[j].getYearHigh()<<"\n";
        }
        writer.close();
    }
   void MarketItem::storeData() {
        Object jsonxxObj;
        jsonxxObj.parse(jsonStr);
        count  = jsonxxObj.get<Number>("count");
        for(int i=0;i<count;i++) {
            Stock stock;
            stock.setSymbol(jsonxxObj.get<Array>("quotes").get<Object>(i).get<String>("symbol")) ;
            stock.setExchange(jsonxxObj.get<Array>("quotes").get<Object>(i).get<String>("exchange"));
            stock.setMarket(jsonxxObj.get<Array>("quotes").get<Object>(i).get<String>("market"));
            stock.setTradeable(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Boolean>("tradeable"));
            std::string temp = jsonxxObj.get<Array>("quotes").get<Object>(i).get<String>("shortName");
            removeComma(temp);
            stock.setShortName(temp);
            stock.setFiftyDayAvg(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("fiftyDayAverage"));
            stock.setYearLow(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("fiftyTwoWeekLow"));
            stock.setYearHigh(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("fiftyTwoWeekHigh")); 
            stock.setRegularMarketChange(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("regularMarketChange"));
            stock.setRegularMarketPrice(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("regularMarketPrice"));
            stock.setRegularMarketPreviousClose(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("regularMarketPreviousClose"));
            stock.setTwoHundredDayAverage(jsonxxObj.get<Array>("quotes").get<Object>(i).get<Number>("twoHundredDayAverage"));
            stocks.push_back(stock);
        }
    }
    std::string MarketItem::getDate() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%m-%d-%Y_%H-%M-%S");
        auto str = oss.str();
        return str;
    }
    int MarketItem::getCount() {
        return count;
    }
    void MarketItem::removeComma(std::string &str) {
        for(int i=0;i< str.length();i++) {
            if(str.at(i) == ',') {
                str.at(i) = ' ';
            }
        }
    }
