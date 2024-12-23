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
void checkID(sinhvien *a, int *id, int *vt){
    int tg=0;
    do{
        tg=0;
        printf("ID sinh vien: ");
        scanf("%d",&id);
        getchar();
        for(int i=0;i<100;i++)if(id==a[i].id){
            *vt=i;
            tg=1;
            break;
        }
        if(!tg)printf("ID sinh vien khong ton tai!\n");
    }while(tg==0);
}
void insertSinhvien(sinhvien *a, int vt){
    printf("Ho va ten: ");
    fgets(a[vt].name,100,stdin);
    if(a[vt].name>0&&a[vt].name[strlen(a[vt].name)-1]=='\n')a[vt].name[strlen(a[vt].name)-1]='\0';
    printf("Tuoi: ");
    scanf("%d",&a[vt].age);
    getchar();
    printf("So dien thoai: ");
    fgets(a[vt].phone,15,stdin);
    if(a[vt].phone>0&&a[vt].phone[strlen(a[vt].phone)-1]=='\n')a[vt].phone[strlen(a[vt].phone)-1]='\0';
    printf("Da cap nhat thong tin thanh cong!\n");
}
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
sinhvien a[100]={
    {422,"Nguyen Manh Hung",18,"0987654321"},
    {123,"Nguyen Sy Trung",18,"19006776"},
    {66,"Nguyen Quyet Thang",20,"0123456789"},
    {312,"Nguyen Tuan Dung",18,"18002088"},
    {111,"Tran Anh Dung",18,"0987666444"}
};
int d,id,tg,vt;
char name[105];
int main(){
    do{
        printf("MENU\n1.Hien thi danh sach sinh vien\n2.Them sinh vien\n3.Sua thong tin sinh vien\n4.Xoa sinh vien\n5.Tim kiem sinh vien\n6.Sap xep danh sach sinh vien\n7.Thoat\nLua chon cua ban: ");
        scanf("%d",&d);
        getchar();
        switch (d){
            case 1:
                printf("STT ID            Ho va ten     Tuoi  So dien thoai\n");
                for(int i=0;i<100;i++)if(a[i].id!=0)printf("%2d %3d%25s %3d%15s\n",i+1,a[i].id,a[i].name,a[i].age,a[i].phone);
                break;
            case 2:
                printf("Them thong tin sinh vien\n");
                do{
                    tg=0;
                    printf("ID sinh vien: ");
                    scanf("%d",&id);
                    getchar();
                    for(int i=0;i<100;i++)if(id==a[i].id){
                        tg=1;
                        break;
                    }
                    if(tg)printf("ID sinh vien da ton tai, khong the them thong tin!\n");
                }while(tg!=0);
                for(int i=0;i<100;i++)if(a[i].id==0){
                    vt=i;
                    a[i].id=id;
                    break;
                }
                insertSinhvien(&a,vt);
                break;
            case 3:
                printf("Sua thong tin sinh vien\n");
                checkID(&a,&id,&vt);
                insertSinhvien(&a,vt);
                break;
            case 4:
                printf("Xoa sinh vien\n");
                checkID(&a,&id,&vt);
                printf("Da xoa thong tin sinh vien id %d!\n",a[vt].id);
                a[vt].id=0;
                break;
            case 5:
                printf("Tim kiem sinh vien:\n");
                printf("Ho va ten: ");
                fgets(name,100,stdin);
                if(strlen(name)>0&&name[strlen(name)-1]=='\n')name[strlen(name)-1]='\0';
                int tg=0;
                for(int i=0;i<100;i++)if(strcmp(a[i].name,name)==0){
                    tg=1;
                    printf("Thong tin sinh vien tim kiem:\nID sinh vien: %d\nHo va ten sinh vien: %s\nTuoi: %d\nSo dien thoai: %s\n",a[i].id,a[i].name,a[i].age,a[i].phone);
                }
                if(!tg)printf("Khong tim thay ten sinh vien trong danh sach!\n");
                break;
            case 6:
                selectionSort(&a,5);
                printf("Da sap xep sinh vien theo ten\n");
                break;
            default:
                break;
        }
    }while(d!=7);
}
