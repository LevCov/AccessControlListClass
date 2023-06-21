#include <unordered_map>
#include <iostream>

template<class Entity, class Resource, class AccessMode = bool>
class ACL
{
  public:
  using EntityId = size_t;
  std::unordered_map<EntityId, std::unordered_map<Resource, AccessMode>> access_list;

    
  
 
    
    
  void AddEntity(EntityId const& e, Resource const& r, AccessMode m)
  {
    access_list[e][r] = m;
  }

  void DelEntity(EntityId const& e)
  {
    access_list.erase(e);
  }
    
    
  void SetAccessMode(EntityId const& e, Resource const& r, AccessMode m)
  {
      access_list[e][r] = m;
  }

  AccessMode GetAccessMode(EntityId const& e, Resource const& r) const
  {
    auto it_e = access_list.find(e); // finds an iterator  by the key e
    if (it_e == access_list.end())
    {
      return AccessMode{};
    }
    auto it_r = it_e->second.find(r); // finds an iterator  by the key r
    if (it_r == it_e->second.end())
    {
      return AccessMode{};
    }
    return it_r->second;
  }

  


};



int main(){
    
    ACL<size_t, std::string, bool>  acl;
    
    // Adding entities 001, 002 for resource 1 with access modes true and false
    acl.AddEntity(001, "resource", true);
    acl.AddEntity(002, "resource", false);
    
    // Getting access rights
    
    std::cout << "Access Mode of Entity 001 for resource is " << acl.GetAccessMode(001, "resource") << std::endl;
    std::cout << "Access Mode of Entity 002 for resource is " << acl.GetAccessMode(002, "resource") << std::endl;
    
    //Access mode change
    acl.SetAccessMode(002, "resource" , true);
    std::cout << "Access Mode of Entity 002 for resource after changing is " << acl.GetAccessMode(002, "resource") << std::endl;
    
    //Delleting an entity 002

    acl.DelEntity(002);
    std::cout << "Access Mode of Entity 002 for resourse after deleting is " << acl.GetAccessMode(002, "resource") << std::endl;
    
    
    
    

    

}
