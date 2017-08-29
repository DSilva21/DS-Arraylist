#include <stdio.h>
#include "Arraylist.h"

int main(void)
{
	//ArrayList의 생성 및 초기화

	List list;
	int data;
	ListInit(&list);
	int sum = 0;

	//0~9의 데이터 저장//
	int i;
	for (i = 0; i < 10; i++)
	{
		LInsert(&list, i);
	}
	

	
	if (LFirst(&list, &data)) //첫번째 데이터 조회
	{
		
		sum += data;
		while (LNext(&list, &data)) //두 번째 이후의 데이터 조회
			sum += data;

	}
	printf("현재 리스트에 저장된 값의 총 합: %d\n",sum);


	//리스트에 저장된 값중 2의배수, 3의 배수를 탐색하여 모두 삭제/ /

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


	//삭제 후 남은 데이터 전체 출력//
	

	if (LFirst(&list, &data))
	{
		printf("%d   ", data);

		while (LNext(&list, &data))
			printf("%d  ", data);

	}
	printf("\n\n");
	getchar(); //즉시 종료 방지
	return 0;

}