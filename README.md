
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
<a href="csv/quotes_12-22-2020_19-23-14.csv">quote for MSFT, AAPL, TSLA, and AMD</a>
<h3>Example usage of --print-quote </h3>
<pre>
~$ ./app.exe [YOUR_API_KEY] --print-quote NVDA
NVIDIA Corporation
ASK: 530.19  |  BID: 529.9     
ASK SIZE: 8  |  BID SIZE: 10   
EXCHANGE: NMS
BOOK VALUE: 24.772
MARKET CAP: 3.28769e+11        
TRAILING PE: 86.8285
FORWARD PE: 45.357
REG. MARKET PRICE: 531.13      
REG. MARKET VOLUME: 4.51663e+06
REG. MARKET HIGH: 533.49       
REG. MARKET LOW: 522.155
REG. MARKET CHANGE: -2.15997
REG. MARKET OPEN: 532.77
REG. MARKET PREV. CLOSE: 533.29
50 DAY AVG.: 533.94
50 DAY AVG. CHANGE: -2.81
200 DAY AVG.: 482.182
200 DAY AVG. CHANGE: 48.9478
1 YEAR HIGH: 589.07  |  1 YEAR LOW: 180.68
</pre>

<h2>Sample CSV Data: </h2>
<a href="csv/top-gainers">topgainers.csv</a><br>
<a href="csv/insider-trades">insidertrades.csv</a><br>
<a href= "csv/etfs">etfs.csv</a><br>
<a href= "csv/mutual-funds">mutual-funds.csv</a><br>

<br><br>
