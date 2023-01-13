#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void controlpanel();
void addbook();
void showbook();
void deletebook();
void updatebook();
void checkbook();

int i;
int kitapid, sayfasayisi;
char kitapadi[20], yazaradi[50];

void controlpanel()
{
    system("cls");
    printf("KUTUPHANE YONETIMI\n");
    printf("1. Kitap Ekle\n");
    printf("2. Kitap Goster\n");
    printf("3. Kitap Sil\n");
    printf("4. Kitap Guncelle\n");
    printf("5. Cikis\n");
    int choice;
    printf("Seciminizi yapiniz:\n ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        addbook();
        break;
    case 2:
        showbook();
        break;
    case 3:
        deletebook();
        break;
    case 4:
        updatebook();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("Yanlis secim yaptiniz.\n");
        break;
    }
}
void addbook()
{
    system("cls");
    FILE *fpw;
    fpw = fopen("kitap.txt", "a");
    printf("Kitap ID: ");
    scanf("%d", &kitapid);
    printf("Kitap Adi: ");
    scanf("%s", &kitapadi);
    printf("Yazar Adi: ");
    scanf("%s", &yazaradi);
    printf("Sayfa Sayisi: ");
    scanf("%d", &sayfasayisi);
    fprintf(fpw, "KiTAP ID:"
                 "%d ",
            kitapid);
    fprintf(fpw, "KiTAP ADI:"
                 "%s ",
            kitapadi);
    fprintf(fpw, "YAZAR ADI:"
                 "%s ",
            yazaradi);
    fprintf(fpw, "SAYFA SAYISI:"
                 "%d"
                 "\n",
            sayfasayisi);
    fclose(fpw);
    printf("Kitap eklendi.\n");
    printf("Ana Menuye donmek icin bir tusa basiniz");
    getch();
    controlpanel();
}
void showbook()
{
    system("cls");
    FILE *fpr;
    int kitapid, sayfasayisi;
    char kitapadi[50], yazaradi[50];
    fpr = fopen("kitap.txt", "r");
    printf("Kitap ID\tKitap Adi\tYazar Adi\tSayfa Sayisi\n");
    while (fscanf(fpr, "%d%s%s%d", &kitapid, &kitapadi, &yazaradi, &sayfasayisi) != EOF)
    {
        printf("%d\t%s\t%s\t%d\n", kitapid, kitapadi, yazaradi, sayfasayisi);
    }
    fclose(fpr);
    printf("Ana Menuye donmek icin bir tusa basiniz");
    getch();
}
void deletebook()
{
    system("cls");
    FILE *fpr, *fpw;
    int kitapid, sayfasayisi;
    char kitapadi[50], yazaradi[50];
    int count = 0;
    fpw = fopen("tmp.txt", "w");
    fpr = fopen("kitap.txt", "r");
    printf("Silmek istediginiz kitabin ID'sini giriniz: ");
    scanf("%d", &kitapid);
    while (fscanf(fpr, "%d%s%s%d", &kitapid, &kitapadi, &yazaradi, &sayfasayisi) != EOF)
    {
        if (kitapid != kitapid)
        {
            system("cls");
            fprintf(fpw, "%d%s%s%d", kitapid, kitapadi, yazaradi, sayfasayisi);
            count++;
        }
        else
        {
            system("cls");
            fscanf(fpr, "%d%s%s%d", &kitapid, &kitapadi, &yazaradi, &sayfasayisi);
        }
        fprintf(fpw, "%d%s%s%d", kitapid, kitapadi, yazaradi, sayfasayisi);
    }
    system("pause");
    fclose(fpr);
    fclose(fpw);
    remove("kitap.txt");
    rename("tmp.txt", "kitap.txt");
    printf("Kitap silindi.\n");
    printf("Ana Menuye donmek icin bir tusa basiniz");
    getch();
    controlpanel();
}
void updatebook()
{
    system("cls");
    FILE *fpr, *fpw;
    fpw = fopen("tmp.txt", "w");
    fpr = fopen("kitap.txt", "r");
    printf("Guncellemek istediginiz kitabin ID'sini giriniz: ");
    scanf("%d", &kitapid);
    while (fscanf(fpr, "%d%s%s%d", &kitapid, &kitapadi, &yazaradi, &sayfasayisi) != EOF)
    {
        if (kitapid != kitapid)
        {
            system("cls");
            fprintf(fpw, "%d%s%s%d", kitapid, kitapadi, yazaradi, sayfasayisi);
        }
        else
        {
            system("cls");
            printf("Kitap ID: ");
            scanf("%d", &kitapid);
            printf("Kitap Adi: ");
            scanf("%s", &kitapadi);
            printf("Yazar Adi: ");
            scanf("%s", &yazaradi);
            printf("Sayfa Sayisi: ");
            scanf("%d", &sayfasayisi);
            fprintf(fpw, "%d%s%s%d", kitapid, kitapadi, yazaradi, sayfasayisi);
        }
    }
    system("pause");
    fclose(fpr);
    fclose(fpw);
    remove("kitap.txt");
    rename("tmp.txt", "kitap.txt");
    printf("Kitap guncellendi.\n");
    printf("Ana Menuye donmek icin bir tusa basiniz");
    getch();
}
int main()
{
    controlpanel();
    return 0;
}