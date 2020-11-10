 
 
#include "app.hpp"
#include <iostream>
#include <thread>
#include <cctype>
#include "quote.hpp"
void makeUpper(std::string &str) {
    for(char ch : str) {
        ch = toupper(ch);
    }
}
bool validateCommand(std::string c, std::vector<std::string> arr) {
  for(int i=0;i<arr.size();i++) {
        if(c == arr[i]) {
        return true;
        }
    }
    return false;
}

// entry point
int main(int argc , char * argv[]) {
    //pass in API Key and option as command line args
    std::vector<std::string> symbols ;
    std::string key = argv[1], ticker;
    std::string command = argv[2];
    std::vector<std::string> options = {"--top-gainers", "--etfs", "--mutual-funds", "--insider-trades", "--quotes", "--print-quote"};

    if(!validateCommand(command, options)) {
        std::cout<<"Invalid command\n";
        exit(1);
    }
    if(key.length() != 50) {
        std::cout<<"Invalid API KEY.\n";
        exit(1);
    }

    if(argc > 3 && command != "--quotes" && command != "--print-quote") {
        std::cout<<"Error! 3 command line arguments needed. \n";
        std::cout<<" ./app.exe [YOUR_API_KEY] --[arguments]\n";
        exit(1);
    }else if(argc == 4 && command == "--print-quote"){
        ticker = argv[3];
    }else if(argc != 4 && command == "--print-quote") {
        std::cout<<"Invalid usage of --print-quote\n";
        exit(1);
    }else if(argc  > 3 && command == "--quotes") {
        for(int i=3;i<argc;i++) {
            std::string ticker = argv[i];
            makeUpper(ticker);
            symbols.push_back(ticker);
        }
    }

    if(command == "--print-quote") {
        Quote q(key, ticker);
        q.show();
    }else {
        std::thread dataThread(App(),key,command, symbols) ; 
        dataThread.join();
    }
    return 0;
}