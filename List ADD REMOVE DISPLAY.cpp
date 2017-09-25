#include <iostream>
using namespace std;

struct node{
	int number;
	node *next;
};

bool isEmpty(node *head);

char menu();
void insertAsFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);;
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head)
{
	if(head==NULL) 
	return true;
	else
	return false;
}


char menu()
{
char choice;
cout <<"--------------------";
cout << "\n      MENU:\n";
cout <<"--------------------\n";
cout << "1.Dodaj Element\n";	
cout << "2.Usun Element\n";
cout << "3.Pokaz Liste\n";
cout << "4.Wyjscie\n";

cin >> choice;
return choice;
}


void insertAsFirstElement(node *&head, node *&last, int number)
{
	node *temp=new node; // utworzenie elementu
	temp->number=number; // przypisanie wartosci number
	temp->next=NULL; // nie ma wskazania na nastepny element (1 element listy)
	head=temp; // nowo dodany element staje sie glowa
	last=temp; //nowo dodany element staje sie ogonem
	
}

void insert(node *&head, node *&last, int number)
{
	if(isEmpty(head))
	{
		insertAsFirstElement(head,last,number);
	}else
	{
		node *temp=new node;
		temp->number=number;
		temp->next=NULL;
		
		last->next=temp; // ostatni element listy wskazuje na nowoutworzony
		last=temp; //
		
	}
}

void remove(node *&head, node *&last)
{
	if(isEmpty(head))
	cout << "Lista jest pusta \n";
	else if (head==last)
	{
		delete head;
		head=NULL;
		last=NULL;
	}
	else{
		node *temp=head;
		head=head->next;
		delete temp;
	}
}

void showList(node *current)
{
	if(isEmpty(current))
	cout << "Lista jest pusta \n";
	else
	{
		cout << "========================";
		cout << "\nLista zawiera: \n";
		
		while(current!=NULL)
		{
			cout << current->number << endl;
			current=current->next;		
		}
		cout << "========================\n";
	}
		
	
}
int main()
{
	node *head=NULL; //wskazanie na glowe listy
	node *last=NULL; // wskazanie na ostatni element
	
	char choice;
	int number;
	
	do{
		choice=menu();
		
		switch(choice)
		{
			case '1': cout << "Wybierz number";
				cin >> number;
				insert(head,last,number);
				break;
			case '2': remove(head, last);
				break;
			case '3': showList(head);
				break;
			default: cout << "Wyjscie\n";
	}
	}while(choice!='4');
	
	
	
	return 0;
}
