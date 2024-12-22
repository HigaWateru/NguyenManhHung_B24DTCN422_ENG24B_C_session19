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
void deleteElement(sinhvien *a,int *size, int id, char *name){
    int tg=0,vt;
    for(int i=0;i< *size;i++)if(a[i].id==id&&strcmp(a[i].name,name)==0){
        tg=1;
        vt=i;
        break;
    }
    if(!tg)printf("ID sinh vien va ho ten khong hop le!\n");
    else{
        for(int i=vt;i< *size-1;i++)a[i]=a[i+1];
        (*size)--;
    }
}
sinhvien a[5]={
    {422,"Nguyen Manh Hung",18,"0987654321"},
    {123,"Nguyen Sy Trung",18,"19006776"},
    {66,"Nguyen Quyet Thang",20,"0123456789"},
    {312,"Nguyen Tuan Dung",18,"18002088"},
    {111,"Tran Anh Dung",18,"0987666444"}
};
int id,n=5;
char name[100];
int main(){
    printf("ID sinh vien can xoa: ");
    scanf("%d",&id);
    getchar();
    printf("Ho ten sinh vien can xoa: ");
    fgets(name,50,stdin);
    if(strlen(name)>0&&name[strlen(name)-1]=='\n')name[strlen(name)-1]='\0';
    deleteElement(&a,&n,id,name);
    printf("STT ID            Ho va ten     Tuoi  So dien thoai\n");
    for(int i=0;i<n;i++)printf("%2d %3d%25s %3d%15s\n",i+1,a[i].id,a[i].name,a[i].age,a[i].phone);
}
