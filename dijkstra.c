#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define infinity INT_MAX

struct graph{
    int data;
    int value;
    struct graph *weight[6];
    struct graph *linked[7];
};
typedef struct graph node;
node *list[7];
int count_array[7] = {4, 1, 8, 6, 5, 3, 9};
int weight_array[10];



void dijkstra(node *root){
    node *visited[7] = {NULL};
    node *xnode[7] = {NULL};
    node *temp[7];
    int a = 0;
    int j = 0;
    int i;
    int count = 0;
    int l = 0;
    int t = 0;
    int x = 0;

    for(i = 0; i < 7; i++)
    temp[i] = (node *)malloc(sizeof(node));

    for(i = 0; i < 7; i++)
        list[i] -> value = infinity;                        // all values are infinity

    root -> value = 0;

    visited[count] = root;
    count++;

    for(i = 0; i < 7; i++)
    temp[i] -> value = infinity;

    while(a < 6){

        while(root -> linked[j] != NULL){                   // root -> linked[] traversal
            if(root -> weight[j] -> value + root -> value< root -> linked[j] -> value)     // weight value and linked value control
                root -> linked[j] -> value = root -> weight[j] -> value + root -> value;
            j++;
        }

        for(i = 0; i < 7; i++){
            for(j = 0; j < count; j++){
                if(list[i] == visited[j]){                    //  passed the node ?
                    t++;
                    break;
                }
            }
            if(t == 0){                           //  if not passed xnode[] = list[]
                xnode[x] = list[i];
                x++;
            }
            t = 0;
        }

        for(i = 0; i < x; i++){
            if(xnode[i] ->  value < temp[l] -> value){              // least value
            temp[l] = xnode[i];
            }
        }


        root = temp[l];                                   //  update root node 

        visited[count] = root;                           // visited[] dizisine root düğümü ata

        count++;

        l++;

        for(i = 0; i < x; i++)
        xnode[i] = NULL;    
     
        printf("%d and %d distance: %d\n",list[0] -> data,root -> data, root -> value);
        j = 0;
        x = 0;
        a++;

    }

}

int j = 0;
void connect(node * node1, node *node2){                            // weight and linked settings
        int i = 0;
        while(node1 -> linked[i] != NULL)
        i++;

        node1 -> linked[i] = node2;

         i = 0;
        while(node2 -> linked[i] != NULL)
        i++;

        node2 -> linked[i] = node1;
        i = 0;
        printf("%d and %d weight: ",node1 -> data, node2 -> data);
        scanf("%d",&weight_array[j]);
    while(node1 -> weight[i] -> value != 0)
        i++;    
        node1 -> weight[i] -> value = weight_array[j];

        i = 0; 
    while(node2 -> weight[i] -> value != 0)
        i++;
        node2 -> weight[i] -> value = weight_array[j];
        j++;

}

void print(node *node1){                                // selected print node links
        int i = 0;
        printf("connected %d: ", node1 -> data);
        while(node1 -> linked[i] != NULL){
        printf("%d ", node1 -> linked[i] -> data);
        i++;
        }
}

int main(){
    int i,j;
    for( i=0; i < 7; i++)
        list[i] = (node *)malloc(sizeof(node));

    for( i=0; i < 7; i++)
        list[i] -> data = count_array[i];

    for(i = 0; i < 7; i++){
        for(j = 0; j < 10; j++){
            list[i] -> weight[j] = (node *)malloc(sizeof(node));
        }
    }
    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            list[i] -> linked[j] = NULL;
        }
    }
    connect(list[0], list[1]);
    connect(list[0], list[2]);
    connect(list[0], list[3]);
    connect(list[1], list[6]);
    connect(list[2], list[6]);
    connect(list[2], list[5]);
    connect(list[2], list[3]);
    connect(list[3], list[4]);
    connect(list[4], list[5]);
    connect(list[5], list[6]);

    printf("\nnodes: ");
    for( i = 0; i < 7; i++)
        printf("%d ",list[i] -> data);                      // print node
    printf("\n\n");
    dijkstra(list[0]);                                      // call dijkstra
    return 0;
}
// list[0] = 4
// list[1] = 1
// list[2] = 8
// list[3] = 6
// list[4] = 5
// list[5] = 3 
// list[6] = 9
