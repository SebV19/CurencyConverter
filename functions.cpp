#include "functions.h"

int hello(){

    fstream MoneyList("Exchange.csv", ios_base::app);
    MoneyList.open("Exchange.csv", ios::in);

    vector <string> row,row_comp;  
    string id, id_comp, amount, amount_comp, country, country_comp, currName, currName_comp;
    string search_id, search_id_comp;

    int sell , buy;
    bool found_currency = false;

    cin>> search_id >> search_id_comp;

    while (getline (MoneyList, id, ',') && !found_currency)
    {
            getline (MoneyList, amount, ',');
            getline (MoneyList, country, ',');
            getline (MoneyList, country, '\n');

                 if(id == search_id)
                {        
                    found_currency = true;
                    row.push_back(id);
                    row.push_back(amount);
                    row.push_back(country);
                    row.push_back(currName);
                }

            }

    while (getline (MoneyList, id_comp, ',') && !found_currency)
    {
            getline (MoneyList, amount_comp, ',');
            getline (MoneyList, country_comp, ',');
            getline (MoneyList, country_comp, '\n');

                 if(id_comp == search_id_comp)
                {        
                    found_currency = true;
                    row_comp.push_back(id_comp);
                    row_comp.push_back(amount_comp);
                    row_comp.push_back(country_comp);
                    row_comp.push_back(currName_comp);
                }

            }

    //search id = row[0]

    cout << row[0] << row[1];
    cout << row_comp[0] << row_comp[1]; 

}
