#include<bits/stdc++.h>
#include "coffeemachinehelper.h"

using namespace std;

//constructor
CoffeeMachine:: CoffeeMachine(){}

void CoffeeMachine:: fillMachine(unordered_map<string,int> stock){
        ingredients = stock;
        reference_ingredients = stock;
}

//function to refill the machine when it is required
void CoffeeMachine:: refillMachine(unordered_map<string,int> stock)
{
    for(auto i : stock){
        ingredients[i.first] += i.second;
    }
    cout<<"Machine has successfully refilled."<<endl;
}

//function to check is refill necessary or not. Here we are checking if the quantity is less than 40% of initial amount.
//we have reference_ingredients to check with initial amount
bool CoffeeMachine:: isRefillNecessary()
{
    int n = ceil(ingredients.size() * 0.4);
    int cnt=0;
    for(auto i: ingredients)
    {
        if(i.second <= reference_ingredients[i.first]*0.4 ){
            cnt++;
        }
    }
    if(cnt>=n)
        return true;
    else
        return false;
}

//function to show the choices for beverages
void CoffeeMachine::getMenu(vector<string> beverages){
    menu = beverages;
    cout<<"Select your options according to your interests:"<<endl;
    for(int i=0;i<menu.size();i++)
    {
        cout<<i+1<<". "<<menu[i]<<endl;
    }
}

vector<string> CoffeeMachine:: readMenu()
{
    return menu;
}

//function to set the recipe in the machine given by the user
void CoffeeMachine:: setRecipe(unordered_map<string, vector<pair<string,int> > > recipe){
    recipe_book = recipe;
}

//function to prepare the beverage as per the recipe given by the user
string CoffeeMachine::createBeverage(string item)
{
    vector<pair<string,int> > recipeforitem = recipe_book[item];
    pair<string, int> p;
    string less_item = "";
    for(int i=0;i<recipeforitem.size();i++)
    {
        p = recipeforitem[i];
        if(ingredients[p.first] > 0 and ingredients[p.first] >= p.second){
            ingredients[p.first] = ingredients[p.first] - p.second;
        }
        else if(ingredients[p.first] > 0){
            less_item = p.first+" is not sufficient.";
            break;
        }
        else{
            less_item = p.first+" is not available.";
            break;
        }
    }

    if(less_item == "")
        return item+" is prepared.";
    else
        return item+" can not be prepared as "+less_item;
}

//function to see the current status of ingredients available in the machine
void CoffeeMachine:: showInventory()
{
    cout<<"#######################"<<endl;
    for(auto i : ingredients){
        cout<<i.first<<": "<<i.second<<endl;
    }
    cout<<"#######################"<<endl<<endl;
}

void CoffeeMachine:: showOptions()
{
    cout<<"Press 0 to enter your choices"<<endl;
    cout<<"Press # to stop the machine"<<endl;
    cout<<"Press * to see the inventory"<<endl;
}
