#pragma once
#include "AccountData.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class DataManager {
    public:
        DataManager();
        void save();
        void load();
        void incrementLayer();
        void appendData(AccountData data) {
            accountData[layerIndex - 1][data.getDate()].push_back(data);
        }
        vector<map<string, vector<AccountData>>> get() {
            return accountData;
        }

    private:
        string filename = "AccountBook.data";
        int layerIndex;
        vector<map<string, vector<AccountData>>> accountData;
};
