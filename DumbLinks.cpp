#include <iostream>
#include <curl/curl.h>
#include <string>
#include <regex>


using namespace std;
string response;
//Call back function to handle incoming data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{                   //append recieved data to userp pointer
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb; //Returns the size of data recieved
}

void curled()
{
    string host;
    cout << "Enter hostname: ";
    cin >> host;
    if(host.find("https://") != 0 && host.find("http://")!=0){
        host = "http://"+host;
    }
    
    //pointer to CURL struct
    CURL *curl; 
    // store result in res
    CURLcode res;   
    //Make a global cur; env
    curl_global_init(CURL_GLOBAL_DEFAULT);
    //initialize curl
    curl = curl_easy_init();
    //if successful
    if(curl){
        //set URL to fetch                 //must convert to c-style string
        curl_easy_setopt(curl, CURLOPT_URL, host.c_str());
        //enable follow redirects control with {num}L
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 2L);
        // set callback to handle response data            
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        //pass response to callback function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        //add user agent
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "DumbLinks/1.0");
        // Set connection timeout to 10 seconds
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
        // Set maximum time for the entire request to 30 seconds
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        // Make HTTP request  
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            //print error if request fails 
            cout << "Your request Failed :/" << curl_easy_strerror(res) << endl;
        }else{
            //cout << "Respons:\n" << response << endl;
        }
        //clean CURL handle
        curl_easy_cleanup(curl);
    }
    //clean the gloabal curl env
    curl_global_cleanup();
}

void link_parse()
{
    //regex to parse links by using <a> tags and href
    regex mylinks("<a\\s+(?:[^>]*?\\s+)?href=\"([^\"]*)\"");
    //find all matches in the response string
    auto links_begin = sregex_iterator(response.begin(),response.end(),mylinks);
    auto links_end = sregex_iterator(); //empty constructo represents end of iterato

    for (sregex_iterator i = links_begin; i!=links_end; ++i){
        //get amount of matches
        smatch match = *i; 
         //extract each url
        string link = match.str(1);
        if( link.find("htt")!=0){

        }else{
        cout << "Found link: " << link << endl; 
        }
    }
}

int main()
{
    cout << "▉▉▉◣ ▉    ▉ ▉   ▉ ▉▉▉         ▉     ▉▉▉▉▉ ▉   ▉ ▉  ▉" << endl;
    cout << "▉  ▉ ▉    ▉ ▉▉ ▉▉ ▉  ▉        ▉       ▉   ▉▉  ▉ ▉ ▉" << endl;
    cout << "▉  ▉ ▉    ▉ ▉ ▉ ▉ ▉▉▉   ▉▉▉▉  ▉       ▉   ▉ ▉ ▉ ▉▉" << endl;
    cout << "▉  ▉ ▉    ▉ ▉   ▉ ▉  ▉        ▉       ▉   ▉  ▉▉ ▉ ▉" << endl;
    cout << "▉▉▉◤  ▉▉▉▉  ▉   ▉ ▉▉▉         ▉▉▉▉▉ ▉▉▉▉▉ ▉   ▉ ▉  ▉" << endl;
    cout << endl ;
    curled();
    link_parse();
    return 0;   
}
