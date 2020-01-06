#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Item
{
    int price;
    string status, name;
};

int main()
{
    const int MAX_SIZE=100;
    Item iArr[MAX_SIZE];
    int arrCount=0;
    string filename, line, word, name, status, price;
    //cout<<"Enter filename: ";
    //cin>>filename;
    ifstream inFile("garageSale.txt");
    if(!inFile.is_open())
    {
        cout<<"Error reading file..."<<endl;
        return -1;
    }else
    {
        int i=0;
        while(getline(inFile, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, status, ',');
            for(int k=0; k<status.length(); k++)
            {
                if(status[k]=='f') //for sale will be 0.
                    status="0";
                else if(status[k]=='w' && status[k+2]=='n') //wanted will be 1.
                    status="1";
            }
            getline(ss, price);

            for(int j=0; j<MAX_SIZE; j++)
            {
                if(iArr[0].name=="")//if array is empty
                {
                    iArr[0].name=name;
                    iArr[0].status=status;
                    iArr[0].price=stoi(price);
                    j++;
                    arrCount++;
                }else if((iArr[j].name.compare(name)==0) && (iArr[j].status.compare(status)==1))
                {
                    if((status=="0") && (iArr[j].price > stoi(price)))
                    {
                        iArr[i].name=name;
                        iArr[i].status=status;
                        iArr[i].price=stoi(price);
                        i++;
                        arrCount++;
                    }
                }
            }
            // iArr[i].name=name;
            // iArr[i].status=status;
            // iArr[i].price=stoi(price);
            // i++;
            // arrCount++;
        }
        for(int n=0; n<MAX_SIZE; n++)
            cout<<iArr[n].name<<" "<<iArr[n].status<<" "<<iArr[n].price<<endl;
    }
    return 0;
}
