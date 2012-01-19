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
        printf("\nEnter ur choice  : ");  //PROMPT FOR OPERATION
        scanf("%d",&choice);
        switch(choice){  //  SWITCH CASE BLOCK
	  case 1:{  //  BLOCK OF PUSH OPERATION
            temp=(struct node *)malloc(sizeof(struct node));
            printf("Enter data :");
            scanf("%d",&i);
	    if((data+1)==i){ //  CHECK OF RESTRICTION OF ENTERD DATA
	      if(i>=10){
		printf("Data beyond limit(9)");
	      break;
	      }
            temp->data=i;  //  ADDING TO STACK
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
	  case 2:{    //  BLOCK OF POP OPERATION
	    
            if(top!=NULL)
            {
	        printf("\nThe poped element is %d\n",top->data);
		
		
		pop->link=top;  //  ADDING POPPED NODES TO POP LIST
		top=top->link;  //SETTING TOP TO PREVIOUS POSITION IN STACK
		pop=pop->link;
		pop->link=NULL;
		
		printf("popped out values : "); // PRINTING CURRENTLY POPPED OUT VALUE
		if(bool){		  
		  start=(struct node *)malloc(sizeof(struct node));
		  start=pop;
		  psave=start;
		  bool=0;
		}
		 
		while(start!=NULL) //  PRINTING ALL POPPED OUT VALUES IN SEQUENCE
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
	  
	  case 3:   // EXIT CASE
	    exit(0);
	}
    
  
    }
}
