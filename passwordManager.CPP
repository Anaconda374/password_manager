#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

//define class for storing data:
class Account{
public:
    std::string siteName = "" ;
    std::string accName = "" ;
    std::string password = "" ;
};

//function declarations:
void reg_account();
std::vector<Account>& load_file(std::vector<Account>& acc_vec);
void accountMatch(std::vector<Account>& acc_vec, std::string str);



int main()
{
    std::vector<Account> acc_total;
    
    //prompt 4 options on console: 
    std::cout<< " * PASSWORD MANAGER * \n" 
    << "Options: "<<"\n"
    << "1. Register(R)"<<"\n"
    << "2. Search(S)"<<"\n"
    << "3. Account Number(N)"<<"\n"
    << "4. Exit(E)" <<"\n"
    << "Select an option to execute(Enter Number/Letter): "
    << std::endl;
    
    char op;
    std::cin >> op;
    std::cin.clear();
    if((op == '1') || (op == 'r') || (op == 'R') ){
        reg_account();
        
    }
    else if((op == '2') || (op == 's') || (op == 'S') ){
        
        std::string siteName;
        std::cout<< "Please input a siteName for search: ";
        std::cin >> siteName;
        // while(getchar()!= '\n');
        accountMatch(load_file(acc_total), siteName);
    }
    else if(op == '3' || op == 'n' || op == 'N' ){
        std::cout<< "There are "<<load_file(acc_total).size()
        << " accounts in the file ." <<std::endl;
    }
    else if((op == 4) || (op == 'e') || (op == 'E') ){
        ;
        
    }
    
    
    return 0;
}

void reg_account(){
    fstream reg("password.txt", ios::app);
    std::string temp;
    std::cout<< "Account: " <<std::endl;
    std::cin >> temp;
    reg << temp << " " <<std::flush;
    while(getchar()!= '\n');
    std::cout << "Name: " <<std::endl;
    std::cin >> temp;
    reg << temp << " " <<std::flush;
    while(getchar()!= '\n');
    std::cout << "Password: " <<std::endl;
    std::cin >> temp;
    reg << temp << " " <<std::flush;
    reg << std::endl;
    
} 

std::vector<Account>& load_file(std::vector<Account>& acc_vec){
    std::string line;
    ifstream load("password.txt");
    while(getline(load, line)){
        Account acc_temp;
        istringstream record(line);
        record >> acc_temp.siteName 
               >> acc_temp.accName 
               >> acc_temp.password;
        acc_vec.push_back(acc_temp);
    }

    return acc_vec;
   
}

void accountMatch(std::vector<Account>& acc_vec, std::string str){
    bool flag = 0;
    for(std::vector<Account>::size_type i=0;
        i< acc_vec.size(); ++i){
            if(str == acc_vec[i].siteName){
                flag = 1;
                std::cout<< "Site Name: "<< acc_vec[i].siteName<<"\n"
                    << "Account Name: "<< acc_vec[i].accName<<"\n"
                    << "password: "<< acc_vec[i].password<<"\n";        
            }
    }
    if(flag == 0){
        std::cout<< "NO Account Matched:( " <<std::endl;
    }
    
}
            
            
            
    
 