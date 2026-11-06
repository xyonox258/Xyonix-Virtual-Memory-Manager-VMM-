#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int stack_use = 20 ,heap_use = 0;
int stack_index = 0,heap_count = 0;
char act_stat[9] = "INACTIVE";
struct st_type
{
	char name[50];
	char value[100];
};
struct heap_type
{
	char name[50];
	char value[100];
	int Token;	
};
struct st_type* array[8];
struct heap_type* Array[10];
void stack_display(int stack_use)
{
	if(stack_use <= 20)printf("[oo........] %d",stack_use);
	else if(stack_use <= 40)printf("[oooo......] %d",stack_use);
	else if(stack_use <= 80)printf("[oooooo....] %d",stack_use);
	else if(stack_use <= 90)printf("[oooooooo..] %d",stack_use);
	else{
		printf("[oooooooooo] %d",stack_use);
	}
}
void heap_display(int heap_use)
{
	if(heap_use == 0)printf("[..........] %d",heap_use);
	else if(heap_use <= 10)printf("[o.........] %d",heap_use);
	else if(heap_use <= 20)printf("[oo........] %d",heap_use);
	else if(heap_use <= 40)printf("[oooo......] %d",heap_use);
	else if(heap_use <= 80)printf("[oooooo....] %d",heap_use);
	else if(heap_use <= 90)printf("[oooooooo..] %d",heap_use);
	else{
		printf("[oooooooooo] %d",heap_use);
	}
}
void Run_Window()
{
	struct heap_type *input = (struct heap_type*)malloc(sizeof(struct heap_type)); 
	int i,j,k;
	printf("\t\t\t\t");
	for(i=0;i<=80;i++)
	{
		printf("=");
	}
	printf("\n");
	printf("\t\t\t\t\t\t . Xyonix Virtual Memory Manager (Run Window) .\n");
	printf("\t\t\t\t");
	for(j=0;j<=80;j++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("\t\t\t\t[ Access Variables here ]\t\t[Dynamic Memory With Token by use ALLoc()]\n");
	printf("\t\t\t\t * Operations & Syntax Guide : \n");
	printf("\t\t\t\t- Access Static Variable  : Acc(Variable_name);          -> [Accessing.. Static Variable]\n");
	printf("\t\t\t\t- Access Dynamic Variable : Dacc(Token);                 -> [Accessing.. Dynamic Variable]\n");
	printf("\t\t\t\t- Dynamic Allocation      : Alloc(variable_name);        -> [Dynamic Allocation]\n");
	printf("\t\t\t\t- Update Dynamic Value    : Update(Token,New_Value);     -> [Update Value of Dynamic Variable]\n");
	printf("\t\t\t\t- Free Dynamic Memory     : Free(Token);                 -> [Free Dynamic Memory]\n");
	printf("\t\t\t\t- Go Back to Main Menu    : Back;                        -> [GO BACk]\n");
	printf("\t\t\t\t !Error : Wrong Syntax will Crash the Program.\n");
	printf("\t\t\t\t");
	for(k=0;k<=80;k++)
	{
		printf("-");
	}
	printf("\n");
	printf("\t\t\t\t\t\t Xyonix-Terminal v1.0.0\n");
	while(1)
	{
		printf("\n");
		printf("\t\t->>> ");
		char in[20],var_name[50],value[100];
		int Token;
		scanf("%s",&in);
		if(sscanf(in,"Alloc(%[^)]);",input->name) == 1)
		{
			if(heap_use == 100)
			{
				printf("\t\t![Failure] Memory Allocation Failed! Heap Memory is Full.\n");
				continue;
			}
			else
			{
				srand(time(NULL));
				int randtk = (rand() % 1000) +1;
				input->Token = randtk;
				Array[heap_count] = input;
				heap_count = heap_count+1;
				heap_use = heap_use + 10;
				strcpy(act_stat,"ACTIVE");
				printf("\t\t [Success] Variable '%s' Successfully Allocated in Heap Memory.\n",input->name);
				printf("\t\t [Property] Mutable & Dynamic Allocaton (Value can be updated)\n");
				printf("\t\t Generated Token    : %d (use this to Update, Access or Free)\n",input->Token);
				printf("\t\t [HEAP MEMORY STATUS]\n");
				printf("\t\t - Bytes Allocated  : %d Bytes(Based on character length)\n",strlen(input->value));
				printf("\t\t - Total HEAP used  : %d%%\n",heap_use);
				printf("\t\t - Available Slots  : %d Variables Remaining\n",(100-heap_use)/10);
				printf("\t\t CRITICAL WARNING   : If you lose this Token, Memory will LEAK!\n");
				printf("\t\t  This Memory block cannot be recovered until you Refresh/Reset Memory\n");
				continue;
			}
		}
		else if(sscanf(in,"Acc(%[^)]);",var_name) == 1)
		{
			int i,flag=0;
			for(i=0;i<10;i++)
			{
			if(array[i] != NULL)
			{
				if(strcmp(array[i]->name,var_name) == 0)
				{
					flag = 1;
					printf("\t\t [Success] Static Variable '%s' accessed successfully.\n",array[i]->name);
					printf("\t\t Value Found :  %s\n",array[i]->value);
					printf("\t\t Property    : Immutable & Static Allocation.\n");
				}
			}
			}
				if(flag == 0)
				{
					printf("\t\t Error : Variable Not Found Error\n");
					continue;
				}
		}
		else if(sscanf(in,"Dacc(%d);",&Token) == 1)
		{
			int ct,flag1 = 0;
			for(ct=0;ct<10;ct++)
			{
				if(Array[ct] != NULL)
				{
				if(Token == Array[ct]->Token)
				{
					flag1 = 1;
					printf("\t\t [Success] Dynamic Variable '%s' accessed successfully.\n",Array[ct]->name);
					printf("\t\t Value Found :  %s\n",Array[ct]->value);
					printf("\t\t Property    : Mutable & Dynamic Allocation.\n");	
				}
				}
			}
					
			if(flag1==0)
			{
				printf("\t\t Error : Variable Not Found Error\n");
				continue;	
			}
		}
		else if(sscanf(in,"Update(%d,%[^)]);",&Token,value) == 2)
		{
			int yt,flag = 0;
			for(yt=0;yt<10;yt++)
			{
				if(Array[yt] != NULL)
				{
					if(Array[yt]->Token == Token)
					{
						strcpy(Array[yt]->value ,value);
						flag = 1;
					}
				}
			}
			if(flag == 1)
			{
				printf("\t\t [Updated] Value changed successfully!\n");
				printf("\t\t Memory State : Overwrote Previous Value -> New Value.\n");
				printf("\t\t Property     : Mutable & Dynamic Allocation.\n");
			}
			else
			{
				printf("\t\t Error : Variable Not Found Error\n");
			}
		}
		else if(sscanf(in,"Free(%d);",&Token) == 1)
		{
			int it,flag = 0;
			for(it=0;it<10;it++)
			{
				if(Array[it] != NULL)
				{
					if(Array[it]->Token == Token)
					{
						flag = 1;
						free(Array[it]);
						Array[it] = NULL;
						printf("\t\t [Released] Memory deallocated successfully!\n");
						printf("\t\t Memory State : Token %d has been wiped from Heap\n",Token);
						heap_use = heap_use - 10;
						if(heap_use == 0)strcpy(act_stat,"INACTIVE");
					}
				}
			}
			if(flag == 0)
			{
				printf("\t\t Error : Unallocated MEMORY access Error\n");
				continue;
			}
		}
		else if(strcmp(in,"Back;") == 0)break;
		else
		{
			printf("\t\t Eror : Syntax Error");
			continue;
		}
	}
		
}

void Editor()
{
	struct st_type *input = (struct st_type*)malloc(sizeof(struct st_type)); 
	int i,j,k;
	printf("\t\t\t\t");
	for(i=0;i<=80;i++)
	{
		printf("=");
	}
	printf("\n");
	printf("\t\t\t\t\t\t . Xyonix Virtual Memory Manager (Editor Window) .\n");
	printf("\t\t\t\t");
	for(j=0;j<=80;j++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("\t\t\t\t\t[Action: Define Variables Here]\t\t[Fixed Memory Without Token]\n");
	printf("\t\t\t\t\tSyntax : <Variable_name> -> Press Enter -> <Value> -> Press Enter\n");
	printf("\t\t\t\t\t[Warning: Duplicate variable names will cause a program crash.]\n");
	printf("\t\t\t\t");
	for(k=0;k<=80;k++)
	{
		printf("-");
	}
	while(1)
	{
		printf("\n\n");
		printf("\t\t\t\tEnter Variable Name : \n \t\t\t\t->>> ");
		scanf(" %s",&input->name);
		printf("\n");
		printf("\t\t\t\tEnter Value : \n \t\t\t\t->>> ");
		scanf(" %s",&input->value);
		printf("\n");
		if(stack_use == 100)
		{
			printf("\t\t\t\t![Failure] Memory Allocation Failed! Stack Memory is Full.\n");
			printf("\t\t\t\t Press Any Key For Go Back : \n \t\t\t\t->>> ");
			char back;
			scanf(" %c",&back);
			printf("\n");
			system("cls");
			break;
		}
		else
		{
			array[stack_index] = input;
			stack_index = stack_index + 1;
			stack_use = stack_use + 10;  
			printf("\t\t\t\t[Success] Variable '%s' Successfully Allocated in Static Memory.\n",input->name);
			printf("\t\t\t\t[Property] This Static Variable is IMMUTABLE (Value cannot be changed).\n");
			printf("\t\t\t\t[STACK MEMORY STATUS]\n");
			printf("\t\t\t\t- Bytes Allocated  : %d Bytes(Based on character length)\n",strlen(input->value));
			printf("\t\t\t\t- Total STACK used : %d%%\n",stack_use);
			printf("\t\t\t\t- Available Slots  : %d Variables Remaining\n",(100-stack_use)/10);
			printf("\t\t\t\t Press [R] for open Run_Window : \n");
			printf("\t\t\t\t Press [C] to Define more Variables : \n");
			printf("\t\t\t\t Press Any Key for Go Back : \n \t\t\t\t->>> ");
			char b;
			scanf(" %c",&b);
			printf("\n");
			if(b == 'R')
			{
				system("cls");
				Run_Window();
				system("cls");
				break;
			}
			else if(b == 'C')continue;
			else
			{
				system("cls");
				break;
			}
			
		}
	}
}
int main()
{
	while(1)
	{
		int i,j,k,l,l1,l2,m;
		char inp;
		printf("\t\t\t\t");
		for(i=0;i<=80;i++)
		{
			printf("=");
		}
		printf("\n");
		printf("\t\t\t\t\t\t\t . Xyonix Virtual Memory Manager .\n");
		printf("\t\t\t\t");
		for(j=0;j<=80;j++)
		{
			printf("=");
		}
		printf("\n\n");
		printf("\t\t\t\t\t\t [STACK MEMORY]\n");
		printf("\t\t\t\t\t\t+ Address Range  : 0x7FFE0000 -> 0x7FFEFFFF\n");
		printf("\t\t\t\t\t\t+ Current Status : ACTIVE\n");
		printf("\t\t\t\t\t\t+ Usage Status   : ");
		stack_display(stack_use);
		printf("%%\n");
		printf("\t\t\t\t");
		for(k=0;k<=80;k++)
		{
			printf("-");
		}
		printf("\n\n");
		printf("\t\t\t\t\t\t [HEAP MEMORY]\n");
		printf("\t\t\t\t\t\t+ Address Range      : 0x00A00000 -> 0x00A0FFFF\n");
		printf("\t\t\t\t\t\t+ Current Status     : %s\n",act_stat);
		printf("\t\t\t\t\t\t+ Usage Status       : ");
		heap_display(heap_use);
		printf("%%\n");
		printf("\t\t\t\t");
		for(l=0;l<=80;l++)
		{
			printf("-");
		}
		printf("\n");
		printf("\t\t\t\t\t\t[1] Open Editor Window (Define Variables)\n");
		printf("\t\t\t\t\t\t[2] Open Run Window (Access/Execute)\n");
		printf("\t\t\t\t\t\t[3] Refresh & Reset Memory\n");
		printf("\t\t\t\t\t\t[4] Safe Exit\n\n");
		printf("\t\t\t\t");
		for(m=0;m<=80;m++)
		{
			printf("=");
		}
		printf("\n");
		printf("\t\t\t\t Please choose an option (1-4):_ ");
		scanf(" %c",&inp);
		printf("\n");
		if(inp == '1')
		{
			system("cls");
			Editor();
		}
		else if(inp == '2')
		{
			system("cls");
			Run_Window();
			system("cls");
		}
		else if(inp == '3')
		{
			for(l1=0;l1<8;l1++)
			{
				if(array[l1] != NULL)
				{
					free(array[l1]);
					array[l1] = NULL;
					stack_use = stack_use - 10;
				}
			}
			for(l2=0;l2<10;l2++)
			{
				if(Array[l2] != NULL)
				{
					free(Array[l2]);
					Array[l2] = NULL;
					heap_use = heap_use - 10;
				}
			}
			strcpy(act_stat ,"INACTIVE");
			printf("\t\t\t\t [Success] Virtual Memory Refreshed & Reset Successfully!\n");
			printf("\t\t\t\t Memory State : Memory spaces re-initialized.\n");
			printf("\t\t\t\t Press [B] for  Back or Any Key for continue.\n");
			char bk;
			scanf(" %c",&bk);
			if(bk == 'B')break;
			else
			{
				system("cls");
				continue;
			}
		}
		else if(inp == '4')
		{
			break;
		}
		else
		{
			printf("\t\t\t\t !Wrong Input Try agian..");
		}
	}	
}
