#include<stdio.h> 				//heap(max_heap and min_heap)
#include<string.h>		

int parent(int ,int [],int );			//parent of a given element
int left(int ,int[], int );			//left child of given element
int right(int ,int [], int );			//right child of given element
int minimum(int ,int []);			//using the input array
int maximum(int ,int []);			//using the input array	
int extract_max(int ,int []); 			//deletion of maximum element in maxheap
int extract_min(int ,int []);			//deletion of minimum element in minheap
void increase_key(int,int [],int ,int );	//increase the value of an element	
void leaf_nodes(int ,int[]);			//leaf nodes in heap
int decrease_key(int ,int [],int ,int );	//decrease the value of an element
void buildheap_max(int ,int []);
void minheapify(int ,int []);
void buildheap_min(int ,int []);
void maxheapify(int ,int [],int );
void heapsort(int ,int []);		
int main()
{
	int n,i,value=0; //number of nodes
	scanf("%d",&n);
	int a[n];		
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	char str[20];
	scanf("%s",str);
	
	while(strcmp(str,"exit")!=0){
		if(strcmp(str,"parent")==0){
			scanf("%d",&i);
			value=parent(n,a,i);
			if(value!=-1)
				printf("%d",a[value]);
		}
		else if(strcmp(str,"left")==0){
			scanf("%d",&i);
			value=left(n,a,i);
			if(value!=-1)
				printf("%d",a[value]);
		}
		else if(strcmp(str,"right")==0){
			scanf("%d",&i);
			value=right(n,a,i);
			if(value!=-1)
				printf("%d",a[value]);
		}
		else if(strcmp(str,"minimum")==0){
			value=minimum(n,a);
			printf("%d",value);
		}
		else if(strcmp(str,"minimum")==0){
			value=maximum(n,a);
			printf("%d",value);
		}
		else if(strcmp(str,"leaf_nodes")==0){
			leaf_nodes(n,a);
		}
		else if(strcmp(str,"buildheap_max")==0){
			buildheap_max(n,a);
			for(i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
		}
		else if(strcmp(str,"heapsort")==0){
			heapsort(n,a);
		}
		else if(strcmp(str,"extract_max")==0){
			value=extract_max(n,a);
			printf("%d",value);
		}
		else if(strcmp(str,"extract_min")==0){
			value=extract_min(n,a);
			printf("%d",value);
		}
		else if(strcmp(str,"increase_key")==0){
			scanf("%d%d",&i,&value);
			increase_key(n,a,i,value);
		}
		else if(strcmp(str,"decrease_key")==0){
			scanf("%d%d",&i,&value);
			decrease_key(n,a,i,value);
		}
		else if(strcmp(str,"buildheap_min")==0){
			buildheap_min(n,a);
			for(i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
		}
		scanf("%s",str);
	}

	return 0;
}

int parent(int n,int a[n],int i){
	int j,item;
	for(j=1;j<=n;j++){
		if(a[j]==i);
			item=j;
	}
	if(item==1){
		printf("root node");
		return -1;
	}
	return item/2;
}

int left(int n,int a[n],int i){
	int j,item;
	for(j=1;j<=n;j++){
		if(a[j]==i)
			item=j;
	}
	if(2*item <= n)
		return 2*item;
	else 
		return -1;
}

int right(int n,int a[n],int i){
	int j,item;
        for(j=1;j<=n;j++){
                if(a[j]==i)
                        item=j;
        }
        if(2*item+1 <= n)
                return 2*item+1;
        else
                return -1;

}

int minimum(int n,int a[n]){
	int min,i;
	min=a[1];
	for(i=1;i<=n;i++){
		if(a[i]<min)
			min=a[i];
	}
	return min;
}

int maximum(int n,int a[n]){
	int max,i;
	max=a[0];
	for(i=1;i<=n;i++){
		if(a[i] > max)
			max=a[i];
	}
	return max;
}

void maxheapify(int n,int a[n],int i){
	int l,r,max=i;
	l=2*i;
	r=l+1;
	if(l<=n && a[l] >a[i])
		max=l;
	if(r<=n && a[r] >a[l])
		max=r;
	if(max!=i) {
		a[max] = a[i] + a[max] - (a[i] = a[max]);
		maxheapify(n,a,max);
	}
}

void minheapify(int n,int a[n],int i){
	int l,r,min=i;
	l=2*i;
	r=l+1;
	if(l<=n && a[l] < a[i])
		min=l;
	if(r<=n && a[r] < a[l])
		min=r;
	if(min!=i) {
		a[min] = a[i] + a[min] - (a[i] = a[min]);
		minheapify(n,a,min);
	}
}

void leaf_nodes(int n,int a[n]){
	int j=0,i;
	j=n/2;
	for(i=j+1;i<=n;i++){
		printf("%d ",a[i]);
	}
}

void buildheap_max(int n,int a[n]){
	int j;
	for(j=n/2;j>=1;j--){
		maxheapify(n,a,j);
	}
}


void buildheap_min(int n,int a[n]){
	int j;
	for(j=n/2;j>=1;j--){
		minheapify(n,a,j);
	}
}

void heapsort(int n,int a[n]){
	int i,k=0,j,l,b[n];
	build_heap(n,a);
	j=n;
	b[j]=a[k];
	j--;
	k++;
	for(i=n;i>=2;i--){
		a[i]=a[1]+a[i]-(a[1]=a[i]);
		n=n-1;
		maxheapify(n-1,a,1);
	}
	for(l=1;l<n;l++){
		printf("%d ",a[l]);
	}
}

int extract_max(int n,int a[n]){
	if(n<1){
		printf("underflow");
		return -1;
	}
	int max;
	max=a[1];
	a[1]=a[n];
	n=n-1;
	maxheapify(n,a,1);
	return max;
}
int extract_min(int n,int a[n]){
	if(n<1){
		printf("underflow");
		return -1;
	}
	int min;
	min=a[1];
	a[1]=a[n];
	n=n-1;
	minheapify(n,a,1);
	return min;
}
void increase_key(int n,int a[n],int i,int value){
	if(value < a[i])
		return ;
	a[i]=value;
	while(i >1 && a[i/2] <= a[i]){
		a[i]=a[i]+a[i/2]-(a[i/2]=a[i]);
		i=i/2;
	}
}
void decrease_key(int n,int a[n],int i,int value){
	if(value > a[i])
		return ;
	a[i]=value;
	while(i >1 && a[i/2] <= a[i]){
		a[i]=a[i]+a[i/2]-(a[i/2]=a[i]);
		i=i/2;
	}
}

