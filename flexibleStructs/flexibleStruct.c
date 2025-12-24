#include<string.h>



typedef struct{
  char* ptr; //Ptr to string start.
  int unsigned len; //STr length.
}StrPtrWLen; //Str metadata Struct.

struct Address{
  StrPtrWLen city; //Instead of the actual Str, its metadata is stored in the Struct so the actual Str can be refered to wherever it is in Memo.
  StrPtrWLen state; //Several arbitrary length Str can now be stored in the Struct since the size of the metadata is fixed.
};

struct Person{
  StrPtrWLen name; //An arbitrary length Str is not forcibly at the end of the Struct now, since the size of its metadata is fixed.
  int unsigned age;
  struct Address address;
};



int main(){


  char name[]="Naveen";
  char city[]="Chicago";
  char state[]="Illinois";


  struct Person person;


  StrPtrWLen namePtrWLen;
  namePtrWLen.ptr=&name[0];
  namePtrWLen.len=strlen(name);
  person.name=namePtrWLen;

  person.age=50;
  
  StrPtrWLen cityPtrWLen;
  cityPtrWLen.ptr=&city[0];
  cityPtrWLen.len=strlen(city);
  person.address.city=cityPtrWLen;
  
  StrPtrWLen statePtrWLen;
  statePtrWLen.ptr=&state[0];
  statePtrWLen.len=strlen(state);
  person.address.state=statePtrWLen;
}
