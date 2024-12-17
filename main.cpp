#include "Functions.h"

extern const int size_arr = 10;

int Menu()
{
	int stateMenu;
	printf("%s","�������� ��������:\n");
	printf("%s","(1) - �������� ������\n");
    printf("%s","(2) - �������� ����\n");
    printf("%s","(3) - �������� � ����� ����\n");
    printf("%s","(4) - ����� �� ���������\n");
	printf("%s","> ");
	scanf("%d", &stateMenu);
	return(stateMenu);
}

int main()
{
	system("@chcp 1251 > NUL 2>&1");
	int answer;
	int count = 0;

	//file dlya chteniya
	char filename[128];

	//massiv structur
	book catalogue[size_arr];
	count = ReadFile(catalogue);

do
	{
	    clearConsole();
		answer = Menu();
		switch (answer)
		{
		case 1:
		    {
		    clearConsole();
		    ShowFile(count, catalogue, size_arr);
		    break;
		    }
        case 2:
            {
                ofstream NewFile(filename);
                for(int i = 0;i<count;i++)
                {
                    NewFile << catalogue[i].author << ";" << catalogue[i].name << ";" << catalogue[i].year << ";" << catalogue[i].price << ";" << catalogue[i].amount << "\n";
                }
                NewFile.close();
                puts("���� ������� �������");
                system("pause");
                break;
            break;
            }
        case 3:
            {
                char newfilename[64];
                printf("%s","\n������� ����� �������� �����(������ ������): ");
                scanf("%s", newfilename);
                getchar();
                ofstream NewFile(newfilename);
                for(int i = 0;i<count;i++)
                {
                    NewFile << catalogue[i].author << ";" << catalogue[i].name << ";" << catalogue[i].year << ";" << catalogue[i].price << ";" << catalogue[i].amount << "\n";
                }
                NewFile.close();
                puts("���� ������� �������");
                system("pause");
                break;
            }
        case 4:
            break;
		default:
		    {
			printf("%s","�������� �����. ���������� ��� ���");
			break;
		    }
		}
	}
	while (answer != 4);
}
