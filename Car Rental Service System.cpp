#include <iostream> 
#include <string> 
#include <Windows.h> 
#include<stdio.h> 
#include<conio.h> 
#include<dos.h> 
#include <ctime> 
#include<cstdlib> 
#include <chrono> 
#include <thread> 
#include <time.h> 
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
using namespace std; 
 
class vehicle { 
private: 
    string name; 
    int seats, model, id; bool check; 
public: 
    vehicle() {} 
    vehicle(string name, int seats, int model, int id) 
    { 
        this->name = name; 
        this->seats = seats; 
        this->model = model; 
        this->id = id; 
        check = true; 
    } 
    void list() 
    { 
        cout << "\t" << id << "\t" << name << "\t" << model << "\t" << seats << endl; 
    } 
    int get_id() { return id; } 
    bool confirm() { return check; } 
    void set_book() { check = false; } 
}; 
class vendor { 
private: 
    string v_name, contact; int age, change; 
    double amount = 0; 
public: 
    vendor() {} 
    static int m, vendor_c; 
    static int count; 
    vehicle object[20]; 
    int num; string name; int seats, model, cars; 
    vendor(string n, int a, string c, int z) 
    { 
        vendor_c++; 
        v_name = n; 
        age = a; 
        contact = c; 
        change = z; 
        m = z; 
        cout << "How many cars you want to give?\t"; 
        cin >> cars; 
 
        for (int i = 0; i < cars; i++) 
        { 
            cout << "Enter car " << i + 1 << " name\t"; 
            cin >> name; 
            cout << "Enter car " << i + 1 << " model\t"; 
            cin >> model; 
            cout << "How many seats in " << name << " ?\t"; 
            cin >> seats; 
            m = m * 10; 
            vehicle o(name, seats, model, m); 
            object[i] = o; 
            count++; 
        } 
    } 
    void display(vendor obj[]) 
    { 
        cout << "\t\tCAR LIST\n\n\tID\tNAME\tMODEL\tSEATS\n"; 
        for (int i = 0; i < vendor_c; i++) 
        { 
            for (int j = 0; j < obj[i].cars; j++) 
            { 
                if (object[j].confirm() == true) 
                    obj[i].object[j].list(); 
            } 
        } 
    } 
    void vendor_details(vendor obj[]) 
    { 
        cout << "\t\tVENDOR ID's And Name\n\tID\tName\n"; 
        for (int i = 0; i < vendor_c; i++) 
        { 
            cout << "\t" << obj[i].change << "\t" << obj[i].get_vname() << endl; 
        } 
        cout << "\tEnter id or name of vendor to see detail info of vendor\t"; 
        string find, temp; 
        cin >> find; 
        SetConsoleTextAttribute(color, 6); 
        for (int i = 0; i < vendor_c; i++) 
        { 
            temp = to_string(obj[i].change); 
            if (obj[i].get_vname() == find || temp == find) 
            { 
                cout << "\t\tName: " << obj[i].v_name << endl; 
                cout << "\t\tVendor id: " << obj[i].change << endl; 
                cout << "\t\tContact: " << obj[i].contact << endl; 
                cout << "\t\tAge: " << obj[i].age << endl; 
                cout << "\t\tTotal cars: " << obj[i].cars << endl; 
                cout << "\t\tCARS DETAILS\n"; 
                for (int j = 0; j < obj[i].cars; j++) 
                { 
                    obj[i].object[j].list(); 
                } 
                break; 
            } 
        } 
    } 
    void book_cars(vendor obj[], int choose, double blnce) 
    { 
        for (int i = 0; i < vendor_c; i++) 
        { 
            for (int j = 0; j < obj[i].cars; j++) 
            { 
                if (obj[i].object[j].get_id() == choose) 
                { 
                    obj[i].amount += blnce; 
                    object[j].set_book(); 
                } 
            } 
        } 
    } 
    string get_vname() { return v_name; } 
    double get_amount() { return amount; } 
    int get_cars() { return cars; } 
}; 
int vendor::m = 1; 
int vendor::count = 0; 
int vendor::vendor_c = 0; 
class customer { 
private: 
    string name, contact, address; int age, id; double money; 
public: 
    static int customer_c; 
    customer() {} 
    customer(int id, string name, string contact, string address, int age, double money) 
    { 
        customer_c++; 
        this->id = id; 
        this->name = name; 
        this->contact = contact; 
        this->address = address; 
        this->age = age; 
        this->money = money; 
    } 
    void display(customer obj[]) { 
        cout << "\t\tCUSTOMER DETAILS\n"; 
        cout << "\t\t\tID\\t\tNAME" << endl; 
        for (int i = 0; i < customer_c; i++) 
        { 
            cout << "\t\t" << obj[i].id << "\t\t" << obj[i].name << endl; 
        } 
        cout << "\tEnter name OR id of Customer to see detail:\t\n"; 
        string ch, temp; cin >> ch; 
        for (int i = 0; i << customer_c; i++) 
        { 
            temp = to_string(obj[i].id); 
            if (ch == temp || ch == obj[i].name) 
            { 
                cout << "\tName:\t" << obj[i].name << endl; 
                cout << "\tContact:\t" << obj[i].contact << endl; 
                cout << "\tAddres:\t" << obj[i].address << endl; 
                cout << "\tAge:\t" << obj[i].age << endl; 
                cout << "\tamount:\t" << obj[i].money << endl; 
            } 
        } 
    } 
    string get_name() { 
        return name; 
    } 
    double get_money() { return money; } 
}; 
int customer::customer_c = 0; 
class admin { 
private: 
    string password; 
    static double company_total_amount; static int total_customers, total_vendors; 
public: 
    admin(string p) { 
        password = p; 
    } 
    bool check(string p) 
    { 
        if (p == password) { 
            return true; 
        } 
    } 
    void operator ++(int) { 
        total_customers++; 
    } 
    void operator ++() { 
        ++total_vendors; 
    } 
    void amount(double final) { 
        company_total_amount += final; 
    } 
    void display() { 
        string p; 
        cout << "\tEnter ADMIN password to see company details:\t"; 
        cin >> p; 
        if (password == p) { 
            cout << "\tTotal Vendors: " << total_vendors << endl; 
            cout << "\tTotal Customers: " << total_customers << endl; 
            cout << "\tTotal Balance of company: " << company_total_amount << endl; 
        } 
    } 
    void customer_details(customer obj[]) { 
        string p; 
        cout << "\tEnter ADMIN password to see company's alll customers:\t"; 
        cin >> p; 
        if (password == p) { 
            cout << "\t\tNAME\tBALANCE\n"; 
            for (int i = 0; i < total_customers; i++) { 
                cout << "\t\t" << obj[i].get_name() << "\t" << obj[i].get_money() << endl; 
            } 
        } 
    } 
    void vendor_details(vendor obj[]) { 
        string p; 
        cout << "\tEnter ADMIN password to see company's vendors:\t"; 
        cin >> p; 
        if (password == p) { 
            cout << "\t\tNAME\tCARS\tBALANCE\n"; 
            for (int i = 0; i < total_vendors; i++) { 
                cout << "\t\t" << obj[i].get_vname() << "\t" << obj[i].get_cars() << "\t" << obj[i].get_amount() 
<< endl; 
            } 
} 
} 
}; 
double admin::company_total_amount = 0; 
int admin::total_customers = 0; 
int admin::total_vendors = 0; 
string bidding(double* amount) 
{ 
SetConsoleTextAttribute(color, 15); 
cout << "How many members are there for bidding?\t"; 
string names[20], temp_name, n; int members; 
cin >> members; 
cout << "\tTAKING NAMES OF ALL MEMBERS\n"; 
for (int i = 0; i < members; i++) 
{ 
} 
cout << "Enter your name (" << (members - (i + 1)) << " mebers left\t"; 
cin >> names[i]; 
//cout << "\t\tBIDDING WILL BE STARTING AFTER 5 SECONDS\n"; 
time_t t = time(0); 
#pragma warning(suppress : 4996) 
tm* tmp = localtime(&t); 
cout << tmp->tm_hour << ":" << tmp->tm_min << ":" << tmp->tm_sec; 
cout << endl << endl; 
int num, sec1, temp = 0, c = 0; 
int sec = tmp->tm_sec; 
temp = sec; 
int temp1, x; 
cout << "Bidding will be started after 5 second\n"; 
    cout.flush(); 
    this_thread::sleep_for(chrono::seconds(5)); 
    cout << "Bidding started\n"; 
    double max = 0, cal; int j = 0; 
    while (1) 
    { 
        time_t t = time(0); 
#pragma warning(suppress : 4996) 
        tm* tmp = localtime(&t); 
        sec1 = tmp->tm_sec; 
 
        temp1 = sec1 - temp; 
        temp = sec1; 
        if (temp1 < 0) 
        { 
            c = c + sec1; 
            // cout<<"\t"<<c<<endl; 
        } 
        else 
        { 
            c = c + temp1; 
            //cout<<"\t"<<c<<endl; 
        } 
        if (c >= 10) 
        { 
            //cout<<"\t"<<c<<endl; 
            break; 
        } 
        else 
        { 
            n = names[j]; 
            cout << "\tEnter amount:\t"; 
            cin >> cal; 
        } 
        if (cal > max) 
        { 
            max = cal; 
            x = j; 
            temp_name = names[j]; 
            //cout << "\t\t\t" << temp_name << endl; 
        } 
        j++; 
        if (j > (members - 1)) { 
            //cout << "\t\tj= " << j << endl; 
            j = 0; 
        } 
    } 
    *amount = max; 
    //cout << amount<<endl; 
    //temp_name = names[x - 1]; 
   // cout << "\t" << temp_name << endl; 
    return temp_name; 
} 
double deduct(double* a) 
{ 
    double percent, temp = *a; 
    percent = temp * 0.3; 
    *a = temp - percent; 
    return percent; 
} 
int main() 
{ 
    /*cout << "hello";*/ 
    string v_name, contact, p; int age, choose, i = 1, j = 0, select; string c_contact, c_address; 
    int c_age, k = 0; 
    vendor obj[10]; customer c_obj[20]; 
    string ch = "yes"; 
    cout << "\tSet password for Admin:\t"; 
    cin >> p; 
    admin adm(p); 
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
    while (ch == "yes") 
    { 
        cout << "\t\tPress the number opposite to the service you want to use.\n"; 
 
 
        SetConsoleTextAttribute(color, 10); 
 
        cout << "\tService\t\tNumber\n\n"; 
        cout << "\tVendor\t\t1\n\tCustomer\t2\n\tVendor_detail\t3\n\tAll 
Vendors\t4\n\tCustomer_Detail\t5\n\tALL Customers\t6\n\tCompany Detail\t7\n\tExit\t\t8" << endl; 
        cin >> select; 
        //system("Color 07"); 
        SetConsoleTextAttribute(color, 15); 
        if (select == 1) { 
            ++adm; 
            cout << "Enter your name:\t"; 
            cin >> v_name; 
            cout << "Enter your contact:\t"; 
            cin >> contact; 
            do { 
                cout << "Enter you age:\t"; 
                cin >> age; 
                if (age < 18) 
                    cout << "You are under age.\n"; 
            } while (age < 18); 
 
            vendor ob(v_name, age, contact, i); 
            obj[j] = ob; 
            j++; 
            i++; 
        } 
        else if (select == 2) 
        { 
            adm++; 
            SetConsoleTextAttribute(color, 4); 
            obj->display(obj); 
            SetConsoleTextAttribute(color, 15); 
            cout << "Enter id of car you want to bid on.\t"; 
            cin >> choose; 
            SetConsoleTextAttribute(color, 5); 
            double amount = 0; 
            //double* ptr = &amount; 
            string n = bidding(&amount); string c_name = n; 
            cout << "\t\t~~~ " << n << " WON THE BID ~~~" << endl; 
            cout << "\tEnter your contact " << n << " :\t"; 
            cin >> c_contact; 
            cout << "\tEnter your age " << n << " :\t"; 
            cin >> c_age; 
            cout << "\tEnter your address " << n << " :\t"; 
            cin >> c_address; 
            double c_amount = amount; 
            double final = deduct(&amount); 
            obj->book_cars(obj, choose, amount); 
            customer temp_c(choose, c_name, c_contact, c_address, c_age, c_amount); 
            c_obj[k] = temp_c; 
            k++; 
            adm.amount(final); 
        } 
        else if (select == 3) 
        { 
            obj->vendor_details(obj); 
        } 
        else if (select == 4) { 
            adm.vendor_details(obj); 
        } 
        else if (select == 5) 
            c_obj->display(c_obj); 
        else if (select == 6) 
            adm.customer_details(c_obj); 
        else if (select == 7) 
            adm.display(); 
        else if (select == 8) 
            break; 
    } 
}