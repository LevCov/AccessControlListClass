# AccessControlListClass

A class that implements an Access control list.


Description of methods:

**void AddEntity(EntityId const& e, Resource const& r, AccessMode m)**
'''
This method adds an entity for the selected resource with
access (true or false).

''

**void DelEntity(EntityId const& e)**
'''
This method deletes the selected entity.
 
'''

**void SetAccessMode(EntityId const& e, Resource const& r, AccessMode m)**
'''
This method changes the access mode for the selected entity to the selected resource.

'''


**AccessMode GetAccessMode(EntityId const& e, Resource const& r) const**
'''
The method shows the access mode of the selected entity to the selected resource.

'''


The main function has an example of using this class.

**Testing**
Run file from root directory:

1) g++ --std=c++17 -o aclClass aclClass.cpp
2) ./aclClass

