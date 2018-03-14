#include <stdio.h>
#include <stdlib.h>

int one()
{
    int n;
    printf("Enter number of buildings: ");
    scanf("%d",&n);
    int i;
    int array[n];
    printf("Enter the height of buildings as space separated integers: ");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    //Program starts here
    int stack[n];
    int top = 0;
    int top_element;
    int max_area = 0;

    for(i=0;i<n;i++){
        if(top==0 || array[stack[top]] <= array[i]){
            stack[++top] = i;
        }
        else{
           top_element = stack[top--];
           int area = array[top_element] * (top==0?i:i-stack[top]-1);
           if(area>max_area){
            max_area = area;
           }
           i--;
        }
    }

    for(i=top;i>0;i--){
        top_element = stack[i];
        int area = array[stack[i]] * (top==0?i:i-stack[top]-1);
        if(area>max_area) max_area = area;
    }

    printf("Max continuous area = %d units",max_area);
    return 0;
}
