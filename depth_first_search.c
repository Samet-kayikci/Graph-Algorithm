#include <stdio.h>
#include <stdlib.h>

struct graph{
    int data;
    struct graph *linked[7];
};
typedef struct graph node;
node *list[7];
int count_array[7] = {5,1,9,2,10,3,8};


void depth_first_search(node *root){

node *stack[7] = {NULL};
node *visited[7] = {NULL};
int a = 0;
int i;
int j = 0;
int count = 0;
int l = 0;
int c = 0;


while (visited[6] == NULL || stack[0] != NULL){
    if(a == 0){
        stack[l] = root;
        visited[count] = root;
        l++;
        count++;
    }
    else{
        for(i = 0; i < count; i++){
            if(visited[i] == root -> linked[j] )
                j++;
        }
        

    if(root -> linked[j] != NULL){
        root = root -> linked[j];
        stack[l] = root;
        visited[count] = root;
        l++;
        count++;
       
    }
    else{
        l --;
        root = root -> linked[0];
        stack[l] = NULL;
    }
        
        
    }
    j = 0;

a++;    
}

for(i = 0; i < 7; i++)
    printf("%d ",visited[i] -> data);

}



void connect(node * node1, node *node2){
        int i = 0;
        while(node1 -> linked[i] != NULL)
        i++;

        node1 -> linked[i] = node2;
         i = 0;
        while(node2 -> linked[i] != NULL)
        i++;

        node2 -> linked[i] = node1;
}

void print(node *node1){
        int i = 0;
        printf("connected %d: ", node1 -> data);
        while(node1 -> linked[i] != NULL){
        printf("%d ", node1 -> linked[i] -> data);
        i++;
        }
}


int main(){
    for(int i=0; i<7; i++)
        list[i] = (node *)malloc(sizeof(node));

    for(int i=0; i<7; i++)
        list[i] -> data = count_array[i];


    connect(list[0],list[1]);
    connect(list[0],list[2]);
    connect(list[0],list[4]);
    connect(list[1],list[3]);
    connect(list[2],list[6]);
    connect(list[3],list[5]);

    for(int i = 0; i < 7; i++)
        printf("%d ",list[i] -> data);

        printf("\n\n");

        print(list[4]);
        printf("\n");
        depth_first_search(list[0]);

    return 0;
}
// list[0] = 5
// list[1] = 1
// list[2] = 9
// list[3] = 2
// list[4] = 10
// list[5] = 3
// list[6] = 8



