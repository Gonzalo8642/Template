/***********************************************************
CSCI 241 - Assignment 1 - Fall 2017

Progammer: Gonzalo Pantoja
Z-ID: z1812839
Section: 4
TA: Abdul Subhan Moin Syed
Date Due: September 14, 2017

Purpose: Read a file of records into an array of objects, 
	 then loop through the array and print the objects. 
************************************************************/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>


using namespace std;

class Provider
{
	public:
		Provider();
	
		void print();
			
		void setProviderNumber(string);
		void setSpecialty(string);
		void setName(string,string,string,string);
		void setAddress1(string);
		void setAddress2(string);
		void setCity(string);
		void setState(string);
		void setZip(string);
		void setPhoneNumber(string);
		
	
	private:
		char providerNumber[7];
		char specialty[41];
		char name[41];
		char address1[41]; 
		char address2[30];
		char city[21];
		char state[3];
		char zip[6];
		char phoneNumber[15];
		
};

int main()
{

	
	string providerVar,
			specialtyVar,
			lastNameVar,
			firstNameVar,
			middleInitialVar,
			titleVar,
			address1Var,
			address2Var,
			cityVar,
			stateVar,
			zipVar,
			phoneNumberVar;
	
	
	ifstream infile;					//input file stream variable
	infile.open( "providers.csv" );		//open file for reading
	
	if( infile.fail() )					//if input file failed to open
	{
		cout<<"File didn't open correctly" << endl;
		exit(-1);						//stop immediately
	}
	
	

	//while info is still available in file 
	while ( !infile.eof() )
	{
		//read line until ',' dilimiter and set to respective variables
		getline(infile,providerVar,',');
		getline(infile,specialtyVar,',');
		getline(infile,lastNameVar,',');
		getline(infile,firstNameVar,',');
		getline(infile,middleInitialVar,',');
		getline(infile,titleVar,',');
		getline(infile,address1Var,',');
		getline(infile,address2Var,',');
		getline(infile,cityVar,',');
		getline(infile,stateVar,',');
		getline(infile,zipVar,',');
		getline(infile,phoneNumberVar,'\n');
		
		
		//create Provider object and fill info
		Provider currentProvider;
		currentProvider.setProviderNumber(providerVar);
		currentProvider.setSpecialty(specialtyVar);
		currentProvider.setName(lastNameVar,firstNameVar,middleInitialVar,titleVar);
		currentProvider.setAddress1(address1Var);
		currentProvider.setAddress2(address2Var);
		currentProvider.setCity(cityVar);
		currentProvider.setState(stateVar);
		currentProvider.setZip(zipVar);
		currentProvider.setPhoneNumber(phoneNumberVar); 
		
		//print information
		currentProvider.print();
	}
	
		
	//closes file
	infile.close();

return 0;
}

/***************************************************************
Method: Provider

Use:      default constructor that initializes the private data members

Arguments: none

Returns:   nothing
***************************************************************/
Provider::Provider()
{
		strcpy(providerNumber,"");
		strcpy(specialty, " ");
		strcpy(name, " ");
		strcpy(address1, " ");
		strcpy(address2, " ");
		strcpy(city, " ");
		strcpy(state, " ");
		strcpy(zip, " ");
		strcpy(phoneNumber, " ");
} 


/***************************************************************
Method: Print

Use:      Prints the data members neatly

Arguments: none

Returns:   nothing
***************************************************************/
void Provider::print()
{
	cout<<"#"<<providerNumber<<endl;
	cout<<name<<endl;
	cout<<specialty<<endl;
	
	cout<<address1<<endl;
	cout<<address2<<endl;
	cout<<city<<", "<<state<<" "<<zip<<endl;
	cout<<phoneNumber<<endl;
	cout<<"\n"<<endl;
}


/***************************************************************
Method: setProviderNumber(string)

Use:      sets private ProviderNumber variable

Arguments: string variable 

Returns:   nothing
***************************************************************/

void Provider::setProviderNumber(string x)
{
	strcpy(providerNumber, x.c_str());
}


/***************************************************************
Method: setSpecialty(string)

Use:      sets private Specialty variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setSpecialty(string x)
{
	strcpy(specialty,x.c_str());
}


/***************************************************************
Method: setName(string,string,string,string)

Use:      sets private Name variable 

Arguments: four string variables. last,first,middle initial, title

Returns:   nothing
***************************************************************/
void Provider::setName(string last, string first, string mi, string title)
{
	strcpy(name,last.c_str());
	strcat(name, ", ");
	strcat(name,first.c_str());
	strcat(name, " ");
	strcat(name,mi.c_str());
	strcat(name, ", ");
	strcat(name,title.c_str());
}


/***************************************************************
Method: setAddress1(string)

Use:      sets private address1 variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setAddress1(string x)
{
	strcpy(address1, x.c_str());
}

/***************************************************************
Method: setAddress2(string)

Use:      sets private address2 variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setAddress2(string x)
{
	strcpy(address2, x.c_str());
}


/***************************************************************
Method: setCity(string)

Use:      sets private city variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setCity(string x)
{
	strcpy(city, x.c_str());
}


/***************************************************************
Method: setState(string)

Use:      sets private state variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setState(string x)
{
	strcpy(state, x.c_str());
}


/***************************************************************
Method: setZip(string)

Use:      sets private zip variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setZip(string x)
{
	strcpy(zip, x.c_str());
}


/***************************************************************
Method: setPhoneNumber(string)

Use:      sets private phoneNumber variable 

Arguments: string variable

Returns:   nothing
***************************************************************/
void Provider::setPhoneNumber(string x)
{
	strcpy(phoneNumber, x.c_str());
}
