#include<stdio.h>
#include<stdlib.h>
struct clientData
{
	int accNum;
	char lastNAme[15];
	char firstName[10];
	double balance;
};
int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0;
	struct clientData client = { 0,"","",0.0 };

	pRead = fopen("c://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}

	pWrite = fopen("c://credit_bin.txt", "wb");
	if (pWrite == NULL)
	{
		fclose(pRead);
		return 0;
	}

	while (!feof(pRead))
	{
		fscanf(pRead, "%d%s%s%lf", &client.accNum, client.lastNAme, client.firstName, &client.balance);
		fwrite(&client, sizeof(struct clientData), 1, pWrite);

		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastNAme, client.firstName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("�HŪ����r�ɪ�ASCII��ơA���x�s���G�i�����ɮ�\n\n");
	system("pause");
	printf("Ū���G�i�����ɮסA�î榡�ƿ�X�p�U�G\n");
	if ((cfPtr = fopen("c://credit_bin.txt", "rb")) == NULL)
	{
		printf("File could not be opened\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastNAme, client.firstName, client.balance);
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}

	system("pause");
	return 0;
}