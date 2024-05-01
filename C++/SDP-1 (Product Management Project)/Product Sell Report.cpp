#include <ctime> // time
#include <bits/stdc++.h> // Basic c++
#include <stdio.h> // Basic C
#include <windows.h> // Using for CMD command. here system("cls")
#include <conio.h> // Using for getch
/*---------------------------------------------------------------*/

using namespace std;

//Product structure
struct prod{
    int id,cnt; // id = id of the product, cnt= count of product
    char name[100]; // product name
    double rate; // rate of the product
} product;


//Sell Products
struct sell{
    char customer[100]; // customer name
    char s_prod_name[100]; // product name that seller want to sell
    int s_prod_cnt; // count of the product seller want to sell
    time_t date; // selling date
    double rate = 0; // rate of the product
}sell;

//Add New Products
class addProduct{
public:

    //Adding Products to the main list
    void add_Products(FILE *f){

        char add_again = 'y';

        while(add_again == 'y' || add_again == 'Y'){ //goes to loop while user enter y;

            system("cls"); // clear console screen

            cout<<"------------------------------------------------------------\n";
            cout<<setw(36)<<"Add Products\n";
            cout<<"------------------------------------------------------------\n\n";

            //Display Products
            rewind(f);
            int has_Product = 0;
            cout<<"------------------------------------------------------------\n";
            cout<<setw(5)<<"ID"<<setw(25)<<"Name"<<setw(7)<<"Count"<<setw(10)<<"Rate"<<setw(13)<<"Total($)\n";
            cout<<"------------------------------------------------------------\n";
            while(fread(&product, sizeof(product), 1, f)==1){
                has_Product = 1;
                cout<<setw(5)<<product.id<<setw(25)<<product.name<<setw(7)<<product.cnt<<setw(10)<<fixed<<setprecision(2)<<product.rate<<setw(13)<<fixed<<setprecision(2)<<(product.rate*product.cnt)<<"\n";
            }
            if(has_Product){
                cout<<"------------------------------------------------------------\n\n";
            }
            else{
                cout<<setw(30)<<"No Entry!\n";
                cout<<"------------------------------------------------------------\n\n";
            }

            //Search by Product id
            cout<<"ID of the product you want to add : ";
            int pid,add_isFound = 0; cin>>pid;

            //Search Product Availability
            rewind(f);
            FILE *f2;
            f2 = fopen("temp.log","a+");
            while(fread(&product, sizeof(product), 1, f)==1){
                if(pid==product.id){
                    add_isFound = 1;

                    system("cls");

                    cout<<"------------------------------------------------------------\n";
                    cout<<setw(36)<<"Add Products\n";
                    cout<<"------------------------------------------------------------\n\n";

                    cout<<"------------------------------------------------------------\n";
                    cout<<setw(5)<<"ID"<<setw(25)<<"Name"<<setw(7)<<"Count"<<setw(10)<<"Rate"<<setw(13)<<"Total($)\n";
                    cout<<"------------------------------------------------------------\n";
                    cout<<setw(5)<<product.id<<setw(25)<<product.name<<setw(7)<<product.cnt<<setw(10)<<fixed<<setprecision(2)<<product.rate<<setw(13)<<fixed<<setprecision(2)<<(product.rate*product.cnt)<<"\n";
                    cout<<"------------------------------------------------------------\n\n";

                    cout<<"Enter the following information....\n";

                    int pro_count = -1;
                    while(pro_count <= 0){
                        cout<<"Amount of the Product you want to add : ";
                        cin>>pro_count;
                        if(pro_count <= 0){
                            cout<<"Amount of product should be a positive number!\n\nRewrite the ";
                        }
                    }

                    product.cnt += pro_count;
                    product.rate = -1.00;

                    while(product.rate<=0){
                        cout<<"New rate of the product : ";
                        cin>>product.rate;
                        if(product.rate<=0){
                            cout<<"Product rate should be greater than zero!\n\nRewrite the ";
                        }
                    }

                    fwrite(&product,sizeof(product),1,f2);
                }

                else{
                    fwrite(&product,sizeof(product),1,f2);
                }
            }

            fclose(f2); //Closing temp.log File
            fclose(f);  //Closing file.log File
            remove("file.log");
            rename("temp.log","file.log");
            f = fopen("file.log","a+");

            if(add_isFound == 0){
                cout<<"\nThis Item is not Listed in the List.\nDo You want to add? (Y/N) : ";

                char list_product;
                cin>>list_product;
                if(list_product == 'Y' ||list_product == 'y'){
                    product.id = pid;
                    cout<<"\nID of the product : "<<product.id<<"\n";
                    fflush(stdin);
                    cout<<"Name of the product : ";
                    scanf("%[^\n]s",product.name);
                    product.cnt = -1;
                    while(product.cnt <= 0){
                        cout<<"Quantity of the product : ";
                        cin>>product.cnt;
                        if(product.cnt <= 0){
                            cout<<"Product Quantity should be a positive number ! \n\nRewrite the ";
                        }
                    }
                    product.rate = -1.00;
                    while(product.rate <= 0.00){
                        cout<<"Rate of the product($) : ";
                        cin>>product.rate;
                        if(product.rate <= 0.00){
                            cout<<"Rate of the product should be greater than zero!\n\nRewrite the ";
                        }
                    }
                    fwrite(&product,sizeof(product),1,f);
                }
            }

            // Add Again?
            cout<<"Do you want to add more ? (Y/N) : ";
            cin>>add_again;
        }
    }
};

