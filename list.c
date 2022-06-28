#include <stdio.h>
#include<stdlib.h>

struct structure{
    int val;
    struct structure *next;  
};

struct structure *ptr = NULL;
struct structure *head = NULL;
struct structure *curr = NULL;

struct structure* create_list(int val, struct structure *ptr){
    if(NULL == ptr)
    {
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;
    head = curr = ptr;
    return ptr;
}

struct structure* add_to_list(int val){
       ptr = (struct structure*)malloc(sizeof(struct structure));

    if(NULL == head)
    {
        return (create_list(val, ptr));
    }
    if(NULL == ptr)
    {
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;
        curr->next = ptr;
        curr = ptr;
    return ptr;
}
struct structure* search_in_list(int val, struct structure **prev){
    struct structure *ptr = head;
    struct structure *tmp = NULL;
    int found = 0;
    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = 1;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(found == 1)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}
int getCount(struct structure* head)
{
    int count = 0;  // Initialize count
    struct structure* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
int delete_from_list(int val)
{
    struct structure *prev = NULL;
    struct structure *del = NULL;

    del = search_in_list(val,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;
    return 0;
}

void swap(struct structure *a, struct structure *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}
void bubbleSort(struct structure *start)
{
    int swapped;
    struct structure *ptr1;
    struct structure *lptr = NULL;
  
   
    /* Checking for empty list */
    if (start == NULL)
        return;
    
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void print_list(void)
{
    struct structure *ptr = head;
    
    int sizeX = getCount(head);
    printf("%d :",sizeX);
    while(ptr != NULL)
    {
         bubbleSort(ptr);
        printf(" %d",ptr->val);   //  "5 6 7 "   "5 6 7"   
        ptr = ptr->next;
    }
    printf("\n");

    return;
}
void scanner(){
    char mode;
    int number;
    
  
    int plsno = scanf( "%c %d", &mode, &number);
    if (plsno == EOF) exit(0);
    
  
    struct structure *ptr = NULL;
    if(mode == 'i'){
        if(search_in_list(number,&ptr)==0)
            add_to_list(number);
    }else if(mode =='d'){
        delete_from_list(number);
    } 
      if(mode=='i' || mode=='d') 
      print_list();
       return scanner();
}
void nodefree(struct structure * start) {
	struct structure * ptr = start;

	while (ptr!=NULL) {
		start = start->next;
		free(ptr);
		ptr = start;
	}
}
int main(){	
  scanner();
  nodefree(ptr);
return 0;

}
