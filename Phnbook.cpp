#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

 typedef struct dnode
{
    char number[50];
        char gmail[40];
        char name[30];
       struct dnode *prev,*next;
}dnode;

  struct dnode *head=NULL,*temp,*ptr;
     struct dnode *ptr1, *ptr2, *dup;
   
  
      void copy(char n[],char r[],char g[])
{
               strcpy(temp->name,n);
                strcpy(temp->number,r);
               strcpy(temp->gmail,g);
               temp->next=NULL;
               temp->prev=NULL;
}
  // (dnode *)malloc(sizeof(dnode))
  void accept()
{
        char number[50];
        char gmail[50];
        char name[50];
    char ans;
      do
        {
    cout<<"ENTER NAME      :";
    cin>>name;
    // cin.getline (name,30);
    cout<<"ENTER NUMBER    :";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>number;
    }
    cout<<"ENTER G-MAIL    :";
    cin>>gmail;
    temp=(dnode *)malloc(sizeof(dnode));
    copy(name,number,gmail);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<"DO YOU WANT TO CONTINUE ADDING CONTACT?????????";
	     printf(" TO CONTINUE ENTER 'Y':");
    cin>>ans;
}while(ans=='y' || ans=='Y');

}
void insert()
    {
        accept();
    }
void display()
{if(head==NULL){
cout<<"YOUR PHONEBOOK IS EMPTY\n\n";
    return;
}
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}
     void sort()
    {
        dnode *i,*j;
        int temp;
        char n[50];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);               
                   strcpy(i->name,j->name);        
                   strcpy(j->name,n);
                   strcpy(n,i->number);
                   strcpy(i->number,j->number);
                   strcpy(j->number,n);
                   strcpy(n,i->gmail);
                   strcpy(i->gmail,j->gmail);
                   strcpy(j->gmail,n);
                }
            }
        }
     
    }
    
    
    void deletecontact(char s[50])
    {
        if(head==NULL){
cout<<"YOUR PHONEBOOK IS EMPTY\n\n";
    return;
}
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else if(ptr->next==NULL)
            {
                c=2;
            }
            ptr=ptr->next;
        }
       if(c==2)  {
            cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
        }
        else if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
      else  if(ptr==head && ptr->next!=NULL)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        else  if(ptr==head && ptr->next==NULL)
        {
            head=NULL;
           
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
     else   if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
     
       
    }
     void searchbyname(char na[50])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                cout<<"NAME FOUND"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
    void searchbynumber(char num[50])
    {
     ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                cout<<"NUMBER FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }   
    }
    void searchbygmail(char gm[50])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->gmail)==0)
            {
                cout<<"G-MAIL FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
		        
            }
            ptr=ptr->next;
        }
    }
    void update(char n[50])
    {
        char ans;
        int c; int x=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                x=1;
                do
                {
                    cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"ENTER NEW-NAME=";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"ENTER NEW PHONE-NUMBER?";
                    cin>>ptr->number;
                    while(strlen(ptr->number)!=10)
    {
    cout<<"ENTER VALID NUMBER  :";
    cin>>ptr->number;
    }
                    break;
                    case 3:
                    cout<<"ENTER NEW G-MAIL";
                    cin>>ptr->gmail;
                    break;
                }
                cout<<"DO YOU WANT TO CONTINUE UPDATING?";
                     printf(" TO CONTINUE ENTER 'Y':");
                cin>>ans;
                }while(ans=='y' ||ans=='Y');
            }
            ptr=ptr->next;
        }            if(x==0)
                    cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
    }

int main()
{
    char n[50];
   
    char name[50];
    char number[50];
    char gmail[50];
     char ans;
    int ch,a;
    cout<<"**************              PHONE BOOK by [rahul]            ********************";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,50);
    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\nLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";
    accept();
    sort();
     do
    {
    cout<<"\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) SEARCH\n";
    cin>>ch;
    switch(ch)
    {
    case 2:
   insert();
   sort();
    break;
    
    case 1:
    //sort();
    display();
    break;
    case 3:
    
        cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
        cin>>n;
      update(n);
      sort();
    break;
    case 4:
    cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
    cin>>name;
    deletecontact(name);
    break;
   
    case 5:
    do
    {
    cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL:";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"ENTER THE NAME TO BE SEARCHED\n";
        cin>>name;
        searchbyname(name);
        break;
        case 2:
        cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
        cin>>number;
        searchbynumber(number);
        break;
        case 3:
        cout<<"ENTER THE GMAIL TO BE SEARCHED\n";
        cin>>gmail;
        searchbygmail(gmail);
        break;
        default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
    }
    cout<<"DO YOU WANT TO CONTINUE SEARCHING?????????";
        printf(" TO CONTINUE ENTER 'Y':");
    cin>>ans;
}while(ans=='y'||ans=='Y');

    break;
   
    default:cout<<"\nNO PROPER INPUT GIVEN..\n";
    }
    cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
      printf(" TO CONTINUE ENTER 'Y':");
    cin>>ans;
}while(ans=='y'|| ans=='Y');

    return 0;
}

