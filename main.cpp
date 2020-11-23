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
};
