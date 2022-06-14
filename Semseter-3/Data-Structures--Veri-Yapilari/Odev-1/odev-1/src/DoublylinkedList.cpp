#include "DoublyLinkedList.hpp"
#include "Node.hpp"

/*
 * @file			B201210033
 * @description		Iki yönlü bağlı liste ile dizi benzeri veri yapısı oluşturan program
 * @course			1. Ogretim C grubu
 * @assignment 		1. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan   yusuf.ozaslan@ogr.sakarya.edu.tr
 */

DoublyLinkedList::DoublyLinkedList()
{
    root = NULL;
    size = 0;
}
Iterator DoublyLinkedList::previousPosition(int index)
{ // index kaç ise o indisteki düğüm dönrürülür
    Iterator itr(root);
    int ind = 1;
    while (itr.hasNext() && index != ind++)
    {
        itr.Next();
    }
    return itr;
}
void DoublyLinkedList::Add(int index, const string &name)
{
    if (index < 0)
        return;
    if (size == 0)
    { // ilk oluşturulacak düğüm root olur
        root = new Node(name);
    }
    else if (index >= size && size != 0) // sona eklenir
    {
        Iterator prevNode = previousPosition(size);
        prevNode.current->next = new Node(name, NULL, prevNode.current);
    }

    else
    {
        Iterator iterator = previousPosition(size);
        iterator.current->next = new Node(iterator.current->data, NULL, iterator.current);
        // liste sonuna yeni düğüm eklenir
        for (int i = size; i - 1 > index; i--, iterator.Previous())
        // liste sonundan geriye doğru gidilir. İstenilen yere gidilene kadar veriler liste sonuna kaydırılır.
        // İstenilen düğüme gidildiğinde veri o düğüme yazılır.
        {
            iterator.current->data = iterator.current->prev->data;
        }
        iterator.current->data = name;
    }
    size++;
}
void DoublyLinkedList::Remove(int index)
{
    if (size == 0)
        return;
    if (size == 1)
    // Listede geriye kalan son düğüm silinir
    {
        delete root;
        root = NULL;
    }
    else if (index == 0)
    { // root düğümünde bulunan veri silinir
        Iterator iterator(root);
        for (int i = 0; i < size - 1; i++, iterator.Next())
        {
            iterator.current->data = iterator.current->next->data;
        }
        iterator.current->prev->next = NULL;
        delete iterator.current;
    }

    else if (index >= size)
    { // Liste sonundaki düğüm silinir
        Iterator lastNode = previousPosition(size);
        lastNode.current->prev->next = NULL; // silinen düğümden önceki düğümün sonrası NULL yapılır
        delete lastNode.current;
    }
    else
    { // Aradan eleman silinir ve diğer elemanlar kaydırılır.
        Iterator iterator = previousPosition(index);
        for (int i = 0; i < size - 1 - index; i++, iterator.Next())
        {
            iterator.current->next->data = iterator.current->next->next->data;
        } // Döngü sonunda iterator en son düğümün öncesini işaret eder.
        delete iterator.current->next;
        iterator.current->next = NULL;
    }
    size--;
}

ostream &operator<<(ostream &output, const DoublyLinkedList &listOut)
{
    for (Iterator itr(listOut.root); itr.hasNext(); itr.Next())
    {
        if (itr.current->next == NULL)
        {
            output << itr.Retrieve();
            break;
        }
        output << itr.Retrieve() << "  <--->  ";
    }
    return output;
}
DoublyLinkedList::~DoublyLinkedList()
{ // Tüm düğümler silinir, bellekte çöp oluşmaz
    while (size != 0)
    {
        Remove(size);
        // En hızlı son düğüm silinir.
    }
}