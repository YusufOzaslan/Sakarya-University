#include "Iterator.hpp"

/*
 * @file			B201210033
 * @description		Iki yönlü bağlı liste ile dizi benzeri veri yapısı oluşturan program
 * @course			1. Ogretim C grubu
 * @assignment 		1. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan   yusuf.ozaslan@ogr.sakarya.edu.tr
 */

Iterator::Iterator()
{
    current = NULL;
}
Iterator::Iterator(Node *node)
{
    current = node;
}
bool Iterator::hasNext()
{
    return current != NULL;
}
void Iterator::Next()
{
    current = current->next;
}
void Iterator::Previous()
{
    current = current->prev;
}
const string Iterator::Retrieve()
{
    return current->data;
}