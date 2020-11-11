
# Yahoo Finance API Command Line Tool 



<h2>About</h2>
<li>This is a command line tool to get data from the yahoo-finance15 API </li>
<li>All you need is your RapidAPI Key.</li> 
<li>It's best if you use this between market open (9:30 Eastern) and market close ( before 16:00 Eastern). </li>
<li>Use control C to terminate the program </li>

<h2>API Endpoints:  </h2>
<li>market/top-gainers: https://yahoo-finance15.p.rapidapi.com/api/yahoo/ga/topgainers?start=0</li>
<li>insider-trades: https://yahoo-finance15.p.rapidapi.com/api/v1/sec/form4 </li>
<li>mutual-funds: https://yahoo-finance15.p.rapidapi.com/api/yahoo/mu/topmutualfunds?start=0</li>
<li>ETFs: https://yahoo-finance15.p.rapidapi.com/api/yahoo/et/topetfs?start=0 </li>

<br >
<h2>Dependencies </h2>
<li>https://github.com/hjiang/jsonxx</li>
<li>Curl </li>
<br >


<h2>Compiling </h2>
<pre>
~$ make
Creating directories
make[1]: Entering directory '/mnt/c/Users/nnmax/Documents/GitHub/yahoo-finance-CLI'
Compiling: src/JSONFetcher.cpp -> build/JSONFetcher.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/JSONFetcher.cpp -o build/JSONFetcher.o
Compiling: src/app.cpp -> build/app.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/app.cpp -o build/app.o
Compiling: src/insidertrades.cpp -> build/insidertrades.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/insidertrades.cpp -o build/insidertrades.o
Compiling: src/jsonxx.cpp -> build/jsonxx.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/jsonxx.cpp -o build/jsonxx.o
Compiling: src/main.cpp -> build/main.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
Compiling: src/marketItem.cpp -> build/marketItem.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/marketItem.cpp -o build/marketItem.o
Compiling: src/quote.cpp -> build/quote.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/quote.cpp -o build/quote.o
Compiling: src/quotes.cpp -> build/quotes.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/quotes.cpp -o build/quotes.o
Compiling: src/stock.cpp -> build/stock.o
clang++ -std=c++17   -Wall -g -I include/ -I /usr/local/include -MP -MMD -c src/stock.cpp -o build/stock.o
Linking: build/exe/app.exe
clang++ -std=c++17  -lcurl -pthread build/JSONFetcher.o build/app.o build/insidertrades.o build/jsonxx.o build/main.o build/marketItem.o build/quote.o build/quotes.o build/stock.o -o build/exe/app.exe
Making symlink: app.exe -> build/exe/app.exe
make[1]: Leaving directory '/mnt/c/Users/nnmax/Documents/GitHub/yahoo-finance-CLI'
</pre>


<h2>Command line Arguments: </h2>
<li>--top-gainers : send GET Request to market/top-gainers endpoint  every 5 min and save data to csv</li>
<li>--mutual-funds : send GET Request mutual-funds endpoint every 5 min and save data to csv</li>
<li>--etfs : send GET Request to ETFs endpoint every 5 min and save data to csv</li>
<li>--insider-trades : send GET Request to insider trades endpoint every 5 min and save data to csv</li>
<li>--quotes [STOCK_TICKERS] : send GET Request to market/quotes endpoint and save data to csv </li>
<li>--print-quote [STOCK_TICKER] : prints the stock's quote to the console </li> 
<br>
<br>



<h2>Usage</h2>
<pre>
~$ ./app.exe [YOUR_API_KEY] --[arguments]
</pre>
<h3>Example to get insider-trading data  </h3>
<pre>
~$ ./app.exe [YOUR_API_KEY] --insider-trades
Fetching data from yahoo-finance15 API......
Saved insider-trades data at 11-09-2020_12-59-37
Fetching data from yahoo-finance15 API......
Saved insider-trades data at 11-09-2020_13-01-37
^C
</pre>
<br>
<h3>Example to get Stock Quotes </h3>
<pre>
~$ ./app.exe [YOUR_API_KEY] --quotes MSFT AAPL TSLA NVDA AMD
</pre>
<br>

<h3>Example usage of --print-quote </h3>
<pre>
~$ ./app.exe [YOUR_API_KEY] --print-quote NVDA
NVIDIA Corporation
ASK: 531.33  |  BID: 531.1   
ASK SIZE: 13  |  BID SIZE: 10
EXCHANGE: NMS
BOOK VALUE: 22.551
MARKET CAP: 3.2749e+11       
TRAILING PE: 97.3851
FORWARD PE: 47.7626
REG. MARKET PRICE: 530.165   
REG. MARKET VOLUME: 5.549e+06
REG. MARKET HIGH: 532.55     
REG. MARKET LOW: 517.964     
REG. MARKET CHANGE: 19.3646  
REG. MARKET OPEN: 522.15
REG. MARKET PREV. CLOSE: 510.8
50 DAY AVG.: 536.229
50 DAY AVG. CHANGE: -6.06457
200 DAY AVG.: 440.641
200 DAY AVG. CHANGE: 89.524
1 YEAR HIGH: 589.07  |  1 YEAR LOW: 180.68
</pre>

<h2>Sample CSV Data: </h2>
<a href="csv/top-gainers">topgainers.csv</a><br>
<a href="csv/insider-trades">insidertrades.csv</a><br>
<a href= "csv/etfs">etfs.csv</a><br>
<a href= "csv/mutual-funds">mutual-funds</a><br>
<a href= "csv/quotes">quotes.csv</a><br>

<br><br>
