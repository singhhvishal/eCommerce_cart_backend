#include<iostream>
#include "datamodel.h"
#include <vector>
using namespace std;


vector<Product> allProducts = {
    Product(1, "apple",26),
    Product(3,"mango",16),
    Product(2,"guava",34),
    Product(7,"banaba",54),
    Product(7,"pineapple",20),
};

Product* chooseProduct() {
    //display the list of products
    vector<string> productlist;
    cout << "Available Products " << endl;

    for (auto product : allProducts) {
        productlist.push_back(product.getDisplayName()) ;
    }
    for (auto i : productlist) {
        cout << i << endl;
    }

    cout << "---------------------------" << endl;
    string choice;
    cin>> choice;

    for (int i=0; i<allProducts.size(); i++){
        if (allProducts[i].getShortName()==choice) {
            return &allProducts[i];
        }
    }
    cout << "Product not found!" << endl;
    return NULL;
}

bool checkout(Cart &cart) {
    if(cart.isEmpty()) {
        return false;
    }

    int total = cart.getTotal();
    cout << "Pay in Cash : ";

    int paid;
    cin>> paid;
    if (paid>=total) {
        cout << "Change " << paid - total << endl;
        cout << "Thank you for shopping!";
        return true;
    }
    else {
        cout << "Not enough cash!";
        return false;
    }
}

int main() {
    
    char action;
    Cart cart;
    while(true) {
        cout << "Select an action - (a)add item, (v)view cart, (c)checkout" << endl;
        cin>> action;

            if (action=='a') {
                //add to cart 
                // view all products + add to the cart
                Product * product =  chooseProduct();
                if (product!= NULL) {
                    cout << "Added to the Cart " << product->getDisplayName() << endl;
                    // adding in the cart
                    cart.addProduct(*product);
                }
            }
            else if(action=='v') {
                    cout <<"--------------"<<endl;
                    cout << cart.viewCart();
                    cout <<"--------------"<<endl;
                }
            else if (action=='c'){
                //checkout
                    cart.viewCart();
                    if (checkout(cart)){
                        break;
                    }
            }

    }

    return 0;
}