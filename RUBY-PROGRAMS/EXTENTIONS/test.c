#include <stdio.h>

#include <ruby-1.9.1/ruby.h>
VALUE hw_mMyModule, hw_cMyClass;

VALUE greet(VALUE self, VALUE names)
{
   int i;
   struct RArray *names_array;
   
   names_array = RARRAY(names);
   
   for(i = 0; i < names_array->len; i++)
   {
       VALUE current = names_array->ptr[i];
       if(rb_respond_to(current, rb_intern("to_s")))
       {
           VALUE name = rb_funcall(current, rb_intern("to_s"), 0);
           printf("hello %s, ", StringValuePtr(name));
       }
   }
   printf("I'm a machine.\n");
   
   return Qnil;
}

void Init_test()
{
   hw_mMyModule = rb_define_module("MyModule");
   hw_cMyClass = rb_define_class_under(hw_mMyModule, "MyClass", rb_cObject);

   rb_define_method(hw_cMyClass, "greet", greet, 1);
}
