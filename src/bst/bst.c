#include"bst.h"
#include<stdlib.h>
#include<stdio.h>
bstn* CreateNode(int data)
{
  bstn *temp = (bstn *)malloc(sizeof(bstn));
  temp->data = data;
  temp->right = NULL;
  temp->left = NULL;
  return temp;
}
bstn* CreateBst(int data)
{
	return CreateNode(data);
}
void AddNode(int data,bstn *head)
{
    int addnodeflag_ = 0;
    bstn *ptr_ = head;
    while(addnodeflag_ != 1)
    {
      if(data<ptr_->data)
      {
        if(ptr_->left != NULL)
        {
          ptr_ = ptr_->left;
        }
        else
        {
          bstn *addnode_ = CreateNode(data);
          ptr_->left = addnode_;
          addnodeflag_ = 1;
        }
      }
      else
      {
        if(ptr_->right != NULL)
        {
          ptr_ = ptr_->right;
        }
        else
        {
          bstn *addnode_ = CreateNode(data);
          ptr_->right = addnode_;
          addnodeflag_ = 1;
        }
      }

    }
}
bstn* SearchKey(bstn *head,int key)
{
	bstn *ptr_ = head;
	bstn *parent_ = ptr_;
	while(ptr_!=NULL && key != ptr_->data)
	{
		if(key<ptr_->data)
		{
			parent_ = ptr_;
			ptr_=ptr_->left;
		}
		else
		{	parent_ = ptr_;
			ptr_=ptr_->right;
		}
	}
	return parent_;
}
bstn* MinKey(bstn *head)
{
	bstn *ptr_ = head;
	while(ptr_->left != NULL)
	{
		ptr_=ptr_->left;
	}
	
	return ptr_;
}
bstn* MaxKey(bstn *head)
{
	bstn *ptr_ = head;
	while(ptr_->right != NULL)
	{
		ptr_=ptr_->right;
	}
	return ptr_;
}
bstn* GetSuccesorParent(bstn *ptr)
{
	bstn *ptr_ = ptr->right;
	bstn *succesorparent_ = NULL;
	while(ptr_->left != NULL)
	{
		succesorparent_ = ptr_;
		ptr_ = ptr_->left;
	}
	return succesorparent_;
}
bstn* DeleteNode(int key,bstn *head)
{
	int root_flag = 0;
	bstn *NodeToDeleteParent_ = SearchKey(head,key);
	bstn *NodeToDelete_ = NULL;
	if(key>NodeToDeleteParent_->data)
	{
		NodeToDelete_ = NodeToDeleteParent_->right;
	}
	else if(key == NodeToDeleteParent_->data)
	{
		NodeToDelete_ = NodeToDeleteParent_;
		root_flag = 1;
	}
	else
	{
		NodeToDelete_ = NodeToDeleteParent_->left;
	}
	if(NodeToDelete_ -> right == NULL && NodeToDelete_ -> left == NULL)
	{

		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NULL;
			free(NodeToDelete_);
		}
		else
		{
			NodeToDeleteParent_->right = NULL;
			free(NodeToDelete_);
		}
	}
	else if(NodeToDelete_->right!=NULL && NodeToDelete_->left==NULL)
	{
		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NodeToDelete_->right;
			free(NodeToDelete_);
		}
		else
		{
			NodeToDeleteParent_->right = NodeToDelete_->right;
			free(NodeToDelete_);
		}	
	}
	else if(NodeToDelete_->left != NULL && NodeToDelete_->right == NULL)
	{
		if(NodeToDelete_->data<NodeToDeleteParent_->data)
		{
			NodeToDeleteParent_->left = NodeToDelete_->left;
			free(NodeToDelete_);
		}
		else
		{
			NodeToDeleteParent_->right = NodeToDelete_->left;
			free(NodeToDelete_);
		}
	}
	else if(NodeToDelete_->left != NULL && NodeToDelete_->right != NULL)
	{
		bstn *succesorParent_ = NodeToDelete_;
		bstn *successor_ = NodeToDelete_->right;
		while (successor_->left != NULL) {
			succesorParent_ = successor_;
			successor_ = successor_->left;
		}
		NodeToDelete_->data = successor_->data;
		if (succesorParent_->left == successor_) {
			succesorParent_->left = successor_->right;
		} else {
			succesorParent_->right = successor_->right;
		}
		free(successor_);
		
		
	}
	return head;

}
void PrintIn(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    PrintIn(tptr_->left);
    printf("%d ",tptr_->data);
    PrintIn(tptr_->right);
}
void PrintPost(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    PrintPost(tptr_->left);
    PrintPost(tptr_->right);
    printf("%d ",tptr_->data);
 }
void PrintPre(bstn *head)
{
    bstn *tptr_ = head;
    if(tptr_ == NULL)
    {
      return;
    }
    printf("%d ",tptr_->data);
    PrintPre(tptr_->left);
    PrintPre(tptr_->right);

}
