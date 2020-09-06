#ifndef COFFEEMACHINEHELPER_H_INCLUDED
#define COFFEEMACHINEHELPER_H_INCLUDED
#include<bits/stdc++.h>

using namespace std;
class CoffeeMachine{
private:
    vector<string> menu;
    unordered_map<string,int> ingredients;
    unordered_map<string,int> reference_ingredients;
    unordered_map<string, vector<pair<string,int> > > recipe_book;

public:
    CoffeeMachine();
    void getMenu(vector<string>);
    vector<string> readMenu();
    void fillMachine(unordered_map<string,int>);
    void refillMachine(unordered_map<string,int>);
    bool isRefillNecessary();
    void setRecipe(unordered_map<string, vector<pair<string,int> > >);
    int getWaterLimit();
    int getMilkLimit();
    string createBeverage(string);
    void showInventory();
    void showOptions();
};


#endif // COFFEEMACHINEHELPER_H_INCLUDED
