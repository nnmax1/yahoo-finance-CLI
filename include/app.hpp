#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <vector>
//App Client class

class App {
    public:
    App(){};
    void operator()(std::string, std::string, std::vector<std::string>)  ;
    private: 
    //api Key
    std::string key; 
    //methods
    void topGainers();
    void mutualFunds(); 
    void etfs();
    void insiderTrades() ;
    void marketQuotes(std::vector<std::string> t);
};
#endif