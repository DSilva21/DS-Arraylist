#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List*plist, LData data)
{
	if (plist->numOfData >= LIST_LEN) //더 이상 저장할 공간이 없다면
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data; // 데이터 저장
	(plist->numOfData)++; //저장된 데이터의 수 증가
}

int LFirst(List*plist, LData*pdata)
{
	if (plist->numOfData == 0) //저장된 데이터가 없으면
		return FALSE;
	(plist->curPosition) = 0; //참조위치 초기화, 첫 번째 데이터의 참조를 의미한다.
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List*plist, LData*pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)  //더 이상 참조할 데이터가 없다면
		return FALSE;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List*plist)
{
	int rpos = plist->curPosition;  //삭제할 데이터의 인덱스값 참조
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos]; //삭제할 데이터를 임시로 저장

	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
