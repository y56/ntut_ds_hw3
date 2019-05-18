/* 
This head file prepares the data-types and operations for 
implementation of the required data structures:
  
1.  a queue using an array.
2.  a circular queue using an array.
3.  a stack using an array.
4.  a queue using two stacks.
*/
/*
隊伍有前方(以front表示)以及後方(以back表示)之分。
若要進入隊伍(Push)，一定是從back進入。
若要離開隊伍(Pop)，一定是從front離開。
ref: http://alrightchiu.github.io/SecondRound/
queue-introjian-jie-bing-yi-linked-listshi-zuo.html
*/
/*----------------------------------------------------------------------------*/
// A structure to represent a queue 
struct Queue 
{ 
    int front; 
    int rear; // rear means back
    int size; 
    unsigned capacity; 
    int* array; 
}; 
