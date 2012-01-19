#include<stdio.h>
#include<stdlib.h>

struct node{  // NODE FOR EACH KID
  int num;
  int eliminated;
  struct node *link;
    
};
struct node *circle,*start,*temp;
void main(){
  int m,n,i,bool=1,won,number=0,incre;
  
  start=(struct node *)malloc(sizeof(struct node));
  circle=(struct node *)malloc(sizeof(struct node));
  printf("GIVE NUMBER OF KIDS  : "); //  ENTERING VALUES OF M AND N
  scanf("%d",&m);
  printf("GIVE VALUE OF N  : ");
  scanf("%d",&n);
  
 for(i=1;i<=m;i++){  //  CREATING CIRCULAR QUEUE
   if(bool){
     circle->num=i;
     circle->eliminated=0;
      bool=0;
      start=circle;
      continue;
  }
   temp=circle;
   circle=(struct node *)malloc(sizeof(struct node));
   circle->num=i;
   circle->eliminated=0;
   temp->link=circle;
         
}
  circle->link=start;
  
  
  while(won!=1){  // FIRST LOOP RUNS TILL WINNING
    incre=1;
    
    while(incre!=n){   //  SECOND LOOP RUNS TILL COUNT IS EQUAL TO GIVEN VALUE N
      while(start->eliminated==1){  //  WHILE LOOP FOR SKIPPING ALREADY ELIMINATED KID(S)
	printf("\n%d skipped ",start->num);
	
	start=start->link;
      }
	if(incre==1){  // TRACKING NUMBER OF FIRST COUNTED KID.
	  number=start->num;
	// printf("\n exit %d numbers ",number);
	  
	}
	if(incre==2){  
	   //printf("\nexit2 %d & %d numbers ",number,start->num);
	if(number==start->num){   //  WINNING CONDITION
	 // printf("answer %d",start->num);
	won=1;
	break;
	  }
  
	}
	incre=incre+1;
	printf("\n%d counted ",start->num);
	 
	start=start->link;
      }      
    while(start->eliminated==1){  // WHILE LOOP FOR SKIPPING ALREADY ELIMINATED KID(S)
	printf("\n%d skipped ",start->num);
	//sleep(1);
	
	start=start->link;
      }
      if(incre==2){   //  IN CASE OF M<4
	  // printf("\nexit2 %d & %d numbers ",number,start->num);
	if(number==start->num){
	//  printf("answer %d",start->num);
	won=1;
	break;
	}}
    if(won!=1){  //  ELIMINATING THE KID AFTER COUNTING
      start->eliminated=1;
    printf("\n%d ELIMINATED ",start->num); 
    start=start->link;
      
    }
  }
  printf("\n\n(!) KID AT POSITION %d WON...\n ",number);
  
}