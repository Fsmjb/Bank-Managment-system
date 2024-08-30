#include <iostream>
#include <conio.h>
#include <string>
using namespace std;


class Acount{
	
	
	public:
	char pin[5];
	float balance = 100.0;
	float loan = 0;
	char f_name[10];
	char l_name[10];
	char phone_number[11];
	
	void creatacount(){
		cout << "	Enter your first name   : ";
		cin  >> f_name;
		cout << "	Enter your last name    : ";
		cin  >> l_name;
		cout << "	Enter you phone Number  : ";
		cin  >> phone_number;
		cout <<"	Enter you 5 digit pin   : ";
		for (int x = 0; x < 5; ++x){
			pin[x] = getch();
			cout << "*";
		}
		cout << endl;
		cout << "	your acount create successfuly" <<endl;
		char no = getch(); // use for pause the screen
//		cout << "**************************************************************************"<<endl;
	}
	 	
};

struct admin{
	char f_name[10] = "Muhammad";
	char l_name[10] = "Junaid";
	int bank_balance = 500000000;
	char pin[6] =  "12345";
};

char login_manu(); // login manu
char logout_manu(); // logout manu
void welcome(); // welcome
void logout(bool *p); // logout function
int check_pin(char a[5], char b[5]){
	int ans = 0;
	for(int x = 0; x< 5; ++x){
		if(a[x] == b[x]){
			ans += 1;
		}
	}
	getch();
	return ans;
}