//View Unsold Products
class viewUnsoldProd{
public:
    void view_Unsold_Product(FILE *f){
        rewind(f);
        int has_Product = 0;
        system("cls");

        cout<<"------------------------------------------------------------\n";
        cout<<setw(39)<<"Remaining Products\n";
        cout<<"------------------------------------------------------------\n\n";
        cout<<"------------------------------------------------------------\n";
        cout<<setw(5)<<"ID"<<setw(25)<<"Name"<<setw(7)<<"Count"<<setw(10)<<"Rate"<<setw(13)<<"Total($)\n";
        cout<<"------------------------------------------------------------\n";

        double g_total = 0;
        while(fread(&product, sizeof(product), 1, f)==1){
            has_Product = 1;
            cout<<setw(5)<<product.id<<setw(25)<<product.name<<setw(7)<<product.cnt<<setw(10)<<fixed<<setprecision(2)<<product.rate<<setw(13)<<fixed<<setprecision(2)<<(product.rate*product.cnt)<<"\n";
            g_total += product.rate*product.cnt;
        }
        if(has_Product){
        cout<<"------------------------------------------------------------\n";
        cout<<setw(50)<<"Grand Total = "<<fixed<<setprecision(2)<<g_total<<"\n\n";
        }
        else{
            cout<<setw(30)<<"No Entry!\n";
            cout<<"------------------------------------------------------------\n\n";
        }
        cout<<"Enter Any Key to return main menu....";
        getch();
    }
};

//View Sold Products
class viewSoldProd{
public:
    void view_Sold_Product(){
        FILE *view_s_p;
        view_s_p = fopen("sold.log","r");
        int has_Product = 0;
        system("cls");

        cout<<"------------------------------------------------------------------------------------------\n";
        cout<<setw(54)<<"View Sold Products\n";
        cout<<"------------------------------------------------------------------------------------------\n\n";
        cout<<"------------------------------------------------------------------------------------------\n";
        cout<<setw(10)<<"Date"<<setw(25)<<"Customer Name"<<setw(25)<<"Product Name"<<setw(7)<<"Count"<<setw(10)<<"Rate"<<setw(13)<<"Total($)\n";
        cout<<"------------------------------------------------------------------------------------------\n";

        double g_total = 0;
        while(fread(&sell, sizeof(sell), 1, view_s_p)==1){
            has_Product = 1;
            int first_line =35;
            tm *now = localtime(&sell.date);
            cout <<setw(4)<<(now->tm_year + 1900)<<setw(1)<<'-'<<setw(2)<<(now->tm_mon + 1)<<setw(1)<<'-'<<setw(2)<<(now->tm_mday)<<setw(25)<<sell.customer;
            cout<<setw(25)<<sell.s_prod_name<<setw(7)<<sell.s_prod_cnt<<setw(10)<<fixed<<setprecision(2)<<sell.rate<<setw(13)<<fixed<<setprecision(2)<<sell.s_prod_cnt*sell.rate<<"\n";

            g_total += sell.s_prod_cnt*sell.rate;
        }
        if(has_Product){
            cout<<"------------------------------------------------------------------------------------------\n";
            cout<<setw(82)<<fixed<<setprecision(2)<<"Grand Total = "<<g_total<<"\n\n";
        }
        else{
            cout<<"No Entry!\n";
        }
        fclose(view_s_p);
        cout<<"Enter Any Key to return main menu....";
        getch();
    }
};

//Selling Products

