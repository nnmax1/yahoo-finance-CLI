#ifndef APP_HPP
#define APP_HPP

#include <string>

//App Client class

class App {
    public:
    App() {
        key = "";
    }
    App(std::string a) {
        key = a;
    }
    void setApiKey(std::string a) {
        key = a;
    }
    void operator()(std::string, std::string)  ;
    private: 
    //api Key
    std::string key; 
    //methods
    void topGainers();
    void mutualFunds(); 
    void etfs();
    void insiderTrades() ;
};
#endif