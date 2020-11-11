#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node* left;
        node* right;
};

class trie{
    node *root;
    
public:
    trie(){
        root=new node();
    }
    
    //insert
    void insert(int n){
        node* temp=root;
        
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            
            if(bit==0){
                if(temp->left==NULL){
                    temp->left= new node();
                }
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right= new node();
                }
                temp=temp->right;
            }
        }
    } 
    
    //find max xor considering current number
    int max_xor_helper(int n){
        node* temp=root;
        int current_ans=0;
        
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            
            if(bit==0){
                if(temp->right!=NULL){
                    temp=temp->right;
                    current_ans+=(1<<i);
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->left!=NULL){
                    temp=temp->left;
                    current_ans+=(1<<i);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return current_ans;
    } 
    
    int max_xor(int* a,int n){
        int i,ans=0;
        
        for(i=0;i<n;i++){
            int val=a[i];
            insert(val);
            ans=max(ans,max_xor_helper(val));
        } 
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    trie t;
    cout<<t.max_xor(a,n);
    
    return 0;   
}