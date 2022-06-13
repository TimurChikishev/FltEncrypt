#include <fltKernel.h>
#include <dontuse.h>
#include <suppress.h>
#include <WinDef.h> 
#include "common.h"
#include "WhiteList.h"

#define MAXPATHLEN		1024

LIST_ENTRY WhiteNameListHeader;
KSPIN_LOCK WhiteNameListLock;


VOID InitWhiteProcNameListAndLock()
{
	InitializeListHead(&WhiteNameListHeader);
	KeInitializeSpinLock(&WhiteNameListLock);
}


VOID AddNameToWhiteNameList(PWSTR xxName, PWSTR xxFileType)
{
	PWHITE_NAME_LIST whiteListNode;
	BOOL bRet;
	KIRQL oldIrql;

	bRet = IsNameInWhiteNameList(xxName, xxFileType);
	if (bRet)
	{
		return;
	}

	whiteListNode = (PWHITE_NAME_LIST)ExAllocatePoolWithTag(NonPagedPool, sizeof(WHITE_NAME_LIST), 'dsf ');
	if (whiteListNode == NULL)
	{
		return;
	}

	wcscpy(whiteListNode->xxName, xxName);
	wcscpy(whiteListNode->xxFileType, xxFileType);
	KeAcquireSpinLock(&WhiteNameListLock, &oldIrql);
	InsertTailList(&WhiteNameListHeader, &whiteListNode->listNode);
	KeReleaseSpinLock(&WhiteNameListLock, oldIrql);
}


VOID DelNameFromWhiteNameList(PWSTR xxName, PWSTR xxFileType)
{
	PWHITE_NAME_LIST whiteList;
	PLIST_ENTRY pListNode;
	KIRQL oldIrql;

	if (!IsListEmpty(&WhiteNameListHeader))
	{
		for (pListNode = WhiteNameListHeader.Flink; pListNode != &WhiteNameListHeader; pListNode = pListNode->Flink)
		{
			whiteList = CONTAINING_RECORD(pListNode, WHITE_NAME_LIST, listNode);
			if (wcscmp(whiteList->xxName, xxName) == 0 && wcscmp(whiteList->xxFileType, xxFileType) == 0)
			{
				KeAcquireSpinLock(&WhiteNameListLock, &oldIrql);
				RemoveEntryList(&whiteList->listNode);
				ExFreePoolWithTag(whiteList, 'dsf ');
				KeReleaseSpinLock(&WhiteNameListLock, oldIrql);
				return;

			}
		}
	}
}


BOOL IsNameInWhiteNameList(PWSTR xxName, PWSTR xxFileType)
{
	PWHITE_NAME_LIST whiteList;
	PLIST_ENTRY pListNode;

	if (!IsListEmpty(&WhiteNameListHeader))
	{
		for (pListNode = WhiteNameListHeader.Flink; pListNode != &WhiteNameListHeader; pListNode = pListNode->Flink)
		{
			whiteList = CONTAINING_RECORD(pListNode, WHITE_NAME_LIST, listNode);
			if (wcscmp(whiteList->xxName, xxName) == 0 && wcscmp(whiteList->xxFileType, xxFileType) == 0)
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}

void wcslower(PWSTR str, int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		if ((str[i] >= L'A') && (str[i] <= L'Z'))
		{
			str[i] += (L'a' - L'A');
		}
	}
}

BOOL SearchIsProtect(PWSTR DirPath, PWSTR FileName)
{
	PWHITE_NAME_LIST whiteList;
	PLIST_ENTRY pListNode;
	WCHAR* wTempPath, * wTempName;
	wTempPath = (WCHAR*)ExAllocatePoolWithTag(NonPagedPool, wcslen(DirPath), 'dsf ');
	wTempName = (WCHAR*)ExAllocatePoolWithTag(NonPagedPool, wcslen(FileName), 'dsf ');

	if (!wTempName || !wTempPath)
		return FALSE;

	RtlZeroMemory(wTempPath, wcslen(DirPath));
	RtlZeroMemory(wTempName, wcslen(FileName));

	RtlCopyMemory(wTempName, FileName, wcslen(FileName));
	RtlCopyMemory(wTempPath, DirPath, wcslen(DirPath));

	wcslower(wTempPath, wcslen(wTempPath));

	wcslower(wTempName, wcslen(wTempName));

	 
	if (wcscmp(L".", wTempName) == 0 || wcscmp(L"..", wTempName) == 0)
		return FALSE;

	if (!IsListEmpty(&WhiteNameListHeader))
	{
		for (pListNode = WhiteNameListHeader.Flink; pListNode != &WhiteNameListHeader; pListNode = pListNode->Flink)
		{
			 
			whiteList = CONTAINING_RECORD(pListNode, WHITE_NAME_LIST, listNode);
	 
			if (wcsstr(wTempName, whiteList->xxName) && wcscmp(whiteList->xxFileType, L"ext") == 0)
			{
				goto quit;
			} 
			else if (wcsstr(wTempPath, whiteList->xxName) && wcscmp(whiteList->xxFileType, L"dir") == 0)
			{
				goto quit;
			} 
			else if (wcscmp(whiteList->xxName, wTempPath) == 0 && wcsstr(wTempName, whiteList->xxFileType))
			{
				goto quit;
			}
		}
	}
	return FALSE;

quit:
	if (wTempName)
	{
		ExFreePoolWithTag(wTempName, 'dsf ');
	}
	if (wTempPath)
	{
		ExFreePoolWithTag(wTempPath, 'dsf ');
	}
	return TRUE;
}

VOID ClearWhiteNameList()
{
	PWHITE_NAME_LIST whiteList;
	PLIST_ENTRY pListNode;
	KIRQL oldIrql;

	KeAcquireSpinLock(&WhiteNameListLock, &oldIrql);
	while (!IsListEmpty(&WhiteNameListHeader))
	{
		pListNode = RemoveTailList(&WhiteNameListHeader);
		whiteList = CONTAINING_RECORD(pListNode, WHITE_NAME_LIST, listNode);
		if (whiteList)
		{
			ExFreePoolWithTag(whiteList, 'dsf ');
		}
	}
	KeReleaseSpinLock(&WhiteNameListLock, oldIrql);
}