class sellProd{
public:
    void sell_Product(FILE *f){
        rewind(f);
        int has_Product = 0;
        system("cls");

        cout<<"------------------------------------------------------------\n";
        cout<<setw(36)<<"Sell Product\n";
        cout<<"------------------------------------------------------------\n\n";
        cout<<"------------------------------------------------------------\n";
        cout<<setw(5)<<"ID"<<setw(25)<<"Name"<<setw(7)<<"Count"<<setw(10)<<"Rate"<<setw(13)<<"Total($)\n";
        cout<<"------------------------------------------------------------\n";
        while(fread(&product, sizeof(product), 1, f)==1){
            has_Product = 1;
            cout<<setw(5)<<product.id<<setw(25)<<product.name<<setw(7)<<product.cnt<<setw(10)<<fixed<<setprecision(2)<<product.rate<<setw(13)<<fixed<<setprecision(2)<<(product.rate*product.cnt)<<"\n";
        }
        if(has_Product == 0){
            cout<<"No Entry!\n";
            cout<<"Enter Any Key to return main menu....";
            getch();
        }
        else{
            cout<<"------------------------------------------------------------\n\n";

            char customer_name[100] = "Default";
            char sell_more = 'Y',same_customer = 'N';
            while(sell_more == 'Y' || sell_more == 'y'){
                if(customer_name == "Default" || (same_customer != 'Y' && same_customer != 'y')){
                    cout<<"Customer Name : ";
                    fflush(stdin);
                    scanf("%[^\n]s",&customer_name);
                }

                strcpy(sell.customer,customer_name);
                int p_found = 0;
                while(p_found == 0){

                    int p_id;
                    cout<<"Product ID : ";
                    cin>>p_id;

                    FILE *TP;
                    TP = fopen("temporary.log","a");

                    rewind(f);
                    while(fread(&product, sizeof(product), 1, f)==1){
                        if(p_id == product.id){
                            strcpy(sell.s_prod_name,product.name);
                            cout<<"Product name : "<<sell.s_prod_name<<"\n";

                            int p_count = 0,pc;
                            while(p_count == 0){
                                cout<<"Amount of \""<< sell.s_prod_name << "\" you want to sell : ";
                                cin>>pc;
                                if(pc < 1 || pc > product.cnt){
                                    cout<<"You cannot sell "<<pc<<" "<<sell.s_prod_name<<"\n";
                                    cout<<"Re Enter the ";
                                }
                                else{
                                    p_count = 1;
                                }
                            }
                            sell.s_prod_cnt = pc;
                            product.cnt -= pc;
                            sell.rate = product.rate;
                            cout<<"Price : "<<sell.rate*sell.s_prod_cnt<<"\n";
                            sell.date = time(0);
                            p_found = 1;
                        }
                        fwrite(&product, sizeof(product), 1, TP);
                    }

                    fclose(TP);
                    fclose(f);
                    remove("file.log");
                    rename("temporary.log","file.log");
                    f = fopen("file.log","a+");

                    if(p_found == 0) cout<<"Wrong ID!\nRewrite ";
                    else{
                        FILE *SP;
                        SP = fopen("Sold.log","a+");
                        fwrite(&sell, sizeof(sell), 1, SP);
                        fclose(SP);
                    }
                }
                cout<<"Do You want to sell more? (Y/N) : ";
                cin>>sell_more;
                if(sell_more == 'Y' || sell_more == 'y'){
                    cout<<"Do you want to sell to the same customer (Y/N) : ";
                    cin>>same_customer;
                }
            }
        }
    }
};
class mainMenu: public addProduct,viewUnsoldProd,sellProd,viewSoldProd{
public:
    mainMenu(FILE *f){
        while(1){
            system("cls");

            //Main Menu
            cout<<"------------------------------------------------------------\n";
            cout<<setw(36)<<"Welcome Home\n";
            cout<<"------------------------------------------------------------\n";
            cout<<"[1] ---------- Add Products\n";
            cout<<"[2] ---------- Sell Products\n";
            cout<<"[3] ---------- View Sold Products\n";
            cout<<"[4] ---------- View Unsold Products\n";
            cout<<"[0] ---------- Exit Program\n";
            cout<<"------------------------------------------------------------\n\n";

            //Choosing from main menu;
            cout<<"Enter Your Choice : ";
            int main_Menu_opt;
            cin>>main_Menu_opt;

            //switch using main menu options
            switch(main_Menu_opt){
                case 1:{
                    add_Products(f);
                    break;
                }
                case 2:{
                    sell_Product(f);
                    break;
                }
                case 3:{
                    view_Sold_Product();
                    break;
                }
                case 4:{
                    view_Unsold_Product(f);
                    break;
                }
                case 0:{
                    cout<<"\n\n\n---------------------------*END*----------------------------\n\n";
                    exit(1);
                }
                default:{
                    cout<<"Wrong Option Selected!\nDouble Press Any Key to continue to Main Menu...";
                    getch();
                }
            }
        }
    }
};
int main(){
    FILE *f;
    f = fopen("file.log","a+");
    mainMenu mainMenu(f);
    fclose(f);
}

