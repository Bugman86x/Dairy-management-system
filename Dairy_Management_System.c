#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <dos.h>
#include <conio.h>

struct customer
{
	char name[20];
	char addr[30];
	char date[12];
	int acc;
	int phone;
	int aid;

}

cust;

struct custentry
{
	int id, acc;
	char category[10], name[20];
	char date[12];
	float fat, degree, rate, qty, amount;
	float tamount;

}

entry;

FILE * fp;
FILE * ft;
int aid;
long sz = sizeof(cust);

void menu();
void newusr();
void addentry();
void find();
void del();
void display();
void showentry();
void findentry();
void modify();
void intro();
void exitt();
void autoid();

void main()
{
	intro();

}

void menu()
{
	system("color 7");

	int ch;

	system("cls");

	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t [1] Create a new account\n");
	printf("\t\t\t [2] Add entrys\n");
	printf("\t\t\t [3] Check the details of existing account\n");
	printf("\t\t\t [4] Update information of existing account\n");
	printf("\t\t\t [5] Remove existing account\n");
	printf("\t\t\t [6] View customer entry\n");
	printf("\t\t\t [7] View customer's list\n");
	printf("\t\t\t [8] View all entrys\n");
	printf("\t\t\t [9] Trancefer money\n");
	printf("\t\t\t [0] Exit\n\n");

	printf("\t\t\t Enter your choice: ");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
			newusr();
			break;

		case 2:
			addentry();
			break;

		case 3:
			find();
			break;

		case 4:
			modify();
			break;

		case 5:
			del();
			break;

		case 6:
			findentry();
			break;

		case 7:
			display();
			break;

		case 8:
			showentry();
			break;
		case 9:
			trmoney();
			break;

		case 0:
			exitt();
			break;

		default:
			printf("\t\t\tSelect the right option!!\n");
			printf("\t\t\tPress any key to continue.\n");
			getch();
			menu();
	}
}

