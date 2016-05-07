#include<stdio.h> 				//separate chaining 
#include<stdlib.h>
#include<string.h>

struct node {
	int data;	
	struct node *next;
};

int hash(int );					//retrun the index
struct node *insertion(struct node *,int );	//insertion on the index value
void display(struct node *);			//display 
struct node *search(struct node *,int );	//search for a value
struct node *deletion(truct node *,int );	//deletion of a value 

int main()
{
	int i;
	struct node *arr[101];

	for(i=0;i<101;i++){
		arr[i]=(struct node *)malloc(sizeof(struct node ));
		arr[i]=NULL;
	}

	char str[20];
	int value,index;
	scanf("%s",str);

	while(strcmp(str,"exit")!=0){
		if(strcmp(str,"insertion")==0){
			scanf("%d",&value);
			index=hash(value);
			arr[index]=insertion(arr[index],value);
		}
		else if(strcmp(str,"display")==0){
			scanf("%d",&index);
			display(arr[index]);
		}
		else if(strcmp(str,"search")==0){
			scanf("%d",&value);
			index=hash(value);
			arr[index]=search(arr[index],value);
		}
		else if (strcmp(str,"deletion")==0){
			scanf("%d",&value);
			index=hash(value);
			arr[index]=deletion(arr[index],value);
		}
		scanf("%s",str);
	}

	return 0;
}

int hash(int value){
	int index;
	index=value%101;  //prefer to use prime number wich avoid collisions
	return index;
}

struct node *insertion(struct node *start,int value){
	if(start==NULL){
		start=(struct node *)malloc(sizeof(struct node ));
		start->data=value;
		start->next=NULL;
		return start;
	}
	struct node *ptr,*tmp;
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	tmp=(struct node *)malloc(sizeof(struct node ));
	tmp->data=value;
	ptr->next=tmp;
	tmp->next=NULL;
	return start;
}

void display(struct node *start){
	while(start!=NULL){
		printf("%d",start->data);
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
		printf("value not exist");
		return start;
	}
	else if(ptr->data==value){
		printf("value found ");
	}
	return start;
}

struct node *deletion(struct node *start,int value){
		struct node *ptr,*tmp;
		ptr=start;	
		while(ptr->data!=value){
			tmp=ptr;
			ptr=ptr->next;
		}
		if(ptr==start){
			start=start->next;
			return start;
		}
		else if(ptr->next==NULL){
			tmp->next=NULL;
			return start;
		}
		else{
			tmp->next=ptr->next;
			return start;
		}
}			
