#include "functions.h"

void findMoney(fstream &file, string searchID, vector<string> storage, string &id, string &amount, string &country, string &currName)
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

    fstream MoneyList;
    MoneyList.open("Exchange.csv", ios::in);

    vector <string> row,row_comp;  

    string id, id_comp, amount, amount_comp, country, country_comp, currName, currName_comp;
    string search_id, search_id_comp;

    int sell;
    bool found_currency = false;

    cout<<"What is the currency that you want to exchange?"; cin >> search_id; cout<<endl;
    cout<<"What currency do you want?";cin >> search_id_comp; cout<<endl;
    cout<<"How much "<<search_id<<" do you have?";cin >> sell; cout<<endl;

    findMoney(MoneyList, search_id, row, id, amount, country, currName);
    findMoney(MoneyList, search_id_comp, row_comp, id_comp, amount_comp, country_comp, currName_comp);

    cout << row.size();
    // float hamn = stof(amount);
    // float bamn =  stof(amount_comp);
    // float final = (sell * bamn)/ hamn;
    // cout << id << country << endl;
    // cout << id_comp<< country_comp << endl;
    // cout << "( " << sell << " x " << bamn << ") / " << hamn << " " <<final<<endl;
    // cout<< search_id << sell << " is equal to " << search_id_comp << " " << final <<" .";

    return 0;
}
