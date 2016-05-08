#include<stdio.h>						//two separate linklist are used to implement certain programs 
#include<stdlib.h>
#include<string.h>

struct node {
	int data;
	struct node *next;
};

struct node *insertion_begin(struct node *,int );		//insertion of element at the beginning of list	
struct node *insertion_end(struct node *,int );			//insertion of element at the end of list
struct node *insertion_after(struct node *,int ,int );		//insertion of elements after a given position
struct node *bubble_sort(struct node *);			//sorting linllist by data using bubblesort
struct node *search(struct node *,int );			//searching an element
struct node *alternate_deletion(struct node *);			//deletion of alternate nodes
struct node *rearrange(struct node *);				//rearrange of two linklist
struct node *deletion_begin(struct node *);			//deletion at the beginning of list
struct node *deletion_end(struct node *);			//deletion at the end of the list
struct node *deletion_after(struct node *,int );		//deletion after a ceratin position
struct node *swap(struct node* ,int, int);			//swapping the data of nodes
struct node *swap_node(struct node *,int ,int);			//swapping the nodes

void maximum(struct node * );					//maximum element in the list
void minimum(struct node *);					//minimum element int the list	
void print_reverse(struct node *);				//print the list in  reverse order
void print_alternate(struct node *);				//print alternate nodes
void display(struct node *);					//print the entire list
void iseven(struct node *,int);					//is the given element even
void isodd(struct node *,int );					//is the given element odd
void summation(struct node *);					//sum of all elements of list
void all_even(struct node *);					//print all even
void all_odd(struct node *);					//print all odd
void swap1(int *,int *); 					//swap two integers using pointers

-----------------------------------------------------------------------------------------------------------------------------------------------

int main()

{
	struct node *start,*ptr,*start1;
	start=(struct node *)malloc(sizeof(struct node ));	//pointer to first list
	start=NULL;
	start1=(struct node *)malloc(sizeof(struct node));	//pointer to second list
	start1=NULL; 
	int value,value1,m,q=0;
	char str[20];
	scanf("%s",str);

	while(strcmp(str,"exit")!=0){	
		if(strcmp(str,"insertion_begin")==0){
			scanf("%d%d",&m,&value);
			if(m==1)
				start=insertion_begin(start,value);
			else if(m==2)
				start1=insertion_begin(start,value);
		}
		else if(strcmp(str,"insertion_end")==0){
			scanf("%d%d",&m,&value);
			if(m==1)
				start=insertion_end(start,value);	
			else if(m==2)
				start1=insertion_end(start1,value);
		}
		else if(strcmp(str,"insertion_after")==0){
			scanf("%d%d%d",&m,&value,&value1);
			if(m==1)
				start=insertion_after(start,value,value1);	
			else 
				start1=insertion_after(start1,value,value1);
		}
		else if(strcmp(str,"display")==0){
			scanf("%d",&m);
			if(m==1)
				display(start);
			else if(m==2)
				display(start1);
		}
		else if(strcmp(str,"search")==0){
			scanf("%d%d",&m,&value);
			if(m==1)	
				ptr=search(start,value);	
			else if(m==2)
				ptr=search(start1,value);
		}
		else if(strcmp(str,"deletion_after")==0){
			scanf("%d%d",&m,&value);
			if(m==1)
				start=deletion_after(start,value);
			if(m==2)
				start1=deletion_after(start1,value);
		}
		else if(strcmp(str,"deletion_begin")==0){
			scanf("%d",&m);
			if(m==1)
				start=deletion_begin(start);
			else if(m==2)
				start1=deletion_begin(start1);
		}
		else if(strcmp(str,"deletion_end")==0){
			scanf("%d",&m);
			if(m==1)
				start=deletion_end(start);
			else if(m==2)
				start1=deletion_end(start1);
		}
		else if(strcmp(str,"iseven")==0){
			scanf("%d",&value);
			iseven(start,value);
		}
		else if(strcmp(str,"isodd")==0){
			scanf("%d",&value);
			isodd(start,value);
		}
		else if(strcmp(str,"summation")==0){
			summation(start);
		}
		else if(strcmp(str,"all_odd")==0){
			all_odd(start);
		}
		else if(strcmp(str,"all_even")==0){
			all_even(start);
		}
		else if(strcmp(str,"swap")==0){
			scanf("%d%d",&value,&value1);
			start=swap(start,value,value1);
		}
		else if(strcmp(str,"swap_node")==0){
			scanf("%d%d",&value,&value1);
			start=swap_node(start,value,value1);
		}
		else if(strcmp(str,"maximum")==0){
			maximum(start);
		}
		else if(strcmp(str,"minimum")==0){
			minimum(start);
		}
		else if(strcmp(str,"print_reverse")==0){
			print_reverse(start);
		}
		else if(strcmp(str,"print_alternate")==0){
			print_alternate(start);
		}
		else if(strcmp(str,"alternate_deletion")==0){
			start=alternate_deletion(start);
		}
		else if(strcmp(str,"rearrange")==0){
			scanf("%d",&m);
			if(m==1)
				start=rearrange(start);
			else if(m==2)
				start1=rearrange(start1);
		}	
		else if(strcmp(str,"bubble_sort")==0){
			start=bubble_sort(start);
		}
		scanf("%s",str);
	}
	return 0;
}


