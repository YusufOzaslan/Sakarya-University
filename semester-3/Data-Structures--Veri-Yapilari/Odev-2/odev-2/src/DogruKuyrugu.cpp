#include "DogruKuyrugu.hpp"

/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

DogruKuyrugu::DogruKuyrugu()
{
    front = back = NULL;
    lengthOfQueue = 0;
    sumOfLengths = 0;
}

NodeNokta *DogruKuyrugu::previousMinNodeNokta() const
{ // Kuyrukta öncelikli düğümün öncesindeki veri bulunur
    if (lengthOfQueue == 0)
        return NULL;
    NodeNokta *temporary = front;
    NodeNokta *previous = NULL;
    Nokta smallest = temporary->data;

    while (temporary->next != NULL)
    {
        if (temporary->next->data < smallest)
        {
            smallest = temporary->next->data;
            previous = temporary;
        }
        temporary = temporary->next;
    }
    return previous;
}

void DogruKuyrugu::CalculateSumOfLengths()
{ // Noktalar arasındaki toplam uzaklık hesaplanır
    if (lengthOfQueue == 0 || lengthOfQueue == 1)
    {
        sumOfLengths = 0;
    }
    else
    {
        NodeNokta *iterator1 = front;
        NodeNokta *iterator2 = front->next;
        for (int i = 0; i < lengthOfQueue - 1; i++)
        { // İki nokta arası uzaklık formülü kullanılır
            sumOfLengths += sqrt(pow(iterator2->data.x - iterator1->data.x, 2) +
                                 pow(iterator2->data.y - iterator1->data.y, 2) +
                                 pow(iterator2->data.z - iterator1->data.z, 2));
            iterator1 = iterator1->next;
            iterator2 = iterator2->next;
        }
    }
}

void DogruKuyrugu::Enqueue(const Nokta &item)
{ // Kuyruğa Nokta verisi eklenir
    NodeNokta *last = new NodeNokta(item);
    if (lengthOfQueue == 0)
        front = back = last;
    else
    {
        back->next = last;
        back = last;
    }
    lengthOfQueue++;
}
void DogruKuyrugu::Dequeue()
{ // Kuyruktan öndeki veri çıkarılır
    if (lengthOfQueue == 0)
        throw "Hata";
    NodeNokta *del = front;
    front = front->next;
    delete del;
    lengthOfQueue--;
}

void DogruKuyrugu::dequeueMin()
{ // Kuyruktan öncelikli veri çıkarılır
    while (lengthOfQueue != 0)
    {
        NodeNokta *previous = previousMinNodeNokta();
        NodeNokta *temp;
        if (previous == NULL)
        {
            cout << front->data;
            // Ekrana yazma fonksiyonunun Nokta verisi için aşırı yüklenmiş hali çağrılır.
            Dequeue();
        }

        else
        {
            cout << previous->next->data;
            // Ekrana yazma fonksiyonunun Nokta verisi için aşırı yüklenmiş hali çağrılır.
            if (previous->next == back)
            {
                back = previous;
            }
            temp = previous->next;
            previous->next = temp->next;
            delete temp;
            lengthOfQueue--;
        }
    }
    cout << endl;
}

// Atama operatörü aşırı yüklenir
DogruKuyrugu &DogruKuyrugu::operator=(const DogruKuyrugu &dogruKuyrugu)
{
    // Kuyruk nesnesi kopyalama yapılır
    this->front = dogruKuyrugu.front;
    this->back = dogruKuyrugu.back;
    this->lengthOfQueue = dogruKuyrugu.lengthOfQueue;
    this->sumOfLengths = dogruKuyrugu.sumOfLengths;

    return *this;
}

bool DogruKuyrugu::operator<(DogruKuyrugu &dogruKuyrugus) const
{ // DogruKuyrugu sınıfı için < operatörü aşırı yüklenir
    return this->sumOfLengths < dogruKuyrugus.sumOfLengths;
}

bool DogruKuyrugu::operator>(DogruKuyrugu &dogruKuyrugus) const
{ // DogruKuyrugu sınıfı için > operatörü aşırı yüklenir
    return this->sumOfLengths > dogruKuyrugus.sumOfLengths;
}

bool operator==(const DogruKuyrugu &dogruKuyrugu1, const DogruKuyrugu &dogruKuyrugu2)
{ // DogruKuyrugu sınıfı için == operatörü aşırı yüklenir
    return dogruKuyrugu1.sumOfLengths == dogruKuyrugu2.sumOfLengths;
}

DogruKuyrugu::~DogruKuyrugu()
{
    //Kuyrukta düğüm kalırsa çöp oluşumu engellenir.
    while (lengthOfQueue != 0)
        Dequeue();
}