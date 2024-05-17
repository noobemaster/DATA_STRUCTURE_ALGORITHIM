#include<stdio.h>
#include<stdlib.h>
//data used
const int ogList[]={123,5,67,89,12,6,34,67,98,90,78,0,1234,654,1};
int List[]={123,5,67,89,12,6,34,67,98,90,78,0,1234,654,1},len=sizeof(List)/sizeof(List[0]);
int sorted_List[]={1,5,8,14,18,20,27,30,45,59,67,70},lenS=sizeof(sorted_List)/sizeof(sorted_List[0]);
int Choice,Exit;
void printArray(int arr[],int lenl){
    printf("\tArray  { ");
    for(int i=0;i<lenl;i++)printf("%d, ",arr[i]);
    printf("}\n");
}
//SEARCH ALGORITHIMS
int binarysearch(int val){//O(log n)
    //divide and conquer  needs to be sorted  divides in middle searches by size
    int mid,high=lenS,low=0,i=0,index=-1;
    mid=low+(high-low)/2;
    while(sorted_List[mid]!=val){
        if(high<low)return index;
        mid=low+(high-low)/2;
        if(val==sorted_List[mid])index=mid;
        if(val>sorted_List[mid])low=mid+1;
        if(val<sorted_List[mid])high=mid-1;
    }
    return index;
}
int interpolationsearch(int val){
    //improved binary search  must be sorted
    int mid=-1,high=lenS-1,low=0,index=-1,i=0;
    while(sorted_List[mid]!=val&&i<lenS){
        if(high==low )break;
        mid=low+( (float)(high-low) / ( sorted_List[high]-sorted_List[low] ) ) * (val-sorted_List[low]);
        if(val>sorted_List[mid])low=mid++;
        if(val<sorted_List[mid])high=mid--;
        i++;
    }
    if(val==sorted_List[mid]){index=mid;}
    return index;
}
int hash_table(int val){
    int hlist[lenS],index,i,ind;
    int hashcode(int valu){return valu%lenS;}
    for(i=0;i<lenS;i++)hlist[i]=-1;
    void create_hash(){
        for(i=0;i<lenS;i++){
            index=hashcode(sorted_List[i]);
            if(hlist[index]!=-1){
                while(hlist[index]!=-1){
                    index++;
                    index=hashcode(index);}
            }
            hlist[index]=sorted_List[i];
        }
    }
    void search(){
        index=hashcode(val);i=0;
        while(hlist[index]!=val&&i<len){index++;index=hashcode(index);i++;}
        if(i==len)index=-1;
        //index;
    }
    create_hash();
    printf("\tAfter hashing:\n");
    printArray(hlist,lenS);
    search();
    return index;
}
void search_exe(){
    printf(" -----------SEARCH ALGORITHMS-----------\n 1.BINARY SEARCH\n 2.INTERPOLATION SEARCH\n 3.HASH TABLES\n");
    printf("    Data used: ");printArray(sorted_List,lenS);
    int sech;printf("\t Enter data to search: ");scanf("%d",&sech);
    printf("\n    #Choose an algorithm: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:
            printf("\t// binary search requires an already sorted array in order to search\n\t//it implements divide and conqure approach\n");
            printf("\t//it divides the array into two if the data being searched is greater than the data at the mid point it searches right  and vice verser\n \n");
            printf("\t%d  is at index %d\n",sech,binarysearch(sech));break;
        case 2:
            printf("\t// interpolation search is an improvement of binary search\n\t//it utilizes probing i.e it calculates the most likely position of the data\n\n");
            printf("\t%d  is at index %d\n",sech,interpolationsearch(sech));break;
        case 3:
            printf("\t//a hash table is a list of items that are sorted using unique indices\n\t//hashing refers to the process of generating a list with unique index\n");
            printf("\t//when an index is already occupied linear probing is used to find the immediate empty index\n\n");
            printf("\t%d  is at index %d\n",sech,hash_table(sech));break;
        default: printf("\t!!!!!!%d is an invalid choice !!!!!!!\n",Choice);search_exe();
    }
    printf(" \n\t->To exit Search enter 0 ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    search_exe();
}
//SORT ALGORITHIMS
void bubblesort(int arr[],int lenth){//O(n^2)
    int temp,i,sorted;
    for(i=0;i<lenth-1;i++){
        sorted=0;
        for(int j=0;j<lenth-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorted=1;
            }
        }
        if(!sorted)break;
    }

}
void insertionsort(int arr[],int lenth){//O(n^2)
    int temp,position,i;
    for(i=1;i<lenth;i++){
    temp=arr[i];
    position=i;
    while(position>0 && arr[position-1]>temp){
        arr[position]=arr[position-1];
        position--;
    }
    arr[position]=temp;
    }

}
void selectionsort(int arr[],int lenth){//O(n^2)
    int min,i,j,temp,position=0;
    for(i=0;i<lenth-1;i++){
        min=i;
        for(j=i+1;j<lenth;j++)if(arr[min]>arr[j])min=j;
        if(min!=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

}
void mergesort(int arr[],int lenth){//O(n log n)
    void merge(int head,int mid, int size){
        int i,j,k;
        int n1=mid-head+1,n2=size-mid;
        int L[n1],R[n2];
        for(i=0;i<n1;i++)L[i]=arr[head+i];
        for(j=0;j<n2;j++)R[j]=arr[mid+1+j];
        k=head;i=0,j=0;
        while(i<n1&&j<n2){
            if(L[i]<=R[j]){arr[k]=L[i];i++;}
            else{arr[k]=R[j];j++;}
            k++;
        }
        while(i<n1){arr[k]=L[i]; i++;k++;}
        while(j<n2){arr[k]=R[j];j++;k++;}
    }
    void divide(int head,int size){
        if(head<size){
            int mid=head+(size-head)/2;
            divide(head,mid);
            divide(mid+1,size);

            merge(head,mid,size);
        }
    }
    divide(0,lenth-1);
}
void shellsort(int arr[],int lenth){//O(n)
    int inter=1,i,temp,position;
    while(inter<(lenth/3))inter=inter*3+1;//knuth's formula
    while(inter>0){
        for(i=inter;i<lenth;i++){
            temp=arr[i];
            position=i;
            while(position>inter-1 && arr[position-inter]>=temp){
                arr[position]=arr[position-inter];
                position=position-inter;
            }
        arr[position]=temp;
        }
       inter=(inter-1)/3;
    }
}
void quicksort(int arr[],int lenth){//O(n^2)
    int part,pivot,lp,i,temp;
    int parts(int lft,int rgt){
       /* lp=lft;
        rp=rgt-1;
        while(1){
        while(arr[lp]<pivot){lp++;break;}
        while(rp>0&&arr[rp]>pivot){rp--;break;}
        if(lp>=rp)break;
        temp=lp;
        lp=rp;
        rp=temp;
        }
        temp=lp;
        lp=rgt;
        printf("%d  %d\t",lp,rp);
        return lp;*/
        pivot=arr[rgt];
        lp=lft-1;
        for(i=lft;i<=rgt;i++){
            if(arr[i]<pivot){
                lp++;
                temp=arr[lp];
                arr[lp]=arr[i];
                arr[i]=temp;
            }
        }
        lp++;
        temp=arr[lp];
        arr[lp]=arr[rgt];
        arr[rgt]=temp;
        return lp;
    }
    void sort(int lft, int rgt){
       /*if(rgt-lft<= 0)return;
        pivot=arr[rgt];
        part=parts(pivot,rgt,lft);
        sort(lft,part-1);
        sort(part+1,rgt);*/
        if(lft<rgt){
            part=parts(lft,rgt);
            sort(lft,part-1);
            sort(part+1,rgt);
        }
    }
    sort(0,lenth-1);
}
void prev(){
    for(int i=0; i<len;i++)List[i]=ogList[i];
}
void sort_exe(){
    printf(" ------------SORT-------------\n 1.BUBLE SORT\n 2.INSERTION SORT\n 3.SELECTION SORT\n 4.MERGE SORT\n 5.SHELL SORT\n 6.QUICK SORT\n 7.VIEW THE ARRAY\n");
    printf("   Data used");printArray(ogList,len);
    printf("\n    #Choose an algorithm: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:
            printf("\t//bubble sort takes the two adjucent elements compares them and swaps them if they are not in order\n");
            printf("\t//it does this for all the items in the list until it is sorted\n\n");
            prev;bubblesort(List,len);printf("\t The list is sorter...\n");
            break;
        case 2:
            printf("\t//insertion sort assumes the first item in the list is already sorted it searches the whole list for items with a lower value and swaps them\n");
            printf("\t//once the first item is the least in the list it moves to the next item and repeats the procedure until the list is sorted\n\n");
            prev();insertionsort(List,len);printf("\t The list is sorted...\n");
            break;
        case 3:
            printf("\t//it divides the list into two parts sorted  at the left and unsorted at the right\n");
            printf("\t//it searches the whole list for items with lower values than the present one an swaps them keeping the left side sorted until the end of the list\n\n");
            prev();selectionsort(List,len);printf("\t Array sorted...\n");
            break;
        case 4:
            printf("\t//it employes divide and conqure technique\n\t//it first divides the list into equal haves and then combines them in a sorted manner\n\n");
            prev();mergesort(List,len);printf("\t The list is sorted...\n");
            break;
        case 5:
            printf("\t//it is based on insertion sort but unlike insertion sort it avoids large shifts by using it only on widely spaced elements\n\n");
            prev();shellsort(List,len);printf("\t Array is sorted...\n");
            break;
        case 6:
            printf("\t//it is based on partitioning of array of data into smaller arrays\n\t//it divides an array into two one that are greater then a certainvalue(pivot) and the other lesser\n\n");
            prev();quicksort(List,len);printf("\t the Aray is sorted...\n");
            break;
        case 7:
            printArray(List,len);
            break;
        default: printf("\t!!!!!!%d is an invalid choice !!!!!!!\n",Choice);sort_exe();
    }
    printf(" \n\t->To exit Search enter 0 ");
    scanf("%d",&Exit);
    if (Exit==0)return;
    sort_exe();

}

int main(){
    printf("---------------------------WELCOME TO ALGORITHIMS--------------------\n");
    printf("1.SEARCH\n2.SORT\n");
    printf("##Select a function: ");scanf("%d",&Choice);
    switch(Choice){
        case 1:search_exe();break;
        case 2:sort_exe();break;
       default: printf("\t!!!!!!%d is an invalid choice !!!!!!!\n",Choice);main();
    }
    printf(" \n->To exit Algorithms enter 0 ");
    scanf("%d",&Exit);
    if (Exit==0)return 0;
    main();
}
