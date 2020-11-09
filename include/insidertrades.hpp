#ifndef INSIDERTRADES_HPP
#define INSIDERTRADES_HPP


#include <string>
#include <vector>
//class to get data from te Insider-trades API Endpoint

//Latest insider trading activities from CEO, Directors, Chief Executive Officer, 10% Owner, etc…

struct Insider  {
    std::string date, reportingOwnerAddress;
    std::string relationship,linkToFilingDetails;
    std::string transactionCode, symbol;
    double sum_transactionShares, aveg_pricePerShare;
    double num_shares_own, tot_value;
};

class InsiderTrades{
    public:
    //constructor
    InsiderTrades(std::string);
    //send another GET Request to API
    void refresh() ;
    //return number of insider trading records
    int getRecords() ;  
    //print insider trades data  to console
    void show() ;
    //export insider trades data to csv
    void exportToCSV();
    //return current date (day/month/year) and time (hours-minutes-seconds)
    std::string getDate() ;
    private:
    std::vector<Insider> insiders;
    std::string jsonStr, apiKey;
    int count;
    //store data in vector 
    void storeData() ;
    void removeComma(std::string &);


};

#endif