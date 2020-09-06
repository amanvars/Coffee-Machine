/*************************************************************************
   ** Project: Coffee Machine
**************************************************************************
   ** $Author: Aman Varshney
**************************************************************************/

#include <bits/stdc++.h>
#include <windows.h>
#include <coffeemachinehelper.h>
using namespace std;

class Test{
    /***
    This is test class for creating testcase. It is having three functions.
    1. to enter all beverages available in machine
    2. to enter the stock in the machine
    3. to enter recipe for each beverage

    When we initiate the test case, machine will start freshly with new data;
    ***/
private:
    int outlets;
    vector<string> beverages ;
    unordered_map<string,int> stock;
    unordered_map<string, vector<pair<string,int> > >  recipe;

public:
    CoffeeMachine coffee_machine;

    Test()
    {
        coffee_machine.fillMachine(getStock());
        coffee_machine.getMenu(getBeverages());
        coffee_machine.setRecipe(getRecipe());

    }

    void setOutlet(int n)
    {
        outlets = n;
    }

    int getOutlet()
    {
        return outlets;
    }

    vector<string> getBeverages()
    {
        beverages  = {"Cappuccino", "Espresso", "Ginger Tea", "Elaichi Tea", "Hot Milk", "Hot Water"};
        return beverages;
    }

    unordered_map<string,int> getStock()
    {
        stock["water"] = 150;
        stock["milk"] = 150;
        stock["coffee"] = 50;
        stock["green_tea_syrup"] = 50;
        stock["elachi_tea_syrup"] = 40;
        stock["sugar"] = 100;
        stock["ginger_syrup"] = 50;
        return stock;
    }

    unordered_map<string, vector<pair<string,int> > > getRecipe()
    {
        recipe["Cappuccino"] = { {"coffee",20}, {"milk",40}, {"sugar", 10}, {"water",20} };
        recipe["Espresso"] = { {"coffee",20}, {"water",50} };
        recipe["Ginger Tea"] = { {"ginger_syrup",10}, {"milk",50}, {"sugar",20}, {"water",30} };
        recipe["Elaichi Tea"] = { {"elachi_tea_syrup",10}, {"milk",50}, {"sugar", 20}, {"water",30} };
        recipe["Hot Milk"] = { {"milk",50} };
        recipe["Hot Water"] = { {"water",50} };
        return recipe;
    }

    void test1()
    {
        cout<<"Executing test case 1"<<endl;
        setOutlet(4);
        int outlet = getOutlet();
//        CoffeeMachine coffee_machine;
       //coffee_machine.getMenu(beverages);
        vector<int> choices = {2,4,1,3,5};
        if(outlet<choices.size())
        {
            cout<<"You have requested "<< choices.size()<< " beverages which is more than "<< outlet<< " outlets"<<endl;
            cout<<"------------------------------------------------"<<endl<<endl;

            return;
        }
        cout<<"Please wait while we are preparing for you..."<<endl;
        Sleep(2000);
        vector<string> menu = getBeverages();
        for(int i=0;i<choices.size();i++)
        {
            string result = coffee_machine.createBeverage(menu[choices[i]-1]);
            cout<<result<<endl;
        }
        cout<<"------------------------------------------------"<<endl<<endl;

    }
    void test2()
    {
        cout<<"Executing test case 2"<<endl;
        setOutlet(5);
        int outlet = getOutlet();
        vector<int> choices = {1,4,1,3};
        cout<<"Please wait while we are preparing for you..."<<endl;
        Sleep(2000);
        vector<string> menu = getBeverages();
        for(int i=0;i<choices.size();i++)
        {
            string result = coffee_machine.createBeverage(menu[choices[i]-1]);
            cout<<result<<endl;
        }
        cout<<"------------------------------------------------"<<endl<<endl;

    }

