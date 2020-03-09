#include "HANDLING.h"

//----if the linked list is circular -> return true, else -> return false
bool TestCircularList(LIST* L)
{
	if (L->head != NULL)
	{
		if (L->tail->next == L->head)
			return true;
	}
	return false;
}