int main(){
system ("color F0"); // setting display color

bool login = 0; // control login loop
int acount_no = 0; // control acount creation sequeance
int login_no = 0; // crontrol login sequence
int amount_loded = 0; // total amount loaded
int amount_withdraw = 0; // total amount withdraw 
int trans_done = 0; // no of taransication done


Acount obj[100]; // create ten object 
admin super; // create admin object


welcome(); //  setting welcome

while(true){ // keep the work agiain & again

	if(login){
		char pr;
		pr = login_manu();
		
		switch(pr){
			case '1': // show balance
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << endl << "	Your balance is : " << obj[login_no].balance  << endl;
				getch();
				break;
				
			case '2': // add money
				system ("cls");
				cout << "**************************************************************************"<< endl;
				int add_amount;
				cout << endl << "	Enter the amount you add : ";
				cin  >> add_amount;
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[login_no].pin,pin);
					if (status == 5){
						obj[login_no].balance += add_amount;
						amount_loded += add_amount;
						cout << "	New balance successfuly added"<< endl;
						cout << "	your New balance is : " << obj[login_no].balance;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
				getch(); 
				break;
				
			case '3': // withdarw
				system ("cls");
				cout << "**************************************************************************"<< endl;
				int withdraw_amount;
				cout << endl << "	Enter the amount you want to withdraw : ";
				cin >> withdraw_amount;
				if(withdraw_amount < obj[login_no].balance){
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[login_no].pin,pin);
					if (status == 5){
						obj[login_no].balance -= withdraw_amount;
						amount_withdraw += withdraw_amount;
						cout << "	Your new blance is : " << obj[login_no].balance << endl;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
					
				}
				
				else{
					cout << "	You have not enough Money" << endl;
				}
				getch();
				break;
				
				
			case '4': // send money
				system("cls");
				cout << "**************************************************************************"<< endl;
				int id_send, amount_send;
				cout << endl << "	Enter the id you want to send money : " ;
				cin  >> id_send;
				id_send -= 1; // to fix to acount;
				
				if((id_send == login_no) || (id_send >= acount_no) || (id_send < 0)){
					cout << "	You enter invilid Id" << endl;
				}
				else{
					cout << "	Enter the amount you want to send : " ;
					cin  >> amount_send;
					
					if(amount_send > obj[login_no].balance){
						cout << "	You have not enough money" << endl;
					}
					else{
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[login_no].pin,pin);
					if (status == 5){
						obj[id_send].balance += amount_send;
						obj[login_no].balance -= amount_send;
						trans_done += 1;
						cout << "	You transication done successfuly " << endl;
						cout << "	Your new balance is : " << obj[login_no].balance;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
					 
					}
				}
				getch();
				break;
			case '5': // get loan
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << "	Are you want to get loan " << endl;
				cout << "	Press Y for yes & other key for no" << endl;
				char press ; press =  getch();
				if ( press == 'y'){
					int amount;
					cout << "	Enter the amount : " ;
					cin  >> amount;
					
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[login_no].pin,pin);
					if (status == 5){
						super.bank_balance -= amount;
						obj[login_no].balance += amount;
						obj[login_no].loan += amount; 
						cout << "	You have recived the loan " << endl;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
				}
				getch();
				break;
			case '6': // return loan
			{
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << "	Are you want to return loan " << endl;
				cout << "	Press Y for yes & other key for no" << endl;
				char press ; press =  getch();
				if ( press == 'y'){
					int amount;
					cout << "	Enter the amount 	: " ;
					cin  >> amount;
					if(amount > obj[login_no].loan){
						cout <<"	Your enter the invilid amount " << endl;
					}
					else {
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[login_no].pin,pin);
					if (status == 5){
						super.bank_balance += amount;
						obj[login_no].balance -= amount;
						obj[login_no].loan -= amount; 
						cout << "	You have return the loan " << endl;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
					}
				}
				getch();
			}
				break;
			case '7':
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << "	Acount No             :			" << login_no + 1 << endl; 
				cout << "	First name            : 		" << obj[login_no].f_name << endl;
				cout << "	Second name           : 		" << obj[login_no].l_name << endl;
				cout << "	Total balance         : 		" << obj[login_no].balance << endl;
				cout << "	Phone Number          :			" << obj[login_no].phone_number << endl;
				cout << "	Amount of loan        : 		" <<obj[login_no].loan << endl;
				getch();
				break;
			case '8': // logout 
				system("cls");
				cout << "**************************************************************************"<< endl;
				char enter;
				cout << "	Are you want to logout" << endl;
				cout << "	Press y for yes & other key  for no" << endl;
				cout << "	";
				enter = getch();
				if (enter == 'y'){
				login = 0;
				}
				break;
			default:
				cout << "	You enter the wrong option" << endl;
				getch();
		}
	}
	else{
		char pr;
		pr = logout_manu();
		switch(pr){
			case '1': // create the acunt
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << "	Acount NO       	: 		" << acount_no + 1  << endl;
				if (acount_no > 99){
					cout << "	Acount limit reached" <<endl;
					getch();
				}
				else{
				obj[acount_no].creatacount();
				acount_no += 1;
				}
				break;
				
			case '2': // control the login system;
				system ("cls");
				cout << "**************************************************************************"<< endl;
				int enter_acount_no; // declare for take acount no to take acount no form user
				cout << "	Enter Acount No		:  ";
				cin  >> enter_acount_no; // get acount no
				if ((enter_acount_no > acount_no) || (enter_acount_no < 1)){
					cout << "	The acount does not exist" << endl;
				}
				else{
					enter_acount_no -= 1; // decrease the acount no to get the fix object
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(obj[enter_acount_no].pin,pin);
					if (status == 5){
						login = 1;
						login_no = enter_acount_no;
						cout << "	You are succesfuly login" << endl;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
				}	
				getch();
				break;
			case '3': // login as admin
			{
				system("cls");
				cout << "**************************************************************************"<< endl;
				string enter_id;
				cout << "	Enter the id of the admin : "  ;
				cin  >> enter_id;
				if(enter_id != "000"){
					cout << "	You enter the wrong id " << endl;
				}
				else{
					enter_acount_no -= 1; // decrease the acount no to get the fix object
					char pin[6]; // get pin
					cout << "	Enter you pin		:  ";
					for (int x = 0; x < 5; ++x){
					pin[x] = getch();
					cout << "*";
					}
					cout << endl;
					int status;
					status = check_pin(super.pin,pin);
					if (status == 5){
						cout << "**************************************************************************"<< endl;
						cout << "	                 Welcome admin " << endl;
						cout << "	First name                : 		"  << super.f_name << endl;
						cout << "	Second name               : 		" << super.l_name << endl;
						cout << "	Total balance             : 		" << super.bank_balance << endl;
						cout << "	No of acounts created     : 		" << acount_no << endl;
						cout << "	Amount of loan given      : 		" << 500000000 - super.bank_balance << endl; 
						cout << "	Amount of blance loded    : 		" << amount_loded << endl;
						cout << "	Amount of blance withdraw : 		" << amount_withdraw << endl;
						cout << "	No of transication done   : 		" << trans_done << endl;
					}
					else{
						cout << "	You enter pin & id don't match" << endl;
					}
				}
				getch();
				break;
			}
			case '4': // exit the system
				system ("cls");
				cout << "**************************************************************************"<< endl;
				cout << "	Are you want to exit"<<endl;
				cout << "	Press Y for yes & other key for No"<< endl;
				char press; press = getch();
				if(press == 'y'){
					return 0;
				}
				break;
			default:
				cout << "	You enter the wrong option"<< endl;
				getch();
		}
	}
	
}


	return 0;
}





void welcome(){
	cout << "**************************************************************************"<<endl;
    cout << "	W   W  EEEEE  L      CCCC  OOO    M   M  EEEEE\n";
    cout << "	W W W  E      L     C      O   O  MM MM  E    \n";
    cout << "	W W W  EEEE   L     C      O   O  M M M  EEEE \n";
    cout << "	W W W  E      L     C      O   O  M   M  E    \n";
    cout << "	W  W   EEEEE  LLLLL  CCCC  OOO    M   M  EEEEE\n";
//	cout << "**************************************************************************"<<endl;
    cout << endl << endl << endl;
//	cout << "**************************************************************************"<<endl;
    cout << "	Welcome to  Bank Managment system" << endl;
    cout << "	press any key to continue" << endl << endl << endl << endl;
	cout << "**************************************************************************"<<endl;
    getch();
}


char login_manu(){
	system ("cls");
	cout << "************************* Menu *****************************" <<endl;
	cout << "	1 -> Show balance" << endl;
	cout << "	2 -> Add money" << endl;
	cout << "	3 -> Withdraw Money" <<endl;
	cout << "	4 -> send Money" << endl;
	cout << "	5 -> Get loan" <<endl;
	cout << "	6 -> Return loan" << endl;
	cout << "	7 -> Acount details " << endl;
	cout << "	8 -> logout" << endl << endl;
	cout << "	Select any one from the manu"<< endl;
	char click;
	click = getch();
	return click;
//	cout << "**************************************************************************"<<endl;
}

char logout_manu(){
	system("cls");
	cout << "************************* Menu ******************************************" <<endl;
	cout << "	1 -> Create acount" << endl ;
	cout << "	2 -> login" << endl;
	cout << "	3 -> login as admin" << endl;
	cout << "	4 -> exit" << endl;
	cout << "	Select any one from the manu" << endl;
	char click;
	click = getch();
	return click; 
//	cout << "**************************************************************************"<<endl;
}


void logout(bool *p){
	char ch;
	system("cls");
	cout << "**************************************************************************"<<endl;
	cout << "	Are you want to logout"<< endl;
	cout << "	Press Y for yes & Press other key for no" << endl;
	ch = getch();
	ch == 'y'? *p = 0: 0;
//	cout << "**************************************************************************"<<endl;
	
}