    void test3()
    {
        cout<<"Executing test case 3"<<endl;
        setOutlet(5);
        int outlet = getOutlet();
        vector<int> choices = {6,5,4,1,3};
        cout<<"Please wait while we are preparing for you..."<<endl;
        Sleep(2000);
        vector<string> menu = getBeverages();
        for(int i=0;i<choices.size();i++)
        {
            string result = coffee_machine.createBeverage(menu[choices[i]-1]);
            cout<<result<<endl;
        }

        cout<<"------------------------------------------------"<<endl<<endl;
    }

    void test4()
    {
        cout<<"Executing test case 4"<<endl;
        cout<<"Showing Inventory status"<<endl;
        Sleep(2000);
        coffee_machine.showInventory();
        cout<<"------------------------------------------------"<<endl<<endl;
    }

    void test5()
    {
        cout<<"Executing test case 5"<<endl;
        cout<<"Checking refill is necessary or not"<<endl;
        Sleep(2000);
        if(coffee_machine.isRefillNecessary()){
            cout<<"----****It seems you need refill of machine.****----"<<endl;
            Sleep(1000);
            cout<<"Refilling the machine."<<endl;
            Sleep(1000);
            coffee_machine.refillMachine(stock);
            coffee_machine.showInventory();
        }
        cout<<"------------------------------------------------"<<endl<<endl;
    }




};


int main()
{

    cout << "Welcome To your favorite Dunzo Coffee Machine." << endl;
     /*** TEST CASE ***/
    Test testcase;
    testcase.test1();
    testcase.test2();
    testcase.test3();
    testcase.test4();
    testcase.test5();

    /***/

    /***
    User choice input, it should be used when we don't want to run the test case automatically
    Above test case should be commented to use below code.
    ***/
//    int num_of_outlets;
//    CoffeeMachine coffee_machine;
//    Test testcase;
//    cout << "Welcome To your favorite Dunzo Coffee Machine." << endl;

//    cout << "Let me know how many outlets you want in machine:";
//    cin>>num_of_outlets;

//    coffee_machine.fillMachine(testcase.getStock());
//    coffee_machine.getMenu(testcase.getBeverages());
//    coffee_machine.setRecipe(testcase.getRecipe());
//    coffee_machine.showOptions();

//    cout<<endl;

//    bool stop_machine = false;
//    while(!stop_machine){
//        char task;
//        cin>>task;
//        switch(task){
//        case '0':{
//            vector<int> choices;
//            vector<string> menu = coffee_machine.readMenu();
//            cout<<"Kindly enter -1 to stop selection if you want less than "<<num_of_outlets<<" beverages"<<endl;
//            cout<<"Enter all your choices at a time upto "<<num_of_outlets<<" times"<<endl;
//            int ch=0;
//            int temp = num_of_outlets;
//            while(ch !=-1 and temp>0)
//            {
//                cin>>ch;
//                temp--;
//                if(ch > menu.size()){
//                    break;
//                }
//                if(ch!=-1 && temp>=0)
//                    choices.push_back(ch);
//                else
//                    break;
//            }
//
//            cout<<"Please wait while we are preparing for you..."<<endl;
//            Sleep(2000);
//
//            for(int i=0;i<choices.size();i++)
//            {
//                string result = coffee_machine.createBeverage(menu[choices[i]-1]);
//                cout<<result<<endl;
//            }
//            cout<<endl;
//            if(coffee_machine.isRefillNecessary())
//                cout<<"----****It seems you need refill of machine. Press + to refill it.****----"<<endl;
//            coffee_machine.showOptions();
//            break;
//        }
//        case '*':{
//            coffee_machine.showInventory();
//            coffee_machine.showOptions();
//            break;
//        }
//        case '+':{
//            coffee_machine.refillMachine(testcase.getStock());
//            coffee_machine.showOptions();
//            break;
//        }
//        case '#':{
//            stop_machine = true;
//            break;
//        }
//        default:
//            cout<<"Oops! Try Again..."<<endl;
//
//        }
//
//    }

/*** uncomment above code to use it as per choice ***/
    cout<<"***************************************"<<endl;
    cout<<"*Thanks for using our Coffee Machine!!*"<<endl;
    cout<<"***************************************"<<endl;

    return 0;
}
