#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;
time_t t = time(0);   // get time now
struct tm *now = localtime(&t); //buildin function to get date.
string IntToString(int a); //funtion to convert integer to string.
double StringToDouble(string str);//funtion to convert string to double.
float StringToFloat(string str);//funtion to convert string to float.
int StringToInteger(string str);//funtion to convert string to integer.
struct Date //date struct
{
	int month;
	int year;
};
class customer  //customer class
{
public:    //public members
	customer();
	~customer();
	void set_cnic(string);
	void set_name(string);
	void set_address(string);
	void set_phone_number(string);
	string get_cnic();
	string  get_name();
	string  get_address();
	string get_phone_number();

private: //private members
	string Cnic;
	string name;
	string address;
	string phoneNumber;
};

customer::customer() //customer class constructor
{
	Cnic = "";
	name = "";
	address = "";
	phoneNumber = "";
}

customer::~customer() //customer class destructor
{
}

void customer::set_cnic(string cnic1) // setter for cnic member of customer class
{
	Cnic = cnic1;
}

void customer::set_name(string name1) // setter for name member of customer class
{
	name = name1;
}

void customer::set_address(string address1) // setter for address member of customer class
{
	address = address1;
}

void customer::set_phone_number(string number) // setter for phone number member of customer class
{
	phoneNumber = number;
}

string customer::get_cnic() // getter for cnic member of customer class
{
	return Cnic;
}

string customer::get_name() // getter for name member of customer class
{
	return name;
}

string customer::get_address() // getter for address member of customer class
{
	return address;
}

string customer::get_phone_number() // getter for phone number member of customer class
{
	return phoneNumber;
}
class Account // Account Class
{
public: //public members
	Account();
	~Account();
	void depositMoney(double);
	double getBalance();
	double withdrawMoney(double);
	void setAccountno(string);
	void setBalance(double);
	void setAccountdate(int,int);
	void setOwner(string, string, string, string);
	string getAccountno();
	Date getAccountdate();
	customer getOwner();
	customer owner;
protected: //protected members
	string accountNo;
	double balance;
	Date accountDate;
};

Account::Account() // Constructor of Account class
{
	balance = 0.0;
	accountDate.month = 0;
	accountDate.year = 0;
	accountNo = "";
}

Account ::~Account() // Destructor of class
{

}

void Account::depositMoney(double balance1) // DepositMoney Function
{
	balance = balance+balance1;
}

double Account::getBalance() //getter for balance in Account class
{
	return balance;
}

double Account::withdrawMoney(double withdraw) //Withdraw Money function
{
	if (withdraw <= balance)
	{
		balance = balance - withdraw;
		return balance;
	}
	else
	{
		cout << "You have not enough balance to withdraw." << endl;
	}
}

void Account::setAccountno(string account) // Setter function for Account number in Account class
{
	accountNo = account;
}

void Account::setBalance(double balance1) // Setter function for Balance in Account class
{
	balance = balance1;
}

void Account::setAccountdate(int month1,int year1) // Setter function for Account date in Account class
{
	accountDate.month = month1;
	accountDate.year = year1;
}

void Account::setOwner(string name1, string cnic1, string add, string ph) //Setter function for owner in Account class
{
	owner.set_name(name1);
	owner.set_cnic(cnic1);
	owner.set_address(add);
	owner.set_phone_number(ph);
}

string Account::getAccountno()  // Getter function for Account number in Account class
{
	return accountNo;
}

Date Account::getAccountdate() //Setter function for Account date in Account class
{
	return accountDate;
}

customer Account::getOwner() // Setter function for owner in Account class
{
	return owner;
}
class savingAccount :public Account //Saving Account class inheritied by Account class
{
public: //public members
	void changeinterestrate(float);
	double getBalance();
	void setintrestrate(float);
	float getintrestrate();

protected: // protected members
	float interestRate;
};

void savingAccount::changeinterestrate(float rate) // Change intrest rate fuction.
{
	interestRate = rate;
}

