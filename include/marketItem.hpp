#ifndef MARKETITEM_HPP
#define MARKETITEM_HPP

#include "stock.hpp"
#include <vector>

//class to get data from the market/...  API Endpoints 
//(e.g market/top-gainers, market/mutual-funds, market/ETFS)

// A Generic market item
class MarketItem{
    public:
    //constructor
    MarketItem(std::string, std::string);
    //send another GET Request to API
    void refresh() ;
    //return number of stocks
    int getCount() ;  
    //print top gainers to console
    void show() ;
    //export top-gainers data to csv
    void exportToCSV();
    //set type
    void setType(std::string);
    //return current date (day/month/year) and time (hours-minutes-seconds)
    std::string getDate() ;
    private:
    std::vector<Stock> stocks;
    std::string jsonStr, apiKey, url, type;
    int count;
    //store data in  vector stocks;
    void storeData() ;
    void removeComma(std::string &);

};

#endif