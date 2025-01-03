#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
// product structure
struct product
{
    int id;
    string name;
    double price;

    // display product details
    void display() const
    {
        cout << "ID:" << id << "\nname:" << name << "\nprice:" << price << "\n\n";
    }
};
// function prototypes
void createProduct();
void readProduct();
void updateProduct();
void deleteProduct();
vector<product> loadProducts();
void saveProducts(const vector<product> &products);
const string filename = "products.txt";
int main()
{
    int choice;
    do
    {
        cout << "1.create product\n";
        cout << "2.read product\n";
        cout << "3.update product\n";
        cout << "4.delete poduct\n";
        cout << "exiting....\n";
        cout << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createProduct();
            break;
        case 2:
            readProduct();
            break;
        case 3:
            updateProduct();
            break;
        case 4:
            deleteProduct();
            break;
        case 5:
            cout << "exiting....\n";
            break;
        default:
            cout << "invalid choice!!try again\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
void createProduct()
{
    vector<product> products = loadProducts();
    product p;
    cout << "enter product id: ";
    cin >> p.id;
    cin.ignore();
    cout << "enter product name: ";
    getline(cin, p.name);
    cin >> p.name;
    cout << "enter product price: ";
    cin >> p.price;
    products.push_back(p);
    saveProducts(products);
    cout << "product added successfully\n";
}
// read all products
void readProducts()
{
    vector<product> products = loadProducts();
    if (products.empty())
    {
        cout << "no products found\n";
    }
    else
    {
        cout << "...products list\n";
        for (const auto &pr : products)
        {
            pr.display();
        }
    }
}
// update an existing product
void updateProduct()
{
    vector<product> products = loadProducts();
    int id;
    bool found = false;
    cout << "enter product ID to update:";
    cin >> id;

    for (auto &pr : products)
    {
        if (pr.id == id)
        {
            found = true;
            cin.ignore();
            cout << "enter the new product name:";
            getline(cin, pr.name);
            cout << "enter the new product price:";
            cin >> pr.price;
            saveProducts(products);
            cout << "product updated successfully\n";
            break;
        }
    }
    if (!found)
    {
        cout << "product with ID" << id << "not found\n";
    }
}
void deleteProduct()
{
    vector<product> products = loadProducts();
    int id;
    bool found = false;
    cout << "enter product ID to delete:";
    cin >> id;
    for (auto it = products.begin(); it !=products.end(); it++)
    {
        if (it -> id == id)
        {
            found = true;
            products.erase(it);
            saveProducts(products);
            cout << "product deleted successfully\n";
            break;
        }
    }
    if (!found){
        cout << "product with Id" << id << "not found\n";
    }
}
//load products from file
