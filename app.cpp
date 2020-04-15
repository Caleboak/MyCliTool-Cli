#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>



using namespace std;


class App{
private:
    string host;
    string input;
    string pick;
    string target;
    string TTL;

    public:
    void SetHost(string input){//pass the input as an argument and set it to host
        host=input;
    }



    void setIPV4(string input){//pass the input as an argument for IPV4 and set it to target
        target= "-4 "+input;

    }

    void setIPV6(string input){//pass the input as an argument for IPV6 and set it to target
        target= "-6 "+input;

    }

    void setTTL(string ttl){//Set the time to live.
        TTL=ttl;
        target=target+ "-i" +TTL;


    }
    void startApp(){//This starts and runs the pingapp
        cout<<"server is started"<<endl;
        cout<<"currently pinging: "<< input<<endl;
        int count=0;
        while (count<1){
            string ping="ping -t 1" +host;
            system(ping.c_str());
        }

    }

};




int main(void){//In the main i give the user the choice to input a host name, IPV4 address or IPV6 address
    string input;
    string pick;
    App tool= App();
    system("cls");
    cout<<"Enter Y or y to input a host Name or enter N or n to enter an IP Address: "<<endl;
    cin>>pick;
    if (pick=="Y" || pick=="y"){//If its a host name
    cout<<"Please Enter a ping Host\n";
    cin>>input;
    tool.SetHost(input);
    tool.startApp();
    }
    else if (pick=="N" || pick=="n")
    {

        cout<<" please input Y or y to enter an IPV4 address or enter N or n for an IPV6 address: "<<endl;
        cin>>pick;
        if(pick=="Y" || pick=="y"){//If its an IPV4 address
            cout<<"please enter an IPV4 address: "<<endl;
            cin>>input;
            tool.setIPV4(input);
        }
        else if(pick=="N" || pick=="n"){//If its an IPV6 address
            cout<<"please enter an IPV6 address: "<<endl;
            cin>>input;
            tool.setIPV6(input);
        }

    }
    tool.startApp();
        return 0;




}
