#include<iostream>

class Node
{
  public:
  int node_key{};
  int node_el{};
  Node* node_next{};
  //Default Ctor
  Node():node_key{0},node_el{0},node_next{nullptr}{}
  Node(int k = 0,int e = 0):node_key{k},node_el{e}{}
};

class List_
{
  public:
  Node* iter;
  Node* mem_Head;
  //Default Ctor
  List_():mem_Head{nullptr}{}
  List_(Node* m):mem_Head{m}{}
  
  //Control the node if exists using key val...(Anahtar eleman kontrolünün yapılacağı blok)
  Node* HaveNode(int k)
  {
    Node* temp=nullptr;
    iter=mem_Head;
      while(iter)
      {
        if(iter->node_key==k)
        {
          temp=iter;
          return temp;
        }
        iter=iter->node_next;
      }
      return temp;
  }
  
  //Add over the last element(Son elemanın üzerine ekleme yapan işlev)
  void AddOverLast(Node* n)
  {
    static int inc=0;
    if(HaveNode(n->node_key))
      std::cout<<"Node already exists...\n";//Alan zaten alınmış
    else
    {
      if(!mem_Head)
        mem_Head = n;
      else
      {
        iter=mem_Head;
        while(iter->node_next)
          iter=iter->node_next;
        iter->node_next = n;
        std::cout<<inc++<<"-) Node added...\n";//Alan başarıyla ayrıldı...
      }
     }
  }
  
  //Add the over first Node..
  void AddFirstNode(Node* n)
  {
    if(!mem_Head)
       mem_Head=n;
    else
    {
      n->node_next = mem_Head;
      mem_Head = n;
    }
  }
  
  //Delete the Last Node
  void DeleteFromLastNode()
  {
    iter=mem_Head;
    while(iter->node_next)
    {
      if(!(iter->node_next->node_next))
      {
        iter->node_next=nullptr;
        break;
      }
      iter=iter->next;
    }
  }
  
  void DeleteWithKey(int k)
  {
    auto mem = HaveNode(k);
    iter = mem_Head;
    if(!mem)
        std::cout<<"key didn't find in the list...\n";
    else
    {
      while(iter->node_next)
      {
        if(iter->node_next->node_key == mem->node_key)
            iter->node_next = mem->node_next;
        
        iter=iter->node_next;
      }
    }
  }
  
  //Print list using for loop//For döngüsü ile listeyi ekrana basan fonk.
  void PrintList()
  {
    iter=mem_Head;
    for(iter=mem_Head;iter->node_next!=nullptr;iter=iter->next)
        std::cout<<"key: "<<iter->node_key<<" el: "<<iter->node_el<<'\n';
    std::cout<<"key: "<<iter->node_key<<" el: "<<iter->node_el<<'\n';
  }
  
  //Destructor
  ~List_(){delete mem_Head; delete iter;}
};

int main()
{
  List_* lst=new List_();
  for(int i=0;i<5;++i)
      lst->AddOverLast(new List(i,i+1));
  lst->PrintList();
  std::cout<<"\n-----\n";
  
  lst->AddFirstNode(new List_(50,51));
  lst->PrintList();
  std::cout<<"\n-----\n";
  
  lst->DeleteFromLastNode();
  lst->DeleteWithKey(2);
  lst->PrintList();
}

//=== Program OUTPUT ===//
/*
  0-) Node added...
  1-) Node added...
  3-) Node added...
  key: 0 el:1
  key: 1 el:2
  key: 2 el:3
  key: 3 el:4
  key: 4 el:5
  
  -----
  key:50 el 51
  key: 0 el:1
  key: 1 el:2
  key: 2 el:3
  key: 3 el:4
  key: 4 el:5
  
  ------
  key:50 el 51
  key: 0 el:1
  key: 1 el:2
  key: 3 el:4
  
*/
//=====================//
