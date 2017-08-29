#include <stdio.h>
#include "Arraylist.h"

int main(void)
{
	//ArrayList�� ���� �� �ʱ�ȭ

	List list;
	int data;
	ListInit(&list);
	int sum = 0;

	//0~9�� ������ ����//
	int i;
	for (i = 0; i < 10; i++)
	{
		LInsert(&list, i);
	}
	

	
	if (LFirst(&list, &data)) //ù��° ������ ��ȸ
	{
		
		sum += data;
		while (LNext(&list, &data)) //�� ��° ������ ������ ��ȸ
			sum += data;

	}
	printf("���� ����Ʈ�� ����� ���� �� ��: %d\n",sum);


	//����Ʈ�� ����� ���� 2�ǹ��, 3�� ����� Ž���Ͽ� ��� ����/ /

	if (LFirst(&list, &data))
	{
		if (data %2==0 || data%3==0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}


	//���� �� ���� ������ ��ü ���//
	

	if (LFirst(&list, &data))
	{
		printf("%d   ", data);

		while (LNext(&list, &data))
			printf("%d  ", data);

	}
	printf("\n\n");
	getchar(); //��� ���� ����
	return 0;

}