double savingAccount::getBalance() //getter for balance of saving account class.
{
	int num_of_month = ((now->tm_mon + 1) - accountDate.month); //setting number of months.
	double money_deposited = this->Account::getBalance();
	balance = money_deposited + ((interestRate / 100)*num_of_month*money_deposited);
	return balance;
}
void savingAccount::setintrestrate( float var) // setter for intresr rate.
{
	interestRate = var;
}
float savingAccount::getintrestrate() //getter for intrest rate of saving account class.
{
	return interestRate;
}
class checkingAccount :public Account //Checking account class inherited by Account class.
{
public: //public members
	void changeinterestrate(float);
	double getBalance();
	void setinsufficient_Fund_Fee(float);
	float getinsufficient_Fund_Fee();
protected: //protected class
	float insufficient_Fund_Fee;
};

void checkingAccount::changeinterestrate(float rate) //defination of change intrest rate function in checking acccount class
{
	insufficient_Fund_Fee = rate;
}

double checkingAccount::getBalance() // defination of get balance of chechking account class
{
	if (this->Account::getBalance() < 10000)
		balance = balance - insufficient_Fund_Fee;
	return balance;
}

void checkingAccount::setinsufficient_Fund_Fee(float var) // defination of set insufficient of chechking account class
{
	insufficient_Fund_Fee = var;
}

float checkingAccount::getinsufficient_Fund_Fee() // defination of get insufficient of chechking account class
{
	return insufficient_Fund_Fee;
}


int size; // global variable for dynamic array

