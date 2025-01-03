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
    void display()
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
        case 2:
            readProduct();
        case 3:
            updateProduct();
        case 4:
            deleteProduct();
        case 5:
            cout << "exiting....\n";
        default:
            cout << "invalid choice!!try again\n";
        }
    } while (choice != 5);
    return 0;
}
void createProduct()
{
    vector<product> products = loadProducts();
    product p;
    cout << "enter product id:";
    cin >> p.id;
    cin.ignore();
    cout << "enter the product name:";
    cin >> p.name;
    cout << "enter the product price:";
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
        for (const auto &p : products)
        {
            p.display();
        }
    }
}
