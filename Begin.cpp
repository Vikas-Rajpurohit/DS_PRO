#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE=26;

unordered_map<string,string> directory;

void search(string name){

    if(directory.find(name) == directory.end()){
        cout<<"No Such Contact"<<endl;
    }
    else{
        cout<<name<<" -> "<<directory[name]<<endl;
    }

}

void New(string name,string contact){
    directory.insert(make_pair(name,contact));

    cout<<"Saved"<<endl;
}

class Trie{
    public:
    Trie *child[ALPHABET_SIZE];
    bool end;

    Trie(){
        for(int i=0;i<ALPHABET_SIZE;i++){
            child[i] = NULL;
        }
        end=false;
    }
};

void insert(Trie* &root,string key){

    Trie* temp=root;
    for(int i=0;i<key.length();i++){
        int idx=key[i] - 'a';

        if(!temp->child[idx]){
            temp->child[idx] = new Trie();
        }

        temp = temp->child[idx];
    }

    temp->end = true;
}

void display(Trie* root,string res){

    Trie* temp = root;
    bool flg = false;

    for(int i=0;i<26;i++){
        if(temp->child[i]){
            flg = true;
        }
    }

    if(temp->end == true && flg){
        cout<<res<<endl;
    }else if(temp->end == true && !flg){
        cout<<res<<endl;
        return ;
    }
     
    for(int i=0;i<26;i++){
        if(temp->child[i]){
            display(temp->child[i],res+char(i+'a'));
        }
    }
}

void displayAll(unordered_map<string,string> m){
    for (auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }   
}

bool search(Trie* root,string key){

    Trie* temp=root;
    for(int i=0;i<key.length();i++){
        int idx=key[i] - 'a';

        if(!temp->child[idx]){
            return false;
        }

        temp = temp->child[idx];
    }

    return temp->end;
}

void query(Trie* root,string key){

    Trie* temp=root;
    for(int i=0;i<key.length();i++){
        int idx=key[i] - 'a';

        if(!temp->child[idx]){
            cout<<"No match found"<<endl;
            return;
        }

        temp = temp->child[idx];
    }

    display(temp,key);
}

int main(){
    Trie *root = new Trie();

    bool flg=true;
    cout<<"Hello What you want to do"<<endl;
    while(flg){
        cout<<"1.Query"<<" "<<"2.Insert"<<" "<<"3.Select"<<" "<<"4.Display All"<<endl;
        cout<<"Enter Option:";
        int a; cin>>a;

        if(a==1){
            cout<<"Enter String"<<endl;
            string str; cin>>str;

            transform(str.begin(), str.end(), str.begin(), ::tolower);

            query(root,str);
        }else if(a==2){
            cout<<"Enter Name and Phone no"<<endl;
            string name,phn;
            cin>>name>>phn;

            transform(name.begin(), name.end(), name.begin(), ::tolower);

            insert(root,name);
            New(name,phn);
        }else if(a==3){
            cout<<"Enter the Contact name"<<endl;
            string s; cin>>s;

            transform(s.begin(), s.end(), s.begin(), ::tolower);
            
            search(s);
        }else if(a==4){
            displayAll(directory);
        }else{
            cout<<"Press another key"<<endl;
        }

        cout<<"Wanna exit ? 1.Yes 2.No"<<endl;

        int e; cin>>e;

        flg = e==1 ? false : true;
    }

    cout<<"Thank you (^_^) "<<endl;
    
    return 0;
}