#include<stdio.h>
#include<stdlib.h>

struct node{
  int num;
  int eliminated;
  struct node *link;
    
};
struct node *circle,*start,*temp;
void main(){
  int m,n,i,bool=1,won,number=0;
  
  start=(struct node *)malloc(sizeof(struct node));
  circle=(struct node *)malloc(sizeof(struct node));
  printf("GIVE NUMBER OF KIDS  : ");
  scanf("%d",&m);
  
 for(i=1;i<=m;i++){
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
  while(won!=1){
    n=1;
    while(n!=(m-1)){
      while(start->eliminated==1){
	printf("\n%d skipped ",start->num);
	
	start=start->link;
      }
	if(n==1){  
	  number=start->num;
	// printf("\n exit %d numbers ",number);
	  
	}
	if(n==2){
	   //printf("\nexit2 %d & %d numbers ",number,start->num);
	if(number==start->num){
	 // printf("answer %d",start->num);
	won=1;
	break;
	  }
  
	}
	n=n+1;
	printf("\n%d counted ",start->num);
	 
	start=start->link;
      }      
    while(start->eliminated==1){
	printf("\n%d skipped ",start->num);
	//sleep(1);
	
	start=start->link;
      }
      if(n==2){ //In case of m<4
	  // printf("\nexit2 %d & %d numbers ",number,start->num);
	if(number==start->num){
	//  printf("answer %d",start->num);
	won=1;
	break;
	}}
    if(won!=1){
      start->eliminated=1;
    printf("\n%d ELIMINATED ",start->num); 
    start=start->link;
      
    }
  }
  printf("\n\n(!) KID AT POSITION %d WON...\n ",number);
  
}