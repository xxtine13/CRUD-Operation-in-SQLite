/*---INFORMATION MANAGEMENT FINAL CASE STUDY---
 MEMBERS: Dalumpines, Sophia
          Delos Reyes, Christine
          Esguerra, Ronan
          Flor, Lea
SECTION: BSCS-2AB-M - (STEM)
---CRUD Operations using SQL Database with the help of C++ Language*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <iomanip>

using namespace std;

//GLOBAL VARIABLES
void createTable();
int menu();
void create();
void read();
void update();
void del();
void deleteTable();

int result, accNum, contactNum;
string query, date, payto, accName, payorsName, address, hold;


sqlite3* db;
sqlite3_stmt* stmt;


int main() {
    int option, cute;
    createTable();
    system("COLOR 04");
    while (1) {
        system("cls");
        option = menu();
        switch (option) {
        case 1:
            system("cls");
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            deleteTable();
            break;
        case 6:
            cout << "\n\t\t\t\t\t\t  ====================================================================";
            cout << "\n\t\t\t\t\t\t    T H A N K   Y O U   F O R   U S I N G   T H I S   P R O G R A M!";
            cout << "\n\t\t\t\t\t\t  ====================================================================\n";
            system("pause");
            exit(0);
        default:
            cout << "\n\t\t\t\t\t\t\tPlease select from 1-6...";
        }
    }

    sqlite3_close(db);
    return 0;
}

void createTable() {

    if (sqlite3_open("billpayment.db", &db) == SQLITE_OK) {
        result = sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS billpayment (date DATE NOT NULL, payto TEXT(50) NOT NULL, accName TEXT(50) NOT NULL, accNum INT NOT NULL, payorsName TEXT(50), address TEXT(50), contactNum INT(11));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if (result != SQLITE_OK) {
            cout << "Error:" << sqlite3_errmsg(db) << "\n";

        }
        else {
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tTable created successfully.\n";

        }
    }
}

int menu() {
    int choice;
    system("COLOR C0");
    cout << "\n\t\t\t\t\t\t\t ___________________________________________________";
    cout << "\n\t\t\t\t\t                                                                       ";
    cout << "\n\t\t\t\t\t                    M-L H U I L L I E R    P A W N S H O P    B I L L            ";
    cout << "\n\t\t\t\t\t                               P A Y M E N T    F O R M                         ";
    cout << "\n\t\t\t\t\t\t\t ___________________________________________________";
    cout << "\n\t\t\t\t\t\t\t\t |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|";
    cout << "\n\t\t\t\t\t\t\t\t |         M A I N   M E N U:        |\n";
    cout << "\t\t\t\t\t\t\t\t |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|";
    cout << "\n\t\t\t\t\t\t\t\t |1.] Create                         |";
    cout << "\n\t\t\t\t\t\t\t\t |2.] Read                           |";
    cout << "\n\t\t\t\t\t\t\t\t |3.] Update                         |";
    cout << "\n\t\t\t\t\t\t\t\t |4.] Delete Data                    |";
    cout << "\n\t\t\t\t\t\t\t\t |5.] Delete Table                   |";
    cout << "\n\t\t\t\t\t\t\t\t |6.] Exit                           |";
    cout << "\n\t\t\t\t\t\t\t\t |___________________________________|";
    cout << "\n\t\t\t\t\t\t\t  --Enter your choice: ";
    cin >> choice;

    return(choice);
}

void create() {
    cout << "\n\n\n\t\t\t\t\t\t\t\t |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|";
    cout << "\n\t\t\t\t\t\t\t\t |      C R E A T E    D A T A:      |\n";
    cout << "\t\t\t\t\t\t\t\t |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|";
    cout << "\n\n\t\t\t\t\t\t\t\t  Date (MM/DD/YYYY): ";
    getline(cin >> ws, date);

    cout << "\n\t\t\t\t\t\t\t\t  Payment to: ";
    getline(cin >> ws, payto);

    cout << "\n\t\t\t\t\t\t\t\t  Account Name: ";
    getline(cin >> ws, accName);

    cout << "\n\t\t\t\t\t\t\t\t  Account Number: ";
    cin >> accNum;

    cout << "\n\t\t\t\t\t\t\t\t  Payor's Name: ";
    getline(cin >> ws, payorsName);

    cout << "\n\t\t\t\t\t\t\t\t  Address: ";
    getline(cin >> ws, address);

    cout << "\n\t\t\t\t\t\t\t\t  Contact Number(+639 ---): ";
    cin >> contactNum;

    query = "INSERT INTO billpayment(date, payto, accName, accNum, payorsName, address, contactNum) VALUES(?,?,?,?,?,?,?) ;";

    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, date.c_str(), date.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, payto.c_str(), payto.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, accName.c_str(), accName.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, accNum);
    sqlite3_bind_text(stmt, 5, payorsName.c_str(), payorsName.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, address.c_str(), address.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, contactNum);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (result != SQLITE_OK) {
        cout << "\n\t\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
    }
    else {
        cout << "\n\t\t\t\t\t\t\t\t  _______________________________";
        cout << "\n\t\t\t\t\t\t\t\t  --Data Created Successfully!...\n";
        system("pause");
    }

}

void read() {

    query = "SELECT rowid, * FROM billpayment";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    if (result != SQLITE_OK) {
        cout << "\n\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
    }
    else {
        system("CLS");
        cout << "________________________________________________________________________________________________________________________________________________________________________\n";
        cout << left << " " << setw(5) << "| ID |" << setw(10) << "|    DATE    |" << setw(15) << " |     PAYMENT TO       |" << setw(15) << "|   ACCOUNT NAME   |" << setw(20) << "|   ACCOUNT NUMBER   |" << setw(20) << "|    PAYOR'S NAME    |" << setw(15) << "|          ADDRESS            |" << setw(20) << "|   CONTACT NUMBER   |" << "\n";

        while (result = sqlite3_step(stmt) == SQLITE_ROW) {
            cout << left << "   " << setw(5) << sqlite3_column_int(stmt, 0)
                << setw(15) << sqlite3_column_text(stmt, 1)
                << setw(25) << sqlite3_column_text(stmt, 2)
                << setw(20) << sqlite3_column_text(stmt, 3)
                << setw(20) << sqlite3_column_int(stmt, 4)
                << setw(25) << sqlite3_column_text(stmt, 5)
                << setw(30) << sqlite3_column_text(stmt, 6)
                << setw(20) << sqlite3_column_int(stmt, 7) << "\n";
        }
    }
    cout << "\n\t\t\t\t\t\t\t______________________________________________";
    cout << "\n\n\t\t\t\t\t\t\tPress any key and press [enter] to continue...";
    cin >> hold;

}

void update() {
    int id;

    //PROMPT TABLE
    query = "SELECT rowid, * FROM billpayment";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    if (result != SQLITE_OK) {
        cout << "\n\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
    }
    else {
        system("CLS");
        cout << "________________________________________________________________________________________________________________________________________________________________________\n";
        cout << left << " " << setw(5) << "| ID |" << setw(10) << "|    DATE    |" << setw(15) << " |     PAYMENT TO       |" << setw(15) << "|   ACCOUNT NAME   |" << setw(20) << "|   ACCOUNT NUMBER   |" << setw(20) << "|    PAYOR'S NAME    |" << setw(15) << "|          ADDRESS            |" << setw(20) << "|   CONTACT NUMBER   |" << "\n";

        while (result = sqlite3_step(stmt) == SQLITE_ROW) {
            cout << left << "   " << setw(5) << sqlite3_column_int(stmt, 0)
                << setw(15) << sqlite3_column_text(stmt, 1)
                << setw(25) << sqlite3_column_text(stmt, 2)
                << setw(20) << sqlite3_column_text(stmt, 3)
                << setw(20) << sqlite3_column_int(stmt, 4)
                << setw(25) << sqlite3_column_text(stmt, 5)
                << setw(30) << sqlite3_column_text(stmt, 6)
                << setw(20) << sqlite3_column_int(stmt, 7) << "\n";
        }
    }
    cout << "\n\t\t\t\t\t\t\t ______________________________________________";
    cout << "\n\t\t\t\t\t\t\t Enter the ID of the record you want to update: ";
    cin >> id;

    cout << "\n\t\t\t\t\t\t\t Enter New Date: ";
    getline(cin >> ws, date);
    cout << "\n\t\t\t\t\t\t\t Enter New Payment to: ";
    getline(cin >> ws, payto);
    cout << "\n\t\t\t\t\t\t\t Enter New Account Name: ";
    getline(cin >> ws, accName);
    cout << "\n\t\t\t\t\t\t\t Enter New Account Number: ";
    cin >> accNum;
    cout << "\n\t\t\t\t\t\t\t Enter New Payor's Name: ";
    getline(cin >> ws, payorsName);
    cout << "\n\t\t\t\t\t\t\t Enter New Address: ";
    getline(cin >> ws, address);
    cout << "\n\t\t\t\t\t\t\t Enter New Contact Number(+639 ---): ";
    cin >> contactNum;

    query = "UPDATE billpayment SET date = ?, payto = ?, accName = ?, accNum = ?, payorsName = ?, address = ?, contactNum = ? WHERE rowid = ?";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, date.c_str(), date.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, payto.c_str(), payto.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, accName.c_str(), accName.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, accNum);
    sqlite3_bind_text(stmt, 5, payorsName.c_str(), payorsName.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, address.c_str(), address.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, contactNum);
    sqlite3_bind_int(stmt, 8, id);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (result != SQLITE_OK) {
        cout << "\n\t\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
    }
    else {
        cout << "\n\t\t\t\t\t\t\t _______________________________";
        cout << "\n\t\t\t\t\t\t\t --Data Updated Successfully!...\n";
        system("pause");
    }
}

void del() {
    int id;
    char confirm;

    //PROMPT TABLE
    query = "SELECT rowid, * FROM billpayment";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    if (result != SQLITE_OK) {
        cout << "\n\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
    }
    else {
        system("CLS");
        cout << "________________________________________________________________________________________________________________________________________________________________________\n";
        cout << left << " " << setw(5) << "| ID |" << setw(10) << "|    DATE    |" << setw(15) << " |     PAYMENT TO       |" << setw(15) << "|   ACCOUNT NAME   |" << setw(20) << "|   ACCOUNT NUMBER   |" << setw(20) << "|    PAYOR'S NAME    |" << setw(15) << "|          ADDRESS            |" << setw(20) << "|   CONTACT NUMBER   |" << "\n";

        while (result = sqlite3_step(stmt) == SQLITE_ROW) {
            cout << left << "   " << setw(5) << sqlite3_column_int(stmt, 0)
                << setw(15) << sqlite3_column_text(stmt, 1)
                << setw(25) << sqlite3_column_text(stmt, 2)
                << setw(20) << sqlite3_column_text(stmt, 3)
                << setw(20) << sqlite3_column_int(stmt, 4)
                << setw(25) << sqlite3_column_text(stmt, 5)
                << setw(30) << sqlite3_column_text(stmt, 6)
                << setw(20) << sqlite3_column_int(stmt, 7) << "\n";
        }
    }
    cout << "\n\t\t\t\t\t\t\t ______________________________________________";
    cout << "\n\t\t\t\t\t\t\t Enter the ID of the record you want to delete: ";
    cin >> id;
    getchar();

    cout << "\n\t\t\t\t\t\t\t Do you want to continue? [Y/N]: ";
    cin >> confirm;

    if ((confirm == 'y') || (confirm == 'Y')) {
        query = "DELETE FROM billpayment WHERE rowid = ?";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if (result != SQLITE_OK) {
            cout << "\n\t\t\t\t\t\t\t ERROR!:" << sqlite3_errmsg(db) << "\n";
        }
        else {
            cout << "\n\t\t\t\t\t\t\t _______________________________";
            cout << "\n\t\t\t\t\t\t\t --Data Deleted Successfully!...\n";
            system("pause");
        }
    }
    else if ((confirm == 'n') || (confirm == 'N')) {
        cout << "\n\t\t\t\t\t\t\t ____________________________";
        cout << "\n\t\t\t\t\t\t\t Operation Cancelled...\n";
        system("pause");
    }
    else {
        cout << "\n\t\t\t\t\t\t\t Please choose between [Y] and [N] only!\n";
    }

}

void deleteTable() {
    char confirm;
    cout << "\n\t\t\t\t\t\t\t\t _______________________________";
    cout << "\n\t\t\t\t\t\t\t\t Do you want to continue? [Y/N]: ";
    cin >> confirm;

    if ((confirm == 'y') || (confirm == 'Y')) {
        query = "DELETE FROM billpayment";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);

        if (result != SQLITE_OK) {
            cout << "\n\t\t\t\t\t\t\t\tERROR!:" << sqlite3_errmsg(db) << "\n";
        }
        else {
            cout << "\n\t\t\t\t\t\t\t\t _______________________________";
            cout << "\n\t\t\t\t\t\t\t\t --Table Deleted Successfully!...\n";
            system("pause");
        }

    }
    else if ((confirm == 'n') || (confirm == 'N')) {
        cout << "\n\t\t\t\t\t\t\t\t ____________________________";
        cout << "\n\t\t\t\t\t\t\t\t Operation cancelled...\n";
        system("pause");
    }
    else {
        cout << "\n\t\t\t\t\t\t\t\t Please choose between [Y] and [N] only\n";
    }
}