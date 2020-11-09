#ifndef QUOTES_HPP
#define QUOTES_HPP

#include <string>
#include <vector>

// A collection of Quotes

class Quotes {
    public:
    Quotes(std::string a, std::vector<std::string> s) {
        apiKey = a;
        symbols = s;
    }
    //export market Quotes to CSV
    void exportQuotes() ;
    std::string getDate();
    private:
    std::string apiKey;
    std::vector<std::string>symbols;
};

#endif