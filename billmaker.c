#include<stdio.h>
struct items{
    char name[15];
    float price;
    int quant;
}it[20];
int count=0,bill_no=101;
float dis_p,amt=0,disc=0;
void println(){
    printf("\n===========================================================================");
}
void print(){
    printf("\t\t\t\tXYZ Supermarket\n");
    printf("\t\t\t    3/top, PQR Shopping Mall\n");
    printf("\t\t\t\tGandhinagar");
    println();
    printf("\nBill No: %d\t\t\t\t\t\t\t%d-%s-%d",bill_no,04,"Feb",2024);
    println();
    printf("\nNo.\tItem Name\t\tUnit Price\tQty\t\tTotal");   
    println();
    for(int i=0;i<count;i++){
        printf("\n%d.\t%-15s\t\t%.2f\t\t%d\t\t%.2f",i+1,it[i].name,it[i].price,it[i].quant,it[i].price*it[i].quant);
    }
    println();
    printf("\nTotal amount: %.2f",amt);
    printf("\nTotal Discount: %.2f",disc);
    println();
    printf("\nAmount to be Paid: %.2f",amt-disc);
}



void main(){
    printf("\t\t\t\tXYZ Supermarket\n");
    printf("\t\t\t    3/top, PQR Shopping Mall\n");
    printf("\t\t\t\tGandhinagar");
    println();
    printf("\nEnter bill no: ");
    scanf("%d",&bill_no);
    printf("Enter the percentage of discount to be applied: ");
    scanf("%f",&dis_p);
    dis_p/=100;
    while(1){
        int tq;
        float tp;
        printf("Enter the name of item %d: ",count+1);
        scanf("%s",it[count].name);
        up_err:
        printf("Enter the Unit Price: ");
        scanf("%f",&tp);
        if(tp>0){
            it[count].price=tp;
        }else{
            printf("Unit Price has to be positive!\n");
            goto up_err;
        }
        q_err:
        printf("Enter the quantity: ");
        scanf("%d",&tq);
        if(tq>0){
            it[count].quant=tq;
        }else{
            printf("Quantity has to be postive!\n");
            goto q_err;
        }
        count++;
        amt+=(tp*tq);
        printf("Record added succesfully!\n");
        printf("Do you wish to add another item? (y/n): ");
        char cont;
        scanf(" %c",&cont);
        if((cont=='Y')||(cont=='y')){
            continue;
        }else if((cont=='N')||cont=='n'){
            break;
        }
        println();
    }
    printf("Generating your bill!\n\n");
    disc=amt*dis_p;
    print();
}