 
 
#include "app.hpp"
#include <iostream>
#include <thread>
#include "quotes.hpp"
#include <cctype>

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
    std::vector<std::string> q ;
    std::string key = argv[1];
    std::string command = argv[2];
    std::vector<std::string> options = {"--top-gainers", "--etfs", "--mutual-funds", "--insider-trades", "--quotes"};

    if(argc != 3 &&  command != "--quotes") {
        std::cout<<"Error! 3 command line arguments needed. \n";
        std::cout<<" ./app.exe [YOUR_API_KEY] --[type_of_market_data]\n";
        exit(1);
    }else if(argc  > 3 && command == "--quotes") {
        for(int i=3;i<argc;i++) {
            std::string ticker = argv[i];
            makeUpper(ticker);
            q.push_back(ticker);
        }
    }
    if(!validateCommand(command, options)) {
        std::cout<<"Invalid command\n";
        exit(1);
    }
    if(key.length() != 50) {
        std::cout<<"Invalid API KEY.\n";
        exit(1);
    }
    if(command == "--quotes") {
        Quotes quotes(key, q);
        try {
        quotes.exportQuotes();
        }catch(std::string * exc) {
            std::cout<<*exc<<"\n";
        }
        std::cout<<"Data saved to quotes_"+quotes.getDate()+".csv\n";
    }else {
        std::thread dataThread(App(),key,command) ; 
        dataThread.join();
    }

    return 0;
}