int main() // Starting of Main Function
{
	// local variables initilization
	ifstream fin;
	ofstream fout;
	int option=0, option1 = 0;
	int local_index=0;
    int integer_balance=0;
	int local_counter = 0;
	double amount=0;
	int ary_index = 0;
	int local_counter2 = 0;
	string *ptr;
	string local_name, local_cnic, local_address, local_ph, local_account, local_temp;
	string checking, checking2, date2, rate2;
	int index_counter = 0;
	string temp;
	int local_month, local_year;
	double local_money;
	float local_rate;
	fin.open("accounts.txt"); //file opening.
		while (getline(fin, local_temp))
		{
			::size++; // counting number of accounts.
		}
	fin.close(); // file closing.
	ptr = new string[::size]; //dynamic array initilization.
	fin.open("accounts.txt");//file opening.
	while (getline(fin, local_temp))
	{
		ptr[local_counter] = local_temp; //loading account in array from file/
		local_counter++;
	}
	fin.close();// file closing.
	do
	{
		system("cls");
		cout << "\tMenu" << endl; //menu
		cout << "1. Bank operation." << endl;
		cout << "2. To exit." << endl;
		cin >> option1;
		switch (option1) //switch 1
		{
		case 1: // if press 1 in switch 1.
		{
			do
			{
			
			    cout << "\tMenu" << endl;  //menu.
				cout << "1. Create New Account." << endl;
				cout << "2. Search Account." << endl;
				cout << "5. Go back to previous menu" << endl;
				cin >> option;
				switch (option) // switch 2.
				{
				case 1: // if press 1 in switch 2.
				{
					
						system("cls");
						customer var; // customer class variable.
						cout << "Enter customer name: ";
						cin.ignore();
						getline(cin, local_name);
						var.set_name(local_name);
						cout << "Enter customer Cnic: ";
						getline(cin, local_cnic);
						var.set_cnic(local_cnic);
						cout << "Enter customer address: ";
						getline(cin, local_address);
						var.set_address(local_address);
						cout << "Enter customer Phone number: ";
						getline(cin, local_ph);
						var.set_phone_number(local_ph);
						cout << "\tMenu" << endl; //menu
						cout << "1.Checking Account." << endl;
						cout << "2.Saving Account." << endl;
						cout << "3.Go back to previous menu" << endl;
						cin >> option;
						switch (option) //switch 3
						{
						case 1: // if press 1 than checking class object created in switch 3.
						{
							cout << "\tChecking Account" << endl;
							cout << "\t   Code:00" << endl;
							checkingAccount var2;
							cout << "Enter Account number: ";
							cin >> local_account;
							var2.setAccountno(local_account);
							cout << "Enter Month: " ;
							cin >> local_month;
							cout << "Enter Year: ";
							cin >> local_year;
							var2.setAccountdate(local_month,local_year);
							cout << "Enter Starting money: " ;
							cin >> local_money;
							var2.setBalance(local_money);
							cout << "Enter interest rate: ";
							cin >> local_rate;
							var2.setinsufficient_Fund_Fee(local_rate);
							var2.changeinterestrate(var2.getinsufficient_Fund_Fee());
							var2.owner = var; // adding customer to account by assinging customer variable.
							fout.open("accounts.txt", ios::app); // opening file for writing in append mode
							fout << var2.getAccountno() << ">>" << var2.getinsufficient_Fund_Fee() << ">>" << var2.getBalance()
								<< ">>" << var2.getAccountdate().month<<"-"<< var2.getAccountdate().month << ">>" << var2.getOwner().get_cnic() << ">>" << var2.getOwner().get_name()
								<< ">>" << var2.getOwner().get_phone_number() << ">>" << var2.getOwner().get_address() << endl;
							fout.close(); // closing file
							::size++; //increment in size/
							delete[]ptr; // deleting array for again intilization of array/
							ptr = new string[::size]; //initilization new array with new size.
							fin.open("accounts.txt"); //opening file.
							while (getline(fin, local_temp))
							{
								ptr[local_counter2] = local_temp; //loading accounts in array from file.
								local_counter2++;
							}
							fin.close(); //closing file.
						}
						break;
						case 2: // if press 1 than Saving class object created in switch 3.
						{
							cout << "\tSaving Account" << endl;
							cout << "\t   Code:01" << endl;
							savingAccount var2;
							cout << "Enter Account number: ";
							cin >> local_account;
							var2.setAccountno(local_account);
							cout << "Enter Month: ";
							cin >> local_month;
							cout << "Enter Year: ";
							cin >> local_year;
							var2.setAccountdate(local_month, local_year);
							cout << "Enter Starting money: " ;
							cin >> local_money;
							var2.setBalance(local_money);
							cout << "Enter interest rate: ";
							cin >> local_rate;
							var2.setintrestrate(local_rate);
							var2.changeinterestrate(var2.getintrestrate());
							var2.owner = var; // adding customer to account by assinging customer variable.
							fout.open("accounts.txt", ios::app); // opening file for writing in append mode
							fout << var2.getAccountno() << ">>" << var2.getintrestrate() << ">>" << var2.getBalance()
								<< ">>" << var2.getAccountdate().month << "-" << var2.getAccountdate().month << ">>" << var2.getOwner().get_cnic() << ">>" << var2.getOwner().get_name()
								<< ">>" << var2.getOwner().get_phone_number() << ">>" << var2.getOwner().get_address() << endl;
							fout.close();// closing file
							::size++; //increment in size/
							int local_counter2 = 0;
							delete[]ptr;// deleting array for again intilization of array.
							ptr = new string[::size];//initilization new array with new size.
							fin.open("accounts.txt"); //opening file.
							while (getline(fin, local_temp))
							{
								ptr[local_counter2] = local_temp; //loading accounts in array from file.
								local_counter2++;
							}
							fin.close(); //closing file.
						}
						break;
						default:
						{
							cout << "Invalid input." << endl;
						}
					}
					
				}
				break;
				case 2: // if press 2 in switch 2 for searching account.
				{
				 //	system("cls");
					string  local_balance;
					local_counter = 0;
					index_counter = 0;
					Account var; // Account class object.
					bool check = false; // bool variable for if account is in the file or not.
					cout << "Enter account number: ";
					cin >> local_account;
					for (int index = 0; index < ::size; index++)
					{
						int len = ptr[index].length();
						for (int i = 0; i < len; i++)
						{
							if (ptr[index][i] != '-'&&i <= 1) 
								checking += ptr[index][i];
							if (ptr[index][i] != '>')
								temp += ptr[index][i];
							
							else if (temp == local_account)
							{  
								checking2 = checking; // 2 digit code is saved in checking2 from file to check if account is saving ang checking.
								local_index = index;
								check = true;
								break;
							}
						}
						temp = "\0";
						checking = "\0";
					}
					if (check == true) // if account is present in file.
					{
						int len2 = ptr[local_index].length();
						for (int i = 0; i < len2; i++)
						{
							if (ptr[local_index][i] != '>')
							{
								temp += ptr[local_index][i];
							}
							if (temp == local_account)
							{
								int l = 0;
								for (int j = 0; j < len2; j++)
								{
									if (ptr[local_index][j] == '>')
										local_counter++;
									if (local_counter == 2)
									{
										 l = j + 1;
										 while (ptr[local_index][l] != '>')
										 {
											 rate2 += ptr[local_index][l]; //rate is saved in rate2 from file
											 l++;
										 }
										
									}
									if (local_counter == 3)
									{
										 l = j + 2;
										while (ptr[local_index][l] != '>')
										{
											local_balance += ptr[local_index][l]; // balance is saved in local_balance from file.
											l++;
										}
										l = l + 2;
										while (ptr[local_index][l] != '-')
										{
											date2 += ptr[local_index][l]; // date is saved in date2 from file.
											l++;
										}
									}
								}
								break;
							}
						}
						double var3 = StringToDouble(local_balance); // balance is converted into double from string.
						int var4 = StringToInteger(date2); // date is converted into integer from string.
						float var5 = StringToFloat(rate2); // rate is converted into float from string.
						if (checking2 == "00" &&check == true) // checking if account is Saving Account.
						{
							var3 = var3+((var5 / 100)*((now->tm_mon + 1) - var4)*var3);
							cout << "var3:" << var3 << endl;
							integer_balance = 0;
							integer_balance = static_cast<int>(var3);// double is converted into interger.
							string new_balance = IntToString(integer_balance); //integer is converted into string.
							string temp_ary[8]; // temporary array for saving account number,intrest/isufficient rate,balance,cnic,name,phonenumber,address.
							int len3 = ptr[local_index].length();
							ary_index = 0;
							for (int i = 0, j = 0; i < len3; i++)
							{
								if (ptr[local_index][i] != '>')
									temp_ary[ary_index] += ptr[local_index][i];
								else
								{
									i = i + 1;
									ary_index = ary_index + 1;
								}

							}
							temp_ary[2] = new_balance; // undating balance.
							ptr[local_index] = temp_ary[0] + ">>" + temp_ary[1] + ">>" + temp_ary[2] + ">>" // updating account information.
								+ temp_ary[3] + ">>" + temp_ary[4] + ">>" + temp_ary[5] + ">>"
								+ temp_ary[6] + ">>" + temp_ary[7];
							fout.open("accounts.txt"); //opening file.
							for (int i = 0; i < ::size; i++) //updating file.
								fout << ptr[i] << endl;
							fout.close(); //closing file.
						}
						
						if (checking2 == "01" &&check == true) // checking if account is Saving Account.
						{
							if (var3 < 10000)
							{
								var3 = var3 - var5;
								integer_balance = 0;
								integer_balance = static_cast<int>(var3);// double is converted into interger.
								string new_balance = IntToString(integer_balance); //integer is converted into string.
								string temp_ary[8]; // temporary array for saving account number,intrest/isufficient rate,balance,cnic,name,phonenumber,address.
								int len3 = ptr[local_index].length();
								ary_index = 0;
								for (int i = 0, j = 0; i < len3; i++)
								{
									if (ptr[local_index][i] != '>')
										temp_ary[ary_index] += ptr[local_index][i];
									else
									{
										i = i + 1;
										ary_index = ary_index + 1;
									}

								}
								temp_ary[2] = new_balance; // undating balance.
								ptr[local_index] = temp_ary[0] + ">>" + temp_ary[1] + ">>" + temp_ary[2] + ">>" // updating account information.
									+ temp_ary[3] + ">>" + temp_ary[4] + ">>" + temp_ary[5] + ">>"
									+ temp_ary[6] + ">>" + temp_ary[7];
								fout.open("accounts.txt"); //opening file.
								for (int i = 0; i < ::size; i++) //updating file.
									fout << ptr[i] << endl;
								fout.close(); //closing file.
							}
						}
						var.setBalance(var3); // updating in account object balance
						int option2;
						cout << "Account Number: " << local_account << " Founded" << endl;
						do
						{
							cout << "\tMenu" << endl; //menu
							cout << "1. Deposite Money." << endl;
							cout << "2. Withdraw Money." << endl;
							cout << "3. View Balance." << endl;
							cout << "4. Go back to previous Menu." << endl;
							cin >> option2;
							switch (option2) //switch 4
							{
							case 1: //if press 1 in switch 4.
							{
								cout << "Account Number: " << local_account << " Founded" << endl;
								cout << "Enter Amount to deposite." << endl;
								cin >> amount;
								var.depositMoney(amount);
								integer_balance = static_cast<int>(var.getBalance()); //converting double into integer.
								string new_balance = IntToString(integer_balance); //integer is converted into string.
								string temp_ary[8];// temporary array for saving account number,intrest/isufficient rate,balance,cnic,name,phonenumber,address.
								int len3 = ptr[local_index].length();
								ary_index = 0;
								for (int i = 0; i < len3; i++)
								{
									if (ptr[local_index][i] != '>')
										temp_ary[ary_index] += ptr[local_index][i];
									else
									{
										i = i + 1;
										ary_index = ary_index + 1;
									}

								}
								temp_ary[2] = new_balance;// undating balance.
								ptr[local_index] = temp_ary[0] + ">>" + temp_ary[1] + ">>" + temp_ary[2] + ">>"// updating account information.
									              + temp_ary[3] + ">>" + temp_ary[4] + ">>" + temp_ary[5] + ">>"
									              + temp_ary[6] + ">>" + temp_ary[7];
								fout.open("accounts.txt");//opening file.
								for (int i = 0; i < ::size; i++)//updating file.
									fout << ptr[i] << endl;
								fout.close();//closing file.
							}

							break;
							case 2:
							{	
								cout << "Account Number: " << local_account << "Founded" << endl;
								cout << "Enter amount to withdraw money." << endl;
								cin >> amount;
								integer_balance = static_cast<int>(var.withdrawMoney(amount));
								string new_balance = IntToString(integer_balance);
								string temp_ary[8];
								int len3 = ptr[local_index].length();
								ary_index = 0;
								for (int i = 0, j = 0; i < len3; i++)
								{
									if (ptr[local_index][i] != '>')
										temp_ary[ary_index] += ptr[local_index][i];
									else
									{
										i = i + 1;
										ary_index = ary_index + 1;
									}

								}
								temp_ary[2] = new_balance;
								ptr[local_index] = temp_ary[0] + ">>" + temp_ary[1] + ">>" + temp_ary[2] + ">>" 
									              + temp_ary[3] + ">>" + temp_ary[4] + ">>" + temp_ary[5]
									              + ">>" + temp_ary[6] + ">>" + temp_ary[7];
								fout.open("accounts.txt");
								for (int i = 0; i < ::size; i++)
									fout << ptr[i] << endl;
								fout.close();
							}
							break;
							case 3:
							{
								system("cls");
								cout << "Account Number: " << local_account <<"Founded"<< endl;
								cout << "Your balance is: " << var.getBalance() << endl;
							}
							break;
							}
							//system("cls");
						} while (option2 != 4);
					}
					else
						system("cls");
					cout << "Account does not found." << endl;
				}
				break;
				case 5:
				{
					break;
				}
				break;
				default:
					cout << "Invalid entry." << endl;
				}//switch 2 end.
			}while (option != 5);
          }//case 1 end.
		  break;
		  case 2:
			  exit(1);
		  break;
		  default:
			  cout << "Invalid entry." << endl;
        }
		system("cls");
	} while (option1 != 2);
	delete[] ptr;
    system("pause");
}
string IntToString(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}
double StringToDouble(string str)
{
	istringstream iss(str);
	double d = 0;
	iss >> d;
	return d;
}
float StringToFloat(string str)
{
	istringstream iss(str);
	float d = 0;
	iss >> d;
	return d;
}
int StringToInteger(string str)
{
	istringstream iss(str);
	int d = 0;
	iss >> d;
	return d;
}