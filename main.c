#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TimeString.h"

// Create a new Entry
void add_entry()
{
	FILE *fp;
	int i = 0;
	printf("\nStart Writting...");
	// Just Storing Time and a line break as default for every file ------>
	char Date_Time[50];
	sprintf(Date_Time, "\n%s\n@%s\nDear Diary,\n\n", DD_Str, TT_Str);
	printf("%s\n", Date_Time);
  

	printf("Enter a multi line string( press ';' to end input)\n");
	// scanf("%[^;]s", text);
	size_t n = 10;
	char *buf = NULL;
	getdelim(&buf, &n, '\;', stdin);


	if (buf == NULL)
	{
		printf("Error: out of memory ...\n");
		exit(1);
	}

	fp = fopen(DD_Str, "a+");
	if (fp == NULL)
	{
		printf("Failed to Open the File, Please check the file name\n");
		exit(0);
	}

	fputs(Date_Time, fp);
	fputs(buf, fp);


	fclose(fp);
}
// Opening Diary
void open_Diary(void)
{
	char *file_name;
	printf("Enter the date of Dairy like DD-MM-YY (23-4-2023) \n");
	scanf("%s", file_name);

	FILE *file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("%s\n", "No Dairy exist");
	}
	else
	{
		char c;
		while ((c = fgetc(file)) != EOF) // Read the file contents and print them.
		{
			printf("%c", c);
		}
	}
	fclose(file);
}
// Displaying Help Menu
void help_menu()
{
	printf("\nDear-Diary Help Menu ~~~~~~~~\nDear-Diary is a Simple & Elegant Diary Writting Software that provides an easy to use CLI Interface.\nYou can support the development by forking the Github repository at 'https://github.com/Naman2608/diary'\n");
	printf("Usage : main <command>");
	printf("\nAvailable Commands : \n");
	printf("-new : Create a New Diary Entry\n-h : Open Help Menu\n-o : Open an old Diary Entry\n");
}

// Handling invalid arguments
void invalid_args()
{
	printf("Invalid Argument(s), Please use '-h' for more information\n");
}

int main(int argc, char const *argv[])
{
	int tm_isdst; /* Daylight Savings Time flag */
	getTheTime();
	// printf("THE TIME IS : %s\n", TT_Str);
	// int i = 0;
	if (argc > 1)
	{
		printf("%d Argument(s) Recieved,\n", argc - 1); // Checking the Arguments
		for (int i = 1; i < argc; i++)
		{
			printf("Argument %d : %s\n", i, argv[i]);
			// Redirecting to help menu
			if (!strcmp(argv[i], "-h"))
			{
				help_menu();
			}
			// Redirecting to New Entry
			else if (!strcmp(argv[i], "-new"))
			{
				add_entry();
			}
			// Opening the diary
			else if (!strcmp(argv[i], "-o"))
			{
				open_Diary();
			}
			// Handling any other argument entered other than above
			else
			{
				invalid_args();
			}
		}
	}
	// Handling no arguments passed
	else
	{
		printf("tm_isdst %d-> ", tm_isdst);
		help_menu();
		printf("\n---------------------------------------------\nPlease use '-new' for Writing about you day \n");
	}
	return 0;
}
