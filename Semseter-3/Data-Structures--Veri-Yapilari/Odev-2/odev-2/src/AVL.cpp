#include "AVL.hpp"

/*
 * @file			B201210033
 * @description		AVL ağaçları ve kuyruk veri yapısı uygulaması
 * @course			1. Ogretim C grubu
 * @assignment 		2. Odev
 * @date 			28/10/2021
 * @author 			Yusuf Ozaslan	yusuf.ozaslan@ogr.sakarya.edu.tr
 */

NodeAVL *AVL::AraVeEkle(NodeAVL *alt_Dugum, const DogruKuyrugu &yeni)
{ // AVL ağacına ekleme yapılır
    if (alt_Dugum == NULL)
        alt_Dugum = new NodeAVL(yeni);
    else if (yeni < alt_Dugum->dataQueue)
    { // yeni eklenen veri ile mevcut verinin büyüklükleri karşlaştırılır
        alt_Dugum->left = AraVeEkle(alt_Dugum->left, yeni);

        if (Yukseklik(alt_Dugum->left) - Yukseklik(alt_Dugum->right) == 2)
        { // İki düğüm arasındaki yükseklik farkı kontrol edilir
            if (yeni < alt_Dugum->left->dataQueue)
            {
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
            else
            {
                alt_Dugum->left = SagCocukIleDegistir(alt_Dugum->left);
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else if (yeni > alt_Dugum->dataQueue)
    { // yeni eklenen veri ile mevcut verinin büyüklükleri karşlaştırılır
        alt_Dugum->right = AraVeEkle(alt_Dugum->right, yeni);
        if (Yukseklik(alt_Dugum->right) - Yukseklik(alt_Dugum->left) == 2)
        { // İki düğüm arasındaki yükseklik farkı kontrol edilir
            if (yeni > alt_Dugum->right->dataQueue)
            {
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
            else
            {
                alt_Dugum->right = SolCocukIleDegistir(alt_Dugum->right);
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
        }
    }
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    return alt_Dugum;
}

NodeAVL *AVL::SolCocukIleDegistir(NodeAVL *alt_Dugum)
{ // Ağaç sağa dödürülür
    NodeAVL *tmp = alt_Dugum->left;
    alt_Dugum->left = tmp->right;
    tmp->right = alt_Dugum;

    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    tmp->yukseklik = 1 + max(Yukseklik(tmp->left), alt_Dugum->yukseklik);
    return tmp;
}
NodeAVL *AVL::SagCocukIleDegistir(NodeAVL *alt_Dugum)
{ // Ağaç sola dödürülür
    NodeAVL *tmp = alt_Dugum->right;
    alt_Dugum->right = tmp->left;
    tmp->left = alt_Dugum;

    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    tmp->yukseklik = 1 + max(Yukseklik(tmp->right), alt_Dugum->yukseklik);
    return tmp;
}

void AVL::postorder(NodeAVL *alt_Dugum)
{ // Postorder dolaşım yapılır
    if (alt_Dugum != NULL)
    {
        postorder(alt_Dugum->left);
        postorder(alt_Dugum->right);
        alt_Dugum->dataQueue.dequeueMin();
        // Ağacın düğümünde bulunan kuyruktan öncelikli çıkarma işlemi başlatılır.
    }
}

int AVL::Yukseklik(NodeAVL *alt_Dugum)
{
    if (alt_Dugum == NULL)
        return -1;
    return 1 + max(Yukseklik(alt_Dugum->left), Yukseklik(alt_Dugum->right));
}
AVL::AVL()
{
    root = NULL;
}
void AVL::Ekle(const DogruKuyrugu &yeni)
{
    root = AraVeEkle(root, yeni);
}
void AVL::postorder()
{
    cout << "\n\n		*************	POSTORDER	*************\n"
         << endl;
    postorder(root);
}

AVL::~AVL()
{
    // Ağacın düğümleri için ayrılan yerler boşaltılır bellekte çöp oluşmaz
    while (root != NULL)
    {
        NodeAVL *del = root;
        if (root->right == NULL)
        {
            // Sağ çocuğu veya hiç çocuğu yoksa çalışır
            root = root->left;
        }

        else if (root->left == NULL) // Sol çocuk yoksa çalışır
            root = root->right;

        else
        { // Silinen düğümün iki çocuğu varsa çalışır
            del = root->left;
            NodeAVL *parent_Node = root;
            while (del->right != NULL)
            {
                parent_Node = del;
                del = del->right;
            }
            root->dataQueue = del->dataQueue;
            if (parent_Node == root)
            {
                root->left = del->left;
            }
            else
                parent_Node->right = del->left;
        }
        delete del;
    }
}