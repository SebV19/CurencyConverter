#include "functions.h"

void display_vector(const vector<string> &v)
{
    for (auto i = v.begin();
         i != v.end(); ++i)
        cout << ',' << *i;
}

void readFile(ifstream &file, string &firstcountry, string &secondcountry, int &money)
{

    file.open("in.txt");

    if(file.is_open())
    {
        file >> firstcountry >> secondcountry >> money;
    }
    
    else
    {
        cout << "ERROR! FILE NOT FOUND!";
    }

}

void findMoney(fstream &file, string searchID, vector<string> &storage, string &id, string &amount, string &country, string &currName)
{
    
    file.open("Exchange.csv", ios::in);
 
    bool found_currency = false;

    while (getline (file, id, ',') && !found_currency)
    {
        getline (file, amount, ',');
        getline (file, country, ',');
        getline (file, country, '\n');

            if(id == searchID)
            {        
                found_currency = true;
                storage.push_back(id);
                storage.push_back(amount);
                storage.push_back(country);
                storage.push_back(currName);
            }
 
    }
    file.close();
    found_currency = false;
}


int hello()
{
    ofstream output("out.txt");
    ifstream input("in.txt");
    fstream MoneyList;

    vector <string> row,row_comp;  

    string id, id_comp, amount, amount_comp, country, country_comp, currName, currName_comp;
    string search_id, search_id_comp;

    int sell;
    bool found_currency = false;

    input.close();

    readFile(input, search_id, search_id_comp, sell);

    findMoney(MoneyList, search_id, row, id, amount, country, currName);
    findMoney(MoneyList, search_id_comp, row_comp, id_comp, amount_comp, country_comp, currName_comp);
 

    float hamn = stof(amount);
    float bamn =  stof(amount_comp);
    float final = (sell * bamn)/ hamn;


    output << final;
    output.close();

    return 0;
}
