#include <stdio.h>
#include <stdlib.h>

struct graph{
    int data;
    struct graph *linked[7];
};
typedef struct graph node;
node *list[7];
int count_array[7] = {4,2,5,9,0,1,7};

void breadth_first_search(node *root, node *search){
    node *temp[7];
    int visited[7];
    int i;
    int j = 0;
    int l= 0;
    node *queue[7] = {NULL};
    int a = 0;
    int count = 0;

    while(a < 8){
        if(a == 0){
            queue[0] = root;
            temp[count] = root;
            visited[count] = temp[count] -> data;
            count++;
        }
        else{
 
            while(root -> linked[j] != NULL){

                for(i = 0; i<count; i++){
                    if(temp[i] == root -> linked[j])
                     j++;
                }

            if(root -> linked[j] != NULL){

                  for(int i = 0; i < 7; i++){
                    if(queue[i] == NULL){
                        queue[i] = root -> linked[j];
                         temp[count] = root -> linked[j];
                         visited[count] = temp[count] -> data;        
                         count++;          
                        break;
                    }
                  }

                
            }
                j++;
            }
        }

            if(a > 0){
                j = 0;
                root = queue[1];
                free(queue[0]);
            for(int i = 0; i<7; i++){
                if(i == 6){
                    queue[i] = NULL;
                }
                else
                queue[i] = queue[i+1];
            }

            }

            printf("%d ", visited[l]);
            l++;
        if(root == search)
        return;
        
        a++;
    }


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

        connect(list[0], list[1]);
        connect(list[0], list[2]);
        connect(list[0], list[3]);
        connect(list[1], list[5]);
        connect(list[2], list[4]);
        connect(list[4], list[6]);



    for(int i = 0; i < 7; i++)
        printf("%d ",list[i] -> data);

        printf("\n\n");

        print(list[4]);
        printf("\n");
        breadth_first_search(list[0],list[6]);




    return 0;
}

// list[0] = 4;
// list[1] = 2;
// list[2] = 5;
// list[3] = 9;
// list[4] = 0;
// list[5] = 1;
// list[6] = 7;
