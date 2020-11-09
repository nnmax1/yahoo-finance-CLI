#ifndef JSONFETCHER_HPP
#define JSONFETCHER_HPP


#include <string>

// a class that can send a GET Request to Yahoo finance RapidAPI API and 
// return the response as a std::string 
// need to initailize a JSONFetcher object with API Key, url, and host

class JSONFetcher {
    public: 
    //constructor
    JSONFetcher() ;
    //constructor
    JSONFetcher(std::string u, std::string a, std::string h);
    //set url, apikey , and host
    void setUrl(std::string u );
    void setApiKey(std::string a) ;
    void setHost(std::string h) ;
    //returns json response as std::string
    std::string getJSON() ;
    //save data to file
    void writeData(std::string filename);
    private: 
    //vars
    std::string url, apiKey, host; 
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};


#endif