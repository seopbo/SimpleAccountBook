#include "DataManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

DataManager::DataManager() {
    layerIndex = 0;
    this->incrementLayer();
}

void DataManager::incrementLayer() {
    layerIndex++;
    accountData.push_back(map<string, vector<AccountData>>{});
}

void DataManager::save() {
    ofstream outFile(filename);
    string line;
    if (outFile.is_open()) {
        //뭔갈 저장하고
        /*
        INCOME type  : date, type, amount
        OUTCOME type : date, type, name, category, amount
        */
        for(int i = 0; i < layerIndex; i++) {
            for (auto data_set : accountData[i]) {
                for (auto data : data_set.second) {
                    line = "";
                    line += data.getDate();
                    line += "," + to_string((int)data.getType());
                    if (data.getType() == DATA_TYPE::OUTCOME)
                    {
                        line += "," + data.getName();
                        line += "," + data.getCategory();
                    }
                    line += "," + to_string(data.getAmount());
                    outFile << line << endl;
                }
            }
        }
        outFile.close();
    } else {
        cout << filename << " can't be opened" << endl;
    }
}

void DataManager::load() {
    ifstream inFile(filename);
    string line;

    if (inFile.is_open()) {
        //뭔가 불러오고
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            vector<string> strVector;
            // date, type, name, category, amount
            while (getline(ss, token, ',')) {
                strVector.push_back(token);
            }
            stringstream type(strVector[1]);
            int itype;
            type >> itype;

            if (itype == (int)DATA_TYPE::INCOME) {
                stringstream amount(strVector[2]);
                int iamount;
                amount >> iamount;
                AccountData data(
                    strVector[0],
                    (DATA_TYPE)itype,
                    iamount);
                accountData[0][strVector[0]].push_back(data);
            } else if (itype == (int)DATA_TYPE::OUTCOME) {
                stringstream amount(strVector[4]);
                int iamount;
                amount >> iamount;
                AccountData data(
                    strVector[0],
                    (DATA_TYPE)itype,
                    iamount,
                    strVector[2],
                    strVector[3]);
                accountData[0][strVector[0]].push_back(data);
            }
        }
        inFile.close();
    } else {
        cout << filename << " can't be opened" << endl;
    }
}