void newusr()
{
	char mdate[12];
	system("cls");
	int ch, opt, i;
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t\tCreate a new account\n\n");
	printf(" \t\t\t\t Enter customer name : ");
	fflush(stdin);
	gets(cust.name);
	for (i = 0; i <= strlen(cust.name); i++)
	{
		if (isdigit(cust.name[i]))
		{
			printf("\t\t\t\t Name not acceptable!!\n");
			printf("\t\t\t\t Press any key to continue \n");
			getch();
			newusr();
		}
	}

	printf("\n \t\t\t\t Enter address : ");
	fflush(stdin);
	gets(cust.addr);
	fflush(stdin);
	phone:
		printf("\n \t\t\t\t Enter phone : ");
	scanf("%d", &cust.phone);

	if (cust.phone < 1000000000 || cust.phone > 10000000000)
	{
		printf(" \t\t\t\t Please enter valid phone number!!\n");
		getch();
		goto phone;
	}

	printf(" \n\t\t\t\t Enter account number : ");
	scanf("%d", &cust.acc);

	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf(" \n\t\t\t\t Customer's Details\n\n");
	printf(" \t\t\t\t Customer Name    : %s\n", cust.name);
	printf(" \t\t\t\t Customer Phone   : %d\n", cust.phone);
	printf(" \t\t\t\t Account number   : %d\n", cust.acc);
	printf(" \t\t\t\t Customer Address : %s\n\n", cust.addr);
	save:
		printf(" \t\t\t\t press[1] to save\n");
	printf(" \t\t\t\t Press[2] to edit\n");
	printf("\t\t\t\t");

	scanf("%d", &ch);

	switch (ch)
	{
		case 1:
			autoid();
			ft = fopen("autoid.txt", "rb");
			fread(&aid, sizeof(aid), 1, ft);
			cust.aid = aid;
			fclose(ft);

			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			sprintf(mdate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			strcpy(cust.date, mdate);

			fp = fopen("cust.txt", "ab");
			fwrite(&cust, sizeof(cust), 1, fp);
			fclose(fp);

			system("cls");
			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
			printf("\t\t\t\tCustomer account created successfully\n\n");
			printf("\t\t\t\tCustomer Id      : %d\n", cust.aid);
			printf("\t\t\t\tCustomer Name    : %s\n", cust.name);
			printf("\t\t\t\tCustomer Phone   : %d\n", cust.phone);
			printf("\t\t\t\tAccount number   : %d\n", cust.acc);
			printf("\t\t\t\tCustomer Address : %s\n", cust.addr);

			printf("\n\t\t\t\tPress[1] to create another customer\n");
			printf("\t\t\t\tpress[0] to menu\n");
			printf("\t\t\t\t");
			scanf("%d", &opt);
			if (opt == 1)
			{
				newusr();
			}

			menu();

			break;

		case 2:
			newusr();
			break;

		default:
			printf("\t\t\t\tSelect the right option!!\n");
			getch();
			goto save;
			break;
	}
}

void addentry()
{
	char chategory[10];
	char cow[10] = "COW   ";
	char bufalo[10] = "BUFFALO";
	char mdate[12];
	int id, ch, opt, ct, mp = 0, f = 0;

	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t\t      Add etry\n\n");
	printf("  \t\t\t Enter the customer ID to add entry : ");
	scanf("%d", &id);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(mdate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	strcpy(entry.date, mdate);

	ft = fopen("cust.txt", "rb");

	while (fread(&cust, sizeof(cust), 1, ft) == 1)
	{
		if (id == cust.aid)
		{
			fp = fopen("cust_entry.txt", "ab+");
			f = 1;
			entry.id = cust.aid;
			entry.acc = cust.acc;
			strcpy(entry.name, cust.name);
			add:
				system("cls");
			printf("\n\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
			printf("\t\t\t\t      Add etry\n\n");
			printf("\t\t\t\tChoose the milk category : ");
			printf("\n\n\t\t\t\t[1] COW milk\n");
			printf("\t\t\t\t[2] BUFFALO milk\n");
			printf("\t\t\t\t");
			scanf("%d", &ct);
			switch (ct)
			{
				case 1:
					strcpy(entry.category, cow);
					break;

				case 2:
					strcpy(entry.category, bufalo);
					mp = 10;
					break;

				default:
					printf("\t\t\t\tEnter the right option\n");
					printf("\t\t\t\tPress any key to continue\n");
					getch();
					goto add;
			}

			printf("\t\t\t\tEnter FAT     : ");
			scanf("%f", &entry.fat);
			printf("\t\t\t\tEnter Degree  : ");
			scanf("%f", &entry.degree);
			printf("\t\t\t\tEnter QTY     : ");
			scanf("%f", &entry.qty);

			entry.rate = entry.fat *entry.degree + mp;
			entry.amount = entry.rate *entry.qty;
			entry.tamount = entry.tamount + entry.amount;

			system("cls");
			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
			printf("\t\t\t\t      Add etry\n\n");
			printf("\t\t\t\tId        : %d\n", entry.id);
			printf("\t\t\t\tCategory  : %s\n", entry.category);
			printf("\t\t\t\tFAT       : %f\n", entry.fat);
			printf("\t\t\t\tDegree    : %f\n", entry.degree);
			printf("\t\t\t\tRate      : RS %f\n", entry.rate);
			printf("\t\t\t\tQuantity  : %f LTR\n", entry.qty);
			printf("\t\t\t\tAmount    : RS %f\n", entry.amount);

			fclose(ft);
			save:
			printf("\n\t\t\t\tPress[1] to save\n");
			printf("\t\t\t\tPress[2] to edit\n");
			printf("\t\t\t\t");
			scanf("%d", &ch);
			if (ch == 1)
			{
				fwrite(&entry, sizeof(entry), 1, fp);
				fclose(fp);
				system("cls");
				printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
				printf("\t\t\t\t      Add etry\n\n");
				printf("\n\t\t\t\tEntry saved successfully\n\n");
				printf("\t\t\t\tPress[1] to  add another entry\n");
				printf("\t\t\t\tPress[0] to menu\n");
				printf("\t\t\t\t");
				scanf("%d", &opt);
				if (opt == 1)
				{
					fclose(fp);
					addentry();
				}
				else
				{
					menu();
				}
			}
			else if (ch == 2)
			{
				goto add;
			}
			else
			{
				printf("\t\t\t\tEnter the right option!!\n");
				printf("\t\t\t\tPress any key to continue\n");
				getch();
				goto save;
			}
		}
	}

	if (f == 0)
	{
		fclose(ft);
		fclose(fp);
		printf("\n\t\t\t\tCustomer not found\n\n");
		printf("\t\t\t\tPress[1] to try again\n");
		printf("\t\t\t\tPress[0] to menu\n");
		printf("\t\t\t\t");
		scanf("%d", &ch);
		if (ch == 1)
		{
			fclose(fp);
			addentry();
		}

		fclose(fp);
		menu();
	}
}

void find()
{
	int id, ch, opt, f = 0;

	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t\t      Search customer\n\n");
	printf("  \t\t\t  Enter customer ID to find customer : ");

	scanf("%d", &id);
	fp = fopen("cust.txt", "rb");
	while (fread(&cust, sizeof(cust), 1, fp) == 1)
	{
		if (id == cust.aid)
		{
			f = 1;
			system("cls");
			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n");
			printf("\t\t\t\t      Search customer\n\n");
			printf("\n\t\t\t\tcustmoer found successefully\n\n");

			printf("\t\t\t\tCustomer ID     : %d\n", cust.aid);
			printf("\t\t\t\tCustomer Name   : %s\n", cust.name);
			printf("\t\t\t\tCustomer Phone  : %d\n", cust.phone);
			printf("\t\t\t\tAccount number  : %d\n", cust.acc);
			printf("\t\t\t\tCustomer Address: %s\n", cust.addr);
			printf("\t\t\t\tDate            : %s\n", cust.date);
			fclose(fp);
			printf("\n\t\t\t\tPress[1] to find again\n");
			printf("\t\t\t\tPress[0]  to menu\n");
			printf("\t\t\t\t");
			scanf("%d", &ch);
			if (ch == 1)
			{
				find();
			}

			menu();
		}
	}

	if (f == 0)
	{
		fclose(fp);
		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
		printf("\t\t\t\t      Search customer\n\n");
		printf("\t\t\t\tCustomer not found!!\n");
		printf("\t\t\t\tpress[1] to try againg\n");
		printf("\t\t\t\tPress[0] to menu\n");
		printf("\t\t\t\t");
		scanf("%d", &opt);
		if (opt == 1)
		{
			find();
		}

		menu();
	}
}

void display()
{
	int f = 0;
	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n");
	printf("\t\t\t\t   Details of all customers\n\n\n");
	fp = fopen("cust.txt", "rb");
	printf("       Date\t    ID      Name\t     Phone NO\t Account NO   Address\n");
	while (fread(&cust, sizeof(cust), 1, fp) == 1)
	{
		f = 1;
		printf("      _________________________________________________________________________________\n");
		printf("       %s   %d   %-18s %d\t %-10d   %s\n", cust.date, cust.aid, cust.name, cust.phone, cust.acc, cust.addr);
	}

	if (fp == NULL)
	{
		fclose(fp);
		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
		printf("\t\t\t\tCustomers not found to display.\n");
		printf("\t\t\t\tPress any key to menu.\n");
		getch();
		menu();
	}

	fclose(fp);
	printf("\n\n\t\t\t\tPress any key to menu!!\n");
	getch();
	menu();

}

void del() {

  int ch;
  system("cls");
  printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
  int f = 0, id;
  printf("\n\t\t\t Enter Id to delete customer\n\t\t\t");
  scanf("%d", & id);
  fp = fopen("cust.txt", "rb");
  ft = fopen("temp.txt", "ab");
  while (fread( & cust, sizeof(cust), 1, fp) == 1) {
    if (id == cust.aid) {
      f = 1;
      printf("\n\t\t\t Selected Customer");
      printf("\n\t\t\t ID   : %d",cust.aid);
      printf("\n\t\t\t Name : %s\n",cust.name);
      printf("\n\t\t\tPress [1] to delete");
      printf("\n\t\t\tpress [0] to menu\n\t\t\t");
      scanf("%d",&ch);
      if(ch==0){
      	
      	fclose(fp);
        fclose(ft);
        remove("temp.txt");
        menu();
      	
	  }
      

    } else {
      fwrite( & cust, sizeof(cust), 1, ft);
    }

  }

  fclose(fp);
  fclose(ft);

  remove("cust.txt");
  rename("temp.txt", "cust.txt");

  if (f == 0) {
    printf("\n\t\t\t user not found\n");
    printf("\n\t\t\t press [1] to try again\n");
    printf("\n\t\t\t press [0] to menue\n");
    scanf("%d", & ch);
    if (ch == 1) {
      del();

    }
    main();
  }
  printf("\n\t\t\t User deleted successfully\n");
  printf("\n\t\t\t press any key to menue\n");
  getch();
  menu();
}

void showentry()
{
	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n");
	printf("\t\t\t\t  Details of all entries\n\n");

	fp = fopen("cust_entry.txt", "rb");

	printf("    %-10s %-5s%-8s     %-5s\t       %-8s      %-5s\t       %-10s  %s  ", "Date", "ID", "Category", "FAT", "Degree", "Rate", "QTY", "Amount\n");
	printf("________________________________________________________________________________________________________\n");

	while (fread(&entry, sizeof(entry), 1, fp) == 1)
	{
		printf(" %s    %d   %-7s    %-12f  %-12f   RS %-12f  %-12f  RS %-12f\n", entry.date, entry.id, entry.category, entry.fat, entry.degree, entry.rate, entry.qty, entry.amount);
		printf("__________________________________________________________________________________________________________\n");
	}

	fclose(fp);
	printf("\n\n\t\t\t\tPress any key to menue\n\n");
	getch();
	menu();
}

void findentry()
{
	char name[20];
	int acc;
	int id, ch, opt, opt2, f = 0;
	float tamount = 0;
	opt:
		system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t\tSelect the format\n");
	printf("\t\t\t\t[1] Table\n");
	printf("\t\t\t\t[2] 1 by 1\n\t\t\t\t");

	scanf("%d", &opt2);
	if (opt2 == 1)
	{
		printf("\t\t\t\tEnter ID to find entry : ");
		scanf("%d", &id);
		fp = fopen("cust_entry.txt", "rb");

		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");

		printf("\t\t\t\tCustomer entries\n\n");

		printf("    %-10s %-5s%-8s     %-5s\t       %-8s      %-5s\t       %-10s  %s  ", "Date", "ID", "Category", "FAT", "Degree", "Rate", "QTY", "Amount\n");
		printf("________________________________________________________________________________________________________\n");

		while (fread(&entry, sizeof(entry), 1, fp) == 1)
		{
			if (id == entry.id)
			{
				tamount = tamount + entry.amount;
				acc = entry.acc;
				strcpy(name, entry.name);

				f = 1;

				printf(" %s    %d   %-7s    %-12f  %-12f   RS %-12f  %-12f  RS %-12f\n", entry.date, entry.id, entry.category, entry.fat, entry.degree, entry.rate, entry.qty, entry.amount);
				printf("__________________________________________________________________________________________________________\n");
			}
		}

		printf("\n\t\t\t\tCustomer name : %s", name);
		printf("\n\t\t\t\tCustomer acc  : %d", acc);
		printf("\n\n\t\t\t\tToatal amount : RS %f", tamount);
		fclose(fp);
		if (f == 0)
		{
			fclose(fp);
			printf("\t\t\t\tCustomer entries not found\n");
			printf("\t\t\t\tPress[1] to try again\n");
			printf("\t\t\t\tPress[0] to menu\n\t\t\t\t");
			scanf("%d", &ch);
			if (ch == 1)
			{
				findentry();
			}

			menu();
		}

		printf("\n\n\t\t\t\tpress[1] to find another entry\n");
		printf("\t\t\t\tpress[0] to menu\n\t\t\t\t");
		scanf("%d", &opt);
		if (opt == 1)
		{
			findentry();
		}

		menu();
	}
	else if (opt2 == 2)
	{
		printf("\t\t\t\tEnter ID to find entry : ");
		scanf("%d", &id);
		fp = fopen("cust_entry.txt", "rb");

		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");

		printf("\t\t\t\tCustomer entries\n\n");
		while (fread(&entry, sizeof(entry), 1, fp) == 1)
		{
			if (id == entry.id)
			{
				f = 1;
				tamount = tamount + entry.amount;
				tamount = tamount + entry.amount;
				acc = entry.acc;
				strcpy(name, entry.name);

				printf("\t\t\t\t%s\n\n", entry.date);
				printf("\t\t\t\tId        : %d\n", entry.id);
				printf("\t\t\t\tCategory  : %s\n", entry.category);
				printf("\t\t\t\tFAT       : %f\n", entry.fat);
				printf("\t\t\t\tDegree    : %f\n", entry.degree);
				printf("\t\t\t\tRate      : RS %f\n", entry.rate);
				printf("\t\t\t\tQuantity  : %f LTR\n", entry.qty);
				printf("\t\t\t\tAmmount   : RS %f\n", entry.amount);
				printf("\t\t\t\t_____________________________\n\n");
			}
		}

		printf("\n\t\t\t\tCustomer name : %s", name);
		printf("\n\t\t\t\tCustomer acc  : %d", acc);
		printf("\n\n\t\t\t\tToatal amount : RS %f", tamount);;
		fclose(fp);
		if (f == 0)
		{
			fclose(fp);
			printf("\t\t\t\tCustomer entries not found\n");
			printf("\t\t\t\tPress[1] to try again\n");
			printf("\t\t\t\tPress[0] to menu\n\t\t\t\t");
			scanf("%d", &ch);
			if (ch == 1)
			{
				findentry();
			}

			menu();
		}

		printf("\n\n\t\t\t\tpress[1] to find another entry\n");
		printf("\t\t\t\tpress[0] to menu\n\t\t\t\t");
		scanf("%d", &opt);
		if (opt == 1)
		{
			findentry();
		}

		menu();
	}
	else
	{
		printf("\t\t\t\tSelect the right option\n");
		getch();
		goto opt;
	}
}

void modify()
{
	int id, i, f = 0, ch, opt;
	system("cls");
	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
	printf("\t\t\t\tEnter customer ID to modify : ");

	scanf("%d", &id);

	fp = fopen("cust.txt", "rb+");

	while (fread(&cust, sizeof(cust), 1, fp) == 1)
	{
		if (id == cust.aid)
		{
			edit: name: system("cls");

			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
			printf("\t\t\t\tCustomer information\n\n");
			printf("\t\t\t\tCustomer ID     : %d\n", cust.aid);
			printf("\t\t\t\tCustomer Name   : %s\n", cust.name);
			printf("\t\t\t\tCustomer Phone  : %d\n", cust.phone);
			printf("\t\t\t\tAccount number  : %d\n", cust.acc);
			printf("\t\t\t\tCustomer Address: %s\n", cust.addr);
			printf("\t\t\t\tDate            : %s\n\n", cust.date);
			printf("\t\t\t\tUpdate customer information\n\n");
			f = 1;
			cust.aid = id;

			printf("\t\t\t\tEnter new name : ");
			fflush(stdin);
			gets(cust.name);

			for (i = 0; i <= strlen(cust.name); i++)
			{
				if (isdigit(cust.name[i]))
				{
					printf("\n\t\t\t\tName not acceptetable!!\n");
					printf("\t\t\t\tPress any key to continue \n");
					getch();
					goto name;
				}
			}

			printf("\n\t\t\t\tEnter new address : ");

			fflush(stdin);
			gets(cust.addr);
			phone: printf("\n\t\t\t\tEnter new phone : ");

			scanf("%d", &cust.phone);
			if (cust.phone < 1000000000 || cust.phone > 10000000000)
			{
				printf("\t\t\t\tEnter valid phone number\n");
				getch();
				goto phone;
			}

			printf("\n\t\t\t\tEnter new account no : ");

			scanf("%d", &cust.acc);

			system("cls");

			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");

			printf("\t\t\t\tUpdated customer information\n\n");
			printf("\t\t\t\tCustomer name   : %s\n", cust.name);
			printf("\t\t\t\tCustomer address: %s\n", cust.addr);
			printf("\t\t\t\tCustomer phone  : %d\n", cust.phone);
			printf("\t\t\t\tAccount number  : %d\n\n", cust.acc);
			save: printf("\t\t\t\tPress[1] to save\n");
			printf("\t\t\t\tPress[2] edit\n\t\t\t\t");
			scanf("%d", &opt);
			if (opt == 1)
			{
				fseek(fp, -sz, 1);
				fwrite(&cust, sizeof(cust), 1, fp);
				fclose(fp);
				system("cls");
				printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
				printf("\t\t\t\tCustomer details updated successefully\n\n");
				printf("\t\t\t\tPress[1] to mofify another customer\n");
				printf("\t\t\t\tPress[0] to memu\n\t\t\t\t");
				scanf("%d", &ch);
				if (ch == 1)
				{
					modify();
				}

				menu();
			}
			else if (opt == 2)
			{
				goto edit;
			}
			else
			{
				printf("\t\t\t\tEnter the right option!!\n");
				printf("\t\t\t\tPress any key to continue\n");
				getch();
				goto save;
			}
		}
	}

	fclose(fp);
	if (f == 0)
	{
		fclose(fp);

		printf("\t\t\t\tCustomer not found to modify\n");
		printf("\t\t\t\tpress[1] to try again\n");
		printf("\t\t\t\tpress[0] to menu\n\t\t\t\t");
		scanf("%d", &ch);
		if (ch == 1)
		{
			modify();
		}

		menu();
	}
}

trmoney()
{
	int i, f = 0, id, ch, opt, acc;
	float tamount;
	char name[20], date[12];
	system("cls");

	printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");

	printf("\t\t\t\t[1] Generate bill\n");
	printf("\t\t\t\t[2] Transfer money\n \t\t\t\t");
	scanf("%d", &ch);
	if (ch == 1)
	{
		system("cls");

		for (i = 100; i <= 110; i++)
		{
			printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");

			printf("    %-10s %-8s     %-5s\t   %-8s        %-5s\t     %-10s     %s  ", "Date", "Category", "FAT", "Degree", "Rate", "QTY", "Amount\n");
			printf("________________________________________________________________________________________________________\n");

			fp = fopen("cust_entry.txt", "rb");

			while (fread(&entry, sizeof(entry), 1, fp) == 1)
			{
				if (i == entry.id)
				{
					f = 1;
					id = entry.id;
					strcpy(name, entry.name);
					tamount = tamount + entry.amount;
					printf(" %s     %-7s    %-12f  %-12f   RS %-12f  %-12f  RS %-12f\n", entry.date, entry.category, entry.fat, entry.degree, entry.rate, entry.qty, entry.amount);
					printf("__________________________________________________________________________________________________________\n");
				}
			}

			if (f == 1)
			{
				printf("\n  ID    : %d", id);
				printf("\t\t\t\t\t\t\t\t\tTotal Amount : %f", tamount);
				printf("\n  Name  : %s", name);
				printf("\t\t\t\t\t\t\t\t              _____________");

				tamount = 0;
				f = 0;
				printf("\n\nPress any key\n");
				getch();
				fclose(fp);
				system("cls");
			}

			system("cls");
		}

		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
		printf("\t\t\t\tPress any key to continue\n");
		getch();
		menu();
	}
	else if (ch == 2)
	{
		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
		printf("\t\t\tAccount     ID   Name            Total amount");
		printf("\n\t\t\t________________________________________________");
		for (i = 100; i <= 110; i++)
		{
			fp = fopen("cust_entry.txt", "rb");

			while (fread(&entry, sizeof(entry), 1, fp) == 1)
			{
				if (i == entry.id)
				{
					f = 1;
					id = entry.id;
					acc = entry.acc;
					strcpy(name, entry.name);
					tamount = tamount + entry.amount;
				}
			}

			if (f == 1)
			{
				printf("\n\t\t\t %-10d %-2d  %-15s %-15f", acc, id, name, tamount);
				printf("\n\t\t\t________________________________________________");
				tamount = 0;
				f = 0;
			}

			fclose(fp);
		}

		printf("\n\n\t\t\t\tPress[1] to transfer money\n");
		printf("\n\t\t\t\tPress[2] to menu");
		scanf("%d", &opt);
		if (opt == 1)
		{
			remove("cust_entry.txt");
			printf("\n\n\t\t\t\tMoney transfered successfully\n");
			getch();
			menu();
		}
		else
		{
			printf("\n\t\t\t\tPress any key to continue\n\n");
			getch();
			menu();
		}
	}
	else
	{
		printf("\t\t\t\tSelect the right option\n");
		getch();
		trmoney();
	}
}

void autoid()
{
	int tid;
	fp = fopen("autoid.txt", "rb");

	if (fread(&aid, sizeof(aid), 1, fp) == 1)
	{
		ft = fopen("tempid.txt", "ab");
		tid = aid;
		tid++;
		aid = tid;
		fclose(fp);

		fwrite(&aid, sizeof(aid), 1, ft);
		fclose(ft);
		remove("autoid.txt");
		rename("tempid.txt", "autoid.txt");
	}
	else
	{
		aid = 100;
		system("cls");
		printf("\n\t\t\t \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DAIRY MANAGEMENT SYSTEM \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \n\n\n");
		printf("\t\t\t\tDatabase not configured\n");
		printf("\t\t\t\tPress any key to configure a database.\n");
		getch();
		printf("\t\t\t\tDatabase configured successfully\n");
		getch();
		fp = fopen("autoid.txt", "ab");
		fwrite(&aid, sizeof(aid), 1, fp);
		rename("tempid.txt", "autoid.txt");
		fclose(fp);
	}
}

void intro()
{
	system("color 6");
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	printf("\n");
	printf("\n\t\t      [ WELLCOME TO THE DAIRY MANAGEMENT SYSTEM ]");
    printf("\n\n\t\t\t           Created by BUGMAN"); 
	printf("\n\t\t\t   ___________________________________\n");
	printf("\n\n\n\t\t\t\tPress any key to continue...\n\n\n");
	printf("\n\t\t https://github.com/Bugman86x/Dairy-management-system\n");

	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

	getch();
	menu();
}

void exitt()
{
	system("color 9");
	system("cls");
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
	printf("\n");
	printf("\n\t\t\t    [ DAIRY MANAGEMENT SYSTEM ]");
    printf("\n\n\t\t\t        Created by BUGMAN"); 
	printf("\n\t\t\t ___________________________________\n");
	printf("\n\n\n\t\t\t   Press any key to close program...\n\n");
	printf("\n\t\t https://github.com/Bugman86x/Dairy-management-system\n");
	printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

	exit(0);

}
