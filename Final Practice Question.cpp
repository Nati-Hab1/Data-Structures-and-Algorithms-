#include <iostream>
#include <string>
using namespace std;
#define TAX_RATE 0.15
int main(){

    cout<<"This program is used to analyze product sales and inventory for a specific store."<<endl;
    cout<<"C++ is a compiled language."<<endl;

    string pro_name = "Omaar";

    const double tax_rate = 0.15;
    int pro_categry;
    pro_categry = 2;

    int init_invent = 20;

    float pro_price{1100.0};
    int items_sold = 7;
    int new_invent;
    float total_sales = 0;
    auto total = total_sales;

    string invent_status;
    decltype(init_invent) helper1 = 30;

    cout<<"Please enter the product name: ";
    cin>>pro_name;
    cout<<"Please enter the product category (Integer from 1-5): ";
    cin>>pro_categry;
    cout<<"Please enter the initial inventory quantity: ";
    cin>>init_invent;
    cout<<"Please enter the product price: ";
    cin>>pro_price;
    cout<<"Please enter the number of items sold: ";
    cin>>items_sold;

    new_invent = init_invent - items_sold;
    total_sales = items_sold * pro_price;

    (new_invent < 10) ? invent_status = "Low inventory" : invent_status = "Sufficient Inventory";

    cout<<endl;
    cout<<endl;

    for(int i = 1; i < items_sold + 1 ; i++){
        cout<<"$"<<pro_price<<endl;
    }

    cout<<endl;

    cout<<"Product name: "<<pro_name<<endl;
    
    if (pro_categry <= 5 && pro_categry >= 1){

        switch(pro_categry){
            case 1:
            cout<<"Category 1: Electronics"<<endl;
            break;
            case 2:
            cout<<"Category 2: Groceries"<<endl;
            break;
            case 3:
            cout<<"Category 3: Clothing"<<endl;
            break;
            case 4:
            cout<<"Category 4: Stationery"<<endl;
            break;
            case 5:
            cout<<"Category 5: Miscellaneous"<<endl;
            break;
        }
    }

    else{
        cout<<"The product category is not in the valid range."<<endl;
    }

    cout<<"Initital inventory quantity: "<<init_invent<<endl;
    cout<<"Product price: "<<pro_price<<endl;
    cout<<"Number of items sold: "<<items_sold<<endl;
    cout<<"Computed new inventory: "<<new_invent<<endl;
    cout<<"Total sales amount: "<<total_sales<<endl;
    cout<<"Inventory status: "<<invent_status<<endl;
    cout<<"The first helper variable(auto): "<<total<<endl;
    cout<<"The second helper vairable(decltype): "<<helper1<<endl;

    cout<<endl;

    return 0;

}

//Check the auto part, Why does it print out the memory location instead of copying and displaying
//the exact value of total sales to the new variable total?