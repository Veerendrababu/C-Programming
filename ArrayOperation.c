//
//  arrayoperations.c
//  ARRAY OPERATION
//
//  Created by Veerendra Babu Bommakanti on 6/3/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define  MAX_LEN 15
int arr[MAX_LEN] = {20,10,1,2,3,4,15,6,0};
int length = 9;

typedef enum  array_operations{
    ADD = 1,
    DISPLAY,
    INSERT,
    DELETE,
    SEARCH,
    GET,
    SET,
    MAX_VALUE,
    MIN_VALUE,
    REVERSE,
    SHIFT,
    ARRAY_RESET,
    ARRAY_LENGTH,
    EXIT
}array_operations_t;

void array_menu(void);

void display(void){
    printf("array data = [ ");
    for(int i = 0;i<length;i++){
        if(i == 0)
            printf("%d",arr[i]);
        else
            printf(", %d",arr[i]);
    }
    printf(" ]\n");
}
void add(int data){
    arr[length] = data;
    length++;
    
}
int insert(int pos,int data){
    int i = 0;
    if((pos<MAX_LEN)&&(pos<length)){
        for( i=length; pos < i; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[i]= data;
        length++;
    }
    else
    {
        return -1;
    }
    return 0;
}
int set(int pos,int data){
    if(pos<length){
        arr[pos] = data;
        return 0;
    }
    else
        return -1;
}
int get(int pos,int *data){
    if(pos<length){
        *data = arr[pos];
        return 0;
    }
    else
        return -1;
}
void delete(int pos){
    if((pos<MAX_LEN)&&(pos<length)){
        for(int i = pos;i<length;i++)
            arr[i]= arr[i+1];
        length--;
    }
}
int max_value(void){
    int max_val = arr[0];
    for(int i = 0;i<length-1;i++){
        if((arr[i] < arr[i+1]) && (arr[i+1] > max_val))
            max_val = arr[i+1];
        else if(arr[i+1] > max_val)
            max_val = arr[i];
    }
    return max_val;
}
int min_value(void){
    int min_val = arr[0];
    int i = 0;
    for(i = 0;i<length-1;i++){
        if((arr[i]<arr[i+1]) && ( arr[i] < min_val))
            min_val = arr[i];
        else if( arr[i+1] < min_val){
            min_val = arr[i+1];
        }
    }
    
    return min_val;
}
int search(int data){
    int pos = 0;
    for( pos = 0;pos<length;pos++){
        if(arr[pos] == data)
            return pos;
    }
    return -1;
}
void reverse(void){
    int temp_var = 0,loop_var = length-1;
    for(int i = 0;i<length/2;i++)
    {
        temp_var = arr[i];
        arr[i] = arr[loop_var];
        arr[loop_var]=temp_var;
        loop_var--;
    }
}
void array_reset(void){
    memset(arr,0,sizeof(arr));
    length = 0;
}
int shift(int pos1,int pos2){
    if(((pos1<length)&&(pos1<MAX_LEN))&&
       (pos1<length)&&(pos1<MAX_LEN))
    {
        int temp = arr[pos1];
        arr[pos1]= arr[pos2];
        arr[pos2]= temp;
        return 0;
    }
    else return -1;
}
void array_operation(array_operations_t operation){
    switch(operation){
        case ADD:
        {
            int data = 0;
            printf("Please enter the input data to add element\n");
            scanf("%d",&data);
            add(data);
            array_menu();
        }
        break;
        case DISPLAY:
        {
            display();
            array_menu();
        }
        break;
        case INSERT:
        {
            int data = 0,pos = 0;
            printf("Please enter the  data to insert element and its position\n");
            scanf("%d %d",&data,&pos);
            insert(pos, data);
            array_menu();
        }
        break;
        case DELETE:
        {
            int pos = 0;
            printf("Please enter the index position to delete\n");
            scanf("%d",&pos);
            delete(pos);
            array_menu();
        }
        break;
        case SEARCH:
        {
            int res = 0;
            int data = 0;
            printf("Please enter the data to search\n");
            scanf("%d",&data);
            res = search(data);
            printf("positon of %d is: %d\n",data,res);
            array_menu();
        }
        break;
        case GET:
        {
            int get_data = 0,index = 0;
            printf("Please enter the index number[%d-%d]\n",0,length-1);
            scanf("%d",&index);
            get(index,&get_data);
            printf("data at index %d is %d\n",index,get_data);
            array_menu();
        }
        break;
        case SET:
        {
            int data = 0,pos = 0,res = 0;
            printf("Please enter the  data to set(replace) element and its position\n");
            scanf("%d %d",&data,&pos);
            set(pos, data);
            if(res!= 0)
                printf("error-1\n");
            array_menu();
        }
        break;
        case MAX_VALUE:
        {
            printf("Maximum value of the array is %d \n",max_value());
            array_menu();
        }
        break;
        case MIN_VALUE:
        {
            printf("Minimum value of the array is %d \n",min_value());
            array_menu();
        }
        break;
        case REVERSE:
        {
            reverse();
            array_menu();
        }
        break;
        case ARRAY_RESET:
            array_reset();
            array_menu();
            break;
        case SHIFT:
        {
            int pos1 = 0,pos2 = 0;
            printf("Please enter the  data to insert element and its position\n");
            scanf("%d %d",&pos1,&pos2);
            int res = shift(pos1,pos2);
            if(res != 0)
                printf("error-3\n");
            array_menu();
        }
        break;
        case ARRAY_LENGTH:
            printf("Array legth is %d\n",length);
            array_menu();
        case EXIT:
        break;
    }
}
void array_menu(void){
    int menu_option = 0;
    static _Bool flag = 1;
    if(flag)
        printf("Welcome to array operations\nPlease select the operation\n");
    flag = 0;
    printf("\
           1. ADD\n\
           2. DISPLAY\n\
           3. INSERT\n\
           4. DELETE\n\
           5. SEARCH\n\
           6. GET\n\
           7. SET\n\
           8. MAX_VALUE\n\
           9. MIN_VALUE\n\
           10. REVERSE\n\
           11. SHIFT \n\
           12. ARRAY_RESET\n\
           13. ARRAY_LENGTH\n\
           14. EXIT\n");
    scanf("%d",&menu_option);
    array_operation(menu_option);
}
int main(int argc, const char * argv[]) {
    array_menu();
    return EXIT_SUCCESS;
}
