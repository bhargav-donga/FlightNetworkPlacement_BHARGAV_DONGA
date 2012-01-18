#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL,*temp,*pop,*start,*psave;
void main()
{
    int data=-1,i=0,choice,bool=1;
 pop=(struct node *)malloc(sizeof(struct node));
    while(1){
      
       printf("\n1) Push\n2) Pop\n3) Exit\n");
        printf("\nEnter ur choice  : ");
        scanf("%d",&choice);
        switch(choice){
	  case 1:{
            temp=(struct node *)malloc(sizeof(struct node));
            printf("Enter data :");
            scanf("%d",&i);
	    if((data+1)==i){
	      if(i>=10){
		printf("Data beyond limit(9)");
	      break;
	      }
            temp->data=i;
            temp->link=top;
            top=temp;
	    data=data+1;
	    printf("pushed %d",data);
	    break;      
	    }else
	    {
	      printf("\n(!) Check data sequence and try again.(must be the next :%d)\n",data+1);
	        
	    }
	    break;
	}
	  case 2:{
	    
            if(top!=NULL)
            {
	        printf("\nThe poped element is %d\n",top->data);
		
		
		pop->link=top;
		top=top->link;
		pop=pop->link;
		pop->link=NULL;
		
		printf("popped out values : ");
		if(bool){		  
		  start=(struct node *)malloc(sizeof(struct node));
		  start=pop;
		  psave=start;
		  bool=0;
		}
		 
		while(start!=NULL)
            {
                printf("%d->",start->data);
                start=start->link;
            }
            start=psave;
            }
            else
            {
                printf("\nStack Underflow");    
            }
	
	    break;
	  }
	  
	  case 3: 
	    exit(0);
	}
    
  
    }
}
