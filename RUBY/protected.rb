class A
  def main_method
    method1
  end
 
  protected
  def method1
    puts "hello from #{self.class}"
  end
end
 
class B < A
  def main_method
    method1
  end
end
 
class C < A
  def main_method
    self.method1
  end
end

c = B.new
c.main_method
