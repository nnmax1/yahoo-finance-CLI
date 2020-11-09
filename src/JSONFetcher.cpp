
#include "JSONFetcher.hpp"
#include <curl/curl.h>
#include <fstream>

   JSONFetcher::JSONFetcher() {
        url = "";
        apiKey = "";
        host = "";
    }
    JSONFetcher::JSONFetcher(std::string u, std::string a, std::string h) {
        url = u;
        apiKey = a;
        host = h;
    }
   void  JSONFetcher::setUrl(std::string u) {
        url = u;
    }
    void  JSONFetcher::setApiKey(std::string a) {
        apiKey = a;
    }
    void  JSONFetcher::setHost(std::string h) {
        host = h;
    }
    std::string  JSONFetcher::getJSON() {
        const char * urlCopy = url.c_str();
        const char * apiCopy = apiKey.c_str();
        const char * hostCopy = host.c_str();
        CURL *curl;
        CURLcode res;
        std::string readBuffer;
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
            curl_easy_setopt(curl, CURLOPT_URL, urlCopy );
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            struct curl_slist *headers = NULL;  
            headers = curl_slist_append(headers, apiCopy  );
            headers = curl_slist_append(headers, hostCopy );
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            return readBuffer;
        }
        return " ";
    }
    void  JSONFetcher::writeData(std::string filename){
        std::ofstream w;
        w.open(filename);
        std::string temp =  getJSON();
        w << temp<<"\n";
        w.close();
    }
    size_t JSONFetcher::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }