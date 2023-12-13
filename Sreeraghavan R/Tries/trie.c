struct node{
    struct node *arr[26];
    int endOfWord;
};

node* createNode(node* prev,char val,int end){
    node* new = (struct node*)malloc(sizeof(struct node));
    prev->arr[val-97] = new;
    new->endOfWord = end;
}

void insertLetter(node* root,char val,int end){
    struct node* iter = root;
    
}