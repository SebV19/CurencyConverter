#include "functions.h"

int hello(){

    fstream MoneyList;
    MoneyList.open("Exchange.csv", ios::in);

    vector <string> row,row_comp;  
    string id, id_comp, amount, amount_comp, country, country_comp, currName, currName_comp;
    string search_id, search_id_comp;

    int sell, buy;
    bool found_currency = false;


    cin>> search_id >> search_id_comp;

    while (getline (MoneyList, id, ',') && !found_currency)
    {
            getline (MoneyList, amount, ',');
            getline (MoneyList, country, ',');
            getline (MoneyList, currName, '\n');

                 if(id == search_id)
                {        
                    found_currency = true;
                    row.push_back(id);
                    row.push_back(amount);
                    row.push_back(country);
                    row.push_back(currName);
                }

    }

    found_currency = false;

    while (getline (MoneyList, id_comp, ',') && !found_currency)
    {
            getline (MoneyList, amount_comp, ',');
            getline (MoneyList, country_comp, ',');
            getline (MoneyList, currName_comp, '\n');

                 if(id_comp == search_id_comp)
                {        
                    found_currency = true;
                    row_comp.push_back(id_comp);
                    row_comp.push_back(amount_comp);
                    row_comp.push_back(country_comp);
                    row_comp.push_back(currName_comp);
                }

            }

    cout<<"da";
    return 0;
}
