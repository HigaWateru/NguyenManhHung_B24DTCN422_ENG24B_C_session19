#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[100];
    int age;
    char phone[20];
}sinhvien;
sinhvien a[5]={
    {422,"Nguyen Manh Hung",18,"0987654321"},
    {123,"Nguyen Sy Trung",18,"19006776"},
    {66,"Nguyen Quyet Thang",20,"0123456789"},
    {312,"Nguyen Tuan Dung",18,"18002088"},
    {111,"Tran Anh Dung",18,"0987666444"}
};
void swap(sinhvien *a, sinhvien *b){
    sinhvien temp= *a;
    *a=*b;
    *b=temp;
}
void getLastName(char *name, char *lastName){
    char *i=strrchr(name,' ');
    if (i!=NULL)strcpy(lastName,i+1);
    else strcpy(lastName,name);
}
void selectionSort(sinhvien *a, int size) {
    char lastName1[50],lastName2[50];
    for (int i=0;i<size-1;i++)for(int j=i+1;j<size;j++){
        getLastName(a[i].name,lastName1);
        getLastName(a[j].name,lastName2);
        if (strcmp(lastName1,lastName2)>0)swap(&a[i],&a[j]);
    }
}
int id;
int main(){
    selectionSort(&a,5);
    printf("STT ID            Ho va ten     Tuoi  So dien thoai\n");
    for(int i=0;i<5;i++)printf("%2d %3d%25s %3d%15s\n",i+1,a[i].id,a[i].name,a[i].age,a[i].phone);
}
