#include "insidertrades.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>

#include "jsonxx.hpp"
#include "JSONFetcher.hpp"
using namespace jsonxx ;

    InsiderTrades::InsiderTrades(std::string a){
        apiKey = a;
        refresh();
    }
    void  InsiderTrades::refresh() {
        jsonStr = "";
        insiders.clear();
        JSONFetcher fetcher;
        fetcher.setUrl("https://yahoo-finance15.p.rapidapi.com/api/v1/sec/form4");
        fetcher.setApiKey("x-rapidapi-key: "+apiKey);
        fetcher.setHost( "x-rapidapi-host: yahoo-finance15.p.rapidapi.com");
        jsonStr = fetcher.getJSON();
        storeData();
    }
    //print records and links to command line/console
   void  InsiderTrades::show() {
       std::cout<<"Insider Trading Records \n";
       std::cout<<"Symbol  : Link/url to Filing\n";
       for(int i=0;i<count;i++) {
           std::cout<<insiders[i].symbol<<"  :  "<<insiders[i].linkToFilingDetails<<"\n";
       }
    }
   void InsiderTrades::exportToCSV() {
        //export top gainers data to CSV
        std::ofstream writer;
        writer.open("insiderTrades_"+getDate()+".csv");
        if(writer.fail()) {
            throw new std::string("FileNotFoundException");
        }
        writer<<"Date, Symbol , Relationship , Reporting Owner Address , Transaction Code , ";
        writer<<"Avg Price Per Share , Sum of Transaction Shares , Link to Filing Details\n";
        for(int i=0;i<count;i++) {
            writer <<insiders[i].date<<" , "<<insiders[i].symbol<<" , ";
            writer <<insiders[i].relationship<<" , "<<insiders[i].reportingOwnerAddress<<" , ";
            writer <<insiders[i].transactionCode <<" , "<< insiders[i].aveg_pricePerShare<< " , ";
            writer << insiders[i].sum_transactionShares<<" , "<<insiders[i].linkToFilingDetails<<"\n";
        }
        writer.close();
    }
   void  InsiderTrades::storeData() {
        Object jsonxxObj;
        jsonxxObj.parse(jsonStr);
       count = jsonxxObj.get<Number>("records");
       for(int i=0;i<count;i++) {
           Insider ins;
           ins.date = jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("date");
           ins.symbol = jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("symbol");
           std::string tempRel = jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("relationship");
           removeComma(tempRel);
           ins.relationship = tempRel;
           std::string tempAddr = jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("reportingOwnerAddress");
           removeComma(tempAddr);
           ins.reportingOwnerAddress = tempAddr;
           ins.linkToFilingDetails =  jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("linkToFilingDetails");
           ins.transactionCode =  jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<String>("transactionCode");
           ins.aveg_pricePerShare =  jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<Number>("aveg_pricePerShare");
           ins.sum_transactionShares = jsonxxObj.get<Array>("form_4_filings").get<Object>(i).get<Number>("sum_transactionShares");
           insiders.push_back(ins);
       }
    }
    std::string  InsiderTrades::getDate() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%m-%d-%Y_%H-%M-%S");
        auto str = oss.str();
        return str;
    }
    int InsiderTrades::getRecords() {
        return count;
    }
    void InsiderTrades::removeComma(std::string &str) {
        for(int i=0;i< str.length();i++) {
            if(str.at(i) == ',') {
                str.at(i) = ' ';
            }
        }
    }