struct node *insertion_begin(struct node *start,int value){
	if(start==NULL){
		start=(struct node *)malloc(sizeof(struct node ));
		start->data=value;
		start->next=NULL;
		return start;
	}
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node ));
	tmp->data=value;
	tmp->next=start;
	start=tmp;
	return start;
}


struct node *insertion_end(struct node *start,int value){
	struct node *ptr,*tmp;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}	
	tmp=(struct node *)malloc(sizeof(struct node ));
	tmp->data=value;
	tmp->next=NULL;
	ptr->next=tmp;
	return start;
}


struct node *insertion_after(struct node *start,int value,int value1){
	struct node *ptr,*tmp;
	ptr=start;
	while(ptr->data!=value){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		printf("value not found");
		return start;
	}
	else{
		tmp=(struct node *)malloc(sizeof(struct node ));
		tmp->data=value1;
		tmp->next=ptr->next;
		ptr->next=tmp;
		return start;
	}
}


void display(struct node *start){
	while(start!=NULL){
		printf("%d  ",start->data);
		start=start->next;
	}
}


struct node *search(struct node *start,int value){
	struct node *ptr;
	ptr=start;
	while(ptr->data!=value){
		ptr=ptr->next;
	}
	if(ptr==NULL){
		printf("value not found");
		return ptr;
	}else {
		printf("value found");
		return ptr;
	}
}


void iseven(struct node *start,int value){
	while(start->data!=value){
		start=start->next;
	}
	if(start==NULL)
		printf("value does not exist");
	else if(start->data%2==0)
		printf("value is even");
	else 
		printf("value is not even");
}


void isodd(struct node *start,int value){
        while(start->data!=value){
                start=start->next;
        }
        if(start==NULL)
                printf("value does not exist");
        else if(start->data%2!=0)
                printf("value is odd");
        else
                printf("value is not odd");
}


void summation(struct node *start){
	int sum=0;
	while(start!=NULL){
		sum=sum+start->data;
		start=start->next;
	}
	printf("%d",sum);
}


void all_even(struct node *start){
	while(start!=NULL){
		if(start->data%2==0){
			printf("%d ",start->data);
			start=start->next;
		}
	}
}


void all_odd(struct node *start){
	while(start!=NULL){
		if(start->data%2!=0){
			printf("%d",start->data);
			start=start->next;
		}
	}
}	 


struct node *swap(struct node *start,int value,int value1){
	struct node *p,*q;
	p=q=start;
	while(p->data!=value){
		p=p->next;
	}
	while(q->data!=value1){
		q=q->next;
	}
	if(q==NULL || p==NULL){	
		printf("value not exist");
		return start;
	}
	int h;
	h=p->data;
	p->data=q->data;
	q->data=h;
	return start;
}


struct node *deletion_begin(struct node *start){
	start=start->next;
	return start;
}


struct node *deletion_end(struct node *start){
	struct node *ptr;
	ptr=start;
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=NULL;
	return start;
}


struct node *deletion_after(struct node *start,int value){
	struct node *ptr,*tmp;
	ptr=start;
	while(ptr->data!=value){
		ptr=ptr->next;
	}
	tmp=ptr->next;
	ptr->next=tmp->next;
	return start;
}


struct node *swap_node(struct node *start,int value,int value1){
	struct node *p,*p1,*tmp;
	struct node *q,*q1;
	p=q=start;
	while(p->data!=value){
		p1=p;
		p=p->next;
	}
	while(q->data!=value){
		q1=q;
		q=q->next;
	}
	if(p==NULL || q==NULL){
		printf("value not exist");
		return start;
	}else{
		p1->next=q;
		q1->next=p;
		tmp=p->next;
		p->next=q->next;
		q->next=tmp;
	}
	return start;
}


void maximum(struct node *start){
	int max;
	if(start==NULL)
		return ;
	max=start->data;
	while(start!=NULL){
		if(start->data > max)
			max=start->data;
		start=start->next;
	}
	printf("%d\n",max);
}


void minimum(struct node *start){
	int min;
	if(start==NULL)
		return ;
	min=start->data;
	while(start!=NULL){
		if(start->data < min)
			min=start->data;
		start=start->next;
	}
	printf("%d\n",min);
}


void print_reverse(struct node *start){
	if(start!=NULL){
		print_reverse(start->next);
		printf("%d ",start->data);
	}
}	


void print_alternate(struct node *start){
	while(start!=NULL && start->next->next!=NULL){
		printf("%d ",start->data);
		start=start->next->next;
	}
}


struct node *alternate_deletion(struct node *start){
	if(start==NULL){
		printf("empty list");
		return start;
	}
	while(start!=NULL && start->next!=NULL){
		start->next=start->next->next;
		start=start->next->next;
	}
	return start;
}


struct node *rearrange(struct node * start){
	struct node *ptr,*tmp;
	ptr=start;
	while(ptr->next->next!=NULL){		
		ptr=ptr->next;
	}
	tmp=ptr->next;
	ptr->next=NULL;
	tmp->next=start->next;
	start->next=tmp;
	return start;
}


void swap1(int *a,int *b){
	int h;
	h=*a;	
	*a=*b;
	*b=h;
}


struct node *bubble_sort(struct node *start){
	struct node *p,*q;
	int h;
	for(p=start;p->next!=NULL;p=p->next){
		for(q=p->next;q->next!=NULL;q=q->next){
			if(p->data > q->data){	
				h=p->data;
				p->data=q->data;
				q->data=h;
			}
		}
	}
	return start;
}	
