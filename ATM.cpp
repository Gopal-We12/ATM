#include<conio.h>  // This is a C programming that we are using this so that we can use a function GETCH.GETCH is used to hold the screen until the user press any key. 
#include<iostream> // It is used to take user input and showing the output.
#include<string>
using namespace std;

class atm{
    private:                         //private member variables(We can not access the data outside the class.)
       long int account_No;
       string name;
       int PIN;
       double balance;
       string mobile_No;

public:              //public member function.           //beacause we want to use it from out side the class.
    //setData function us setting the Data into the private member variales.
     
    void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a)
    {
                account_No=account_No_a;      //assing the formal argumentd to be the private member variables.
                name=name_a;
                PIN=PIN_a;
                balance=balance_a;
                mobile_No=mobile_No_a;
    }

    //getAccountNo function is returning the user's account no.
    long int getAccountNo()
    {
        return account_No;
    }
    //getName function is returning the user's Name

    string getName()
    {
        return name;
    }

    //getPin function is returing the user's PIN
    int getPIN()
    {
        return PIN;
    } 

    //get balance function is returning the balance.

    double getBalance()
    {
        return balance;
    }

   //getMoblieNo is returning the user's Mobile No.balance.

   string getMobileNo()
   {
       return mobile_No;
   }

   //setMobile fuction is updating the user mobile no.

   void setMobile(string mob_prev,string mob_new)
   {
    if(mob_prev==mobile_No){                                             //it will check old Mobile no
       mobile_No=mob_new;                                              //and Update with new,if old  matches;
       cout<<endl<<"Sucessfully Updated Mobile no.";
       _getch();                                                      //getch is to hold the screen(until user press any key)
    }
    else							                                 // Does not update if old mobile no. does not matches
		{
			cout << endl << "Incorrect !!! Old Mobile no";
			_getch();			                                     //getch is to hold the screen ( untill user press any key )
		} 
   }

   //cashWithdraw function is used to withdraw money from the Atm.
   void cashWithDraw(int amount_a){
    if(amount_a > 0 && amount_a < balance){                   //check entered amount validity.
             balance-=amount_a;
             cout<<endl<<"Please Collect Your Cash";
             cout<<endl<<"Available Balance :"<<balance;
             _getch();
    }  
    else{
        cout<<endl<<"Invaild Input or Insufficient Balance";
        _getch();           //getch is to hold the screen(untill user press any key)
    }
 
   }

} ;



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    int choice=0,enterPIN;                  //enterPIN and enterAccountNO.----->user authentication
    long int enterAccountNo;

    system("cls");                        //It use to clear the screen,and whenever we were moving from one menu to another,then screen get automatically cleaned.
                                        //Here we are not using file handling .with the help of file handling ,we can permanently store the data.
    //created User(object)

    atm user1;
    //Set User Details(into object)(Setting Default Data)
    user1.setData(377485,"Gopal_Keshari",1542,745628.90,"9369335512");



    do{                        //By using do while loop we are able to run our application multiple times as you can relate this with the real time machine.
                               //That software runnig into the machine is running for infinite time.The user can't exit or close it
        system("cls");
        cout<<endl<<"****Welcome to ATM****"<<endl;
        cout<<endl<<"Enter Your Account No ";        // asking user to ener account no.
        
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN ";
        cin>>enterPIN;

        //check wheher enter value matches with user details.
        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())){
            do
            {
                int amount = 0;
                string oldMobileNo,newMobileNo;

                system("cls");
                //user Inteface....
                cout<<endl<<"****Welcome to ATM****"<<endl;
                cout<<endl<<"Select Options ";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Balance";
                cout<<endl<<"3. Show User Details";
                cout<<endl<<"4. Update Mobile no.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;                //taking user choice.
                 

               switch(choice){              //switch condition
                case 1:                    //if user presses.
                 cout<<endl<<"Your Bank balance is :"<<user1.getBalance();   //getBalance is....printing the users bank balance.

                 _getch();
                 break;


                case 2:
                 cout<<endl<<"Enter the amount :";
                 cin>>amount;
                 user1.cashWithDraw(amount);    //calling cashWithdraw function.
                                                //passing the withdraw function.
                 break;


               case 3:
                 cout << endl<< "***User Details are :- ";
                 cout << endl<< "Account no:-" <<user1.getAccountNo();
                 cout << endl <<"Name:-      "<<user1.getName();
                 cout<< endl <<"Balance:-    " <<user1.getBalance();
                 cout<< endl <<"Mobile No:-  "<<user1.getMobileNo();      
                                                            //getting and printing user details.
                _getch();
                  break;


                case 4:
                    cout<<endl<< "Enter old_Mobile No. ";
                    cin>> oldMobileNo;

                    cout<<endl<< "Enter New Mobile No. ";     
                    cin>> newMobileNo;

                    user1.setMobile(oldMobileNo,newMobileNo);          
                    break;


                case 5:
                     exit(0);                                  //exit application.

                default:							// handle invalid user inputs
					   cout << endl << "Enter Valid Data !!!";
			} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}

		else
		{
			 cout << endl << "User Details are Invalid !!! ";
			 _getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}
